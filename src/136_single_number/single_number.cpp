/leetcode/src/136_single_number/single_number.cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Return the element that appears only once while every other element appears twice.
    // TODO: implement the algorithm (e.g., XOR scan).
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};

static void print_result(int actual, int expected) {
    cout << actual << " | " << expected << " | " << (actual == expected ? "PASS" : "FAIL") << "\n";
}

int main() {
    Solution sol;

    vector<pair<vector<int>, int>> tests = {
        {{2, 2, 1}, 1},
        {{4, 1, 2, 1, 2}, 4},
        {{1}, 1},
        {{0, 1, 0}, 1},
        {{-1, -1, -2}, -2},
        {{17, 12, 5, 12, 5}, 17}
    };

    for (auto &tc : tests) {
        vector<int> nums = tc.first;
        int expected = tc.second;
        int actual = sol.singleNumber(nums);
        print_result(actual, expected);
    }

    return 0;
}
