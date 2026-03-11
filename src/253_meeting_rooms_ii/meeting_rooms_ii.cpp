#include <iostream>
#include <vector>

class Solution {
   public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) { return 0; }
};

void runTests() {
    Solution sol;
    std::vector<std::vector<std::vector<int>>> inputs = {
        {{0, 30}, {5, 10}, {15, 20}},      {{7, 10}, {2, 4}},
        {{1, 5}, {2, 3}, {3, 6}},          {{1, 2}, {2, 3}, {3, 4}},
        {{1, 10}, {2, 9}, {3, 8}, {4, 7}}, {{5, 8}},
    };
    std::vector<int> expecteds = {2, 1, 2, 1, 4, 1};

    for (size_t i = 0; i < inputs.size(); ++i) {
        auto intervals = inputs[i];
        int actual = sol.minMeetingRooms(intervals);
        std::cout << actual << " | " << expecteds[i] << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}
