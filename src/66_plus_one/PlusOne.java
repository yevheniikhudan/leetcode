import java.util.Arrays;

class Solution {

    public int[] plusOne(int[] digits) {
        int n = digits.length;

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        int[] newNumber = new int[n + 1];
        newNumber[0] = 1;
        return newNumber;
    }
}

public class PlusOne {

    public static void main(String[] args) {
        Solution sol = new Solution();

        int[][] inputs = {
            { 1, 2, 3 },
            { 4, 3, 2, 1 },
            { 9 },
            { 9, 9 },
            { 0 },
        };

        int[][] expected = {
            { 1, 2, 4 },
            { 4, 3, 2, 2 },
            { 1, 0 },
            { 1, 0, 0 },
            { 1 },
        };

        for (int i = 0; i < inputs.length; i++) {
            int[] actual = sol.plusOne(inputs[i]);
            String actualStr = (actual == null)
                ? "null"
                : Arrays.toString(actual);
            String expectedStr = Arrays.toString(expected[i]);
            boolean pass =
                (actual != null) && Arrays.equals(actual, expected[i]);
            System.out.println(
                actualStr +
                    " | " +
                    expectedStr +
                    " | " +
                    (pass ? "PASS" : "FAIL")
            );
        }
    }
}
