/*
3381. Maximum Subarray Sum With Length Divisible by K

You are given an array of integers nums and an integer k.
Return the maximum sum of a subarray of nums, such that the size 
of the subarray is divisible by k.
*/

import java.util.Arrays;

public class MaximumSubarraySumWithLengthDivisibleByK {
    /**
     * Find maximum sum of subarray with length divisible by k.
     * 
     * @param nums Array of integers
     * @param k    Divisor for subarray length
     * @return Maximum sum of subarray with length divisible by k
     * 
     *         Time Complexity: O(n)
     *         Space Complexity: O(k)
     */
    public long maxSubarraySum(int[] nums, int k) {
        long maxSum = Long.MIN_VALUE;
        long[] minPrefix = new long[k];
        Arrays.fill(minPrefix, Long.MAX_VALUE);
        minPrefix[0] = 0;
        long prefix = 0;

        for (int i = 0; i < nums.length; i++) {
            prefix += nums[i];
            int remainder = (i + 1) % k;
            if (minPrefix[remainder] != Long.MAX_VALUE) {
                maxSum = Math.max(maxSum, prefix - minPrefix[remainder]);
            }
            minPrefix[remainder] = Math.min(minPrefix[remainder], prefix);
        }

        return maxSum;
    }

    public static void main(String[] args) {
        MaximumSubarraySumWithLengthDivisibleByK solution = new MaximumSubarraySumWithLengthDivisibleByK();

        // Test case 1: Simple case with k=1
        int[] nums1 = { 1, 2 };
        int k1 = 1;
        long result1 = solution.maxSubarraySum(nums1, k1);
        System.out.printf("Test 1: %d (expected: 3)%n", result1);

        // Test case 2: All negative numbers
        int[] nums2 = { -1, -2, -3, -4, -5 };
        int k2 = 4;
        long result2 = solution.maxSubarraySum(nums2, k2);
        System.out.printf("Test 2: %d (expected: -10)%n", result2);

        // Test case 3: Mixed positive and negative
        int[] nums3 = { -5, 1, 2, -3, 4 };
        int k3 = 2;
        long result3 = solution.maxSubarraySum(nums3, k3);
        System.out.printf("Test 3: %d (expected: 4)%n", result3);

        // Test case 4: Single element
        int[] nums4 = { 5 };
        int k4 = 1;
        long result4 = solution.maxSubarraySum(nums4, k4);
        System.out.printf("Test 4: %d (expected: 5)%n", result4);

        // Test case 5: Entire array
        int[] nums5 = { 1, 2, 3, 4 };
        int k5 = 4;
        long result5 = solution.maxSubarraySum(nums5, k5);
        System.out.printf("Test 5: %d (expected: 10)%n", result5);

        // Test case 6: k = 2, multiple valid subarrays
        int[] nums6 = { 1, -1, 5, -2, 3 };
        int k6 = 2;
        long result6 = solution.maxSubarraySum(nums6, k6);
        System.out.printf("Test 6: %d (expected: 5)%n", result6);

        // Test case 7: Large negative at start
        int[] nums7 = { -10, 5, 5 };
        int k7 = 3;
        long result7 = solution.maxSubarraySum(nums7, k7);
        System.out.printf("Test 7: %d (expected: 0)%n", result7);
    }
}
