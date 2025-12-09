/*
567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1,
or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Check if s2 contains a permutation of s1.
     *
     * @param s1 Pattern string to find permutation of
     * @param s2 String to search in
     * @return True if s2 contains a permutation of s1
     *
     * Time Complexity: O(n + m) where n = s2.length(), m = s1.length()
     * Space Complexity: O(1) - at most 26 letters
     */
    bool checkInclusion(string s1, string s2) {
        array<int, 26> countS1 = {0};
        array<int, 26> countS2 = {0};

        for (char ch : s1) {
            countS1[ch - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++) {
            countS2[s2[i] - 'a']++;
        }

        if (countS1 == countS2) {
            return true;
        }

        for (int i = s1.size(); i < s2.size(); i++) {
            countS2[s2[i] - 'a']++;
            countS2[s2[i - s1.size()] - 'a']--;
            if (countS1 == countS2) {
                return true;
            }
        }

        return false;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    bool result1 = solution.checkInclusion("ab", "eidbaooo");
    cout << "Test 1: " << (result1 ? "true" : "false") << " (expected: true)\n";

    // Test case 2: Example 2
    bool result2 = solution.checkInclusion("ab", "eidboaoo");
    cout << "Test 2: " << (result2 ? "true" : "false") << " (expected: false)\n";

    // Test case 3: s1 longer than s2
    bool result3 = solution.checkInclusion("hello", "hi");
    cout << "Test 3: " << (result3 ? "true" : "false") << " (expected: false)\n";

    // Test case 4: Exact match
    bool result4 = solution.checkInclusion("ab", "ab");
    cout << "Test 4: " << (result4 ? "true" : "false") << " (expected: true)\n";

    // Test case 5: Permutation at start
    bool result5 = solution.checkInclusion("abc", "baxyzabc");
    cout << "Test 5: " << (result5 ? "true" : "false") << " (expected: true)\n";

    // Test case 6: Permutation at end
    bool result6 = solution.checkInclusion("abc", "xyzabc");
    cout << "Test 6: " << (result6 ? "true" : "false") << " (expected: true)\n";

    // Test case 7: No permutation
    bool result7 = solution.checkInclusion("abc", "xyz");
    cout << "Test 7: " << (result7 ? "true" : "false") << " (expected: false)\n";

    // Test case 8: Duplicate characters
    bool result8 = solution.checkInclusion("aab", "cbaebabacd");
    cout << "Test 8: " << (result8 ? "true" : "false") << " (expected: true)\n";

    // Test case 9: Single character
    bool result9 = solution.checkInclusion("a", "ab");
    cout << "Test 9: " << (result9 ? "true" : "false") << " (expected: true)\n";

    // Test case 10: All same characters
    bool result10 = solution.checkInclusion("aa", "aaa");
    cout << "Test 10: " << (result10 ? "true" : "false") << " (expected: true)\n";
}

int main() {
    runTests();
    return 0;
}
