/**
 * Problem 58: Length of Last Word
 * Given a string s consisting of words and spaces, return the length of the last word.
 */

class Solution {

    /**
     * Find the length of the last word in a string.
     *
     * A word is a maximal substring consisting of non-space characters only.
     *
     * @param s A string consisting of words and spaces (1 <= s.length <= 10^4)
     * @return The length of the last word in the string
     */
    public int lengthOfLastWord(String s) {
        int right = s.length() - 1;
        while (s.charAt(right) == ' ') right--;
        int left = right;
        while (left > 0 && s.charAt(left) != ' ') left--;
        if (s.charAt(left) == ' ') left++;

        return right - left + 1;
    }
}

/**
 * Helper class for testing lengthOfLastWord solution
 */
public class LengthOfLastWord {

    /**
     * Helper method to run a single test case
     */
    private static void testCase(
        Solution solution,
        String input,
        int expected
    ) {
        int result = solution.lengthOfLastWord(input);
        String status = result == expected ? "PASS" : "FAIL";
        System.out.println(result + " | " + expected + " | " + status);
    }

    /**
     * Main function with test cases
     */
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Basic example with two words
        // Input: "Hello World", Expected: 5
        testCase(solution, "Hello World", 5);

        // Test case 2: String with leading and trailing spaces
        // Input: "   fly me   to   the moon  ", Expected: 4
        testCase(solution, "   fly me   to   the moon  ", 4);

        // Test case 3: Multiple words with consistent spacing
        // Input: "luffy is still joyboy", Expected: 6
        testCase(solution, "luffy is still joyboy", 6);

        // Test case 4: Single character
        // Input: "a", Expected: 1
        testCase(solution, "a", 1);

        // Test case 5: Single word with trailing spaces
        // Input: "hello   ", Expected: 5
        testCase(solution, "hello   ", 5);

        // Test case 6: Single word with leading spaces
        // Input: "    hello", Expected: 5
        testCase(solution, "    hello", 5);

        // Test case 7: Multiple consecutive spaces between words
        // Input: "a  b  c", Expected: 1
        testCase(solution, "a  b  c", 1);

        // Test case 8: Word with spaces around it
        // Input: "  world  ", Expected: 5
        testCase(solution, "  world  ", 5);
    }
}
