#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> res;

        for (auto& interval : intervals) {
            if (res.size() == 0 || interval[0] > res.back()[1]) {
                res.push_back(interval);
            } else {
                auto& prev = res.back();
                prev[1] = std::max(prev[1], interval[1]);
            }
        }

        return res;
    }
};

// Helper test scaffolding
void printVector(const std::vector<std::vector<int>>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "[" << v[i][0] << "," << v[i][1] << "]";
        if (i < v.size() - 1) std::cout << ",";
    }
    std::cout << "]";
}

void runTests() {
    Solution sol;
    std::vector<std::vector<std::vector<int>>> inputs = {{{1, 3}, {2, 6}, {8, 10}, {15, 18}},
                                                         {{1, 4}, {4, 5}},
                                                         {{4, 7}, {1, 4}},
                                                         {{1, 3}},
                                                         {{1, 2}, {3, 4}, {5, 6}},
                                                         {{1, 10}, {2, 3}, {4, 5}, {6, 7}}};
    std::vector<std::vector<std::vector<int>>> expecteds = {
        {{1, 6}, {8, 10}, {15, 18}}, {{1, 5}}, {{1, 7}}, {{1, 3}},
        {{1, 2}, {3, 4}, {5, 6}},    {{1, 10}}};

    for (size_t i = 0; i < inputs.size(); ++i) {
        std::vector<std::vector<int>> actual = sol.merge(inputs[i]);
        printVector(actual);
        std::cout << " | ";
        printVector(expecteds[i]);
        std::cout << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}
