import java.util.*;

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        return false;
    }
}

public class WordBreak {
    public static void main(String[] args) {
        testWordBreak();
    }

    public static void testWordBreak() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        String s1 = "leetcode";
        List<String> wordDict1 = Arrays.asList("leet", "code");
        boolean expected1 = true;
        boolean actual1 = solution.wordBreak(s1, wordDict1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        String s2 = "applepenapple";
        List<String> wordDict2 = Arrays.asList("apple", "pen");
        boolean expected2 = true;
        boolean actual2 = solution.wordBreak(s2, wordDict2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Example 3
        String s3 = "catsandog";
        List<String> wordDict3 = Arrays.asList("cats", "dog", "sand", "and", "cat");
        boolean expected3 = false;
        boolean actual3 = solution.wordBreak(s3, wordDict3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: Single word
        String s4 = "a";
        List<String> wordDict4 = Arrays.asList("a");
        boolean expected4 = true;
        boolean actual4 = solution.wordBreak(s4, wordDict4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: No match
        String s5 = "abc";
        List<String> wordDict5 = Arrays.asList("d", "e");
        boolean expected5 = false;
        boolean actual5 = solution.wordBreak(s5, wordDict5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: Reuse words
        String s6 = "aaaa";
        List<String> wordDict6 = Arrays.asList("a", "aa");
        boolean expected6 = true;
        boolean actual6 = solution.wordBreak(s6, wordDict6);
        System.out.println(actual6 + " | " + expected6);
    }
}
