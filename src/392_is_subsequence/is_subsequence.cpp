#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0,
            j = 0;

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.length();
    }
};

void testSolution() {
    Solution solution;

    // Test Case 1: Basic subsequence
    string s1 = "abc";
    string t1 = "ahbgdc";
    bool result1 = solution.isSubsequence(s1, t1);
    bool expected1 = true;
    cout << result1 << " | " << expected1 << " | " << (result1 == expected1 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Not a subsequence
    string s2 = "axc";
    string t2 = "ahbgdc";
    bool result2 = solution.isSubsequence(s2, t2);
    bool expected2 = false;
    cout << result2 << " | " << expected2 << " | " << (result2 == expected2 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Empty s
    string s3 = "";
    string t3 = "ahbgdc";
    bool result3 = solution.isSubsequence(s3, t3);
    bool expected3 = true;
    cout << result3 << " | " << expected3 << " | " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Empty t with non-empty s
    string s4 = "a";
    string t4 = "";
    bool result4 = solution.isSubsequence(s4, t4);
    bool expected4 = false;
    cout << result4 << " | " << expected4 << " | " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Identical strings
    string s5 = "abc";
    string t5 = "abc";
    bool result5 = solution.isSubsequence(s5, t5);
    bool expected5 = true;
    cout << result5 << " | " << expected5 << " | " << (result5 == expected5 ? "PASS" : "FAIL") << endl;

    // Test Case 6: s longer than t
    string s6 = "abcd";
    string t6 = "abc";
    bool result6 = solution.isSubsequence(s6, t6);
    bool expected6 = false;
    cout << result6 << " | " << expected6 << " | " << (result6 == expected6 ? "PASS" : "FAIL") << endl;
}

int main() {
    testSolution();
    return 0;
}
