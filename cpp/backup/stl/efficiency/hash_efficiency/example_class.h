#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H
#include <cstdint>
#include <vector>

using std::vector;

#pragma pack(push, 8)

class ExampleClass {
public:
    ExampleClass(void)
		: mEdgeComponentFaceLabels(500)
		, mVertexTangentFaceLabels(500)
    {
    }

    const vector<uint64_t>& edgeComponentFaceLbls(void) const
    {
        return mEdgeComponentFaceLabels;
    }

    const vector<uint64_t>& vertexTangentFaceLbls(void) const
    {
        return mVertexTangentFaceLabels;
    }

    uint32_t loopCode(void) const
    {
        return mLoopCode;
    }

    uint32_t edgeCode(void) const
    {
        return mEdgeCode;
    }

private:
    vector<uint64_t> mEdgeComponentFaceLabels;
    vector<uint64_t> mVertexTangentFaceLabels;
    int32_t mLoopCode;
    int32_t mEdgeCode;
};

#pragma pack(pop)

#endif

