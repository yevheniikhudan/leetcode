import java.util.*;

// Solution class for logic
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits == null || digits.length() == 0)
            return res;
        Map<Character, String> numbersToLetters = Map.of(
                '2', "abc",
                '3', "def",
                '4', "ghi",
                '5', "jkl",
                '6', "mno",
                '7', "pqrs",
                '8', "tuv",
                '9', "wxyz");
        backtrack(digits, 0, new StringBuilder(), res, numbersToLetters);
        return res;
    }

    private void backtrack(String digits, int index, StringBuilder sb, List<String> res, Map<Character, String> map) {
        if (sb.length() == digits.length()) {
            res.add(sb.toString());
            return;
        }
        String letters = map.get(digits.charAt(index));
        for (char c : letters.toCharArray()) {
            sb.append(c);
            backtrack(digits, index + 1, sb, res, map);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}

// Main/test class
public class LetterCombinationsOfAPhoneNumber {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Object[][] tests = {
                { "23", Arrays.asList("ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf") },
                { "", Arrays.asList() },
                { "2", Arrays.asList("a", "b", "c") },
                { "7", Arrays.asList("p", "q", "r", "s") },
                { "9", Arrays.asList("w", "x", "y", "z") },
        };
        for (int i = 0; i < tests.length; ++i) {
            String digits = (String) tests[i][0];
            List<String> expected = (List<String>) tests[i][1];
            List<String> result = sol.letterCombinations(digits);
            Collections.sort(result);
            Collections.sort(expected);
            System.out.println("Test " + (i + 1) + ": " + result + " | " + expected);
        }
    }
}
