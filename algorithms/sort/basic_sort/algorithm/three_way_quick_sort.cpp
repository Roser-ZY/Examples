#include <vector>

// The range is [begin, end].
std::pair<int, int> three_way_partition(int* nums, int begin, int end)
{
    int target = begin;
    int greater = end;
    int equal = begin + 1;

    // The equal range is [less, equal - 1].
    while (equal <= greater) {
        while (equal <= greater && nums[equal] < nums[target]) {
            std::swap(nums[target], nums[equal]);
            ++target;
            ++equal;
        }
        while (equal <= greater && nums[equal] > nums[target]) {
            std::swap(nums[greater], nums[equal]);
            --greater;
        }
        while (nums[equal] == nums[target]) {
            ++equal;
        }
    }

    return {target, equal - 1};
}

void three_way_quick_sort(int* nums, int begin, int end)
{
    //    std::cout << "Quick sorting..." << std::endl;
    //    std::cout << begin << ' ' << end << std::endl;

    while (begin < end) {
        auto equal_range = three_way_partition(nums, begin, end);
        if (equal_range.first - begin < end - equal_range.second) {
            three_way_quick_sort(nums, begin, equal_range.first - 1);
            begin = equal_range.second + 1;
        }
        else {
            three_way_quick_sort(nums, equal_range.second + 1, end);
            end = equal_range.first - 1;
        }
    }
}
