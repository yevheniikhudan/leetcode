import java.util.*;

public class LongestIdealSubsequence {
    public int longestIdealString(String s, int k) {
        int[] dp = new int[26];
        int result = 0;
        for (char ch : s.toCharArray()) {
            int curr = ch - 'a';
            int maxLen = 0;
            for (int prev = 0; prev < 26; prev++) {
                if (Math.abs(curr - prev) <= k) {
                    maxLen = Math.max(maxLen, dp[prev]);
                }
            }
            dp[curr] = maxLen + 1;
            result = Math.max(result, dp[curr]);
        }

        return result;
    }

    // Test scaffolding
    public static void main(String[] args) {
        LongestIdealSubsequence sol = new LongestIdealSubsequence();
        System.out.println(sol.longestIdealString("acfgbd", 2) + " | 4");
        System.out.println(sol.longestIdealString("abcd", 3) + " | 4");
        System.out.println(sol.longestIdealString("abcde", 0) + " | 1");
        System.out.println(sol.longestIdealString("a", 25) + " | 1");
        System.out.println(sol.longestIdealString("azazaz", 25) + " | 6");
    }
}
