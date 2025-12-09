/*
121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock
on the ith day. You want to maximize your profit by choosing a single day to
buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find maximum profit from single buy and sell transaction.
     *
     * @param prices Array of stock prices by day
     * @return Maximum profit achievable
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_price = INT_MAX;

        for (int price : prices) {
            min_price = min(min_price, price);
            res = max(res, price - min_price);
        }

        return res;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    int result1 = solution.maxProfit(prices1);
    cout << "Test 1: " << result1 << " (expected: 5)\n";

    // Test case 2: Example 2 - prices decreasing
    vector<int> prices2 = {7, 6, 4, 3, 1};
    int result2 = solution.maxProfit(prices2);
    cout << "Test 2: " << result2 << " (expected: 0)\n";

    // Test case 3: Single element
    vector<int> prices3 = {5};
    int result3 = solution.maxProfit(prices3);
    cout << "Test 3: " << result3 << " (expected: 0)\n";

    // Test case 4: Prices increasing
    vector<int> prices4 = {1, 2, 3, 4, 5};
    int result4 = solution.maxProfit(prices4);
    cout << "Test 4: " << result4 << " (expected: 4)\n";

    // Test case 5: All same price
    vector<int> prices5 = {3, 3, 3, 3};
    int result5 = solution.maxProfit(prices5);
    cout << "Test 5: " << result5 << " (expected: 0)\n";

    // Test case 6: Two elements
    vector<int> prices6 = {2, 4};
    int result6 = solution.maxProfit(prices6);
    cout << "Test 6: " << result6 << " (expected: 2)\n";

    // Test case 7: Buy at end
    vector<int> prices7 = {3, 2, 6, 5, 0, 3};
    int result7 = solution.maxProfit(prices7);
    cout << "Test 7: " << result7 << " (expected: 4)\n";

    // Test case 8: Large dataset simulation
    vector<int> prices8 = {2, 1, 4, 5, 2, 9, 7};
    int result8 = solution.maxProfit(prices8);
    cout << "Test 8: " << result8 << " (expected: 8)\n";
}

int main() {
    runTests();
    return 0;
}
