#include "set_memory.h"
#include "unordered_set_memory.h"
#include "unordered_map_memory.h"
#include "vector_memory.h"

#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::make_pair;

void unorderedMapTest(void) {
    cout << "Unordered Map Memory:" << endl;
    UnorderedMapMemory<uint64_t, uint32_t> unorderedMapMemory(20000);
    for (uint32_t ei = 0; ei < 500; ei++) {
        unorderedMapMemory.insertElement(make_pair(ei, ei));
    }
    cout << unorderedMapMemory.getVirtualMemoryUsage() << endl;
    cout << unorderedMapMemory.getPhysicalMemoryUsage() << endl;
}

void vectorTest(void) {
    cout << "Vector Memory:" << endl;
    VectorMemory<uint64_t> vectorMemory(20000);
    for (uint32_t ei = 0; ei < 500; ei++) {
        vectorMemory.pushElement(ei);
    }
    cout << vectorMemory.getVirtualMemoryUsage() << endl;
    cout << vectorMemory.getPhysicalMemoryUsage() << endl;
}

void setTest(void) {
    cout << "Set Memory:" << endl;
    SetMemory<uint64_t>* setMemory = new SetMemory<uint64_t>(1);
    for (uint32_t ei = 0; ei < 1000000; ei++) {
        setMemory->insertElement(ei);
    }
    cout << setMemory->getVirtualMemoryUsage() << endl;
    cout << setMemory->getPhysicalMemoryUsage() << endl;

	delete setMemory;
}

void unorderedSetTest(void) {
    cout << "Unordered Set Memory:" << endl;
    UnorderedSetMemory<uint64_t>* unorderedSetMemory = new UnorderedSetMemory<uint64_t>(1);
    for (uint32_t ei = 0; ei < 1000000; ei++) {
        unorderedSetMemory->insertElement(ei);
    }
    cout << unorderedSetMemory->getVirtualMemoryUsage() << endl;
    cout << unorderedSetMemory->getPhysicalMemoryUsage() << endl;

	delete unorderedSetMemory;
}

int main(void)
{
	unorderedSetTest();
	setTest();
    return 0;
}
