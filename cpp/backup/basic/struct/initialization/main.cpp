#include <iostream>
using namespace std;

struct ExampleStruct {
    int a;
    double b;
};

void displayStruct(const ExampleStruct& example)
{
	cout << example.a << ' ' << example.b << endl;
}

int main(void)
{
    ExampleStruct struct1 = {0, 1.0};
    ExampleStruct struct2{5, 2.0};

	displayStruct(struct1);
	displayStruct(struct2);
	displayStruct(ExampleStruct{5, 10.0});

	return 0;
}
