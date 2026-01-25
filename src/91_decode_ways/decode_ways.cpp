#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int numDecodings(string s) {
        int dpI = 1, dpIMinus1 = 1, dpIMinus2 = 1;

        for (size_t i = 1; i <= s.length(); i++) {
            dpI = (s[i - 1] == '0') ? 0 : dpIMinus1;

            if (i >= 2) {
                int twoDigit = stoi(s.substr(i - 2, 2));
                if (twoDigit >= 10 && twoDigit <= 26) {
                    dpI += dpIMinus2;
                }
            }

            dpIMinus2 = dpIMinus1;
            dpIMinus1 = dpI;
        }

        return dpI;
    }
};

// Test helper
void testNumDecodings() {
    Solution solution;

    // Test case 1: Example 1
    string s1 = "12";
    int expected1 = 2;
    int actual1 = solution.numDecodings(s1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    string s2 = "226";
    int expected2 = 3;
    int actual2 = solution.numDecodings(s2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: Example 3
    string s3 = "06";
    int expected3 = 0;
    int actual3 = solution.numDecodings(s3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: Single digit
    string s4 = "1";
    int expected4 = 1;
    int actual4 = solution.numDecodings(s4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: Leading zero
    string s5 = "10";
    int expected5 = 1;
    int actual5 = solution.numDecodings(s5);
    cout << actual5 << " | " << expected5 << endl;

    // Test case 6: Invalid
    string s6 = "00";
    int expected6 = 0;
    int actual6 = solution.numDecodings(s6);
    cout << actual6 << " | " << expected6 << endl;
}

int main() {
    testNumDecodings();
    return 0;
}
