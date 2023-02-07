#include <chrono>
#include <iostream>
#include <thread>
#include <string>
using namespace std;

class Example{
public:
	int key;
	int val;
	string desc;

	static int construct_count;
	static int copy_construct_count;
	static int deconstruct_count;

	Example(){
		++construct_count;
		cout << "Construct Example " << construct_count << endl;
	}
	~Example(){
		++deconstruct_count;
		cout << "Deconstruct Example " << deconstruct_count << endl;
	}
	Example(const Example& exp){
		this->key = exp.key; 
		this->val = exp.val; 
		this->desc = exp.desc;

		++copy_construct_count;
		cout << "Copy Construct Example " << copy_construct_count << endl;
	}

	int get_key(){
		return key;
	}
	int get_val(){
		return val;
	}
	string get_desc(){
		return desc;
	}


};

int Example::construct_count = 0;
int Example::copy_construct_count = 0;
int Example::deconstruct_count = 0;

void display_example(Example exp){
	cout << exp.key << " " << exp.val << " " << exp.desc << endl;
}

Example generate_example(){
	Example exp;
	exp.key = 1;
	exp.val = 100;
	exp.desc = "return";

	return exp;
}


int main(){
	cout << "未接收返回值：" << endl;
	generate_example();
	cout << endl;
	this_thread::sleep_for(chrono::seconds(3));

	cout << "接收返回值：" << endl;
	Example exp = generate_example();
	cout << endl;
	this_thread::sleep_for(chrono::seconds(3));

	cout << "右值引用接收返回值：" << endl;
	Example&& exp_ref = generate_example();
	cout << endl;
	this_thread::sleep_for(chrono::seconds(3));

	cout << "值传递：" << endl;
	display_example(exp);
	this_thread::sleep_for(chrono::seconds(3));

	return 0;
}
