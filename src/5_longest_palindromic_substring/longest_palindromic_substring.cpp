#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int n = s.length();
        vector<int> indices = {0, 0};

        for (int i = 0; i < n; i++) {
            expand(s, n, i, i, indices);      // Odd length
            expand(s, n, i, i + 1, indices);  // Even length
        }

        return s.substr(indices[0], indices[1] - indices[0] + 1);
    }

   private:
    void expand(const string& s, int n, int left, int right, vector<int>& indices) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }

        left++;
        right--;

        if (right - left + 1 > indices[1] - indices[0] + 1) {
            indices[0] = left;
            indices[1] = right;
        }
    }
};

// Test helper
void testLongestPalindrome() {
    Solution solution;

    // Test case 1: Example 1
    string s1 = "babad";
    string expected1 = "bab";  // or "aba"
    string actual1 = solution.longestPalindrome(s1);
    cout << "\"" << actual1 << "\" | \"" << expected1 << "\"" << endl;

    // Test case 2: Example 2
    string s2 = "cbbd";
    string expected2 = "bb";
    string actual2 = solution.longestPalindrome(s2);
    cout << "\"" << actual2 << "\" | \"" << expected2 << "\"" << endl;

    // Test case 3: Single character
    string s3 = "a";
    string expected3 = "a";
    string actual3 = solution.longestPalindrome(s3);
    cout << "\"" << actual3 << "\" | \"" << expected3 << "\"" << endl;

    // Test case 4: All same characters
    string s4 = "aaa";
    string expected4 = "aaa";
    string actual4 = solution.longestPalindrome(s4);
    cout << "\"" << actual4 << "\" | \"" << expected4 << "\"" << endl;

    // Test case 5: No palindrome longer than 1
    string s5 = "abc";
    string expected5 = "a";  // or "b" or "c"
    string actual5 = solution.longestPalindrome(s5);
    cout << "\"" << actual5 << "\" | \"" << expected5 << "\"" << endl;

    // Test case 6: Even length
    string s6 = "abba";
    string expected6 = "abba";
    string actual6 = solution.longestPalindrome(s6);
    cout << "\"" << actual6 << "\" | \"" << expected6 << "\"" << endl;
}

int main() {
    testLongestPalindrome();
    return 0;
}
