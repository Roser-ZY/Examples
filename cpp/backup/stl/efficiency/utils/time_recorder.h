#ifndef TIME_RECORDER_H
#define TIME_RECORDER_H

#include <thread>
#include <chrono>

using TimePoint = std::chrono::steady_clock::time_point;
using NanoDuration = std::chrono::nanoseconds;

#pragma pack(push, 8)

class TimeRecorder final {
public:
	TimeRecorder(void);
	~TimeRecorder(void);
	static TimeRecorder& instance(void) {
		static TimeRecorder recorder;
		return recorder;
	}

	void begin(void);
	void end(void);
	NanoDuration timeUsage(void) const;

private:
	TimeRecorder(const TimeRecorder& other) = delete;
	TimeRecorder(TimeRecorder&& other) = delete;

private:
	TimePoint m_beginTime;
	TimePoint m_endTime;
	NanoDuration m_timeUsage;
};

#pragma pack(pop)

#endif

