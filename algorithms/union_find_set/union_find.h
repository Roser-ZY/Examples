#include <vector>

class UnionFind{
private:
	int count; 								// 计算连通分量，可设置为总数再递减，或按实际情况确定增减方式
	std::vector<int> pt; 					// 父链接数组
	std::vector<int> rk; 					// 权重数组
public:
	int find(int a);
	void connect(int x, int y);
}
