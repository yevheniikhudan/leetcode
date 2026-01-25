class Solution {
    public int numDecodings(String s) {
        int dpI = 1, dpIMinus1 = 1, dpIMinus2 = 1;

        for (int i = 1; i <= s.length(); i++) {
            dpI = (s.charAt(i - 1) == '0') ? 0 : dpIMinus1;

            if (i >= 2 && Integer.parseInt(s.substring(i - 2, i)) >= 10
                    && Integer.parseInt(s.substring(i - 2, i)) <= 26) {
                dpI += dpIMinus2;
            }

            dpIMinus2 = dpIMinus1;
            dpIMinus1 = dpI;
        }

        return dpI;
    }
}

public class DecodeWays {
    public static void main(String[] args) {
        testNumDecodings();
    }

    // Test helper
    public static void testNumDecodings() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        String s1 = "12";
        int expected1 = 2;
        int actual1 = solution.numDecodings(s1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        String s2 = "226";
        int expected2 = 3;
        int actual2 = solution.numDecodings(s2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Example 3
        String s3 = "06";
        int expected3 = 0;
        int actual3 = solution.numDecodings(s3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: Single digit
        String s4 = "1";
        int expected4 = 1;
        int actual4 = solution.numDecodings(s4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Leading zero
        String s5 = "10";
        int expected5 = 1;
        int actual5 = solution.numDecodings(s5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: Invalid
        String s6 = "00";
        int expected6 = 0;
        int actual6 = solution.numDecodings(s6);
        System.out.println(actual6 + " | " + expected6);
    }
}
