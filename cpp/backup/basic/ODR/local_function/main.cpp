#include "local_function.h"

#include <iostream>
using namespace std;

namespace Global {
    extern int calculateAdd(int lh, int rh);
    extern int calculateSub(int lh, int rh);
};  // namespace Global

// Error, this is definition not declaration.
// extern int Global::calculateAdd(int lh, int rh);
// extern int Global::calculateSub(int lh, int rh);

int main(void)
{
    cout << Global::calculateAdd(10, 5) << endl;
    cout << Global::calculateSub(10, 5) << endl;

    return 0;
}
