#ifndef UNORDERED_SET_MEMORY_H
#define UNORDERED_SET_MEMORY_H

#include "memory_test_container.h"

#include <cstddef>
#include <cstdint>
#include <unordered_set>
#include <utility>
#include <vector>

template <typename Tp>
class UnorderedSetMemory : public MemoryTestContainer {
private:
    std::vector<std::unordered_set<Tp>> m_internalSetArray;

public:
    UnorderedSetMemory(uint32_t containerNum = 1)
        : MemoryTestContainer(containerNum)
        , m_internalSetArray()
    {
        ProcessStat originStat;
        currentProcessStat(&originStat);
        m_originalVirtualMemoryUsage = originStat.vsize;
        m_originalPhysicalMemoryUsage = originStat.rss;

        // Initialize empty internal maps.
        for (uint32_t ci = 0; ci < m_containerNum; ++ci) {
            std::unordered_set<Tp> internalSet;
            m_internalSetArray.push_back(std::move(internalSet));
        }
    }

    virtual ~UnorderedSetMemory(void) override
    {
        MemoryTestContainer::~MemoryTestContainer();
        m_internalSetArray.clear();
        m_internalSetArray.resize(0);
        m_internalSetArray.shrink_to_fit();
    }

    void insertElement(Tp element)
    {
        for (auto& internalSet : m_internalSetArray) {
            internalSet.insert(element);
        }
    }
};

#endif

