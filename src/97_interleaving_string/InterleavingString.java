import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        Map<String, Boolean> dp = new HashMap<>();

        return dfs(0, 0, 0, s1, s2, s3, dp);
    }

    private boolean dfs(int i, int j, int k, String s1, String s2, String s3, Map<String, Boolean> dp) {
        if (k == s3.length()) {
            return i == s1.length() && j == s2.length();
        }
        String key = i + "," + j;
        if (dp.containsKey(key)) {
            return dp.get(key);
        }

        boolean res = false;
        if (i < s1.length() && s1.charAt(i) == s3.charAt(k)) {
            res = dfs(i + 1, j, k + 1, s1, s2, s3, dp);
        }
        if (!res && j < s2.length() && s2.charAt(j) == s3.charAt(k)) {
            res = dfs(i, j + 1, k + 1, s1, s2, s3, dp);
        }

        dp.put(key, res);
        return res;
    }
}

public class InterleavingString {
    public static void main(String[] args) {
        Solution sol = new Solution();
        // Test case 1: Example 1
        System.out.println(sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") + " | true");
        // Test case 2: Example 2
        System.out.println(sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") + " | false");
        // Test case 3: Example 3
        System.out.println(sol.isInterleave("", "", "") + " | true");
        // Test case 4: One empty
        System.out.println(sol.isInterleave("a", "", "a") + " | true");
        // Test case 5: No match
        System.out.println(sol.isInterleave("a", "b", "ab") + " | true");
        // Test case 6: Length mismatch
        System.out.println(sol.isInterleave("a", "b", "abc") + " | false");
    }
}
