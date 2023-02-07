#include <iostream>
#include <vector>
#include <string>

#include "sort.hpp"
using namespace std;

void verify(string test_name, void sort(vector<int>&)){
	vector<int> nums = {4, 5, 8, 9, 3, 6, 1, 2, 7, 0};
	sort(nums);
	cout << test_name << ": \t";
	for(int num : nums){
		cout << num << " ";
	}
	cout << endl;
}

void verify(string test_name, void sort(vector<int>&, int, int)){
	vector<int> nums = {4, 5, 8, 9, 3, 6, 1, 2, 7, 0};
	sort(nums, 0, nums.size() - 1);
	cout << test_name << ": \t";
	for(int num : nums){
		cout << num << " ";
	}
	cout << endl;
}
int main(){
	verify("Insert Sort", insert_sort);
	verify("Shell Sort", shell_sort);
	verify("Quick Sort", quick_sort);

	return 0;
}
