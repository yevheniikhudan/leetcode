#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * Product of Array Except Self
     *
     * @param nums List of integers
     * @return List of products except self
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; i++) {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }
};

void test_product_of_array_except_self() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Test 1: [1,2,3,4] -> [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    assert(result1 == vector<int>({24, 12, 8, 6}));

    // Test case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Test 2: [-1,1,0,-3,3] -> [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    assert(result2 == vector<int>({0, 0, 9, 0, 0}));

    // Test case 3: Zeros
    vector<int> nums3 = {0, 0, 2, 3};
    vector<int> result3 = solution.productExceptSelf(nums3);
    cout << "Test 3: [0,0,2,3] -> [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    assert(result3 == vector<int>({0, 0, 0, 0}));

    // Test case 4: Negative numbers
    vector<int> nums4 = {-2, -3, -4};
    vector<int> result4 = solution.productExceptSelf(nums4);
    cout << "Test 4: [-2,-3,-4] -> [";
    for (size_t i = 0; i < result4.size(); i++) {
        cout << result4[i];
        if (i < result4.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    assert(result4 == vector<int>({12, 8, 6}));

    cout << "All test cases passed!" << endl;
}

int main() {
    test_product_of_array_except_self();
    return 0;
}
