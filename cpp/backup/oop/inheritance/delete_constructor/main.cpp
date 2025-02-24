#include "add.h"
#include <iostream>

using namespace std;

int main() {
    Calculate* pCal = new Add;
    cout << pCal->cal(3, 5) << endl;
}