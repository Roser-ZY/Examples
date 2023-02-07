#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> resize_nums;
	vector<int> reserve_nums;

	// resize 与 reserve 区别
	resize_nums.resize(10);
	reserve_nums.reserve(10);
	printf("resize 与 reserve 扩容：\n");
	printf("[resize] size: %ld, capacity: %ld\n", resize_nums.size(), resize_nums.capacity());
	printf("[reserve] size: %ld, capacity: %ld\n\n", reserve_nums.size(), reserve_nums.capacity());

	// resize 与 reserve 减容
	resize_nums.resize(5);
	reserve_nums.reserve(5);
	printf("resize 与 reserve 减容：\n");
	printf("[resize] size: %ld, capacity: %ld\n", resize_nums.size(), resize_nums.capacity());
	printf("[reserve] size: %ld, capacity: %ld\n\n", reserve_nums.size(), reserve_nums.capacity());

	// shrink_to_fit 作用
	resize_nums.shrink_to_fit();
	reserve_nums.shrink_to_fit();
	printf("非空 vector 与空 vector 调用 shrink_to_fit 的区别：\n");
	printf("[nonempty] size: %ld, capacity: %ld\n", resize_nums.size(), resize_nums.capacity());
	printf("[empty] size: %ld, capacity: %ld\n\n", reserve_nums.size(), reserve_nums.capacity());

	// 内存回收
	// 初始化
	resize_nums.resize(10);
	reserve_nums.reserve(10);
	resize_nums.clear();
	reserve_nums.clear();
	resize_nums.shrink_to_fit();
	reserve_nums.clear();
	printf("vector内存回收：\n");
	printf("[recycled] size: %ld, capacity: %ld\n", resize_nums.size(), resize_nums.capacity());
	printf("[nothing] size: %ld, capacity: %ld\n\n", reserve_nums.size(), reserve_nums.capacity());
	
	return 0;
}
