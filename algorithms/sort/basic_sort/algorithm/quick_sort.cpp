#include <iostream>
#include <vector>
using namespace std;

int part_sort(vector<int>& nums, int l, int r){
	int target = nums[l];
	int m = l;
	while(l < r){
		while(l < r && nums[r] >= target) --r;
		nums[m] = nums[r];
		m = r;

		while(l < r && nums[l] <= target) ++l;
		nums[m] = nums[l];
		m = l;
	}
	nums[m] = target;
	return m;
}

void quick_sort(vector<int>& nums, int l, int r){
	if(l >= r) return;

	int m = part_sort(nums, l, r);
	quick_sort(nums, m + 1, r);
	quick_sort(nums, l, m - 1);
}

