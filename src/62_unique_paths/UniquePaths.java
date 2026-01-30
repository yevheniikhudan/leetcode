class Solution {
    public int uniquePaths(int m, int n) {
        int[] dp = new int[n + 1];
        dp[1] = 1;

        for (int i = 0; i < m; i++) {
            for (int col = 1; col <= n; col++) {
                dp[col] = dp[col] + dp[col - 1];
            }
        }

        return dp[n];
    }
}

class UniquePaths {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // Test cases
        testCase(sol, 3, 7, 28);
        testCase(sol, 3, 2, 3);
        testCase(sol, 1, 1, 1);
        testCase(sol, 1, 10, 1);
        testCase(sol, 10, 1, 1);
        testCase(sol, 2, 2, 2);
    }

    private static void testCase(Solution sol, int m, int n, int expected) {
        int actual = sol.uniquePaths(m, n);
        System.out.println(actual + " | " + expected);
    }
}
