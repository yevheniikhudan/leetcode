import java.util.*;

class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] counts = new int[26];
        for (char c : chars.toCharArray()) {
            counts[c - 'a']++;
        }
        int result = 0;
        for (String word : words) {
            int[] wordCounts = new int[26];
            for (char c : word.toCharArray()) {
                wordCounts[c - 'a']++;
            }
            boolean canForm = true;
            for (int i = 0; i < 26; i++) {
                if (wordCounts[i] > counts[i]) {
                    canForm = false;
                    break;
                }
            }
            if (canForm) {
                result += word.length();
            }
        }
        return result;
    }
}

public class FindWordsThatCanBeFormedByCharacters {
    public static void main(String[] args) {
        testCountCharacters();
    }

    public static void testCountCharacters() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        String[] words1 = { "cat", "bt", "hat", "tree" };
        String chars1 = "atach";
        int expected1 = 6;
        int actual1 = solution.countCharacters(words1, chars1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        String[] words2 = { "hello", "world", "leetcode" };
        String chars2 = "welldonehoneyr";
        int expected2 = 10;
        int actual2 = solution.countCharacters(words2, chars2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: No good words
        String[] words3 = { "abc", "def" };
        String chars3 = "xyz";
        int expected3 = 0;
        int actual3 = solution.countCharacters(words3, chars3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: All words good
        String[] words4 = { "a", "b" };
        String chars4 = "ab";
        int expected4 = 2;
        int actual4 = solution.countCharacters(words4, chars4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Words with duplicates
        String[] words5 = { "aa", "bb" };
        String chars5 = "aab";
        int expected5 = 2;
        int actual5 = solution.countCharacters(words5, chars5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: Single word
        String[] words6 = { "test" };
        String chars6 = "tset";
        int expected6 = 4;
        int actual6 = solution.countCharacters(words6, chars6);
        System.out.println(actual6 + " | " + expected6);
    }
}
