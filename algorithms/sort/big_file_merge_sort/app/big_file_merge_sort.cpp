#include <fstream>
#include <iostream>
#include <string>

#include <queue>

using std::priority_queue;
using std::pair;

void quick_sort(const int* nums, int size)
{
    // Todo: Implement.
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
    int size = buffer_size / sizeof(int);
    int* num_buffer = new int[size];
    int pos;
    while (file.good()) {
        file.read(reinterpret_cast<char*>(num_buffer), buffer_size);
        // Sort the buffer.
        quick_sort(num_buffer, size);

        // Todo: Write to a temporal data file.
    }

    delete[] num_buffer;
    file.close();
    std::cout << "Complete." << std::endl;
}

void multi_file_merge_sort()
{

}

int main() {
    return 0;
}
