#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
            res ^= i + 1;
        }

        return res;
    }
};

// ---------- Test Helpers ----------

void check(int actual, int expected, const std::string& label) {
    bool ok = actual == expected;
    std::cout << actual << " | " << expected << " | "
              << (ok ? "PASS" : "FAIL")
              << " (" << label << ")\n";
}

// ---------- Tests ----------

int main() {
    Solution sol;

    std::vector<int> nums1 = {3, 0, 1};
    check(sol.missingNumber(nums1), 2, "Example 1");

    std::vector<int> nums2 = {0, 1};
    check(sol.missingNumber(nums2), 2, "Example 2");

    std::vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    check(sol.missingNumber(nums3), 8, "Example 3");

    std::vector<int> nums4 = {0};
    check(sol.missingNumber(nums4), 1, "Missing last element");

    std::vector<int> nums5 = {1};
    check(sol.missingNumber(nums5), 0, "Missing first element");

    std::vector<int> nums6 = {2, 0, 1};
    check(sol.missingNumber(nums6), 3, "Missing at end");

    std::vector<int> nums7 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    check(sol.missingNumber(nums7), 9, "Large range");

    return 0;
}
