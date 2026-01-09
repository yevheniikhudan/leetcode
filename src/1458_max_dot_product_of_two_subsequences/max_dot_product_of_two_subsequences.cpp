#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = nums1[i] * nums2[j];
                dp[i][j] = val;
                if (i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + val);
                if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    struct Test {
        vector<int> nums1;
        vector<int> nums2;
        int expected;
    } tests[] = {
        {{2, 1, -2, 5}, {3, 0, -6}, 18},
        {{3, -2}, {2, -6, 7}, 21},
        {{-1, -1}, {1, 1}, -1},
        {{1}, {1}, 1},
        {{-5}, {-2}, 10},
        {{1, 2, 3}, {-1, -2, -3}, -1},
    };
    for (int i = 0; i < 6; ++i) {
        int result = sol.maxDotProduct(tests[i].nums1, tests[i].nums2);
        cout << "Test " << (i + 1) << ": " << result << " | " << tests[i].expected << endl;
    }
    return 0;
}
