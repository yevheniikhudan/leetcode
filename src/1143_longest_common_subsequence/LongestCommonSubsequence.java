import java.util.Arrays;

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        // swap to reduce space
        if (text1.length() < text2.length()) {
            String temp = text1;
            text1 = text2;
            text2 = temp;
        }
        int n = text1.length();
        int m = text2.length();

        int[] dp = new int[m + 1];
        Arrays.fill(dp, 0);

        for (int i = 0; i < n; i++) {
            int[] nextRow = new int[m + 1];
            for (int j = 0; j < m; j++) {
                if (text1.charAt(i) == text2.charAt(j)) {
                    nextRow[j + 1] = 1 + dp[j];
                } else {
                    nextRow[j + 1] = Math.max(nextRow[j], dp[j + 1]);
                }
            }

            dp = nextRow;
        }

        return dp[m];
    }
}

class LongestCommonSubsequence {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // Test cases
        testCase(sol, "abcde", "ace", 3);
        testCase(sol, "abc", "abc", 3);
        testCase(sol, "abc", "def", 0);
        testCase(sol, "", "a", 0);
        testCase(sol, "a", "a", 1);
        testCase(sol, "abcd", "acbd", 3);
    }

    private static void testCase(Solution sol, String text1, String text2, int expected) {
        int actual = sol.longestCommonSubsequence(text1, text2);
        System.out.println(actual + " | " + expected);
    }
}
