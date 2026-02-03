#include <iostream>
#include <string>

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        unordered_map<string, bool> dp;

        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
            if (k == s3.length()) {
                return i == s1.length() && j == s2.length();
            }
            string key = to_string(i) + "," + to_string(j);
            if (dp.count(key)) {
                return dp[key];
            }

            bool res = false;
            if (i < s1.length() && s1[i] == s3[k]) {
                res = dfs(i + 1, j, k + 1);
            }
            if (!res && j < s2.length() && s2[j] == s3[k]) {
                res = dfs(i, j + 1, k + 1);
            }

            dp[key] = res;
            return res;
        };

        return dfs(0, 0, 0);
    }
};

int main() {
    Solution sol;
    // Test case 1: Example 1
    std::cout << (sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") ? "true" : "false") << " | true"
              << std::endl;
    // Test case 2: Example 2
    std::cout << (sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") ? "true" : "false") << " | false"
              << std::endl;
    // Test case 3: Example 3
    std::cout << (sol.isInterleave("", "", "") ? "true" : "false") << " | true" << std::endl;
    // Test case 4: One empty
    std::cout << (sol.isInterleave("a", "", "a") ? "true" : "false") << " | true" << std::endl;
    // Test case 5: No match
    std::cout << (sol.isInterleave("a", "b", "ab") ? "true" : "false") << " | true" << std::endl;
    // Test case 6: Length mismatch
    std::cout << (sol.isInterleave("a", "b", "abc") ? "true" : "false") << " | false" << std::endl;
    return 0;
}
