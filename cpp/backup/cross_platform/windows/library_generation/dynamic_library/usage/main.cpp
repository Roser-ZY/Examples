#include "export_struct.h"

#include <iostream>
using namespace std;

int main(void)
{
    Add addStruct(5, 5);
    cout << addStruct() << endl;

    addStruct.lh = 10;
    addStruct.rh = 10;
    cout << addStruct() << endl;
	return 0;
}
