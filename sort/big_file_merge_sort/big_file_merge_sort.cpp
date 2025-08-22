#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <queue>
#include <string>

const std::string file_name = "1g_int_example_file.dat";
const std::string target_file_name = "1g_int_sorted_file.dat";
const std::string file_extension = ".dat";
const std::filesystem::path segment_directory = "segments";

void verify_sorted(int nums[], int size) {
    std::cout << "Verifying ..." << std::endl;

    for (int i = 1; i < size; ++i) {
        if (nums[i - 1] > nums[i]) {
            std::cout << "Verify failed: " << nums[i - 1] << ' ' << nums[i]
                      << std::endl;
            return;
        }
    }
    std::cout << "Segment verify success." << std::endl;
}

void verify_file_sorted() {
    std::cout << "Verifying final file ..." << std::endl;
    std::ifstream file(target_file_name,
                       std::ios_base::binary | std::ios_base::in);
    if (!file.is_open()) {
        std::cerr << "File open failed: " << file_name << std::endl;
        return;
    }

    // Read 64MB every time.
    int buffer_size = 64 * 1024 * 1024;
    int* num_buffer = new int[buffer_size / sizeof(int)];
    int position = 0;
    while (file.good()) {
        file.read(reinterpret_cast<char*>(num_buffer), buffer_size);

        // Get the real size.
        int read_size = file.gcount();
        int read_num_size = read_size / sizeof(int);

        // Debug: Print the sorted nums.
        verify_sorted(num_buffer, read_num_size);

        // Update the file read position.
        position += read_size;
    }

    delete[] num_buffer;
    file.close();
    std::cout << "File verify success." << std::endl;
}

// The range is [begin, end].
std::pair<int, int> range_partition(int* nums, int begin, int end) {
    int first_equal = begin;
    int greater = end;
    int current = begin + 1;

    // The first_equal range is [first_equal, current - 1].
    // Of course the first_equal is the target.
    while (current <= greater) {
        while (current <= greater && nums[current] < nums[first_equal]) {
            std::swap(nums[first_equal], nums[current]);
            ++first_equal;
            ++current;
        }
        while (current <= greater && nums[current] > nums[first_equal]) {
            std::swap(nums[greater], nums[current]);
            --greater;
        }
        while (current <= greater && nums[current] == nums[first_equal]) {
            ++current;
        }
    }

    return {first_equal, current - 1};
}

void range_quick_sort(int* nums, int begin, int end) {
    // std::cout << "Quick sorting..." << std::endl;
    // std::cout << begin << ' ' << end << std::endl;

    while (begin < end) {
        auto equal_range = range_partition(nums, begin, end);
        // Reduce the number of recursion by only recursive the short partition.
        if (equal_range.first - begin < end - equal_range.second) {
            range_quick_sort(nums, begin, equal_range.first - 1);
            begin = equal_range.second + 1;
        } else {
            range_quick_sort(nums, equal_range.second + 1, end);
            end = equal_range.first - 1;
        }
    }
}

void write_segment_to_file(int nums[], int size, int file_num) {
    if (size == 0) {
        std::cout << "Write size is zero!" << std::endl;
    }

    // Create a directory for the segments.
    if (!std::filesystem::exists(segment_directory) &&
        !std::filesystem::create_directory(segment_directory)) {
        std::cerr << "The directory for semgents create failed." << std::endl;
        return;
    }
    if (!std::filesystem::is_directory(segment_directory)) {
        std::cerr << "The path " << segment_directory << " is not a directory."
                  << std::endl;
        return;
    }

    // Write to the target file.
    std::filesystem::path file_name =
        segment_directory /
        ("segment_" + std::to_string(file_num) + file_extension);
    std::ofstream file(file_name, std::ios_base::binary | std::ios_base::out);
    if (!file.is_open()) {
        std::cerr << "File open failed: " << file_name << std::endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(nums), size * sizeof(int));
    file.close();
    std::cout << "File " << file_name << " saved." << std::endl;
}

void read_and_sort() {
    std::ifstream file(file_name, std::ios_base::binary | std::ios_base::in);
    if (!file.is_open()) {
        std::cerr << "File open failed: " << file_name << std::endl;
        return;
    }

    // Read 32MB every time.
    int buffer_size = 32 * 1024 * 1024;
    int* num_buffer = new int[buffer_size / sizeof(int)];
    int position = 0;
    std::cout << "Read buffer..." << std::endl;

    while (file.good()) {
        file.read(reinterpret_cast<char*>(num_buffer), buffer_size);

        // Get the real size.
        int read_size = file.gcount();
        int read_num_size = read_size / sizeof(int);

        if (read_size <= 0) {
            break;
        }

        std::cout << "Quick sort range " << position << " to "
                  << position + read_size << std::endl;
        // Sort the buffer.
        range_quick_sort(num_buffer, 0, read_num_size - 1);

        // Debug: Print the sorted nums.
        verify_sorted(num_buffer, read_num_size);

        // Write to a temporal data file.
        write_segment_to_file(num_buffer, read_num_size, position);

        // Update the file read position.
        position += read_size;
    }

    delete[] num_buffer;
    file.close();
    std::cout << "Complete." << std::endl;
}

void k_way_file_merge_sort() {
    if (!std::filesystem::exists(segment_directory) ||
        !std::filesystem::is_directory(segment_directory)) {
        return;
    }

    // Construct the min-heap;
    std::vector<std::ifstream> file_read_streams;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        min_heap;
    for (const auto& entry :
         std::filesystem::directory_iterator(segment_directory)) {
        if (entry.is_regular_file() &&
            entry.path().extension() == file_extension) {
            auto entry_path = entry.path();
            std::ifstream file_read_stream(
                entry_path, std::ios_base::in | std::ios_base::binary);
            if (!file_read_stream.is_open()) {
                std::cout << entry_path << " open failed." << std::endl;
                continue;
            }
            file_read_streams.push_back(std::move(file_read_stream));
        }
    }

    // TODO: Use buffers to speed up.
    int read_stream_size = file_read_streams.size();
    for (int i = 0; i < read_stream_size; ++i) {
        int num = 0;
        file_read_streams[i].read(reinterpret_cast<char*>(&num), sizeof(num));
        if (file_read_streams[i].good()) {
            min_heap.push({num, i});
        } else {
            std::cout << "File " << i << " read failed!" << std::endl;
        }
    }

    // Merge sort and write to the target file.
    std::ofstream file_write_stream(target_file_name, std::ios_base::out);
    if (!file_write_stream.is_open()) {
        std::cout << target_file_name << " open failed." << std::endl;
    }

    // TODO: Use buffers to speed up.
    while (!min_heap.empty()) {
        auto value_pair = min_heap.top();
        min_heap.pop();

        // Write the sorted num to the target(final) file.
        file_write_stream.write(reinterpret_cast<char*>(&value_pair.first),
                                sizeof(value_pair.first));

        int next_num = 0;
        int file_index = value_pair.second;
        file_read_streams[file_index].read(reinterpret_cast<char*>(&next_num),
                                           sizeof(next_num));
        if (file_read_streams[file_index].good()) {
            min_heap.push({next_num, file_index});
        }
    }

    // Close streams.
    file_write_stream.close();
    for (auto& read_stream : file_read_streams) {
        read_stream.close();
    }
}

int main() {
    read_and_sort();
    k_way_file_merge_sort();
    verify_file_sorted();
    return 0;
}
