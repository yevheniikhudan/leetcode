/*
1590. Make Sum Divisible by P

Given an array of positive integers nums, remove the smallest subarray
(possibly empty) such that the sum of the remaining elements is divisible by p.
It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if
it's impossible.
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find the length of the smallest subarray to remove so that the sum
     * of remaining elements is divisible by p.
     *
     * @param nums Array of positive integers
     * @param p Divisor
     * @return Length of smallest subarray to remove, or -1 if impossible
     *
     * Time Complexity: O(n)
     * Space Complexity: O(min(n, p))
     */
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int remain = totalSum % p;

        if (remain == 0) {
            return 0;
        }

        int curSum = 0;
        unordered_map<int, int> seen;
        seen[0] = -1;
        int res = nums.size();

        for (int index = 0; index < nums.size(); index++) {
            curSum = (curSum + nums[index]) % p;
            int prefix = (curSum - remain + p) % p;

            if (seen.find(prefix) != seen.end()) {
                int length = index - seen[prefix];
                res = min(res, length);
            }

            seen[curSum] = index;
        }

        return res == nums.size() ? -1 : res;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> nums1 = {3, 1, 4, 2};
    int result1 = solution.minSubarray(nums1, 6);
    cout << "Test 1: " << result1 << " (expected: 1)\n";

    // Test case 2: Example 2
    vector<int> nums2 = {6, 3, 5, 2};
    int result2 = solution.minSubarray(nums2, 9);
    cout << "Test 2: " << result2 << " (expected: 2)\n";

    // Test case 3: Example 3 - already divisible
    vector<int> nums3 = {1, 2, 3};
    int result3 = solution.minSubarray(nums3, 3);
    cout << "Test 3: " << result3 << " (expected: 0)\n";

    // Test case 4: Single element - impossible
    vector<int> nums4 = {5};
    int result4 = solution.minSubarray(nums4, 3);
    cout << "Test 4: " << result4 << " (expected: -1)\n";

    // Test case 5: Already divisible (sum = 10)
    vector<int> nums5 = {1, 2, 3, 4};
    int result5 = solution.minSubarray(nums5, 5);
    cout << "Test 5: " << result5 << " (expected: 0)\n";

    // Test case 6: Remove last element (sum = 11, remove 1)
    vector<int> nums6 = {1, 2, 3, 5};
    int result6 = solution.minSubarray(nums6, 5);
    cout << "Test 6: " << result6 << " (expected: 1)\n";

    // Test case 7: Cannot remove entire array
    vector<int> nums7 = {26, 19, 11, 14, 18, 4, 7, 1, 30, 23, 19, 8, 10, 6, 26, 3};
    int result7 = solution.minSubarray(nums7, 26);
    cout << "Test 7: " << result7 << " (expected: 3)\n";

    // Test case 8: Large numbers
    vector<int> nums8 = {1000000000, 1000000000, 1000000000};
    int result8 = solution.minSubarray(nums8, 3);
    cout << "Test 8: " << result8 << " (expected: 0)\n";
}

int main() {
    runTests();
    return 0;
}
