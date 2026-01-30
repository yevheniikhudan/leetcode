#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]";
}

// Helper function to run test case
void runTestCase(const vector<int>& nums, bool expected) {
    Solution solution;
    vector<int> numsCopy = nums;  // Copy to avoid modifying original
    bool actual = solution.canPartition(numsCopy);
    cout << (actual ? "true" : "false") << " | " << (expected ? "true" : "false") << endl;
}

int main() {
    // Test case 1
    vector<int> nums1 = {1, 5, 11, 5};
    runTestCase(nums1, true);

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 5};
    runTestCase(nums2, false);

    // Test case 3
    vector<int> nums3 = {1, 2, 3};
    runTestCase(nums3, true);

    // Test case 4
    vector<int> nums4 = {1, 1};
    runTestCase(nums4, true);

    // Test case 5
    vector<int> nums5 = {1};
    runTestCase(nums5, false);

    // Test case 6
    vector<int> nums6 = {2, 2, 1, 1};
    runTestCase(nums6, true);

    return 0;
}
