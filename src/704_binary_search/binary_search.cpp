/*
704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an
integer target, write a function to search target in nums. If target exists,
then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Binary search for target in sorted array.
     *
     * @param nums Sorted vector in ascending order
     * @param target Value to search for
     * @return Index of target if found, -1 otherwise
     *
     * Time Complexity: O(log n) where n = nums.size()
     * Space Complexity: O(1) - only constant extra space
     */
    int search(vector<int>& nums, int target) {
        int result = 1;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return result;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1 - target found in middle-right
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int result1 = solution.search(nums1, 9);
    cout << "Test 1: " << result1 << " (expected: 4)\n";

    // Test case 2: Example 2 - target not found
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int result2 = solution.search(nums2, 2);
    cout << "Test 2: " << result2 << " (expected: -1)\n";

    // Test case 3: Single element - found
    vector<int> nums3 = {5};
    int result3 = solution.search(nums3, 5);
    cout << "Test 3: " << result3 << " (expected: 0)\n";

    // Test case 4: Single element - not found
    vector<int> nums4 = {5};
    int result4 = solution.search(nums4, -5);
    cout << "Test 4: " << result4 << " (expected: -1)\n";

    // Test case 5: Target at beginning
    vector<int> nums5 = {-1, 0, 3, 5, 9, 12};
    int result5 = solution.search(nums5, -1);
    cout << "Test 5: " << result5 << " (expected: 0)\n";

    // Test case 6: Target at end
    vector<int> nums6 = {-1, 0, 3, 5, 9, 12};
    int result6 = solution.search(nums6, 12);
    cout << "Test 6: " << result6 << " (expected: 5)\n";

    // Test case 7: Target smaller than all elements
    vector<int> nums7 = {1, 2, 3, 4, 5};
    int result7 = solution.search(nums7, 0);
    cout << "Test 7: " << result7 << " (expected: -1)\n";

    // Test case 8: Target larger than all elements
    vector<int> nums8 = {1, 2, 3, 4, 5};
    int result8 = solution.search(nums8, 6);
    cout << "Test 8: " << result8 << " (expected: -1)\n";

    // Test case 9: Two elements - target is first
    vector<int> nums9 = {1, 3};
    int result9 = solution.search(nums9, 1);
    cout << "Test 9: " << result9 << " (expected: 0)\n";

    // Test case 10: Two elements - target is second
    vector<int> nums10 = {1, 3};
    int result10 = solution.search(nums10, 3);
    cout << "Test 10: " << result10 << " (expected: 1)\n";
}

int main() {
    runTests();
    return 0;
}
