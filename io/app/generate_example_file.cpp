#include <fstream>
#include <iostream>

int main()
{
    std::string file_name = "1g_int_example_file.dat";
    std::ofstream file(file_name, std::ios::binary | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "File open failed: " << file_name << std::endl;
        return 0;
    }
    std::cout << "Writing to the file..." << std::endl;

    // Write data to the file.
    // 1G file.
    // Use a buffer to speed up the writing process.
    constexpr int buffer_size = 1024 * 1024;
    int* buffer = new int[buffer_size];
    for (int i = 0; i < 1024 / sizeof(int); ++i) {
        for (int i = 0; i < buffer_size; ++i) {
            buffer[i] = rand();
        }
        file.write(reinterpret_cast<char*>(buffer), buffer_size * sizeof(int));
    }

    delete[] buffer;
    file.close();
    std::cout << "Complete." << std::endl;
    return 0;
}