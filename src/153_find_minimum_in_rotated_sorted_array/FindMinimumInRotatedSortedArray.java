/*
153. Find Minimum in Rotated Sorted Array

Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
For example, the array nums = [0,1,2,4,5,6,7] might become:
- [4,5,6,7,0,1,2] if it was rotated 4 times.
- [0,1,2,4,5,6,7] if it was rotated 7 times.

Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
*/

class Solution {
    /**
     * Find minimum element in rotated sorted array.
     * 
     * @param nums Rotated sorted array with unique elements
     * @return Minimum element in the array
     * 
     *         Time Complexity: O(log n) - binary search
     *         Space Complexity: O(1) - constant extra space
     */
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
}

public class FindMinimumInRotatedSortedArray {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example 1 - rotated 3 times
        int result1 = solution.findMin(new int[] { 3, 4, 5, 1, 2 });
        System.out.println("Test 1: " + result1 + " (expected: 1)");

        // Test case 2: Example 2 - rotated 4 times
        int result2 = solution.findMin(new int[] { 4, 5, 6, 7, 0, 1, 2 });
        System.out.println("Test 2: " + result2 + " (expected: 0)");

        // Test case 3: Example 3 - not rotated (or rotated n times)
        int result3 = solution.findMin(new int[] { 11, 13, 15, 17 });
        System.out.println("Test 3: " + result3 + " (expected: 11)");

        // Test case 4: Single element
        int result4 = solution.findMin(new int[] { 1 });
        System.out.println("Test 4: " + result4 + " (expected: 1)");

        // Test case 5: Two elements - rotated
        int result5 = solution.findMin(new int[] { 2, 1 });
        System.out.println("Test 5: " + result5 + " (expected: 1)");

        // Test case 6: Two elements - not rotated
        int result6 = solution.findMin(new int[] { 1, 2 });
        System.out.println("Test 6: " + result6 + " (expected: 1)");

        // Test case 7: Minimum at beginning (rotated once)
        int result7 = solution.findMin(new int[] { 5, 1, 2, 3, 4 });
        System.out.println("Test 7: " + result7 + " (expected: 1)");

        // Test case 8: Minimum at end
        int result8 = solution.findMin(new int[] { 2, 3, 4, 5, 1 });
        System.out.println("Test 8: " + result8 + " (expected: 1)");

        // Test case 9: Large array
        int result9 = solution.findMin(new int[] { 6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5 });
        System.out.println("Test 9: " + result9 + " (expected: 1)");

        // Test case 10: Negative numbers
        int result10 = solution.findMin(new int[] { 3, 4, 5, -1, 0, 1, 2 });
        System.out.println("Test 10: " + result10 + " (expected: -1)");
    }
}
