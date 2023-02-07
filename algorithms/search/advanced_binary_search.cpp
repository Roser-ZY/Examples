#include <iostream>
#include <vector>
using namespace std;

// 根据题目实行判断条件
int condition(vector<int>& nums, int ind){
	return nums[ind] - 24;
}

int advanced_binary_search(vector<int>& nums){
	int left = 0, right = nums.size();
	while(left < right){
		int mid = left + ((right - left) >> 1);
		// 若条件满足，返回索引
		// 若模糊查找，则没有条件满足，仅根据单调性找到临界索引
		if(condition(nums, mid) == 0) return mid;
		// 若条件不满足，且可单调，则调整 left 与 right
		// 注意 left 与 right 的调整选择 mid 还是 mid ± 1 要根据题意判断
		else if(condition(nums, mid) > 0) right = mid - 1;
		else left = mid + 1;
	}

	// 若未找到则返回一个无效值
	return -1;
}

int main(){
	vector<int> nums = {0, 1, 2, 6, 10, 24, 30};
	cout << advanced_binary_search(nums) << endl;;

	return 0;
}
