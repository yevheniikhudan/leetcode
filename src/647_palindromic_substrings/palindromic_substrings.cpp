#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            res += helper(s, i, i);      // Odd length
            res += helper(s, i, i + 1);  // Even length
        }

        return res;
    }

   private:
    int helper(const string& s, int left, int right) {
        int res = 0;

        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            res++;
            left--;
            right++;
        }

        return res;
    }
};

// Test helper
void testCountSubstrings() {
    Solution solution;

    // Test case 1: Example 1
    string s1 = "abc";
    int expected1 = 3;
    int actual1 = solution.countSubstrings(s1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    string s2 = "aaa";
    int expected2 = 6;
    int actual2 = solution.countSubstrings(s2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: Single character
    string s3 = "a";
    int expected3 = 1;
    int actual3 = solution.countSubstrings(s3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: Two same characters
    string s4 = "aa";
    int expected4 = 3;  // "a", "a", "aa"
    int actual4 = solution.countSubstrings(s4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: Mixed
    string s5 = "aba";
    int expected5 = 4;  // "a", "b", "a", "aba"
    int actual5 = solution.countSubstrings(s5);
    cout << actual5 << " | " << expected5 << endl;

    // Test case 6: All different
    string s6 = "abcd";
    int expected6 = 4;
    int actual6 = solution.countSubstrings(s6);
    cout << actual6 << " | " << expected6 << endl;
}

int main() {
    testCountSubstrings();
    return 0;
}
