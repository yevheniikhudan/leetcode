/*
33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown
pivot index k (1 <= k < nums.length) such that the resulting array is
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).

Given the array nums after the possible rotation and an integer target, return
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Search for target in rotated sorted array.
     *
     * @param nums Rotated sorted array with unique elements
     * @param target Value to search for
     * @return Index of target if found, -1 otherwise
     *
     * Time Complexity: O(log n) - binary search
     * Space Complexity: O(1) - constant extra space
     */
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target == nums[mid]) {
                return mid;
            }

            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1 - target found
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int result1 = solution.search(nums1, 0);
    cout << "Test 1: " << result1 << " (expected: 4)\n";

    // Test case 2: Example 2 - target not found
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int result2 = solution.search(nums2, 3);
    cout << "Test 2: " << result2 << " (expected: -1)\n";

    // Test case 3: Example 3 - single element, not found
    vector<int> nums3 = {1};
    int result3 = solution.search(nums3, 0);
    cout << "Test 3: " << result3 << " (expected: -1)\n";

    // Test case 4: Single element, found
    vector<int> nums4 = {1};
    int result4 = solution.search(nums4, 1);
    cout << "Test 4: " << result4 << " (expected: 0)\n";

    // Test case 5: No rotation, target found
    vector<int> nums5 = {1, 2, 3, 4, 5};
    int result5 = solution.search(nums5, 3);
    cout << "Test 5: " << result5 << " (expected: 2)\n";

    // Test case 6: Target at beginning
    vector<int> nums6 = {4, 5, 6, 7, 0, 1, 2};
    int result6 = solution.search(nums6, 4);
    cout << "Test 6: " << result6 << " (expected: 0)\n";

    // Test case 7: Target at end
    vector<int> nums7 = {4, 5, 6, 7, 0, 1, 2};
    int result7 = solution.search(nums7, 2);
    cout << "Test 7: " << result7 << " (expected: 6)\n";

    // Test case 8: Target at inflection point
    vector<int> nums8 = {4, 5, 6, 7, 0, 1, 2};
    int result8 = solution.search(nums8, 7);
    cout << "Test 8: " << result8 << " (expected: 3)\n";

    // Test case 9: Two elements - rotated
    vector<int> nums9 = {3, 1};
    int result9 = solution.search(nums9, 1);
    cout << "Test 9: " << result9 << " (expected: 1)\n";

    // Test case 10: Large array with rotation
    vector<int> nums10 = {6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5};
    int result10 = solution.search(nums10, 3);
    cout << "Test 10: " << result10 << " (expected: 8)\n";

    // Test case 11: Target smaller than all in left portion
    vector<int> nums11 = {4, 5, 6, 7, 0, 1, 2};
    int result11 = solution.search(nums11, 1);
    cout << "Test 11: " << result11 << " (expected: 5)\n";

    // Test case 12: Target larger than all in right portion
    vector<int> nums12 = {4, 5, 6, 7, 0, 1, 2};
    int result12 = solution.search(nums12, 6);
    cout << "Test 12: " << result12 << " (expected: 2)\n";
}

int main() {
    runTests();
    return 0;
}
