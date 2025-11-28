/*
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the
container contains the most water.

Return the maximum amount of water a container can store.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int max_area = 0;

        int left = 0, right = height.size() - 1;

        while (left < right) {
            max_area = max(max_area, (right - left) * min(height[left], height[right]));

            if (height[left] < height[right]) {
                left += 1;
            } else {
                right -= 1;
            }
        }

        return max_area;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result1 = solution.maxArea(height1);
    cout << "Test 1: " << result1 << " (expected: 49)\n";

    // Test case 2: Example 2
    vector<int> height2 = {1, 1};
    int result2 = solution.maxArea(height2);
    cout << "Test 2: " << result2 << " (expected: 1)\n";

    // Test case 3: Increasing heights
    vector<int> height3 = {1, 2, 3, 4, 5};
    int result3 = solution.maxArea(height3);
    cout << "Test 3: " << result3 << " (expected: 6)\n";

    // Test case 4: Decreasing heights
    vector<int> height4 = {5, 4, 3, 2, 1};
    int result4 = solution.maxArea(height4);
    cout << "Test 4: " << result4 << " (expected: 6)\n";

    // Test case 5: All same height
    vector<int> height5 = {3, 3, 3, 3};
    int result5 = solution.maxArea(height5);
    cout << "Test 5: " << result5 << " (expected: 9)\n";

    // Test case 6: Two tall lines far apart
    vector<int> height6 = {10, 1, 1, 1, 1, 1, 1, 1, 1, 10};
    int result6 = solution.maxArea(height6);
    cout << "Test 6: " << result6 << " (expected: 90)\n";

    // Test case 7: Peak in middle
    vector<int> height7 = {1, 3, 5, 4, 2};
    int result7 = solution.maxArea(height7);
    cout << "Test 7: " << result7 << " (expected: 6)\n";
}

int main() {
    runTests();
    return 0;
}
