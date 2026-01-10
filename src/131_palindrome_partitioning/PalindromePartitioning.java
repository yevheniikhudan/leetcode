import java.util.*;

// Solution class for logic
class Solution {
    List<List<String>> result;
    List<String> part;
    String s;

    public List<List<String>> partition(String s) {
        this.result = new ArrayList<>();
        this.part = new LinkedList<>();
        this.s = s;

        dfs(0);

        return result;
    }

    private void dfs(int start) {
        if (start == s.length()) {
            result.add(new ArrayList<>(part));
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(start, end)) {
                part.add(s.substring(start, end + 1));
                dfs(end + 1);
                part.removeLast();
            }
        }
    }

    private boolean isPalindrome(int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right))
                return false;

            left += 1;
            right -= 1;
        }
        return true;
    }
}

// Main/test class
public class PalindromePartitioning {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Object[][] tests = {
                { "aab", Arrays.asList(Arrays.asList("a", "a", "b"), Arrays.asList("aa", "b")) },
                { "a", Arrays.asList(Arrays.asList("a")) },
                { "racecar", Arrays.asList(
                        Arrays.asList("r", "a", "c", "e", "c", "a", "r"),
                        Arrays.asList("r", "a", "cec", "a", "r"),
                        Arrays.asList("r", "aceca", "r"),
                        Arrays.asList("racecar")) },
                { "abba", Arrays.asList(
                        Arrays.asList("a", "b", "b", "a"),
                        Arrays.asList("a", "bb", "a"),
                        Arrays.asList("abba")) },
                { "abc", Arrays.asList(Arrays.asList("a", "b", "c")) },
        };
        for (int i = 0; i < tests.length; ++i) {
            String s = (String) tests[i][0];
            List<List<String>> expected = (List<List<String>>) tests[i][1];
            List<List<String>> result = sol.partition(s);
            System.out.println("Test " + (i + 1) + ": " + result + " | " + expected);
        }
    }
}
