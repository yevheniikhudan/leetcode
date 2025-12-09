/*
1590. Make Sum Divisible by P

Given an array of positive integers nums, remove the smallest subarray 
(possibly empty) such that the sum of the remaining elements is divisible by p. 
It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if 
it's impossible.
*/

import java.util.HashMap;
import java.util.Map;

public class MakeSumDivisibleByP {
    /**
     * Find the length of the smallest subarray to remove so that the sum
     * of remaining elements is divisible by p.
     * 
     * @param nums Array of positive integers
     * @param p    Divisor
     * @return Length of smallest subarray to remove, or -1 if impossible
     * 
     *         Time Complexity: O(n)
     *         Space Complexity: O(min(n, p))
     */
    public int minSubarray(int[] nums, int p) {
        long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int remain = (int) (totalSum % p);

        if (remain == 0) {
            return 0;
        }

        int curSum = 0;
        Map<Integer, Integer> seen = new HashMap<>();
        seen.put(0, -1);
        int res = nums.length;

        for (int index = 0; index < nums.length; index++) {
            curSum = (curSum + nums[index]) % p;
            int prefix = (curSum - remain + p) % p;

            if (seen.containsKey(prefix)) {
                int length = index - seen.get(prefix);
                res = Math.min(res, length);
            }

            seen.put(curSum, index);
        }

        return res == nums.length ? -1 : res;
    }

    public static void main(String[] args) {
        MakeSumDivisibleByP solution = new MakeSumDivisibleByP();

        // Test case 1: Example 1
        int[] nums1 = { 3, 1, 4, 2 };
        int result1 = solution.minSubarray(nums1, 6);
        System.out.printf("Test 1: %d (expected: 1)%n", result1);

        // Test case 2: Example 2
        int[] nums2 = { 6, 3, 5, 2 };
        int result2 = solution.minSubarray(nums2, 9);
        System.out.printf("Test 2: %d (expected: 2)%n", result2);

        // Test case 3: Example 3 - already divisible
        int[] nums3 = { 1, 2, 3 };
        int result3 = solution.minSubarray(nums3, 3);
        System.out.printf("Test 3: %d (expected: 0)%n", result3);

        // Test case 4: Single element - impossible
        int[] nums4 = { 5 };
        int result4 = solution.minSubarray(nums4, 3);
        System.out.printf("Test 4: %d (expected: -1)%n", result4);

        // Test case 5: Already divisible (sum = 10)
        int[] nums5 = { 1, 2, 3, 4 };
        int result5 = solution.minSubarray(nums5, 5);
        System.out.printf("Test 5: %d (expected: 0)%n", result5);

        // Test case 6: Remove last element (sum = 11, remove 1)
        int[] nums6 = { 1, 2, 3, 5 };
        int result6 = solution.minSubarray(nums6, 5);
        System.out.printf("Test 6: %d (expected: 1)%n", result6);

        // Test case 7: Cannot remove entire array
        int[] nums7 = { 26, 19, 11, 14, 18, 4, 7, 1, 30, 23, 19, 8, 10, 6, 26, 3 };
        int result7 = solution.minSubarray(nums7, 26);
        System.out.printf("Test 7: %d (expected: 3)%n", result7);

        // Test case 8: Large numbers
        int[] nums8 = { 1000000000, 1000000000, 1000000000 };
        int result8 = solution.minSubarray(nums8, 3);
        System.out.printf("Test 8: %d (expected: 0)%n", result8);
    }
}
