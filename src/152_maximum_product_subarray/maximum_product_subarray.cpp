#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = 1;
        int minSoFar = 1;
        int result = nums[0];

        for (int num : nums) {
            int nextMax = num * maxSoFar;
            int nextMin = num * minSoFar;
            maxSoFar = max({num, nextMax, nextMin});
            minSoFar = min({num, nextMax, nextMin});
            result = max(result, maxSoFar);
        }

        return result;
    }
};

// Test helper
void testMaxProduct() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> nums1 = {2, 3, -2, 4};
    int expected1 = 6;
    int actual1 = solution.maxProduct(nums1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    vector<int> nums2 = {-2, 0, -1};
    int expected2 = 0;
    int actual2 = solution.maxProduct(nums2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: All positive
    vector<int> nums3 = {1, 2, 3, 4};
    int expected3 = 24;
    int actual3 = solution.maxProduct(nums3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: All negative
    vector<int> nums4 = {-1, -2, -3};
    int expected4 = -1;
    int actual4 = solution.maxProduct(nums4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: Single element
    vector<int> nums5 = {5};
    int expected5 = 5;
    int actual5 = solution.maxProduct(nums5);
    cout << actual5 << " | " << expected5 << endl;

    // Test case 6: With zero
    vector<int> nums6 = {2, 0, 3, -1};
    int expected6 = 3;
    int actual6 = solution.maxProduct(nums6);
    cout << actual6 << " | " << expected6 << endl;
}

int main() {
    testMaxProduct();
    return 0;
}
