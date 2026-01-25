class Solution {
    public int countSubstrings(String s) {
        int res = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            res += helper(s, i, i); // Odd length
            res += helper(s, i, i + 1); // Even length
        }

        return res;
    }

    private int helper(String s, int left, int right) {
        int res = 0;

        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            res++;
            left--;
            right++;
        }

        return res;
    }
}

public class PalindromicSubstrings {
    public static void main(String[] args) {
        testCountSubstrings();
    }

    // Test helper
    public static void testCountSubstrings() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        String s1 = "abc";
        int expected1 = 3;
        int actual1 = solution.countSubstrings(s1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        String s2 = "aaa";
        int expected2 = 6;
        int actual2 = solution.countSubstrings(s2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Single character
        String s3 = "a";
        int expected3 = 1;
        int actual3 = solution.countSubstrings(s3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: Two same characters
        String s4 = "aa";
        int expected4 = 3; // "a", "a", "aa"
        int actual4 = solution.countSubstrings(s4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Mixed
        String s5 = "aba";
        int expected5 = 4; // "a", "b", "a", "aba"
        int actual5 = solution.countSubstrings(s5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: All different
        String s6 = "abcd";
        int expected6 = 4;
        int actual6 = solution.countSubstrings(s6);
        System.out.println(actual6 + " | " + expected6);
    }
}
