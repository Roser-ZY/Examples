#include <iostream>
#include <vector>
using namespace std;

// 插入排序在局部有序或数量较少时排序效果更优
void insert_sort(vector<int>& nums){
	int i, j;
	for(i = 1; i < nums.size(); ++i){
		int key = nums[i];
		for(j = i - 1; j >= 0 && nums[j] > key; --j){
			nums[j + 1] = nums[j];
		}
		nums[j + 1] = key;
	}
}

