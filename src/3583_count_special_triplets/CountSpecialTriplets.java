/*
3583. Count Special Triplets

You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:
- 0 <= i < j < k < n, where n = nums.length
- nums[i] == nums[j] * 2
- nums[k] == nums[j] * 2

Return the total number of special triplets in the array.
Since the answer may be large, return it modulo 10^9 + 7.
*/

import java.util.HashMap;
import java.util.Map;

class CountSpecialTriplets {
    private static final int MOD = 1_000_000_007;

    /**
     * Count the number of special triplets in the array.
     *
     * @param nums Array of integers
     * @return Number of special triplets modulo 10^9 + 7
     *
     *         Time Complexity: O(n) where n = nums.length
     *         Space Complexity: O(n) for frequency maps
     */
    public int countSpecialTriplets(int[] nums) {
        Map<Integer, Integer> freqPrev = new HashMap<>();
        Map<Integer, Integer> freqNext = new HashMap<>();
        long result = 0;

        // Initialize freqNext with all elements
        for (int num : nums) {
            freqNext.put(num, freqNext.getOrDefault(num, 0) + 1);
        }

        // For each position j, count triplets where nums[i] = nums[k] = nums[j] * 2
        for (int num : nums) {
            freqNext.put(num, freqNext.get(num) - 1);

            long countBefore = freqPrev.getOrDefault(num * 2, 0);
            long countAfter = freqNext.getOrDefault(num * 2, 0);
            result += countBefore * countAfter;

            freqPrev.put(num, freqPrev.getOrDefault(num, 0) + 1);
        }

        return (int) (result % MOD);
    }

    public static void main(String[] args) {
        CountSpecialTriplets solution = new CountSpecialTriplets();

        // Test case 1: Example 1
        int result1 = solution.countSpecialTriplets(new int[] { 6, 3, 6 });
        System.out.println("Test 1: " + result1 + " (expected: 1)");

        // Test case 2: Example 2 - with zeros
        int result2 = solution.countSpecialTriplets(new int[] { 0, 1, 0, 0 });
        System.out.println("Test 2: " + result2 + " (expected: 1)");

        // Test case 3: Example 3
        int result3 = solution.countSpecialTriplets(new int[] { 8, 4, 2, 8, 4 });
        System.out.println("Test 3: " + result3 + " (expected: 2)");

        // Test case 4: No valid triplets
        int result4 = solution.countSpecialTriplets(new int[] { 1, 2, 3 });
        System.out.println("Test 4: " + result4 + " (expected: 0)");

        // Test case 5: Minimum length
        int result5 = solution.countSpecialTriplets(new int[] { 4, 2, 4 });
        System.out.println("Test 5: " + result5 + " (expected: 1)");

        // Test case 6: All zeros
        int result6 = solution.countSpecialTriplets(new int[] { 0, 0, 0, 0 });
        System.out.println("Test 6: " + result6 + " (expected: 4)");

        // Test case 7: Multiple valid triplets
        int result7 = solution.countSpecialTriplets(new int[] { 10, 5, 10, 5, 10 });
        System.out.println("Test 7: " + result7 + " (expected: 4)");

        // Test case 8: Large numbers
        int result8 = solution.countSpecialTriplets(new int[] { 100, 50, 100, 50, 100, 50, 100 });
        System.out.println("Test 8: " + result8 + " (expected: 10)");
    }
}
