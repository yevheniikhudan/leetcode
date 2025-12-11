/*
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height
where the width of each bar is 1, return the area of the largest rectangle
in the histogram.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find the largest rectangle area in a histogram.
     *
     * @param heights Vector of bar heights
     * @return Maximum rectangle area
     *
     * Time Complexity: O(n) where n = heights.size()
     * Space Complexity: O(n) for the stack
     */
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        int n = heights.size();
        stack<int> stk;

        for (int i = 0; i < n + 1; i++) {
            while (!stk.empty() && (i == n || heights[stk.top()] > heights[i])) {
                int stackIndex = stk.top();
                int height = heights[stackIndex];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                result = max(result, height * width);
            }
            stk.push(i);
        }

        return result;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    int result1 = solution.largestRectangleArea(heights1);
    cout << "Test 1: " << result1 << " (expected: 10)\n";

    // Test case 2: Example 2
    vector<int> heights2 = {2, 4};
    int result2 = solution.largestRectangleArea(heights2);
    cout << "Test 2: " << result2 << " (expected: 4)\n";

    // Test case 3: Single bar
    vector<int> heights3 = {5};
    int result3 = solution.largestRectangleArea(heights3);
    cout << "Test 3: " << result3 << " (expected: 5)\n";

    // Test case 4: Increasing heights
    vector<int> heights4 = {1, 2, 3, 4, 5};
    int result4 = solution.largestRectangleArea(heights4);
    cout << "Test 4: " << result4 << " (expected: 9)\n";

    // Test case 5: Decreasing heights
    vector<int> heights5 = {5, 4, 3, 2, 1};
    int result5 = solution.largestRectangleArea(heights5);
    cout << "Test 5: " << result5 << " (expected: 9)\n";

    // Test case 6: All same height
    vector<int> heights6 = {3, 3, 3, 3};
    int result6 = solution.largestRectangleArea(heights6);
    cout << "Test 6: " << result6 << " (expected: 12)\n";

    // Test case 7: With zeros
    vector<int> heights7 = {2, 0, 2};
    int result7 = solution.largestRectangleArea(heights7);
    cout << "Test 7: " << result7 << " (expected: 2)\n";

    // Test case 8: Large rectangle in middle
    vector<int> heights8 = {1, 2, 3, 4, 5, 3, 3, 2};
    int result8 = solution.largestRectangleArea(heights8);
    cout << "Test 8: " << result8 << " (expected: 15)\n";
}

int main() {
    runTests();
    return 0;
}
