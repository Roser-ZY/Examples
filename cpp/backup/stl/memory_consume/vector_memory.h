#ifndef VECTOR_MEMORY_H
#define VECTOR_MEMORY_H

#include "memory_test_container.h"

#include <cstddef>
#include <cstdint>
#include <vector>

template <typename Tp>
class VectorMemory : public MemoryTestContainer {
private:
    std::vector<std::vector<Tp>> m_internalVectorArray;

public:
    VectorMemory(uint32_t containerNum = 1)
		: MemoryTestContainer(containerNum)
        , m_internalVectorArray()
    {
        ProcessStat originStat;
        currentProcessStat(&originStat);
        m_originalVirtualMemoryUsage = originStat.vsize;
        m_originalPhysicalMemoryUsage = originStat.rss;

        // Initialize empty internal maps.
        for (uint32_t ci = 0; ci < m_containerNum; ++ci) {
			std::vector<Tp> internalVector;
            m_internalVectorArray.push_back(std::move(internalVector));
        }
    }

    virtual ~VectorMemory(void) override
    {
		MemoryTestContainer::~MemoryTestContainer();
        m_internalVectorArray.clear();
        m_internalVectorArray.resize(0);
        m_internalVectorArray.shrink_to_fit();
    }

    void pushElement(Tp element)
    {
        for (auto& internalVector : m_internalVectorArray) {
            internalVector.push_back(element);
        }
    }
};

#endif

