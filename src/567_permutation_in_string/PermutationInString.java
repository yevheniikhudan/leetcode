/*
567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, 
or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
*/

import java.util.Arrays;

public class PermutationInString {
    /**
     * Check if s2 contains a permutation of s1.
     * 
     * @param s1 Pattern string to find permutation of
     * @param s2 String to search in
     * @return True if s2 contains a permutation of s1
     * 
     *         Time Complexity: O(n + m) where n = s2.length(), m = s1.length()
     *         Space Complexity: O(1) - at most 26 letters
     */
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        int[] countS1 = new int[26];
        int[] countS2 = new int[26];

        for (int i = 0; i < s1.length(); i++) {
            countS1[s1.charAt(i) - 'a']++;
        }

        for (int i = 0; i < s1.length(); i++) {
            countS2[s2.charAt(i) - 'a']++;
        }

        if (Arrays.compare(countS1, countS2) == 0) {
            return true;
        }

        for (int i = s1.length(); i < s2.length(); i++) {
            countS2[s2.charAt(i) - 'a']++;
            countS2[s2.charAt(i - s1.length()) - 'a']--;

            if (Arrays.compare(countS1, countS2) == 0) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        PermutationInString solution = new PermutationInString();

        // Test case 1: Example 1
        boolean result1 = solution.checkInclusion("ab", "eidbaooo");
        System.out.printf("Test 1: %b (expected: true)%n", result1);

        // Test case 2: Example 2
        boolean result2 = solution.checkInclusion("ab", "eidboaoo");
        System.out.printf("Test 2: %b (expected: false)%n", result2);

        // Test case 3: s1 longer than s2
        boolean result3 = solution.checkInclusion("hello", "hi");
        System.out.printf("Test 3: %b (expected: false)%n", result3);

        // Test case 4: Exact match
        boolean result4 = solution.checkInclusion("ab", "ab");
        System.out.printf("Test 4: %b (expected: true)%n", result4);

        // Test case 5: Permutation at start
        boolean result5 = solution.checkInclusion("abc", "baxyzabc");
        System.out.printf("Test 5: %b (expected: true)%n", result5);

        // Test case 6: Permutation at end
        boolean result6 = solution.checkInclusion("abc", "xyzabc");
        System.out.printf("Test 6: %b (expected: true)%n", result6);

        // Test case 7: No permutation
        boolean result7 = solution.checkInclusion("abc", "xyz");
        System.out.printf("Test 7: %b (expected: false)%n", result7);

        // Test case 8: Duplicate characters
        boolean result8 = solution.checkInclusion("aab", "cbaebabacd");
        System.out.printf("Test 8: %b (expected: true)%n", result8);

        // Test case 9: Single character
        boolean result9 = solution.checkInclusion("a", "ab");
        System.out.printf("Test 9: %b (expected: true)%n", result9);

        // Test case 10: All same characters
        boolean result10 = solution.checkInclusion("aa", "aaa");
        System.out.printf("Test 10: %b (expected: true)%n", result10);
    }
}
