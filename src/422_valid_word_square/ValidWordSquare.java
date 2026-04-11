import java.util.Arrays;
import java.util.List;

class Solution {

    /**
     * Determine if the given array of strings forms a valid word square.
     *
     * A valid word square means that the k-th row and k-th column
     * read the same string for all k.
     *
     * @param words List of strings to check
     * @return true if valid word square, false otherwise
     */
    public boolean validWordSquare(List<String> words) {
        for (int wordNum = 0; wordNum < words.size(); wordNum++) {
            for (
                int charPos = 0;
                charPos < words.get(wordNum).length();
                charPos++
            ) {
                if (
                    charPos >= words.size() ||
                    wordNum >= words.get(charPos).length() ||
                    words.get(wordNum).charAt(charPos) !=
                    words.get(charPos).charAt(wordNum)
                ) {
                    return false;
                }
            }
        }
        return true;
    }
}

// ============================================================================
// Helper Class for Testing
// ============================================================================

public class ValidWordSquare {

    static void printResult(boolean actual, boolean expected) {
        System.out.println(
            (actual ? "true" : "false") +
                " | " +
                (expected ? "true" : "false") +
                " | " +
                (actual == expected ? "PASS" : "FAIL")
        );
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test Case 1: Valid square with equal length words
        List<String> words1 = Arrays.asList("abcd", "bnrt", "crmy", "dtye");
        boolean result1 = solution.validWordSquare(words1);
        boolean expected1 = true;
        printResult(result1, expected1);

        // Test Case 2: Valid square with unequal length words
        List<String> words2 = Arrays.asList("abcd", "bnrt", "crm", "dt");
        boolean result2 = solution.validWordSquare(words2);
        boolean expected2 = true;
        printResult(result2, expected2);

        // Test Case 3: Invalid square - mismatch in row/column
        List<String> words3 = Arrays.asList("ball", "area", "read", "lady");
        boolean result3 = solution.validWordSquare(words3);
        boolean expected3 = false;
        printResult(result3, expected3);

        // Test Case 4: Single word (always valid)
        List<String> words4 = Arrays.asList("a");
        boolean result4 = solution.validWordSquare(words4);
        boolean expected4 = true;
        printResult(result4, expected4);

        // Test Case 5: Two identical words
        List<String> words5 = Arrays.asList("ab", "ba");
        boolean result5 = solution.validWordSquare(words5);
        boolean expected5 = true;
        printResult(result5, expected5);

        // Test Case 6: Invalid - different characters at symmetric positions
        List<String> words6 = Arrays.asList("abc", "bda", "cec");
        boolean result6 = solution.validWordSquare(words6);
        boolean expected6 = false;
        printResult(result6, expected6);
    }
}
