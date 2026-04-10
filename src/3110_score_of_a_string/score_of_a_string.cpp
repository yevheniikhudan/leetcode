#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        /**
         * Calculate the score of a string as the sum of absolute differences
         * of ASCII values of consecutive characters.
         *
         * Args:
         *     s: A string of lowercase English letters
         *
         * Returns:
         *     The score of the string
         */
        int res = 0;

        for (int i = 1; i < s.size(); i++) {
            res += abs((s[i] - 'a') - (s[i-1] - 'a'));
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Test case 1: Basic example with "hello"
    string s1 = "hello";
    int result1 = solution.scoreOfString(s1);
    int expected1 = 13;
    cout << result1 << " | " << expected1 << " | " << (result1 == expected1 ? "PASS" : "FAIL") << endl;

    // Test case 2: All identical characters
    string s2 = "aaaa";
    int result2 = solution.scoreOfString(s2);
    int expected2 = 0;
    cout << result2 << " | " << expected2 << " | " << (result2 == expected2 ? "PASS" : "FAIL") << endl;

    // Test case 3: Two different characters
    string s3 = "ab";
    int result3 = solution.scoreOfString(s3);
    int expected3 = 1;
    cout << result3 << " | " << expected3 << " | " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test case 4: Ascending sequence
    string s4 = "abc";
    int result4 = solution.scoreOfString(s4);
    int expected4 = 2;
    cout << result4 << " | " << expected4 << " | " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test case 5: Maximum difference (a to z)
    string s5 = "az";
    int result5 = solution.scoreOfString(s5);
    int expected5 = 25;
    cout << result5 << " | " << expected5 << " | " << (result5 == expected5 ? "PASS" : "FAIL") << endl;

    // Test case 6: Alternating pattern
    string s6 = "aabbcc";
    int result6 = solution.scoreOfString(s6);
    int expected6 = 2;
    cout << result6 << " | " << expected6 << " | " << (result6 == expected6 ? "PASS" : "FAIL") << endl;

    return 0;
}
