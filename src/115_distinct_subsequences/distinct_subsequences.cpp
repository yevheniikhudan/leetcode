#include <iostream>
#include <string>

class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (m > n) {
            return 0;
        }

        unordered_map<string, int> memo;

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (j == m) {
                return 1;
            }
            if (i == n) {
                return 0;
            }
            string key = to_string(i) + "," + to_string(j);
            if (memo.count(key)) {
                return memo[key];
            }

            int res = dfs(i + 1, j);
            if (s[i] == t[j]) {
                res += dfs(i + 1, j + 1);
            }

            memo[key] = res;
            return res;
        };

        return dfs(0, 0);
    }
};

int main() {
    Solution sol;
    // Test case 1: Example 1
    std::cout << sol.numDistinct("rabbbit", "rabbit") << " | 3" << std::endl;
    // Test case 2: Example 2
    std::cout << sol.numDistinct("babgbag", "bag") << " | 3" << std::endl;
    // Test case 3: t empty
    std::cout << sol.numDistinct("a", "") << " | 1" << std::endl;
    // Test case 4: s empty
    std::cout << sol.numDistinct("", "a") << " | 0" << std::endl;
    // Test case 5: Exact match
    std::cout << sol.numDistinct("abc", "abc") << " | 1" << std::endl;
    // Test case 6: Multiple ways
    std::cout << sol.numDistinct("aaa", "aa") << " | 3" << std::endl;
    return 0;
}
