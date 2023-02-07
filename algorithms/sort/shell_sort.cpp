#include <iostream>
#include <vector>
using namespace std;

/**
 * 希尔排序是基于插入排序的一种优化算法，巧妙利用插入排序的优势进行优化。
 * 希尔排序的主要思路是先将小体量的子序列排序，然后不断增大子序列体量(即缩小间隔)，并在此基础。上实现局部有序。
 *
 * 时间复杂度与递增序列相关，递增序列为 N/3 时约为 N 的 3/2 次方。
 * 虽然希尔排序的时间复杂度并非最优，但是一种不需要额外空间且性能较优的排序算法
 * **/
void shell_sort(vector<int>& nums){
	int len = nums.size();
	int h = 1;
	// 构造序列
	while(h < len / 3) h = h * 3 + 1; 					// 1, 4, 13, 40, 121, 364, 1093, ...
	// 希尔排序
	while(h >= 1){
		for(int i = h; i < len; ++i){
			// 按照 h 间隔进行插入排序
			for(int j = i; j >= h && nums[j] < nums[j - h]; j -= h){
				swap(nums[j], nums[j - h]);
			}
		}
		h /= 3;
	}
}
