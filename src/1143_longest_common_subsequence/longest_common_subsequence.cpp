#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        // swap to reduce space
        if (text1.size() < text2.size()) {
            string temp = text1;
            text1 = text2;
            text2 = temp;
        }

        int n = text1.size();
        int m = text2.size();

        vector<int> dp(m + 1, 0);

        for (int i = 0; i < n; i++) {
            vector<int> nextRow(m + 1, 0);
            for (int j = 0; j < m; j++) {
                if (text1[i] == text2[j]) {
                    nextRow[j + 1] = 1 + dp[j];
                } else {
                    nextRow[j + 1] = max(nextRow[j], dp[j + 1]);
                }
            }

            dp = nextRow;
        }

        return dp[m];
    }
};

// Helper function to run test case
void runTestCase(const string& text1, const string& text2, int expected) {
    Solution solution;
    int actual = solution.longestCommonSubsequence(text1, text2);
    cout << actual << " | " << expected << endl;
}

int main() {
    // Test case 1
    runTestCase("abcde", "ace", 3);

    // Test case 2
    runTestCase("abc", "abc", 3);

    // Test case 3
    runTestCase("abc", "def", 0);

    // Test case 4
    runTestCase("", "a", 0);

    // Test case 5
    runTestCase("a", "a", 1);

    // Test case 6
    runTestCase("abcd", "acbd", 3);

    return 0;
}
