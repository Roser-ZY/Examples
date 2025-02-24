#include <iostream>
#include "inline.h"
using namespace std;

extern void displayA();
extern void displayB();

// inline void displayErr() {
//     cout << "Hello Error!" << endl;
// }

// inline void displayErr() {
//     cout << "Hello Error!" << endl;
// }

int main() {
    // displayErr();
    displayA();
    displayB();
    return 0;
}