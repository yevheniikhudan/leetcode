/*
424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of 
the string and change it to any other uppercase English character. You can 
perform this operation at most k times.

Return the length of the longest substring containing the same letter you can 
get after performing the above operations.
*/

import java.util.HashMap;
import java.util.Map;

public class LongestRepeatingCharacterReplacement {
    /**
     * Find the length of the longest substring with same characters after
     * at most k replacements.
     * 
     * @param s String of uppercase English letters
     * @param k Maximum number of replacements allowed
     * @return Length of longest substring with repeating characters
     * 
     *         Time Complexity: O(n)
     *         Space Complexity: O(1) - at most 26 letters
     */
    public int characterReplacement(String s, int k) {
        Map<Character, Integer> counts = new HashMap<>();
        int result = 0;
        int maxFrequency = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            counts.put(s.charAt(right), 1 + counts.getOrDefault(s.charAt(right), 0));
            maxFrequency = Math.max(counts.get(s.charAt(right)), maxFrequency);

            while ((right - left + 1) - maxFrequency > k) {
                counts.put(s.charAt(left), counts.get(s.charAt(left)) - 1);
                left++;
            }

            result = Math.max(result, right - left + 1);
        }

        return result;
    }

    public static void main(String[] args) {
        LongestRepeatingCharacterReplacement solution = new LongestRepeatingCharacterReplacement();

        // Test case 1: Example 1
        String s1 = "ABAB";
        int result1 = solution.characterReplacement(s1, 2);
        System.out.printf("Test 1: %d (expected: 4)%n", result1);

        // Test case 2: Example 2
        String s2 = "AABABBA";
        int result2 = solution.characterReplacement(s2, 1);
        System.out.printf("Test 2: %d (expected: 4)%n", result2);

        // Test case 3: No replacements needed - all same
        String s3 = "AAAA";
        int result3 = solution.characterReplacement(s3, 0);
        System.out.printf("Test 3: %d (expected: 4)%n", result3);

        // Test case 4: Single character
        String s4 = "A";
        int result4 = solution.characterReplacement(s4, 1);
        System.out.printf("Test 4: %d (expected: 1)%n", result4);

        // Test case 5: Can replace entire string
        String s5 = "ABCD";
        int result5 = solution.characterReplacement(s5, 3);
        System.out.printf("Test 5: %d (expected: 4)%n", result5);

        // Test case 6: No replacements allowed
        String s6 = "ABAB";
        int result6 = solution.characterReplacement(s6, 0);
        System.out.printf("Test 6: %d (expected: 1)%n", result6);

        // Test case 7: Longer string with pattern
        String s7 = "AAABBBCCC";
        int result7 = solution.characterReplacement(s7, 2);
        System.out.printf("Test 7: %d (expected: 5)%n", result7);

        // Test case 8: Complex case
        String s8 = "ABCDE";
        int result8 = solution.characterReplacement(s8, 1);
        System.out.printf("Test 8: %d (expected: 2)%n", result8);
    }
}
