#include <fstream>
#include <iostream>
#include <string>

#include "read_file_in_segments.h"

void read()
{
    std::string file_name = "1g_int_example_file.dat";
    std::ifstream file(file_name, std::ios_base::binary | std::ios_base::in);
    if (!file.is_open()) {
        std::cerr << "File open failed: " << file_name << std::endl;
        return 0;
    }

    // Read 256MB every time.
    int buffer_size = 256 * 1024 * 1024;
    int* buffer = new int[buffer_size / sizeof(int)];
    int pos;
    while (file.good()) {

        file.read(reinterpret_cast<char*>(buffer), buffer_size);
        int int_num = file.gcount() / sizeof(int);
    }

    delete[] buffer;
    file.close();
    std::cout << "Complete." << std::endl;
}
