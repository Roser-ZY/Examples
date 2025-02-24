#include "add.h"
#include <iostream>

void display(int a) {
    std::cout << "display: " << a << std::endl;
}

int UtilClass::add(int l, int r) {
    std::cout << "add" << std::endl;
    return l + r;
}