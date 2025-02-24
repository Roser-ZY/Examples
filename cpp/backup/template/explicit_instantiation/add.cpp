#include "add.h"

template <class A>
A myAdd(A l, A r) {
    return l + r;
}

template int myAdd<int>(int, int);