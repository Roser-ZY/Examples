#include <iostream>

int func(const int& arg){
	std::cout << arg << std::endl;
	return arg;
}

int main(){
	int x = 20;
	func(x);
	func(10);

	return 0;
}
