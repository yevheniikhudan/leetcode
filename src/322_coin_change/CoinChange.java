import java.util.Arrays;

class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int coin : coins) {
            for (int a = 1; a < dp.length; a++) {
                int remainder = a - coin;
                if (remainder >= 0) {
                    if (dp[remainder] != Integer.MAX_VALUE) {
                        dp[a] = Math.min(dp[a], 1 + dp[remainder]);
                    }
                }
            }
        }

        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }
}

public class CoinChange {
    public static void main(String[] args) {
        testCoinChange();
    }

    public static void testCoinChange() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int[] coins1 = { 1, 2, 5 };
        int amount1 = 11;
        int expected1 = 3;
        int actual1 = solution.coinChange(coins1, amount1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int[] coins2 = { 2 };
        int amount2 = 3;
        int expected2 = -1;
        int actual2 = solution.coinChange(coins2, amount2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Example 3
        int[] coins3 = { 1 };
        int amount3 = 0;
        int expected3 = 0;
        int actual3 = solution.coinChange(coins3, amount3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: Possible with multiple coins
        int[] coins4 = { 1, 3, 4 };
        int amount4 = 6;
        int expected4 = 2; // 3 + 3
        int actual4 = solution.coinChange(coins4, amount4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Impossible
        int[] coins5 = { 5 };
        int amount5 = 3;
        int expected5 = -1;
        int actual5 = solution.coinChange(coins5, amount5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: Large amount
        int[] coins6 = { 1, 2, 5 };
        int amount6 = 100;
        int expected6 = 20; // 20 fives
        int actual6 = solution.coinChange(coins6, amount6);
        System.out.println(actual6 + " | " + expected6);
    }
}
