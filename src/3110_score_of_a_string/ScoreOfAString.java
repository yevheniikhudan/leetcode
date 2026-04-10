class Solution {

    /**
     * Calculate the score of a string as the sum of absolute differences
     * of ASCII values of consecutive characters.
     *
     * @param s A string of lowercase English letters
     * @return The score of the string
     */
    public int scoreOfString(String s) {
        int res = 0;

        for (int i = 1; i < s.length(); i++) {
            res += Math.abs((s.charAt(i) - 'a') - (s.charAt(i - 1) - 'a'));
        }
        return res;
    }
}

public class ScoreOfAString {

    public static void main(String[] args) {
        runTests();
    }

    private static void runTests() {
        Solution solution = new Solution();

        // Test case 1: Basic example with "hello"
        String s1 = "hello";
        int result1 = solution.scoreOfString(s1);
        int expected1 = 13;
        String status1 = (result1 == expected1) ? "PASS" : "FAIL";
        System.out.println(result1 + " | " + expected1 + " | " + status1);

        // Test case 2: All identical characters
        String s2 = "aaaa";
        int result2 = solution.scoreOfString(s2);
        int expected2 = 0;
        String status2 = (result2 == expected2) ? "PASS" : "FAIL";
        System.out.println(result2 + " | " + expected2 + " | " + status2);

        // Test case 3: Two different characters
        String s3 = "ab";
        int result3 = solution.scoreOfString(s3);
        int expected3 = 1;
        String status3 = (result3 == expected3) ? "PASS" : "FAIL";
        System.out.println(result3 + " | " + expected3 + " | " + status3);

        // Test case 4: Ascending sequence
        String s4 = "abc";
        int result4 = solution.scoreOfString(s4);
        int expected4 = 2;
        String status4 = (result4 == expected4) ? "PASS" : "FAIL";
        System.out.println(result4 + " | " + expected4 + " | " + status4);

        // Test case 5: Maximum difference (a to z)
        String s5 = "az";
        int result5 = solution.scoreOfString(s5);
        int expected5 = 25;
        String status5 = (result5 == expected5) ? "PASS" : "FAIL";
        System.out.println(result5 + " | " + expected5 + " | " + status5);

        // Test case 6: Alternating pattern
        String s6 = "aabbcc";
        int result6 = solution.scoreOfString(s6);
        int expected6 = 2;
        String status6 = (result6 == expected6) ? "PASS" : "FAIL";
        System.out.println(result6 + " | " + expected6 + " | " + status6);
    }
}
