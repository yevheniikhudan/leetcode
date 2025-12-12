/*
875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the i-th pile has
piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses
some pile of bananas and eats k bananas from that pile. If the pile has less
than k bananas, she eats all of them instead and will not eat any more bananas
during this hour.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find minimum eating speed to finish all bananas within h hours.
     *
     * @param piles Vector of banana pile sizes
     * @param h Hours available
     * @return Minimum eating speed k
     *
     * Time Complexity: O(n log m) where n = piles.size(), m = max(piles)
     * Space Complexity: O(1) - only constant extra space
     */
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            long long total = 0;
            for (int pile : piles) {
                total += (pile + mid - 1) / mid;
            }

            if (total <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> piles1 = {3, 6, 7, 11};
    int result1 = solution.minEatingSpeed(piles1, 8);
    cout << "Test 1: " << result1 << " (expected: 4)\n";

    // Test case 2: Example 2 - must eat one pile per hour
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int result2 = solution.minEatingSpeed(piles2, 5);
    cout << "Test 2: " << result2 << " (expected: 30)\n";

    // Test case 3: Example 3
    vector<int> piles3 = {30, 11, 23, 4, 20};
    int result3 = solution.minEatingSpeed(piles3, 6);
    cout << "Test 3: " << result3 << " (expected: 23)\n";

    // Test case 4: Single pile
    vector<int> piles4 = {1000000000};
    int result4 = solution.minEatingSpeed(piles4, 2);
    cout << "Test 4: " << result4 << " (expected: 500000000)\n";

    // Test case 5: Many hours available
    vector<int> piles5 = {3, 6, 7, 11};
    int result5 = solution.minEatingSpeed(piles5, 100);
    cout << "Test 5: " << result5 << " (expected: 1)\n";

    // Test case 6: Exact hours match piles
    vector<int> piles6 = {5, 10, 15, 20};
    int result6 = solution.minEatingSpeed(piles6, 4);
    cout << "Test 6: " << result6 << " (expected: 20)\n";

    // Test case 7: All same size piles
    vector<int> piles7 = {10, 10, 10, 10};
    int result7 = solution.minEatingSpeed(piles7, 10);
    cout << "Test 7: " << result7 << " (expected: 5)\n";

    // Test case 8: Small piles, exact hours match piles
    vector<int> piles8 = {1, 1, 1, 1};
    int result8 = solution.minEatingSpeed(piles8, 4);
    cout << "Test 8: " << result8 << " (expected: 1)\n";
}

int main() {
    runTests();
    return 0;
}
