class Solution {

    public int appendCharacters(String s, String t) {
        /*
        Find the minimum number of characters to append to s
        to make t a subsequence of s.

        Args:
            s: The original string
            t: The target string that should be a subsequence

        Returns:
            The number of characters to append
        */
        int sPointer = 0,
            tPointer = 0;

        while (sPointer < s.length() && tPointer < t.length()) {
            if (s.charAt(sPointer) == t.charAt(tPointer)) {
                tPointer++;
            }

            sPointer++;
        }
        return t.length() - tPointer;
    }
}

public class AppendCharactersToStringToMakeSubsequence {

    public static void runTests() {
        Solution solution = new Solution();

        // Test case 1: Basic example
        String s1 = "coaching";
        String t1 = "coding";
        int result1 = solution.appendCharacters(s1, t1);
        int expected1 = 4;
        System.out.println(
            result1 +
                " | " +
                expected1 +
                " | " +
                (result1 == expected1 ? "PASS" : "FAIL")
        );

        // Test case 2: t is already subsequence
        String s2 = "abcde";
        String t2 = "a";
        int result2 = solution.appendCharacters(s2, t2);
        int expected2 = 0;
        System.out.println(
            result2 +
                " | " +
                expected2 +
                " | " +
                (result2 == expected2 ? "PASS" : "FAIL")
        );

        // Test case 3: s and t don't match
        String s3 = "z";
        String t3 = "abcde";
        int result3 = solution.appendCharacters(s3, t3);
        int expected3 = 5;
        System.out.println(
            result3 +
                " | " +
                expected3 +
                " | " +
                (result3 == expected3 ? "PASS" : "FAIL")
        );

        // Test case 4: t is already complete subsequence
        String s4 = "aabbcc";
        String t4 = "abc";
        int result4 = solution.appendCharacters(s4, t4);
        int expected4 = 0;
        System.out.println(
            result4 +
                " | " +
                expected4 +
                " | " +
                (result4 == expected4 ? "PASS" : "FAIL")
        );

        // Test case 5: Partial match
        String s5 = "abc";
        String t5 = "abcd";
        int result5 = solution.appendCharacters(s5, t5);
        int expected5 = 1;
        System.out.println(
            result5 +
                " | " +
                expected5 +
                " | " +
                (result5 == expected5 ? "PASS" : "FAIL")
        );

        // Test case 6: Single character match
        String s6 = "a";
        String t6 = "aa";
        int result6 = solution.appendCharacters(s6, t6);
        int expected6 = 1;
        System.out.println(
            result6 +
                " | " +
                expected6 +
                " | " +
                (result6 == expected6 ? "PASS" : "FAIL")
        );
    }

    public static void main(String[] args) {
        runTests();
    }
}
