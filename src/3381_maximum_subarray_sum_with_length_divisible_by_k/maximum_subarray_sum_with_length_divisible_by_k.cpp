/*
3381. Maximum Subarray Sum With Length Divisible by K

You are given an array of integers nums and an integer k.
Return the maximum sum of a subarray of nums, such that the size
of the subarray is divisible by k.
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find maximum sum of subarray with length divisible by k.
     *
     * @param nums Array of integers
     * @param k Divisor for subarray length
     * @return Maximum sum of subarray with length divisible by k
     *
     * Time Complexity: O(n)
     * Space Complexity: O(k)
     */
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long maxSum = LLONG_MIN;
        vector<long long> minPrefix(k, LLONG_MAX);
        minPrefix[0] = 0;
        long long prefix = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int remainder = (i + 1) % k;
            if (minPrefix[remainder] != LLONG_MAX) {
                maxSum = max(maxSum, prefix - minPrefix[remainder]);
            }
            minPrefix[remainder] = min(minPrefix[remainder], prefix);
        }

        return maxSum;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Simple case with k=1
    vector<int> nums1 = {1, 2};
    int k1 = 1;
    long long result1 = solution.maxSubarraySum(nums1, k1);
    cout << "Test 1: " << result1 << " (expected: 3)\n";

    // Test case 2: All negative numbers
    vector<int> nums2 = {-1, -2, -3, -4, -5};
    int k2 = 4;
    long long result2 = solution.maxSubarraySum(nums2, k2);
    cout << "Test 2: " << result2 << " (expected: -10)\n";

    // Test case 3: Mixed positive and negative
    vector<int> nums3 = {-5, 1, 2, -3, 4};
    int k3 = 2;
    long long result3 = solution.maxSubarraySum(nums3, k3);
    cout << "Test 3: " << result3 << " (expected: 4)\n";

    // Test case 4: Single element
    vector<int> nums4 = {5};
    int k4 = 1;
    long long result4 = solution.maxSubarraySum(nums4, k4);
    cout << "Test 4: " << result4 << " (expected: 5)\n";

    // Test case 5: Entire array
    vector<int> nums5 = {1, 2, 3, 4};
    int k5 = 4;
    long long result5 = solution.maxSubarraySum(nums5, k5);
    cout << "Test 5: " << result5 << " (expected: 10)\n";

    // Test case 6: k = 2, multiple valid subarrays
    vector<int> nums6 = {1, -1, 5, -2, 3};
    int k6 = 2;
    long long result6 = solution.maxSubarraySum(nums6, k6);
    cout << "Test 6: " << result6 << " (expected: 5)\n";

    // Test case 7: Large negative at start
    vector<int> nums7 = {-10, 5, 5};
    int k7 = 3;
    long long result7 = solution.maxSubarraySum(nums7, k7);
    cout << "Test 7: " << result7 << " (expected: 0)\n";
}

int main() {
    runTests();
    return 0;
}
