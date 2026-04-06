class Solution {

    public boolean isSubsequence(String s, String t) {
        int i = 0,
            j = 0;

        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
            }
            j++;
        }
        return i == s.length();
    }
}

public class IsSubsequence {

    public static void main(String[] args) {
        testSolution();
    }

    public static void testSolution() {
        Solution solution = new Solution();

        // Test Case 1: Basic subsequence
        String s1 = "abc";
        String t1 = "ahbgdc";
        boolean result1 = solution.isSubsequence(s1, t1);
        boolean expected1 = true;
        System.out.println(
            result1 +
                " | " +
                expected1 +
                " | " +
                (result1 == expected1 ? "PASS" : "FAIL")
        );

        // Test Case 2: Not a subsequence
        String s2 = "axc";
        String t2 = "ahbgdc";
        boolean result2 = solution.isSubsequence(s2, t2);
        boolean expected2 = false;
        System.out.println(
            result2 +
                " | " +
                expected2 +
                " | " +
                (result2 == expected2 ? "PASS" : "FAIL")
        );

        // Test Case 3: Empty s
        String s3 = "";
        String t3 = "ahbgdc";
        boolean result3 = solution.isSubsequence(s3, t3);
        boolean expected3 = true;
        System.out.println(
            result3 +
                " | " +
                expected3 +
                " | " +
                (result3 == expected3 ? "PASS" : "FAIL")
        );

        // Test Case 4: Empty t with non-empty s
        String s4 = "a";
        String t4 = "";
        boolean result4 = solution.isSubsequence(s4, t4);
        boolean expected4 = false;
        System.out.println(
            result4 +
                " | " +
                expected4 +
                " | " +
                (result4 == expected4 ? "PASS" : "FAIL")
        );

        // Test Case 5: Identical strings
        String s5 = "abc";
        String t5 = "abc";
        boolean result5 = solution.isSubsequence(s5, t5);
        boolean expected5 = true;
        System.out.println(
            result5 +
                " | " +
                expected5 +
                " | " +
                (result5 == expected5 ? "PASS" : "FAIL")
        );

        // Test Case 6: s longer than t
        String s6 = "abcd";
        String t6 = "abc";
        boolean result6 = solution.isSubsequence(s6, t6);
        boolean expected6 = false;
        System.out.println(
            result6 +
                " | " +
                expected6 +
                " | " +
                (result6 == expected6 ? "PASS" : "FAIL")
        );
    }
}
