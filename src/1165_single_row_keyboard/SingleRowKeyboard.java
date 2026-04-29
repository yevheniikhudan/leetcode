import java.util.*;

class Solution {

    public int calculateTime(String keyboard, String word) {
        Map<Character, Integer> indices = new HashMap<>();
        for (int i = 0; i < keyboard.length(); i++) {
            indices.put(keyboard.charAt(i), i);
        }

        int ans = indices.get(word.charAt(0));
        for (int i = 1; i < word.length(); i++) {
            ans += Math.abs(
                indices.get(word.charAt(i - 1)) - indices.get(word.charAt(i))
            );
        }
        return ans;
    }
}

public class SingleRowKeyboard {

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        String keyboard1 = "abcdefghijklmnopqrstuvwxyz";
        String word1 = "cba";
        int result1 = solution.calculateTime(keyboard1, word1);
        int expected1 = 4;
        System.out.println(
            result1 +
                " | " +
                expected1 +
                " | " +
                (result1 == expected1 ? "PASS" : "FAIL")
        );

        // Test case 2
        String keyboard2 = "pqrstuvwxyzabcdefghijklmno";
        String word2 = "leetcode";
        int result2 = solution.calculateTime(keyboard2, word2);
        int expected2 = 73;
        System.out.println(
            result2 +
                " | " +
                expected2 +
                " | " +
                (result2 == expected2 ? "PASS" : "FAIL")
        );

        // Test case 3
        String keyboard3 = "abcdefghijklmnopqrstuvwxyz";
        String word3 = "abc";
        int result3 = solution.calculateTime(keyboard3, word3);
        int expected3 = 2;
        System.out.println(
            result3 +
                " | " +
                expected3 +
                " | " +
                (result3 == expected3 ? "PASS" : "FAIL")
        );

        // Test case 4
        String keyboard4 = "abcdefghijklmnopqrstuvwxyz";
        String word4 = "a";
        int result4 = solution.calculateTime(keyboard4, word4);
        int expected4 = 0;
        System.out.println(
            result4 +
                " | " +
                expected4 +
                " | " +
                (result4 == expected4 ? "PASS" : "FAIL")
        );

        // Test case 5
        String keyboard5 = "zyxwvutsrqponmlkjihgfedcba";
        String word5 = "z";
        int result5 = solution.calculateTime(keyboard5, word5);
        int expected5 = 25;
        System.out.println(
            result5 +
                " | " +
                expected5 +
                " | " +
                (result5 == expected5 ? "PASS" : "FAIL")
        );
    }
}
