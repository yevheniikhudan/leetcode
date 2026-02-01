class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j < amount + 1; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
}

class CoinChangeIi {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // Test cases
        testCase(sol, 5, new int[] { 1, 2, 5 }, 4);
        testCase(sol, 3, new int[] { 2 }, 0);
        testCase(sol, 10, new int[] { 10 }, 1);
        testCase(sol, 0, new int[] { 1 }, 1);
        testCase(sol, 1, new int[] {}, 0);
        testCase(sol, 2, new int[] { 1, 2 }, 2);
    }

    private static void testCase(Solution sol, int amount, int[] coins, int expected) {
        int actual = sol.change(amount, coins);
        System.out.println(actual + " | " + expected);
    }
}
