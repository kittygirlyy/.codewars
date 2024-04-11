// https://www.codewars.com/kata/52b7ed099cdc285c300001cd
#include <vector>
#include <utility>

int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    if (intervals.empty()) return 0;

    std::sort(intervals.begin(), intervals.end());

    int length{ 0 };
    int start{ intervals[0].first };
    int end{ intervals[0].second };

    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first <= end) {
            end = std::max(end, intervals[i].second);
        } else {
            length += end - start;
            start = intervals[i].first;
            end = intervals[i].second;
        }
    }

    length += end - start;

    return length;
}