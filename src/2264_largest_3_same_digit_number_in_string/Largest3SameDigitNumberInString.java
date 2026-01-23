class Solution {
    public String largestGoodInteger(String num) {
        char maxDigit = '\0';

        for (int i = 2; i < num.length(); i++) {
            if (num.charAt(i - 2) == num.charAt(i - 1) && num.charAt(i - 1) == num.charAt(i)) {
                maxDigit = (char) Math.max(maxDigit, num.charAt(i));
            }
        }

        return maxDigit == '\0' ? "" : String.valueOf(maxDigit).repeat(3);
    }
}

public class Largest3SameDigitNumberInString {
    public static void main(String[] args) {
        testLargestGoodInteger();
    }

    public static void testLargestGoodInteger() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        String num1 = "6777133339";
        String expected1 = "777";
        String actual1 = solution.largestGoodInteger(num1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        String num2 = "2300019";
        String expected2 = "000";
        String actual2 = solution.largestGoodInteger(num2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Example 3
        String num3 = "42352338";
        String expected3 = "";
        String actual3 = solution.largestGoodInteger(num3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: All same
        String num4 = "111";
        String expected4 = "111";
        String actual4 = solution.largestGoodInteger(num4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Multiple, choose largest
        String num5 = "999888";
        String expected5 = "999";
        String actual5 = solution.largestGoodInteger(num5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: No good
        String num6 = "123456";
        String expected6 = "";
        String actual6 = solution.largestGoodInteger(num6);
        System.out.println(actual6 + " | " + expected6);
    }
}
