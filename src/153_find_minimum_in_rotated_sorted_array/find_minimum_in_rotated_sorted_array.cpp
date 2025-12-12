/*
153. Find Minimum in Rotated Sorted Array

Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
For example, the array nums = [0,1,2,4,5,6,7] might become:
- [4,5,6,7,0,1,2] if it was rotated 4 times.
- [0,1,2,4,5,6,7] if it was rotated 7 times.

Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find minimum element in rotated sorted array.
     *
     * @param nums Rotated sorted array with unique elements
     * @return Minimum element in the array
     *
     * Time Complexity: O(log n) - binary search
     * Space Complexity: O(1) - constant extra space
     */
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1 - rotated 3 times
    vector<int> nums1 = {3, 4, 5, 1, 2};
    int result1 = solution.findMin(nums1);
    cout << "Test 1: " << result1 << " (expected: 1)\n";

    // Test case 2: Example 2 - rotated 4 times
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int result2 = solution.findMin(nums2);
    cout << "Test 2: " << result2 << " (expected: 0)\n";

    // Test case 3: Example 3 - not rotated (or rotated n times)
    vector<int> nums3 = {11, 13, 15, 17};
    int result3 = solution.findMin(nums3);
    cout << "Test 3: " << result3 << " (expected: 11)\n";

    // Test case 4: Single element
    vector<int> nums4 = {1};
    int result4 = solution.findMin(nums4);
    cout << "Test 4: " << result4 << " (expected: 1)\n";

    // Test case 5: Two elements - rotated
    vector<int> nums5 = {2, 1};
    int result5 = solution.findMin(nums5);
    cout << "Test 5: " << result5 << " (expected: 1)\n";

    // Test case 6: Two elements - not rotated
    vector<int> nums6 = {1, 2};
    int result6 = solution.findMin(nums6);
    cout << "Test 6: " << result6 << " (expected: 1)\n";

    // Test case 7: Minimum at beginning (rotated once)
    vector<int> nums7 = {5, 1, 2, 3, 4};
    int result7 = solution.findMin(nums7);
    cout << "Test 7: " << result7 << " (expected: 1)\n";

    // Test case 8: Minimum at end
    vector<int> nums8 = {2, 3, 4, 5, 1};
    int result8 = solution.findMin(nums8);
    cout << "Test 8: " << result8 << " (expected: 1)\n";

    // Test case 9: Large array
    vector<int> nums9 = {6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5};
    int result9 = solution.findMin(nums9);
    cout << "Test 9: " << result9 << " (expected: 1)\n";

    // Test case 10: Negative numbers
    vector<int> nums10 = {3, 4, 5, -1, 0, 1, 2};
    int result10 = solution.findMin(nums10);
    cout << "Test 10: " << result10 << " (expected: -1)\n";
}

int main() {
    runTests();
    return 0;
}
