#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        /*
        Find the minimum number of characters to append to s
        to make t a subsequence of s.

        Args:
            s: The original string
            t: The target string that should be a subsequence

        Returns:
            The number of characters to append
        */
        int sPointer = 0,
            tPointer = 0;

        while (sPointer < s.length() && tPointer < t.length()) {
            if (s[sPointer] == t[tPointer]) {
                tPointer++;
            }

            sPointer++;
        }
        return t.length() - tPointer;
    }
};


// Test cases
void runTests() {
    Solution solution;

    // Test case 1: Basic example
    string s1 = "coaching";
    string t1 = "coding";
    int result1 = solution.appendCharacters(s1, t1);
    int expected1 = 4;
    cout << result1 << " | " << expected1 << " | " << (result1 == expected1 ? "PASS" : "FAIL") << "\n";

    // Test case 2: t is already subsequence
    string s2 = "abcde";
    string t2 = "a";
    int result2 = solution.appendCharacters(s2, t2);
    int expected2 = 0;
    cout << result2 << " | " << expected2 << " | " << (result2 == expected2 ? "PASS" : "FAIL") << "\n";

    // Test case 3: s and t don't match
    string s3 = "z";
    string t3 = "abcde";
    int result3 = solution.appendCharacters(s3, t3);
    int expected3 = 5;
    cout << result3 << " | " << expected3 << " | " << (result3 == expected3 ? "PASS" : "FAIL") << "\n";

    // Test case 4: t is already complete subsequence
    string s4 = "aabbcc";
    string t4 = "abc";
    int result4 = solution.appendCharacters(s4, t4);
    int expected4 = 0;
    cout << result4 << " | " << expected4 << " | " << (result4 == expected4 ? "PASS" : "FAIL") << "\n";

    // Test case 5: Partial match
    string s5 = "abc";
    string t5 = "abcd";
    int result5 = solution.appendCharacters(s5, t5);
    int expected5 = 1;
    cout << result5 << " | " << expected5 << " | " << (result5 == expected5 ? "PASS" : "FAIL") << "\n";

    // Test case 6: Single character match
    string s6 = "a";
    string t6 = "aa";
    int result6 = solution.appendCharacters(s6, t6);
    int expected6 = 1;
    cout << result6 << " | " << expected6 << " | " << (result6 == expected6 ? "PASS" : "FAIL") << "\n";
}

int main() {
    runTests();
    return 0;
}
