/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width
of each bar is 1, compute how much water it can trap after raining.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Calculate trapped rainwater using two pointers.
     *
     * @param height Array representing elevation map
     * @return Total units of trapped water
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, max_left = 0, max_right = 0, res = 0;

        while (left < right) {
            int h_l = height[left], h_r = height[right];

            if (h_l < h_r) {
                max_left = max(max_left, h_l);
                res += max_left - h_l;
                left += 1;
            } else {
                max_right = max(max_right, h_r);
                res += max_right - h_r;
                right -= 1;
            }
        }

        return res;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result1 = solution.trap(height1);
    cout << "Test 1: " << result1 << " (expected: 6)\n";

    // Test case 2: Example 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    int result2 = solution.trap(height2);
    cout << "Test 2: " << result2 << " (expected: 9)\n";

    // Test case 3: No water trapped (flat)
    vector<int> height3 = {3, 3, 3, 3};
    int result3 = solution.trap(height3);
    cout << "Test 3: " << result3 << " (expected: 0)\n";

    // Test case 4: No water trapped (increasing)
    vector<int> height4 = {1, 2, 3, 4, 5};
    int result4 = solution.trap(height4);
    cout << "Test 4: " << result4 << " (expected: 0)\n";

    // Test case 5: No water trapped (decreasing)
    vector<int> height5 = {5, 4, 3, 2, 1};
    int result5 = solution.trap(height5);
    cout << "Test 5: " << result5 << " (expected: 0)\n";

    // Test case 6: Simple valley
    vector<int> height6 = {3, 0, 2};
    int result6 = solution.trap(height6);
    cout << "Test 6: " << result6 << " (expected: 2)\n";

    // Test case 7: Multiple valleys
    vector<int> height7 = {3, 0, 2, 0, 4};
    int result7 = solution.trap(height7);
    cout << "Test 7: " << result7 << " (expected: 7)\n";

    // Test case 8: Two elements
    vector<int> height8 = {2, 1};
    int result8 = solution.trap(height8);
    cout << "Test 8: " << result8 << " (expected: 0)\n";
}

int main() {
    runTests();
    return 0;
}
