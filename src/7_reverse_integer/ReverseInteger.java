class Solution {
    public int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int digit = x % 10;
            x = x / 10;

            if ((result > Integer.MAX_VALUE / 10) || (result < Integer.MIN_VALUE / 10)) {
                return 0;
            }

            result = result * 10 + digit;
        }

        return result;
    }
}

public class ReverseInteger {
    public static void main(String[] args) {
        testReverse();
    }

    public static void testReverse() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int x1 = 123;
        int expected1 = 321;
        int actual1 = solution.reverse(x1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int x2 = -123;
        int expected2 = -321;
        int actual2 = solution.reverse(x2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Example 3
        int x3 = 120;
        int expected3 = 21;
        int actual3 = solution.reverse(x3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: x=0
        int x4 = 0;
        int expected4 = 0;
        int actual4 = solution.reverse(x4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Positive overflow
        int x5 = 1534236469;
        int expected5 = 0;
        int actual5 = solution.reverse(x5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: Negative overflow
        int x6 = -1534236469;
        int expected6 = 0;
        int actual6 = solution.reverse(x6);
        System.out.println(actual6 + " | " + expected6);
    }
}
