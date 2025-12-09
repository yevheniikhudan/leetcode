/*
76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum 
window substring of s such that every character in t (including duplicates) is 
included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/

import java.util.HashMap;
import java.util.Map;

public class MinimumWindowSubstring {
    /**
     * Find the minimum window substring of s that contains all characters from t.
     * 
     * @param s Source string to search in
     * @param t Target string with characters to find
     * @return Minimum window substring, or "" if no such substring exists
     * 
     *         Time Complexity: O(m + n) where m = s.length(), n = t.length()
     *         Space Complexity: O(k) where k = unique characters in t
     */
    public String minWindow(String s, String t) {
        Map<Character, Integer> dictT = new HashMap<>();
        Map<Character, Integer> dictS = new HashMap<>();

        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            dictT.put(ch, dictT.getOrDefault(ch, 0) + 1);
        }
        int required = dictT.size();
        int matched = 0;
        int minLen = Integer.MAX_VALUE;
        int minIndex = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char rightChar = s.charAt(right);
            dictS.put(rightChar, dictS.getOrDefault(rightChar, 0) + 1);

            if (dictT.containsKey(rightChar) && dictT.get(rightChar).equals(dictS.get(rightChar))) {
                matched++;
            }

            while (matched == required) {
                if (right - left + 1 < minLen) {
                    minIndex = left;
                    minLen = right - left + 1;
                }

                char leftChar = s.charAt(left);

                if (dictT.containsKey(leftChar) && dictT.get(rightChar).equals(dictS.get(rightChar))) {
                    matched--;
                }

                dictS.put(leftChar, dictS.get(leftChar) - 1);
                left++;
            }
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(minIndex, minIndex + minLen);
    }

    public static void main(String[] args) {
        MinimumWindowSubstring solution = new MinimumWindowSubstring();

        // Test case 1: Example 1
        String result1 = solution.minWindow("ADOBECODEBANC", "ABC");
        System.out.printf("Test 1: '%s' (expected: 'BANC')%n", result1);

        // Test case 2: Example 2
        String result2 = solution.minWindow("a", "a");
        System.out.printf("Test 2: '%s' (expected: 'a')%n", result2);

        // Test case 3: Example 3 - impossible
        String result3 = solution.minWindow("a", "aa");
        System.out.printf("Test 3: '%s' (expected: '')%n", result3);

        // Test case 4: t longer than s
        String result4 = solution.minWindow("abc", "abcd");
        System.out.printf("Test 4: '%s' (expected: '')%n", result4);

        // Test case 5: Multiple occurrences
        String result5 = solution.minWindow("ADOBECODEBANC", "AABC");
        System.out.printf("Test 5: '%s' (expected: 'ADOBEC')%n", result5);

        // Test case 6: Entire string is minimum
        String result6 = solution.minWindow("abc", "abc");
        System.out.printf("Test 6: '%s' (expected: 'abc')%n", result6);

        // Test case 7: Window at beginning
        String result7 = solution.minWindow("cabwefgewcwaefgcf", "cae");
        System.out.printf("Test 7: '%s' (expected: 'cwae')%n", result7);

        // Test case 8: Duplicates in t
        String result8 = solution.minWindow("aaaaaaaaaaaabbbbbcdd", "abcdd");
        System.out.printf("Test 8: '%s' (expected: 'abbbbbcdd')%n", result8);

        // Test case 9: Case sensitive
        String result9 = solution.minWindow("Aa", "Aa");
        System.out.printf("Test 9: '%s' (expected: 'Aa')%n", result9);

        // Test case 10: No common characters
        String result10 = solution.minWindow("abc", "def");
        System.out.printf("Test 10: '%s' (expected: '')%n", result10);
    }
}
