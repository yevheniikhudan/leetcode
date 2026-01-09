// Solution class for logic
class Solution {
    public int maxDotProduct(int[] A, int[] B) {
        int n = A.length, m = B.length;
        int[][] dp = new int[n][m];
        int res = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = A[i] * B[j];
                dp[i][j] = val;

                if (i > 0 && j > 0) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + val);
                }

                if (i > 0)
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                if (j > 0)
                    dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);

                res = Math.max(res, dp[i][j]);
            }
        }
        return res;
    }
}

// Main/test class
public class MaxDotProductOfTwoSubsequences {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][][] tests = {
                { { 2, 1, -2, 5 }, { 3, 0, -6 }, { 18 } },
                { { 3, -2 }, { 2, -6, 7 }, { 21 } },
                { { -1, -1 }, { 1, 1 }, { -1 } },
                { { 1 }, { 1 }, { 1 } },
                { { -5 }, { -2 }, { 10 } },
                { { 1, 2, 3 }, { -1, -2, -3 }, { -1 } },
        };
        for (int i = 0; i < tests.length; ++i) {
            int[] nums1 = tests[i][0];
            int[] nums2 = tests[i][1];
            int expected = tests[i][2][0];
            int result = sol.maxDotProduct(nums1, nums2);
            System.out.println("Test " + (i + 1) + ": " + result + " | " + expected);
        }
    }
}
