/*
424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of
the string and change it to any other uppercase English character. You can
perform this operation at most k times.

Return the length of the longest substring containing the same letter you can
get after performing the above operations.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    /**
     * Find the length of the longest substring with same characters after
     * at most k replacements.
     *
     * @param s String of uppercase English letters
     * @param k Maximum number of replacements allowed
     * @return Length of longest substring with repeating characters
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1) - at most 26 letters
     */
    int characterReplacement(string s, int k) {
        int res = 0;
        int max_frequency = 0;
        unordered_map<char, int> counts;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            counts[s[right]]++;
            max_frequency = max(max_frequency, counts[s[right]]);

            while ((right - left + 1) - max_frequency > k) {
                counts[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    string s1 = "ABAB";
    int result1 = solution.characterReplacement(s1, 2);
    cout << "Test 1: " << result1 << " (expected: 4)\n";

    // Test case 2: Example 2
    string s2 = "AABABBA";
    int result2 = solution.characterReplacement(s2, 1);
    cout << "Test 2: " << result2 << " (expected: 4)\n";

    // Test case 3: No replacements needed - all same
    string s3 = "AAAA";
    int result3 = solution.characterReplacement(s3, 0);
    cout << "Test 3: " << result3 << " (expected: 4)\n";

    // Test case 4: Single character
    string s4 = "A";
    int result4 = solution.characterReplacement(s4, 1);
    cout << "Test 4: " << result4 << " (expected: 1)\n";

    // Test case 5: Can replace entire string
    string s5 = "ABCD";
    int result5 = solution.characterReplacement(s5, 3);
    cout << "Test 5: " << result5 << " (expected: 4)\n";

    // Test case 6: No replacements allowed
    string s6 = "ABAB";
    int result6 = solution.characterReplacement(s6, 0);
    cout << "Test 6: " << result6 << " (expected: 1)\n";

    // Test case 7: Longer string with pattern
    string s7 = "AAABBBCCC";
    int result7 = solution.characterReplacement(s7, 2);
    cout << "Test 7: " << result7 << " (expected: 5)\n";

    // Test case 8: Complex case
    string s8 = "ABCDE";
    int result8 = solution.characterReplacement(s8, 1);
    cout << "Test 8: " << result8 << " (expected: 2)\n";
}

int main() {
    runTests();
    return 0;
}
