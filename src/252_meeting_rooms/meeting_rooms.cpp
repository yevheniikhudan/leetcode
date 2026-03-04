#include <iostream>
#include <vector>

class Solution {
   public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
        bool res = true;
        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }

        return res;
    }
};

void runTests() {
    Solution sol;
    std::vector<std::vector<std::vector<int>>> inputs = {
        {{0, 30}, {5, 10}, {15, 20}}, {{7, 10}, {2, 4}}, {{1, 2}, {2, 3}, {3, 4}},
        {{1, 5}, {2, 3}, {5, 6}},     {{1, 2}},          {{5, 8}, {9, 15}, {15, 20}, {21, 22}},
    };
    std::vector<bool> expecteds = {false, true, true, false, true, true};

    std::cout << std::boolalpha;
    for (size_t i = 0; i < inputs.size(); ++i) {
        auto intervals = inputs[i];
        bool actual = sol.canAttendMeetings(intervals);
        std::cout << actual << " | " << expecteds[i] << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}
