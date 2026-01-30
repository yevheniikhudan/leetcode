#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 0; i < m; i++) {
            for (int col = 1; col <= n; col++) {
                dp[col] = dp[col] + dp[col - 1];
            }
        }

        return dp[n];
    }
};

// Helper function to run test case
void runTestCase(int m, int n, int expected) {
    Solution solution;
    int actual = solution.uniquePaths(m, n);
    cout << actual << " | " << expected << endl;
}

int main() {
    // Test case 1
    runTestCase(3, 7, 28);

    // Test case 2
    runTestCase(3, 2, 3);

    // Test case 3
    runTestCase(1, 1, 1);

    // Test case 4
    runTestCase(1, 10, 1);

    // Test case 5
    runTestCase(10, 1, 1);

    // Test case 6
    runTestCase(2, 2, 2);

    return 0;
}
