#include <iostream>

using namespace std;

int main() {
    // 指针能否赋值取决于指向的类型
    int value1 = 10;
    const int constValue = value1;
    int value2 = constValue;

    int* intPointer1 = &value1;
    const int* constIntPointer1 = &value1;

    int* intPointer2 = constIntPointer1;                    // 错误：不能将 const int 赋值给 int
    int* intPointer3 = intPointer1;

    const int* constIntPointer2 = intPointer1;
    const int* constIntPointer3 = constIntPointer1;

    const int* const constIntConstPointer1 = intPointer1;

    int* const intConstPointer1 = constIntConstPointer1;    // 错误：不能将 const int 赋值给 int
    const int* constIntPointer4 = constIntConstPointer1;
}