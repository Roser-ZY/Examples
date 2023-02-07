#include <iostream>
#include <vector>

int binary_search(std::vector<int> nums, int target){
	int l = 0, r = nums.size() - 1;
	while(l <= r){
		int i = l + ((r - l) >> 2);
		if(nums[i] == target){
				return i;
		}
		else if(nums[i] < target){
				l = i + 1;
		}
		else{
			r = i - 1;
		}
	}

	return -1;
}

int main(){
	std::vector<int> nums = {1,2,3,4,5,6,89};
	std::cout << binary_search(nums, 6) << std::endl;

	return 0;
}
