#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);

        int LIS = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
                LIS++;
                continue;
            }

            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            *it = nums[i];
        }

        return LIS;
    }
};

// Test helper
void testLengthOfLIS() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    int expected1 = 4;
    int actual1 = solution.lengthOfLIS(nums1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    int expected2 = 4;
    int actual2 = solution.lengthOfLIS(nums2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: Example 3
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    int expected3 = 1;
    int actual3 = solution.lengthOfLIS(nums3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: Strictly increasing
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int expected4 = 5;
    int actual4 = solution.lengthOfLIS(nums4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: Strictly decreasing
    vector<int> nums5 = {5, 4, 3, 2, 1};
    int expected5 = 1;
    int actual5 = solution.lengthOfLIS(nums5);
    cout << actual5 << " | " << expected5 << endl;

    // Test case 6: Mixed with duplicates
    vector<int> nums6 = {1, 3, 2, 3, 1, 4};
    int expected6 = 4;  // e.g., [1,2,3,4]
    int actual6 = solution.lengthOfLIS(nums6);
    cout << actual6 << " | " << expected6 << endl;
}

int main() {
    testLengthOfLIS();
    return 0;
}
