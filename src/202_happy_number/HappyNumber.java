import java.util.Arrays;
import java.util.List;
import java.util.Objects;

/**
 * Java skeleton for LeetCode 202. Happy Number
 *
 * Conventions:
 * - `Solution` contains the algorithm signature only (no implementation).
 * - `HappyNumber` contains `main` and test scaffolding.
 *
 * The algorithm method intentionally returns `null` to indicate "not implemented".
 * Tests print output in the format: actual | expected | PASS/FAIL
 */

class Solution {

    /**
     * Determine if a number is "happy".
     *
     * Signature only — no implementation provided in the skeleton.
     *
     * @param n input number (may be null)
     * @return Boolean result or null if unimplemented
     */
    public Boolean isHappy(Integer n) {
        int slow = n,
            fast = n;

        while (true) {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));

            if (slow == 1 || fast == 1) {
                return true;
            }
            if (slow == fast) {
                return false;
            }
        }
    }

    private int sumOfSquares(int n) {
        int res = 0;
        while (n > 0) {
            int digit = n % 10;
            res += digit * digit;
            n /= 10;
        }

        return res;
    }
}

public class HappyNumber {

    private static class TestCase {

        final Integer input;
        final Boolean expected;

        TestCase(Integer input, Boolean expected) {
            this.input = input;
            this.expected = expected;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        List<TestCase> tests = Arrays.asList(
            new TestCase(19, true),
            new TestCase(2, false),
            new TestCase(1, true),
            new TestCase(7, true),
            new TestCase(116, false),
            new TestCase(1999999999, false) // large value example
        );

        for (TestCase tc : tests) {
            Boolean actual = solution.isHappy(tc.input);
            String status = Objects.equals(actual, tc.expected)
                ? "PASS"
                : "FAIL";
            System.out.println(
                String.valueOf(actual) +
                    " | " +
                    String.valueOf(tc.expected) +
                    " | " +
                    status
            );
        }
    }
}
