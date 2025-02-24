#include "export_class.h"
#include <iostream>

int UtilClass::add(int l, int r) {
    std::cout << "add" << std::endl;
    return l + r;
}