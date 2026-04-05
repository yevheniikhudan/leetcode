import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

    public int[] countBits(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i / 2] + (i % 2);
        }

        return dp;
    }
}

public class CountingBits {

    private static void printResult(int[] actual, int[] expected) {
        String actualStr = Arrays.toString(actual);
        String expectedStr = Arrays.toString(expected);
        String status = Arrays.equals(actual, expected) ? "PASS" : "FAIL";
        System.out.println(actualStr + " | " + expectedStr + " | " + status);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        // Test cases: {input n, expected output array}
        List<int[]> testCases = new ArrayList<>();
        testCases.add(new int[] { 2, 0, 1, 1 });
        testCases.add(new int[] { 5, 0, 1, 1, 2, 1, 2 });
        testCases.add(new int[] { 0, 0 });
        testCases.add(new int[] { 1, 0, 1 });
        testCases.add(new int[] { 10, 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2 });

        for (int i = 0; i < testCases.size(); i++) {
            int[] tc = testCases.get(i);
            int n = tc[0];
            int[] expected = Arrays.copyOfRange(tc, 1, tc.length); // Extract expected array
            int[] actual = sol.countBits(n);
            printResult(actual, expected);
        }
    }
}
