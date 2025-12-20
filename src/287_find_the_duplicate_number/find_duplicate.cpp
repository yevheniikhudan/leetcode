/**
 * 287. Find the Duplicate Number
 *
 * Given an array of integers nums containing n + 1 integers where each integer
 * is in the range [1, n] inclusive.
 *
 * There is only one repeated number in nums, return this repeated number.
 * You must solve the problem without modifying the array nums and using only
 * constant extra space.
 *
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find the duplicate number in the array.
     *
     * @param nums Vector of integers with n+1 elements in range [1, n]
     * @return The duplicate number
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        // Phase 1: Find meeting point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find cycle entrance
        slow = 0;  // ✅ Reset slow to start
        // fast stays at meeting point

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];  // Both move 1 step now
        }

return slow;  // They meet at the duplicate!
    }
};

void test_find_duplicate() {
    Solution solution;

    // Test case 1: Example 1 - basic case
    vector<int> nums1 = {1, 3, 4, 2, 2};
    int result1 = solution.findDuplicate(nums1);
    cout << "Test 1: " << result1 << " (expected: 2)" << endl;

    // Test case 2: Example 2 - duplicate at different position
    vector<int> nums2 = {3, 1, 3, 4, 2};
    int result2 = solution.findDuplicate(nums2);
    cout << "Test 2: " << result2 << " (expected: 3)" << endl;

    // Test case 3: Example 3 - all same number
    vector<int> nums3 = {3, 3, 3, 3, 3};
    int result3 = solution.findDuplicate(nums3);
    cout << "Test 3: " << result3 << " (expected: 3)" << endl;

    // Test case 4: Duplicate at start
    vector<int> nums4 = {1, 1};
    int result4 = solution.findDuplicate(nums4);
    cout << "Test 4: " << result4 << " (expected: 1)" << endl;

    // Test case 5: Duplicate at end
    vector<int> nums5 = {1, 2, 3, 4, 4};
    int result5 = solution.findDuplicate(nums5);
    cout << "Test 5: " << result5 << " (expected: 4)" << endl;

    // Test case 6: Larger array
    vector<int> nums6 = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1, 4};
    int result6 = solution.findDuplicate(nums6);
    cout << "Test 6: " << result6 << " (expected: 9)" << endl;

    // Test case 7: Sequential with duplicate in middle
    vector<int> nums7 = {1, 2, 3, 3, 4, 5, 6};
    int result7 = solution.findDuplicate(nums7);
    cout << "Test 7: " << result7 << " (expected: 3)" << endl;
}

int main() {
    test_find_duplicate();
    return 0;
}
