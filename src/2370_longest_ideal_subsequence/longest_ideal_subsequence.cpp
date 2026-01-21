#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        for (char ch : s) {
            int curr = ch - 'a';
            int maxLen = 0;
            for (int prev = 0; prev < 26; ++prev) {
                if (abs(curr - prev) <= k) {
                    maxLen = max(maxLen, dp[prev]);
                }
            }
            dp[curr] = maxLen + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// Test scaffolding
void test() {
    Solution sol;
    cout << sol.longestIdealString("acfgbd", 2) << " | 4\n";
    cout << sol.longestIdealString("abcd", 3) << " | 4\n";
    cout << sol.longestIdealString("abcde", 0) << " | 1\n";
    cout << sol.longestIdealString("a", 25) << " | 1\n";
    cout << sol.longestIdealString("azazaz", 25) << " | 6\n";
}

int main() {
    test();
    return 0;
}
