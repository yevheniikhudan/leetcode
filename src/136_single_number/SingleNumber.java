import java.util.Arrays;

/**
 * Java skeleton for LeetCode 136 - Single Number
 *
 * Conventions:
 * - `Solution` contains the algorithm signature only (no implementation).
 * - `SingleNumber` contains `main` and test scaffolding.
 *
 * The method in `Solution` intentionally returns a default value (no implementation).
 * Tests print results in the format: actual | expected | PASS/FAIL
 */

class Solution {

    /**
     * Return the element that appears only once in the array while every other
     * element appears exactly twice.
     *
     * Signature only — no implementation provided in the skeleton.
     *
     * @param nums input array
     * @return the single number (default value provided here)
     */
    public int singleNumber(int[] nums) {
        int ans = 0;

        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
}

public class SingleNumber {

    private static void printResult(int actual, int expected) {
        System.out.println(
            actual +
                " | " +
                expected +
                " | " +
                (actual == expected ? "PASS" : "FAIL")
        );
    }

    private static int[] cloneArray(int[] a) {
        return Arrays.copyOf(a, a.length);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        int[][] inputs = {
            { 2, 2, 1 },
            { 4, 1, 2, 1, 2 },
            { 1 },
            { 0, 1, 0, 1, 99 },
            { -1, -1, 2 },
            { 17, 12, 5, 12, 5 },
        };

        int[] expected = { 1, 4, 1, 99, 2, 17 };

        for (int i = 0; i < inputs.length; i++) {
            int[] inp = cloneArray(inputs[i]);
            int exp = expected[i];
            int actual = sol.singleNumber(inp);
            printResult(actual, exp);
        }
    }
}
