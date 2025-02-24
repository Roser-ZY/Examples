#include <cstdint>
#include <functional>
#include <unordered_set>

#pragma pack(push, 8)

template <typename T>
class CollisionProbility {
private:
	std::hash<T> hasher;
	std::unordered_set<uint64_t> table;
	uint64_t hashValue;

public:
	void add(T value);
	uint32_t collisionCount(void);
	double collisionProbility(void);
};

#pragma pack(pop)
