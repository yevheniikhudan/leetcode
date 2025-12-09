/*
2044. Keep Multiplying Found Values by Two

You are given an array of integers nums. You are also given an integer original
which is the first number that needs to be searched for in nums.

You then do the following steps:
1. If original is found in nums, multiply it by two (i.e., set original = 2 * original).
2. Otherwise, stop the process.
3. Repeat this process with the new number as long as you keep finding the number.

Return the final value of original.
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Keep multiplying found values by two.
     *
     * @param nums Vector of integers
     * @param original Starting value to search for
     * @return Final value of original after all multiplications
     *
     * Time Complexity: O(n) where n = nums.size()
     * Space Complexity: O(n) for the hash set
     */
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> nums_set(nums.begin(), nums.end());

        while (nums_set.count(original)) {
            original *= 2;
        }

        return original;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> nums1 = {5, 3, 6, 1, 12};
    int result1 = solution.findFinalValue(nums1, 3);
    cout << "Test 1: " << result1 << " (expected: 24)\n";

    // Test case 2: Example 2
    vector<int> nums2 = {2, 7, 9};
    int result2 = solution.findFinalValue(nums2, 4);
    cout << "Test 2: " << result2 << " (expected: 4)\n";

    // Test case 3: Single element found
    vector<int> nums3 = {8};
    int result3 = solution.findFinalValue(nums3, 8);
    cout << "Test 3: " << result3 << " (expected: 16)\n";

    // Test case 4: Single element not found
    vector<int> nums4 = {5};
    int result4 = solution.findFinalValue(nums4, 3);
    cout << "Test 4: " << result4 << " (expected: 3)\n";

    // Test case 5: Multiple multiplications
    vector<int> nums5 = {1, 2, 4, 8, 16};
    int result5 = solution.findFinalValue(nums5, 1);
    cout << "Test 5: " << result5 << " (expected: 32)\n";

    // Test case 6: Large array
    vector<int> nums6 = {2, 4, 8, 16, 32, 64};
    int result6 = solution.findFinalValue(nums6, 2);
    cout << "Test 6: " << result6 << " (expected: 128)\n";

    // Test case 7: No multiplication
    vector<int> nums7 = {10, 20, 30};
    int result7 = solution.findFinalValue(nums7, 5);
    cout << "Test 7: " << result7 << " (expected: 5)\n";

    // Test case 8: Original is largest in array
    vector<int> nums8 = {1, 2, 3, 4, 5};
    int result8 = solution.findFinalValue(nums8, 5);
    cout << "Test 8: " << result8 << " (expected: 10)\n";
}

int main() {
    runTests();
    return 0;
}
