#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        long long hold = LLONG_MIN;
        int sold = 0;
        int rest = 0;

        for (int price : prices) {
            int prevSold = sold;
            sold = hold + price;
            hold = max(hold, (long long)rest - price);
            rest = max(rest, prevSold);
        }

        return max(sold, rest);
    }
};

// Helper function to run test case
void runTestCase(const vector<int>& prices, int expected) {
    Solution solution;
    vector<int> pricesCopy = prices;  // Copy to avoid modifying original
    int actual = solution.maxProfit(pricesCopy);
    cout << actual << " | " << expected << endl;
}

int main() {
    // Test case 1
    runTestCase({1, 2, 3, 0, 2}, 3);

    // Test case 2
    runTestCase({1}, 0);

    // Test case 3
    runTestCase({1, 2}, 1);

    // Test case 4
    runTestCase({2, 1}, 0);

    // Test case 5
    runTestCase({1, 2, 4}, 3);

    // Test case 6
    runTestCase({1, 3, 2, 4}, 4);

    return 0;
}
