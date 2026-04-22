#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> counts;

        for (int num : nums) {
            counts[num] += 1;
        }

        int maxNumber = -1;

        for (const auto& [key, value] : counts) {
            if (value == 1) maxNumber = max(maxNumber, key);
        }

        return maxNumber;
    }
};

// Helper function for testing
void testSolution() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {5, 7, 3, 9, 4, 9, 8, 3, 1};
    int result1 = solution.largestUniqueNumber(nums1);
    int expected1 = 8;
    cout << "Test 1: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;

    // Test case 2
    vector<int> nums2 = {9, 9, 8, 8};
    int result2 = solution.largestUniqueNumber(nums2);
    int expected2 = -1;
    cout << "Test 2: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;

    // Test case 3
    vector<int> nums3 = {1, 1, 1, 1, 2, 2, 2, 3};
    int result3 = solution.largestUniqueNumber(nums3);
    int expected3 = 3;
    cout << "Test 3: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test case 4
    vector<int> nums4 = {5};
    int result4 = solution.largestUniqueNumber(nums4);
    int expected4 = 5;
    cout << "Test 4: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test case 5
    vector<int> nums5 = {0, 1, 0, 2, 3, 3};
    int result5 = solution.largestUniqueNumber(nums5);
    int expected5 = 2;
    cout << "Test 5: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

int main() {
    testSolution();
    return 0;
}
