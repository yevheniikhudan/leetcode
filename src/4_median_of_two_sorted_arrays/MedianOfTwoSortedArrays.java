/*
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

class Solution {
    /**
     * Find median of two sorted arrays using binary search on partition.
     * 
     * @param nums1 First sorted array
     * @param nums2 Second sorted array
     * @return Median of combined arrays
     * 
     *         Time Complexity: O(log min(m, n)) - binary search on smaller array
     *         Space Complexity: O(1) - constant extra space
     */
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
                int m = nums1.length, n = nums2.length;

        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0, right = m;

        while (left <= right) {
            int partition_a = (left + right) / 2;
            int partition_b = (m + n + 1) / 2 - partition_a;
            int max_left_a = partition_a > 0 ? nums1[partition_a - 1] : Integer.MIN_VALUE;
            int max_left_b = partition_b > 0 ? nums2[partition_b - 1] : Integer.MIN_VALUE;
            int min_right_a = partition_a < m ? nums1[partition_a] : Integer.MAX_VALUE;
            int min_right_b = partition_b < n ? nums2[partition_b] : Integer.MAX_VALUE;

            if (max_left_a <= min_right_b && max_left_b <= min_right_a) {
                if ((m + n) % 2 == 0) {
                    return (double)(Math.max(max_left_a, max_left_b) + Math.min(min_right_a, min_right_b)) / 2;
                } else {
                    return Math.max(max_left_a, max_left_b);
                }
            }

            if (max_left_a > min_right_b) {
                right = partition_a - 1;
            } else {
                left = partition_a + 1;
            }
        }

        return 0.0;
    }
}

public class MedianOfTwoSortedArrays {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example 1 - odd total length
        double result1 = solution.findMedianSortedArrays(new int[] { 1, 3 }, new int[] { 2 });
        System.out.println("Test 1: " + result1 + " (expected: 2.0)");

        // Test case 2: Example 2 - even total length
        double result2 = solution.findMedianSortedArrays(new int[] { 1, 2 }, new int[] { 3, 4 });
        System.out.println("Test 2: " + result2 + " (expected: 2.5)");

        // Test case 3: One empty array
        double result3 = solution.findMedianSortedArrays(new int[] {}, new int[] { 1 });
        System.out.println("Test 3: " + result3 + " (expected: 1.0)");

        // Test case 4: Both single element
        double result4 = solution.findMedianSortedArrays(new int[] { 2 }, new int[] { 3 });
        System.out.println("Test 4: " + result4 + " (expected: 2.5)");

        // Test case 5: No overlap
        double result5 = solution.findMedianSortedArrays(new int[] { 1, 2 }, new int[] { 3, 4, 5 });
        System.out.println("Test 5: " + result5 + " (expected: 3.0)");

        // Test case 6: Complete overlap
        double result6 = solution.findMedianSortedArrays(new int[] { 1, 3, 5 }, new int[] { 2, 4, 6 });
        System.out.println("Test 6: " + result6 + " (expected: 3.5)");

        // Test case 7: Different sizes
        double result7 = solution.findMedianSortedArrays(new int[] { 1, 2, 3, 4, 5 }, new int[] { 6 });
        System.out.println("Test 7: " + result7 + " (expected: 3.5)");

        // Test case 8: Negative numbers
        double result8 = solution.findMedianSortedArrays(new int[] { -5, -3, -1 }, new int[] { 0, 2, 4 });
        System.out.println("Test 8: " + result8 + " (expected: -0.5)");

        // Test case 9: All elements in nums1 < nums2
        double result9 = solution.findMedianSortedArrays(new int[] { 1, 2 }, new int[] { 3, 4, 5, 6 });
        System.out.println("Test 9: " + result9 + " (expected: 3.5)");

        // Test case 10: Single element arrays
        double result10 = solution.findMedianSortedArrays(new int[] { 1 }, new int[] { 2, 3, 4, 5 });
        System.out.println("Test 10: " + result10 + " (expected: 3.0)");
    }
}
