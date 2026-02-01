#include <iostream>
#include <vector>

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = 1;

        for (int num : nums) {
            unordered_map<int, int> nextDp;

            for (auto& pair : dp) {
                int total = pair.first;
                int count = pair.second;
                nextDp[total - num] += count;
                nextDp[total + num] += count;
            }

            dp = move(nextDp);
        }

        return dp[target];
    }
};

int main() {
    Solution sol;
    // Test case 1: Example 1
    std::vector<int> nums1 = {1, 1, 1, 1, 1};
    std::cout << sol.findTargetSumWays(nums1, 3) << " | 5" << std::endl;
    // Test case 2: Example 2
    std::vector<int> nums2 = {1};
    std::cout << sol.findTargetSumWays(nums2, 1) << " | 1" << std::endl;
    // Test case 3: No ways
    std::vector<int> nums3 = {1};
    std::cout << sol.findTargetSumWays(nums3, 2) << " | 0" << std::endl;
    // Test case 4: Target 0
    std::vector<int> nums4 = {1, 1};
    std::cout << sol.findTargetSumWays(nums4, 0) << " | 2" << std::endl;
    // Test case 5: Larger numbers
    std::vector<int> nums5 = {1, 2, 3};
    std::cout << sol.findTargetSumWays(nums5, 0) << " | 2" << std::endl;
    // Test case 6: All zeros
    std::vector<int> nums6 = {0, 0};
    std::cout << sol.findTargetSumWays(nums6, 0) << " | 4" << std::endl;
    return 0;
}
