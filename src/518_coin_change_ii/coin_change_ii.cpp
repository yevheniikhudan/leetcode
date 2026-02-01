#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j < amount + 1; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];
    }
};

// Helper function to run test case
void runTestCase(int amount, const vector<int>& coins, int expected) {
    Solution solution;
    vector<int> coinsCopy = coins;  // Copy to avoid modifying original
    int actual = solution.change(amount, coinsCopy);
    cout << actual << " | " << expected << endl;
}

int main() {
    // Test case 1
    runTestCase(5, {1, 2, 5}, 4);

    // Test case 2
    runTestCase(3, {2}, 0);

    // Test case 3
    runTestCase(10, {10}, 1);

    // Test case 4
    runTestCase(0, {1}, 1);

    // Test case 5
    runTestCase(1, {}, 0);

    // Test case 6
    runTestCase(2, {1, 2}, 2);

    return 0;
}
