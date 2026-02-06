import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numDistinct(String s, String t) {
        int n = s.length();
        int m = t.length();

        if (m > n) {
            return 0;
        }

        Map<String, Integer> memo = new HashMap<>();

        return dfs(0, 0, s, t, memo, n, m);
    }

    private int dfs(int i, int j, String s, String t, Map<String, Integer> memo, int n, int m) {
        if (j == m) {
            return 1;
        }
        if (i == n) {
            return 0;
        }
        String key = i + "," + j;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        int res = dfs(i + 1, j, s, t, memo, n, m);
        if (s.charAt(i) == t.charAt(j)) {
            res += dfs(i + 1, j + 1, s, t, memo, n, m);
        }

        memo.put(key, res);
        return res;
    }
}

public class DistinctSubsequences {
    public static void main(String[] args) {
        Solution sol = new Solution();
        // Test case 1: Example 1
        System.out.println(sol.numDistinct("rabbbit", "rabbit") + " | 3");
        // Test case 2: Example 2
        System.out.println(sol.numDistinct("babgbag", "bag") + " | 5");
        // Test case 3: t empty
        System.out.println(sol.numDistinct("a", "") + " | 1");
        // Test case 4: s empty
        System.out.println(sol.numDistinct("", "a") + " | 0");
        // Test case 5: Exact match
        System.out.println(sol.numDistinct("abc", "abc") + " | 1");
        // Test case 6: Multiple ways
        System.out.println(sol.numDistinct("aaa", "aa") + " | 3");
    }
}
