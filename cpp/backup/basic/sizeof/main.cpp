#include <iostream>

int main() {
    int arr[10];
    int* ptr = arr;

    std::size_t arr_size = sizeof(arr);  // 返回的是整个数组的大小
    std::size_t ptr_size = sizeof(ptr);  // 返回的是指针的大小

    std::cout << "Array size in bytes: " << arr_size << std::endl;
    std::cout << "Pointer size in bytes: " << ptr_size << std::endl;

    return 0;
}
