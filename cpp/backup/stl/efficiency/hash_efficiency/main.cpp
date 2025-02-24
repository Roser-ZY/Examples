#include "example_class.h"
#include "../utils/time_recorder.h"

#include <cstddef>
#include <functional>
#include <iostream>

using std::size_t;
using std::cout;
using std::endl;

size_t exampleHash(const ExampleClass& obj)
{
    const auto& edgeComponentFacelabels = obj.edgeComponentFaceLbls();
    const auto& vertexTangentFacelabels = obj.vertexTangentFaceLbls();
	size_t hashCode = 0xffffffff;
    for (const auto& label : edgeComponentFacelabels) {
        hashCode ^= std::hash<uint64_t>{}(label);
    }
    for (const auto& label : vertexTangentFacelabels) {
        hashCode ^= std::hash<uint64_t>{}(label);
    }
	hashCode ^= std::hash<uint32_t>{}(obj.loopCode());
	hashCode ^= std::hash<uint32_t>{}(obj.edgeCode());
	return hashCode;
}


int main(void)
{
	ExampleClass exampleClass;
	TimeRecorder::instance().begin();
	exampleHash(exampleClass);
	TimeRecorder::instance().end();
	cout << "Time usage for hashing ExampleClass: " << TimeRecorder::instance().timeUsage().count() << endl;

    return 0;
}
