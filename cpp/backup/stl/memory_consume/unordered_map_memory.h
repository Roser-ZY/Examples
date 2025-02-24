#ifndef UNORDERED_MAP_MEMORY_H
#define UNORDERED_MAP_MEMORY_H

#include "memory_test_container.h"

#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename Key, typename Tp>
class UnorderedMapMemory : public MemoryTestContainer {
private:
    std::vector<std::unordered_map<Key, Tp>> m_internalMapArray;

public:
    UnorderedMapMemory(uint32_t containerNum = 1)
        : MemoryTestContainer(containerNum)
        , m_internalMapArray()
    {
        ProcessStat originStat;
        currentProcessStat(&originStat);
        m_originalVirtualMemoryUsage = originStat.vsize;
        m_originalPhysicalMemoryUsage = originStat.rss;

        // Initialize empty internal maps.
        for (uint32_t ci = 0; ci < m_containerNum; ++ci) {
            std::unordered_map<Key, Tp> internalMap;
            m_internalMapArray.push_back(std::move(internalMap));
        }
    }

    virtual ~UnorderedMapMemory(void) override
    {
        MemoryTestContainer::~MemoryTestContainer();
        m_internalMapArray.clear();
        m_internalMapArray.resize(0);
        m_internalMapArray.shrink_to_fit();
    }

    void insertElement(std::pair<Key, Tp> element)
    {
        for (auto& internalMap : m_internalMapArray) {
            internalMap.insert(element);
        }
    }
};

#endif

