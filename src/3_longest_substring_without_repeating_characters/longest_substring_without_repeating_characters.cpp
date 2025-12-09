/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate
characters.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    /**
     * Find the length of the longest substring without repeating characters.
     *
     * @param s Input string
     * @return Length of longest substring with unique characters
     *
     * Time Complexity: O(n)
     * Space Complexity: O(min(n, m)) where m is charset size
     */
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> seen;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            if (seen.count(ch)) {
                left = max(left, seen[ch] + 1);
            }

            res = max(res, right - left + 1);
            seen[ch] = right;
        }

        return res;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    string s1 = "abcabcbb";
    int result1 = solution.lengthOfLongestSubstring(s1);
    cout << "Test 1: " << result1 << " (expected: 3)\n";

    // Test case 2: Example 2 - all same characters
    string s2 = "bbbbb";
    int result2 = solution.lengthOfLongestSubstring(s2);
    cout << "Test 2: " << result2 << " (expected: 1)\n";

    // Test case 3: Example 3
    string s3 = "pwwkew";
    int result3 = solution.lengthOfLongestSubstring(s3);
    cout << "Test 3: " << result3 << " (expected: 3)\n";

    // Test case 4: Empty string
    string s4 = "";
    int result4 = solution.lengthOfLongestSubstring(s4);
    cout << "Test 4: " << result4 << " (expected: 0)\n";

    // Test case 5: All unique characters
    string s5 = "abcdef";
    int result5 = solution.lengthOfLongestSubstring(s5);
    cout << "Test 5: " << result5 << " (expected: 6)\n";

    // Test case 6: Single character
    string s6 = "a";
    int result6 = solution.lengthOfLongestSubstring(s6);
    cout << "Test 6: " << result6 << " (expected: 1)\n";

    // Test case 7: With spaces and special characters
    string s7 = "a b!c";
    int result7 = solution.lengthOfLongestSubstring(s7);
    cout << "Test 7: " << result7 << " (expected: 5)\n";

    // Test case 8: Duplicate at start and end
    string s8 = "dvdf";
    int result8 = solution.lengthOfLongestSubstring(s8);
    cout << "Test 8: " << result8 << " (expected: 3)\n";

    // Test case 9: Two characters alternating
    string s9 = "au";
    int result9 = solution.lengthOfLongestSubstring(s9);
    cout << "Test 9: " << result9 << " (expected: 2)\n";

    // Test case 10: Complex case
    string s10 = "tmmzuxt";
    int result10 = solution.lengthOfLongestSubstring(s10);
    cout << "Test 10: " << result10 << " (expected: 5)\n";
}

int main() {
    runTests();
    return 0;
}
