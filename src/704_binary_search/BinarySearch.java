/*
704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an 
integer target, write a function to search target in nums. If target exists, 
then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
    /**
     * Binary search for target in sorted array.
     * 
     * @param nums   Sorted array in ascending order
     * @param target Value to search for
     * @return Index of target if found, -1 otherwise
     * 
     *         Time Complexity: O(log n) where n = nums.length
     *         Space Complexity: O(1) - only constant extra space
     */
    public int search(int[] nums, int target) {
        int result = -1;
        int left = 0, right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
}

public class BinarySearch {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example 1 - target found in middle-right
        int result1 = solution.search(new int[] { -1, 0, 3, 5, 9, 12 }, 9);
        System.out.println("Test 1: " + result1 + " (expected: 4)");

        // Test case 2: Example 2 - target not found
        int result2 = solution.search(new int[] { -1, 0, 3, 5, 9, 12 }, 2);
        System.out.println("Test 2: " + result2 + " (expected: -1)");

        // Test case 3: Single element - found
        int result3 = solution.search(new int[] { 5 }, 5);
        System.out.println("Test 3: " + result3 + " (expected: 0)");

        // Test case 4: Single element - not found
        int result4 = solution.search(new int[] { 5 }, -5);
        System.out.println("Test 4: " + result4 + " (expected: -1)");

        // Test case 5: Target at beginning
        int result5 = solution.search(new int[] { -1, 0, 3, 5, 9, 12 }, -1);
        System.out.println("Test 5: " + result5 + " (expected: 0)");

        // Test case 6: Target at end
        int result6 = solution.search(new int[] { -1, 0, 3, 5, 9, 12 }, 12);
        System.out.println("Test 6: " + result6 + " (expected: 5)");

        // Test case 7: Target smaller than all elements
        int result7 = solution.search(new int[] { 1, 2, 3, 4, 5 }, 0);
        System.out.println("Test 7: " + result7 + " (expected: -1)");

        // Test case 8: Target larger than all elements
        int result8 = solution.search(new int[] { 1, 2, 3, 4, 5 }, 6);
        System.out.println("Test 8: " + result8 + " (expected: -1)");

        // Test case 9: Two elements - target is first
        int result9 = solution.search(new int[] { 1, 3 }, 1);
        System.out.println("Test 9: " + result9 + " (expected: 0)");

        // Test case 10: Two elements - target is second
        int result10 = solution.search(new int[] { 1, 3 }, 3);
        System.out.println("Test 10: " + result10 + " (expected: 1)");
    }
}
