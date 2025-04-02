#include <fstream>
#include <iostream>
#include <queue>
#include <string>

// The range is [begin, end].
std::pair<int, int> partition(int* nums, int begin, int end)
{
    int target = begin;
    int greater = end;
    int equal = begin + 1;

    // The equal range is [less, equal - 1].
    while (equal <= greater) {
        while (equal <= greater && nums[equal] < nums[target]) {
            std::swap(nums[target], nums[equal]);
            ++target;
            ++equal;
        }
        while (equal <= greater && nums[equal] > nums[target]) {
            std::swap(nums[greater], nums[equal]);
            --greater;
        }
        while (nums[equal] == nums[target]) {
            ++equal;
        }
    }

    return {target, equal - 1};
}

void quick_sort(int* nums, int begin, int end)
{
    //    std::cout << "Quick sorting..." << std::endl;
    //    std::cout << begin << ' ' << end << std::endl;

    while (begin < end) {
        auto equal_range = partition(nums, begin, end);
        if (equal_range.first - begin < end - equal_range.second) {
            quick_sort(nums, begin, equal_range.first - 1);
            begin = equal_range.second + 1;
        }
        else {
            quick_sort(nums, equal_range.second + 1, end);
            end = equal_range.first - 1;
        }
    }
}

void write_segment_to_file(const int* nums, int size, int file_num)
{
}

void verify_sorted(const int* nums, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            std::cout << "Verify failed: " << nums[i] << ' ' << nums[i + 1] << std::endl;
            return;
        }
    }
    std::cout << "Verify success." << std::endl;
}

void read_and_sort()
{
    std::string file_name = "1g_int_example_file.dat";
    std::ifstream file(file_name, std::ios_base::binary | std::ios_base::in);
    if (!file.is_open()) {
        std::cerr << "File open failed: " << file_name << std::endl;
        return;
    }

    // Read 256MB every time.
    int buffer_size = 256 * 1024 * 1024;
    int* num_buffer = new int[buffer_size / sizeof(int)];
    int position = 0;
    while (file.good()) {
        std::cout << "Read buffer..." << std::endl;
        file.read(reinterpret_cast<char*>(num_buffer), buffer_size);

        // Update the file read position.
        int read_size = file.gcount() - position;
        int read_num_size = read_size / sizeof(int);
        position = file.gcount();

        // Sort the buffer.
        quick_sort(num_buffer, 0, read_num_size - 1);

        // Debug: Print the sorted nums.
        verify_sorted(num_buffer, 15);

        // Write to a temporal data file.
        write_segment_to_file(num_buffer, read_num_size, position);

        break;
    }

    delete[] num_buffer;
    file.close();
    std::cout << "Complete." << std::endl;
}

void multi_file_merge_sort()
{
}

int main()
{
    read_and_sort();
    return 0;
}
