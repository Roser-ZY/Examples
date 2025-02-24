#ifdef __linux__
#ifndef PROCESS_UTIL_H
#define PROCESS_UTIL_H
#include <cstddef>
#include <cstdint>
#include <string>

struct ProcessStat {
    uint16_t pid;         // Process id;
    uint16_t ppid;        // Process id of the parent process;
    uint16_t sid;         // Session id;
    std::string tcomm;    // Fiel name of the executable;
    char state;           // Status of the process;
    uint16_t numThreads;  // Number of threads;

    size_t vsize;  // Virtual memory size (Bytes);
    size_t rss;    // Resident set memory size (Bytes);
};

int32_t currentProcessStat(ProcessStat* stat);

#endif
#endif
