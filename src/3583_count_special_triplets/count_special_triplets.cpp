/*
3583. Count Special Triplets

You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:
- 0 <= i < j < k < n, where n = nums.length
- nums[i] == nums[j] * 2
- nums[k] == nums[j] * 2

Return the total number of special triplets in the array.
Since the answer may be large, return it modulo 10^9 + 7.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Count the number of special triplets in the array.
     *
     * @param nums Vector of integers
     * @return Number of special triplets modulo 10^9 + 7
     *
     * Time Complexity: O(n) where n = nums.size()
     * Space Complexity: O(n) for frequency maps
     */
    int countSpecialTriplets(vector<int>& nums) {
        // TODO: Implement solution
        return 0;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> nums1 = {6, 3, 6};
    int result1 = solution.countSpecialTriplets(nums1);
    cout << "Test 1: " << result1 << " (expected: 1)\n";

    // Test case 2: Example 2 - with zeros
    vector<int> nums2 = {0, 1, 0, 0};
    int result2 = solution.countSpecialTriplets(nums2);
    cout << "Test 2: " << result2 << " (expected: 1)\n";

    // Test case 3: Example 3
    vector<int> nums3 = {8, 4, 2, 8, 4};
    int result3 = solution.countSpecialTriplets(nums3);
    cout << "Test 3: " << result3 << " (expected: 2)\n";

    // Test case 4: No valid triplets
    vector<int> nums4 = {1, 2, 3};
    int result4 = solution.countSpecialTriplets(nums4);
    cout << "Test 4: " << result4 << " (expected: 0)\n";

    // Test case 5: Minimum length
    vector<int> nums5 = {4, 2, 4};
    int result5 = solution.countSpecialTriplets(nums5);
    cout << "Test 5: " << result5 << " (expected: 1)\n";

    // Test case 6: All zeros
    vector<int> nums6 = {0, 0, 0, 0};
    int result6 = solution.countSpecialTriplets(nums6);
    cout << "Test 6: " << result6 << " (expected: 4)\n";

    // Test case 7: Multiple valid triplets
    vector<int> nums7 = {10, 5, 10, 5, 10};
    int result7 = solution.countSpecialTriplets(nums7);
    cout << "Test 7: " << result7 << " (expected: 4)\n";

    // Test case 8: Large numbers
    vector<int> nums8 = {100, 50, 100, 50, 100, 50, 100};
    int result8 = solution.countSpecialTriplets(nums8);
    cout << "Test 8: " << result8 << " (expected: 10)\n";
}

int main() {
    runTests();
    return 0;
}
