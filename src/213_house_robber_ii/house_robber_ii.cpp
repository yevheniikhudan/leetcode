#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        auto robHelper = [&](int left, int right) -> int {
            int a = 0, b = 0;
            for (int i = left; i < right; i++) {
                int temp = b;
                b = max(nums[i] + a, b);
                a = temp;
            }
            return b;
        };

        return max(robHelper(0, n - 1), robHelper(1, n));
    }
};

// Test helper
void testRob() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> nums1 = {2, 3, 2};
    int expected1 = 3;
    int actual1 = solution.rob(nums1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    vector<int> nums2 = {1, 2, 3, 1};
    int expected2 = 4;
    int actual2 = solution.rob(nums2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: Example 3
    vector<int> nums3 = {1, 2, 3};
    int expected3 = 3;
    int actual3 = solution.rob(nums3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: Single house
    vector<int> nums4 = {5};
    int expected4 = 5;
    int actual4 = solution.rob(nums4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: Two houses
    vector<int> nums5 = {1, 2};
    int expected5 = 2;
    int actual5 = solution.rob(nums5);
    cout << actual5 << " | " << expected5 << endl;

    // Test case 6: All zeros
    vector<int> nums6 = {0, 0, 0};
    int expected6 = 0;
    int actual6 = solution.rob(nums6);
    cout << actual6 << " | " << expected6 << endl;
}

int main()