import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Problem 3741: Minimum Distance Between Three Equal Elements II
 *
 * Find the minimum distance between any three equal elements in an array.
 * If no three equal elements exist, return -1.
 */

class Solution {

    /**
     * Finds the minimum distance between any three equal elements in the array.
     *
     * The distance between three elements at indices i, j, k (where i < j < k)
     * is defined as (k - i) * 2.
     *
     * @param nums Array of integers where 1 <= nums[i] <= 100
     * @return Minimum distance between three equal elements, or -1 if none exist
     */
    public int minimumDistance(int[] nums) {
        Map<Integer, List<Integer>> occur = new HashMap<>();
        int res = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {
            if (!occur.containsKey(nums[i])) {
                occur.put(nums[i], new ArrayList<>());
            }

            occur.get(nums[i]).add(i);
        }

        for (List<Integer> indices : occur.values()) {
            if (indices.size() < 3) {
                continue;
            }

            for (int i = 2; i < indices.size(); i++) {
                res = Math.min(res, indices.get(i) - indices.get(i - 2));
            }
        }

        return res == Integer.MAX_VALUE ? -1 : res * 2;
    }
}

/**
 * Test harness for the Solution class.
 * Contains main method and helper functions for testing.
 */
public class MinimumDistanceBetweenThreeEqualElementsII {

    public static void main(String[] args) {
        runAllTests();
    }

    /**
     * Runs all test cases and displays results in the required format.
     */
    static void runAllTests() {
        Solution solution = new Solution();

        System.out.println(
            "================================================================================"
        );
        System.out.println(
            "Testing: Problem 3741 - Minimum Distance Between Three Equal Elements II"
        );
        System.out.println(
            "================================================================================\n"
        );

        int passed = 0;
        int failed = 0;
        int totalTests = 0;

        // Test Case 1: All elements are the same
        totalTests++;
        int[] test1 = { 1, 1, 1, 1, 1 };
        int expected1 = 4;
        int actual1 = solution.minimumDistance(test1);
        boolean pass1 = (actual1 == expected1);
        System.out.println("Test Case 1: All elements are the same");
        System.out.println("Input: " + arrayToString(test1));
        System.out.println(
            actual1 + " | " + expected1 + " | " + (pass1 ? "PASS" : "FAIL")
        );
        if (pass1) passed++;
        else failed++;
        System.out.println();

        // Test Case 2: No three equal elements
        totalTests++;
        int[] test2 = { 1, 2, 3, 4, 5 };
        int expected2 = -1;
        int actual2 = solution.minimumDistance(test2);
        boolean pass2 = (actual2 == expected2);
        System.out.println("Test Case 2: No three equal elements");
        System.out.println("Input: " + arrayToString(test2));
        System.out.println(
            actual2 + " | " + expected2 + " | " + (pass2 ? "PASS" : "FAIL")
        );
        if (pass2) passed++;
        else failed++;
        System.out.println();

        // Test Case 3: Multiple values, 1's at indices [0,1,3,4]
        totalTests++;
        int[] test3 = { 1, 1, 2, 1, 1 };
        int expected3 = 6;
        int actual3 = solution.minimumDistance(test3);
        boolean pass3 = (actual3 == expected3);
        System.out.println(
            "Test Case 3: Multiple values, 1's at indices [0,1,3,4]"
        );
        System.out.println("Input: " + arrayToString(test3));
        System.out.println(
            actual3 + " | " + expected3 + " | " + (pass3 ? "PASS" : "FAIL")
        );
        if (pass3) passed++;
        else failed++;
        System.out.println();

        // Test Case 4: Exactly three equal elements
        totalTests++;
        int[] test4 = { 5, 5, 5 };
        int expected4 = 4;
        int actual4 = solution.minimumDistance(test4);
        boolean pass4 = (actual4 == expected4);
        System.out.println("Test Case 4: Exactly three equal elements");
        System.out.println("Input: " + arrayToString(test4));
        System.out.println(
            actual4 + " | " + expected4 + " | " + (pass4 ? "PASS" : "FAIL")
        );
        if (pass4) passed++;
        else failed++;
        System.out.println();

        // Test Case 5: All identical elements - longer array
        totalTests++;
        int[] test5 = { 3, 3, 3, 3, 3 };
        int expected5 = 4;
        int actual5 = solution.minimumDistance(test5);
        boolean pass5 = (actual5 == expected5);
        System.out.println(
            "Test Case 5: All identical elements - longer array"
        );
        System.out.println("Input: " + arrayToString(test5));
        System.out.println(
            actual5 + " | " + expected5 + " | " + (pass5 ? "PASS" : "FAIL")
        );
        if (pass5) passed++;
        else failed++;
        System.out.println();

        // Test Case 6: Two values with 3+ occurrences
        totalTests++;
        int[] test6 = { 1, 1, 2, 1, 2, 2, 1, 2 };
        int expected6 = 6;
        int actual6 = solution.minimumDistance(test6);
        boolean pass6 = (actual6 == expected6);
        System.out.println("Test Case 6: Two values with 3+ occurrences");
        System.out.println("Input: " + arrayToString(test6));
        System.out.println(
            actual6 + " | " + expected6 + " | " + (pass6 ? "PASS" : "FAIL")
        );
        if (pass6) passed++;
        else failed++;
        System.out.println();

        // Test Case 7: Only two 5's, but 10 has three
        totalTests++;
        int[] test7 = { 5, 5, 10, 10, 10 };
        int expected7 = 4;
        int actual7 = solution.minimumDistance(test7);
        boolean pass7 = (actual7 == expected7);
        System.out.println("Test Case 7: Only two 5's, but 10 has three");
        System.out.println("Input: " + arrayToString(test7));
        System.out.println(
            actual7 + " | " + expected7 + " | " + (pass7 ? "PASS" : "FAIL")
        );
        if (pass7) passed++;
        else failed++;
        System.out.println();

        // Test Case 8: 1's at indices [0,3,6], raw distance = 6, multiply by 2 = 12
        totalTests++;
        int[] test8 = { 1, 2, 3, 1, 4, 5, 1 };
        int expected8 = 12;
        int actual8 = solution.minimumDistance(test8);
        boolean pass8 = (actual8 == expected8);
        System.out.println(
            "Test Case 8: 1's at indices [0,3,6], final distance = 12"
        );
        System.out.println("Input: " + arrayToString(test8));
        System.out.println(
            actual8 + " | " + expected8 + " | " + (pass8 ? "PASS" : "FAIL")
        );
        if (pass8) passed++;
        else failed++;
        System.out.println();

        // Test Case 9: 2's at indices [0, 2, 3], raw distance = 3, multiply by 2 = 6
        totalTests++;
        int[] test9 = { 2, 1, 2, 2 };
        int expected9 = 6;
        int actual9 = solution.minimumDistance(test9);
        boolean pass9 = (actual9 == expected9);
        System.out.println(
            "Test Case 9: 2's at indices [0, 2, 3], final distance = 6"
        );
        System.out.println("Input: " + arrayToString(test9));
        System.out.println(
            actual9 + " | " + expected9 + " | " + (pass9 ? "PASS" : "FAIL")
        );
        if (pass9) passed++;
        else failed++;
        System.out.println();

        // Print summary
        System.out.println(
            "================================================================================"
        );
        System.out.println(
            String.format(
                "Results: %d passed, %d failed out of %d tests",
                passed,
                failed,
                totalTests
            )
        );
        System.out.println(
            "================================================================================"
        );
    }

    /**
     * Converts an integer array to a readable string format.
     *
     * @param arr The array to convert
     * @return String representation of the array
     */
    static String arrayToString(int[] arr) {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < arr.length; i++) {
            sb.append(arr[i]);
            if (i < arr.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}
