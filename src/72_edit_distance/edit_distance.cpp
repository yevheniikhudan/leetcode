#include <iostream>
#include <string>

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;
    // Test case 1: Example 1
    std::cout << sol.minDistance("horse", "ros") << " | 3" << std::endl;
    // Test case 2: Example 2
    std::cout << sol.minDistance("intention", "execution") << " | 5" << std::endl;
    // Test case 3: Empty word1
    std::cout << sol.minDistance("", "a") << " | 1" << std::endl;
    // Test case 4: Empty word2
    std::cout << sol.minDistance("a", "") << " | 1" << std::endl;
    // Test case 5: Identical
    std::cout << sol.minDistance("abc", "abc") << " | 0" << std::endl;
    // Test case 6: Single replace
    std::cout << sol.minDistance("a", "b") << " | 1" << std::endl;
    return 0;
}
