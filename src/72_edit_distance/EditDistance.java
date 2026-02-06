class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j - 1], Math.min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }

        return dp[m][n];
    }
}

public class EditDistance {
    public static void main(String[] args) {
        Solution sol = new Solution();
        // Test case 1: Example 1
        System.out.println(sol.minDistance("horse", "ros") + " | 3");
        // Test case 2: Example 2
        System.out.println(sol.minDistance("intention", "execution") + " | 5");
        // Test case 3: Empty word1
        System.out.println(sol.minDistance("", "a") + " | 1");
        // Test case 4: Empty word2
        System.out.println(sol.minDistance("a", "") + " | 1");
        // Test case 5: Identical
        System.out.println(sol.minDistance("abc", "abc") + " | 0");
        // Test case 6: Single replace
        System.out.println(sol.minDistance("a", "b") + " | 1");
    }
}
