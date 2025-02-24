#include "time_recorder.h"

#include <chrono>

TimeRecorder::TimeRecorder(void)
    : m_beginTime()
    , m_endTime()
    , m_timeUsage(0)
{
}

TimeRecorder::~TimeRecorder(void)
{
}

void TimeRecorder::begin(void)
{
    m_beginTime = std::chrono::steady_clock::now();
}

void TimeRecorder::end(void)
{
    m_endTime = std::chrono::steady_clock::now();
    m_timeUsage = static_cast<std::chrono::nanoseconds>(m_endTime - m_beginTime);
}

NanoDuration TimeRecorder::timeUsage(void) const
{
    return m_timeUsage;
}

