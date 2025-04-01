#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using std::pair;
using std::priority_queue;

void partial()
{
}

// The range is [begin, end).
void quick_sort(const int* nums, int begin, int end)
{
    if (begin >= end) {
        return;
    }
    int less = begin + 1;
    int greater = end - 1;
    int target = begin;
    while (less < greater) {
        while (less < greater && nums[less] <= nums[target]) {
            less++;
        }
        while (less < greater && nums[greater] > nums[target]) {
            greater--;
        }

        if (less < greater) {
            std::swap(nums[less], nums[greater]);
        }
    }
    std::swap(nums[less - 1], nums[target]);
    target = less - 1;

    quick_sort(nums, begin, target);
    quick_sort(nums, target + 1, end);
}

void write_segment_to_file(const int* nums, int size, int file_num)
{
}

void print_nums(const int* nums, int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << '\n' << std::endl;
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
        file.read(reinterpret_cast<char*>(num_buffer), buffer_size);

        // Update the file read position.
        int read_size = file.gcount() - position;
        int read_num_size = read_size / sizeof(int);
        position = file.gcount();

        // Sort the buffer.
        quick_sort(num_buffer, 0, read_num_size);

        // Debug: Print the sorted nums.
        print_nums(num_buffer, read_num_size);
        
        // Write to a temporal data file.
        write_segment_to_file(num_buffer, read_num_size, position);
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
    return 0;
}
