#include <iostream>
#include "add.h"
using namespace std;

extern int addInt(int, int);

int main() {
    cout << addInt(1, 2) << endl;
    cout << myAdd(2, 3) << endl;
    return 0;
}