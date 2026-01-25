class Solution {
    public String longestPalindrome(String s) {
        if (s.isEmpty()) {
            return "";
        }

        int n = s.length();
        int[] indices = { 0, 0 };

        for (int i = 0; i < n; i++) {
            expand(s, n, i, i, indices); // Odd length
            expand(s, n, i, i + 1, indices); // Even length
        }

        return s.substring(indices[0], indices[1] + 1);
    }

    private void expand(String s, int n, int left, int right, int[] indices) {
        while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }

        left++;
        right--;

        if (right - left + 1 > indices[1] - indices[0] + 1) {
            indices[0] = left;
            indices[1] = right;
        }
    }
}

public class LongestPalindromicSubstring {
    public static void main(String[] args) {
        testLongestPalindrome();
    }

    // Test helper
    public static void testLongestPalindrome() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        String s1 = "babad";
        String expected1 = "bab"; // or "aba"
        String actual1 = solution.longestPalindrome(s1);
        System.out.println("\"" + actual1 + "\" | \"" + expected1 + "\"");

        // Test case 2: Example 2
        String s2 = "cbbd";
        String expected2 = "bb";
        String actual2 = solution.longestPalindrome(s2);
        System.out.println("\"" + actual2 + "\" | \"" + expected2 + "\"");

        // Test case 3: Single character
        String s3 = "a";
        String expected3 = "a";
        String actual3 = solution.longestPalindrome(s3);
        System.out.println("\"" + actual3 + "\" | \"" + expected3 + "\"");

        // Test case 4: All same characters
        String s4 = "aaa";
        String expected4 = "aaa";
        String actual4 = solution.longestPalindrome(s4);
        System.out.println("\"" + actual4 + "\" | \"" + expected4 + "\"");

        // Test case 5: No palindrome longer than 1
        String s5 = "abc";
        String expected5 = "a"; // or "b" or "c"
        String actual5 = solution.longestPalindrome(s5);
        System.out.println("\"" + actual5 + "\" | \"" + expected5 + "\"");

        // Test case 6: Even length
        String s6 = "abba";
        String expected6 = "abba";
        String actual6 = solution.longestPalindrome(s6);
        System.out.println("\"" + actual6 + "\" | \"" + expected6 + "\"");
    }
}
