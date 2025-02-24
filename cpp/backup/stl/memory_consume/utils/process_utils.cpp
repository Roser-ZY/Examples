#include "process_utils.h"

#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using std::ifstream;
using std::string;
using std::vector;

int32_t currentProcessStat(ProcessStat* stat)
{
    if (stat == nullptr) {
        return -1;
    }

    ifstream ifs("/proc/self/stat", std::ios_base::in);
    if (!ifs.is_open()) {
        return -1;
    }
    vector<string> fields;
    string field;
    while (ifs >> field) {
        field += '\0';
        fields.push_back(field);
    }
    // The number of fileds in /proc/self/stat is 52.
    if (fields.size() < 52) {
        return -1;
    }

    // Fill fields.
    stat->pid = std::stoi(fields[0]);
    stat->ppid = std::stoi(fields[3]);
    stat->sid = std::stoi(fields[5]);
    stat->tcomm = fields[1];
    stat->state = fields[2].size() > 0 ? fields[2][0] : '\0';
    stat->numThreads = std::stoi(fields[19]);
    stat->vsize = std::stoll(fields[22]);
    stat->rss = std::stoll(fields[23]);

    return 0;
}
