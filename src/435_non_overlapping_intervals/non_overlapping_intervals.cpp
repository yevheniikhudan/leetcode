#include <algorithm>
#include <iostream>
#include <std>
#include <vector>

class Solution {
   public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& x, const vector<int>& y) { return x[1] < y[1]; });
        int last = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last) {
                res++;
            } else {
                last = intervals[i][1];
            }
        }

        return res;
    }
};

// Helper test scaffolding
void runTests() {
    Solution sol;
    std::vector<std::vector<std::vector<int>>> inputs = {{{1, 2}, {2, 3}, {3, 4}, {1, 3}},
                                                         {{1, 2}, {1, 2}, {1, 2}},
                                                         {{1, 2}, {2, 3}},
                                                         {{1, 100}, {11, 22}, {1, 11}, {2, 12}},
                                                         {{1, 2}}};
    std::vector<int> expecteds = {1, 2, 0, 2, 0};

    for (size_t i = 0; i < inputs.size(); ++i) {
        int actual = sol.eraseOverlapIntervals(inputs[i]);
        std::cout << actual << " | " << expecteds[i] << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}
