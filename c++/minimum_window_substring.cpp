/*
76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum
window substring of s such that every character in t (including duplicates) is
included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/

#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find the minimum window substring of s that contains all characters from t.
     *
     * @param s Source string to search in
     * @param t Target string with characters to find
     * @return Minimum window substring, or "" if no such substring exists
     *
     * Time Complexity: O(m + n) where m = s.length(), n = t.length()
     * Space Complexity: O(k) where k = unique characters in t
     */
    string minWindow(string s, string t) {
        unordered_map<char, int> dictS;
        unordered_map<char, int> dictT;

        for (char ch : t) {
            dictT[ch]++;
        }
        int required = dictT.size();

        int left = 0;
        int min_len = INT_MAX;
        int min_index = 0;
        int matched = 0;

        for (int right = 0; right < s.size(); right++) {
            char right_char = s[right];
            dictS[right_char]++;

            if (dictT.count(right_char) && dictT[right_char] == dictS[right_char]) {
                matched++;
            }

            while (matched == required) {
                char left_char = s[left];

                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_index = left;
                }

                if (dictT.count(left_char) && dictT[left_char] == dictS[left_char]) {
                    matched--;
                }
                dictS[left_char]--;
                left++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_index, min_len);
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    string result1 = solution.minWindow("ADOBECODEBANC", "ABC");
    cout << "Test 1: '" << result1 << "' (expected: 'BANC')\n";

    // Test case 2: Example 2
    string result2 = solution.minWindow("a", "a");
    cout << "Test 2: '" << result2 << "' (expected: 'a')\n";

    // Test case 3: Example 3 - impossible
    string result3 = solution.minWindow("a", "aa");
    cout << "Test 3: '" << result3 << "' (expected: '')\n";

    // Test case 4: t longer than s
    string result4 = solution.minWindow("abc", "abcd");
    cout << "Test 4: '" << result4 << "' (expected: '')\n";

    // Test case 5: Multiple occurrences - need 2 A's
    string result5 = solution.minWindow("ADOBECODEBANC", "AABC");
    cout << "Test 5: '" << result5 << "' (expected: 'ADOBECODEBA')\n";

    // Test case 6: Entire string is minimum
    string result6 = solution.minWindow("abc", "abc");
    cout << "Test 6: '" << result6 << "' (expected: 'abc')\n";

    // Test case 7: Window at beginning
    string result7 = solution.minWindow("cabwefgewcwaefgcf", "cae");
    cout << "Test 7: '" << result7 << "' (expected: 'cwae')\n";

    // Test case 8: Duplicates in t
    string result8 = solution.minWindow("aaaaaaaaaaaabbbbbcdd", "abcdd");
    cout << "Test 8: '" << result8 << "' (expected: 'abbbbbcdd')\n";

    // Test case 9: Case sensitive
    string result9 = solution.minWindow("Aa", "Aa");
    cout << "Test 9: '" << result9 << "' (expected: 'Aa')\n";

    // Test case 10: No common characters
    string result10 = solution.minWindow("abc", "def");
    cout << "Test 10: '" << result10 << "' (expected: '')\n";
}

int main() {
    runTests();
    return 0;
}
