/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate 
characters.
*/

import java.util.HashMap;
import java.util.Map;

public class LongestSubstringWithoutRepeatingCharacters {
    /**
     * Find the length of the longest substring without repeating characters.
     * 
     * @param s Input string
     * @return Length of longest substring with unique characters
     * 
     *         Time Complexity: O(n)
     *         Space Complexity: O(min(n, m)) where m is charset size
     */
    public int lengthOfLongestSubstring(String s) {
        int res = 0;
        Map<Character, Integer> seen = new HashMap<>();
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            if (seen.containsKey(ch)) {
                left = Math.max(seen.get(ch) + 1, left);
            }

            seen.put(ch, right);
            res = Math.max(res, right - left + 1);
        }

        return res;
    }

    public static void main(String[] args) {
        LongestSubstringWithoutRepeatingCharacters solution = new LongestSubstringWithoutRepeatingCharacters();

        // Test case 1: Example 1
        String s1 = "abcabcbb";
        int result1 = solution.lengthOfLongestSubstring(s1);
        System.out.printf("Test 1: %d (expected: 3)%n", result1);

        // Test case 2: Example 2 - all same characters
        String s2 = "bbbbb";
        int result2 = solution.lengthOfLongestSubstring(s2);
        System.out.printf("Test 2: %d (expected: 1)%n", result2);

        // Test case 3: Example 3
        String s3 = "pwwkew";
        int result3 = solution.lengthOfLongestSubstring(s3);
        System.out.printf("Test 3: %d (expected: 3)%n", result3);

        // Test case 4: Empty string
        String s4 = "";
        int result4 = solution.lengthOfLongestSubstring(s4);
        System.out.printf("Test 4: %d (expected: 0)%n", result4);

        // Test case 5: All unique characters
        String s5 = "abcdef";
        int result5 = solution.lengthOfLongestSubstring(s5);
        System.out.printf("Test 5: %d (expected: 6)%n", result5);

        // Test case 6: Single character
        String s6 = "a";
        int result6 = solution.lengthOfLongestSubstring(s6);
        System.out.printf("Test 6: %d (expected: 1)%n", result6);

        // Test case 7: With spaces and special characters
        String s7 = "a b!c";
        int result7 = solution.lengthOfLongestSubstring(s7);
        System.out.printf("Test 7: %d (expected: 5)%n", result7);

        // Test case 8: Duplicate at start and end
        String s8 = "dvdf";
        int result8 = solution.lengthOfLongestSubstring(s8);
        System.out.printf("Test 8: %d (expected: 3)%n", result8);

        // Test case 9: Two characters alternating
        String s9 = "au";
        int result9 = solution.lengthOfLongestSubstring(s9);
        System.out.printf("Test 9: %d (expected: 2)%n", result9);

        // Test case 10: Complex case
        String s10 = "tmmzuxt";
        int result10 = solution.lengthOfLongestSubstring(s10);
        System.out.printf("Test 10: %d (expected: 5)%n", result10);
    }
}
