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

class Solution {
    /**
     * Search for target in rotated sorted array.
     * 
     * @param nums   Rotated sorted array with unique elements
     * @param target Value to search for
     * @return Index of target if found, -1 otherwise
     * 
     *         Time Complexity: O(log n) - binary search
     *         Space Complexity: O(1) - constant extra space
     */
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Key observation: one half is always sorted
            // Check which half is sorted, then determine if target is in that sorted half
            if (nums[mid] < nums[right]) { // Right half is sorted: [mid...right]
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // Target in right sorted half
                } else {
                    right = mid - 1; // Target in left half
                }
            } else { // Left half is sorted: [left...mid]
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Target in left sorted half
                } else {
                    left = mid + 1; // Target in right half
                }
            }
        }
        return -1;
    }
}

public class SearchInRotatedSortedArray {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example 1 - target found
        int result1 = solution.search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 0);
        System.out.println("Test 1: " + result1 + " (expected: 4)");

        // Test case 2: Example 2 - target not found
        int result2 = solution.search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 3);
        System.out.println("Test 2: " + result2 + " (expected: -1)");

        // Test case 3: Example 3 - single element, not found
        int result3 = solution.search(new int[] { 1 }, 0);
        System.out.println("Test 3: " + result3 + " (expected: -1)");

        // Test case 4: Single element, found
        int result4 = solution.search(new int[] { 1 }, 1);
        System.out.println("Test 4: " + result4 + " (expected: 0)");

        // Test case 5: No rotation, target found
        int result5 = solution.search(new int[] { 1, 2, 3, 4, 5 }, 3);
        System.out.println("Test 5: " + result5 + " (expected: 2)");

        // Test case 6: Target at beginning
        int result6 = solution.search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 4);
        System.out.println("Test 6: " + result6 + " (expected: 0)");

        // Test case 7: Target at end
        int result7 = solution.search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 2);
        System.out.println("Test 7: " + result7 + " (expected: 6)");

        // Test case 8: Target at inflection point
        int result8 = solution.search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 7);
        System.out.println("Test 8: " + result8 + " (expected: 3)");

        // Test case 9: Two elements - rotated
        int result9 = solution.search(new int[] { 3, 1 }, 1);
        System.out.println("Test 9: " + result9 + " (expected: 1)");

        // Test case 10: Large array with rotation
        int result10 = solution.search(new int[] { 6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5 }, 3);
        System.out.println("Test 10: " + result10 + " (expected: 8)");

        // Test case 11: Target smaller than all in left portion
        int result11 = solution.search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 1);
        System.out.println("Test 11: " + result11 + " (expected: 5)");

        // Test case 12: Target larger than all in right portion
        int result12 = solution.search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 6);
        System.out.println("Test 12: " + result12 + " (expected: 2)");
    }
}
