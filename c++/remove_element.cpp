#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * Remove Element
     *
     * @param nums List of integers
     * @param val Value to remove
     * @return Number of elements not equal to val
     */
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

void test_remove_element() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int k1 = solution.removeElement(nums1, val1);
    cout << "Test 1: [3,2,2,3], val = 3, k = " << k1 << endl;
    sort(nums1.begin(), nums1.begin() + k1);
    assert(k1 == 2 && vector<int>(nums1.begin(), nums1.begin() + k1) == vector<int>({2, 2}));

    // Test case 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int k2 = solution.removeElement(nums2, val2);
    cout << "Test 2: [0,1,2,2,3,0,4,2], val = 2, k = " << k2 << endl;
    sort(nums2.begin(), nums2.begin() + k2);
    assert(k2 == 5 &&
           vector<int>(nums2.begin(), nums2.begin() + k2) == vector<int>({0, 0, 1, 3, 4}));

    // Test case 3: All elements are val
    vector<int> nums3 = {2, 2, 2, 2, 2};
    int val3 = 2;
    int k3 = solution.removeElement(nums3, val3);
    cout << "Test 3: [2,2,2,2,2], val = 2, k = " << k3 << endl;
    assert(k3 == 0);

    // Test case 4: No elements are val
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int val4 = 6;
    int k4 = solution.removeElement(nums4, val4);
    cout << "Test 4: [1,2,3,4,5], val = 6, k = " << k4 << endl;
    sort(nums4.begin(), nums4.begin() + k4);
    assert(k4 == 5 &&
           vector<int>(nums4.begin(), nums4.begin() + k4) == vector<int>({1, 2, 3, 4, 5}));

    cout << "All test cases passed!" << endl;
}

int main() {
    test_remove_element();
    return 0;
}
