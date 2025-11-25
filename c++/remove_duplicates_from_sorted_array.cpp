#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * Remove Duplicates from Sorted Array
     *
     * @param nums List of sorted integers
     * @return Number of unique elements after removing duplicates
     */
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int k = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k]) {
                nums[++k] = nums[i];
            }
        }

        return k + 1;
    }
};

void test_remove_duplicates_from_sorted_array() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 2};
    int k1 = solution.removeDuplicates(nums1);
    cout << "Test 1: [1,1,2], k = " << k1 << endl;
    assert(k1 == 2 && vector<int>(nums1.begin(), nums1.begin() + k1) == vector<int>({1, 2}));

    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = solution.removeDuplicates(nums2);
    cout << "Test 2: [0,0,1,1,1,2,2,3,3,4], k = " << k2 << endl;
    assert(k2 == 5 &&
           vector<int>(nums2.begin(), nums2.begin() + k2) == vector<int>({0, 1, 2, 3, 4}));

    // Test case 3: All elements same
    vector<int> nums3 = {2, 2, 2, 2, 2};
    int k3 = solution.removeDuplicates(nums3);
    cout << "Test 3: [2,2,2,2,2], k = " << k3 << endl;
    assert(k3 == 1 && vector<int>(nums3.begin(), nums3.begin() + k3) == vector<int>({2}));

    // Test case 4: No duplicates
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int k4 = solution.removeDuplicates(nums4);
    cout << "Test 4: [1,2,3,4,5], k = " << k4 << endl;
    assert(k4 == 5 &&
           vector<int>(nums4.begin(), nums4.begin() + k4) == vector<int>({1, 2, 3, 4, 5}));

    cout << "All test cases passed!" << endl;
}

int main() {
    test_remove_duplicates_from_sorted_array();
    return 0;
}
