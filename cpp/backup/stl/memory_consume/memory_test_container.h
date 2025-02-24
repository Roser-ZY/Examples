#ifndef MEMORY_TEST_CONTAINER_H
#define MEMORY_TEST_CONTAINER_H

#include "utils/process_utils.h"

#include <cstddef>
#include <cstdint>
#include <vector>

class MemoryTestContainer {
protected:
    size_t m_originalVirtualMemoryUsage;
    size_t m_originalPhysicalMemoryUsage;
    uint32_t m_containerNum;

public:
    MemoryTestContainer(uint32_t containerNum)
        : m_originalVirtualMemoryUsage(0)
        , m_originalPhysicalMemoryUsage(0)
        , m_containerNum(containerNum)
    {
    }

    virtual ~MemoryTestContainer(void) = 0;
	
    virtual size_t getVirtualMemoryUsage(void)
    {
        ProcessStat currentStat;
        currentProcessStat(&currentStat);
        return currentStat.vsize - m_originalVirtualMemoryUsage;
    }

    virtual size_t getPhysicalMemoryUsage(void)
    {
        ProcessStat currentStat;
        currentProcessStat(&currentStat);
        return currentStat.vsize - m_originalVirtualMemoryUsage;
    }
};

#endif

