#include <iostream>
#include <vector>

class Solution {
   public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int a = nums[0], b = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int current = max(nums[i] + a, b);
            a = b;
            b = current;
        }

        return b;
    }
};

// Test helper
void testRob() {
    Solution solution;

    // Test case 1: Example 1
    std::vector<int> nums1 = {1, 2, 3, 1};
    int expected1 = 4;
    int actual1 = solution.rob(nums1);
    std::cout << actual1 << " | " << expected1 << std::endl;

    // Test case 2: Example 2
    std::vector<int> nums2 = {2, 7, 9, 3, 1};
    int expected2 = 12;
    int actual2 = solution.rob(nums2);
    std::cout << actual2 << " | " << expected2 << std::endl;

    // Test case 3: n=1
    std::vector<int> nums3 = {5};
    int expected3 = 5;
    int actual3 = solution.rob(nums3);
    std::cout << actual3 << " | " << expected3 << std::endl;

    // Test case 4: n=2
    std::vector<int> nums4 = {1, 2};
    int expected4 = 2;
    int actual4 = solution.rob(nums4);
    std::cout << actual4 << " | " << expected4 << std::endl;

    // Test case 5: All zeros
    std::vector<int> nums5 = {0, 0, 0};
    int expected5 = 0;
    int actual5 = solution.rob(nums5);
    std::cout << actual5 << " | " << expected5 << std::endl;
}

int main() {
    testRob();
    return 0;
}
