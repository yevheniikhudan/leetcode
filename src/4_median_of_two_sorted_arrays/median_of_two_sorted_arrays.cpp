/*
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find median of two sorted arrays using binary search on partition.
     *
     * @param nums1 First sorted array
     * @param nums2 Second sorted array
     * @return Median of combined arrays
     *
     * Time Complexity: O(log min(m, n)) - binary search on smaller array
     * Space Complexity: O(1) - constant extra space
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0, right = m;

        while (left <= right) {
            int partition_a = (left + right) / 2;
            int partition_b = (m + n + 1) / 2 - partition_a;
            int max_left_a = partition_a > 0 ? nums1[partition_a - 1] : INT_MIN;
            int max_left_b = partition_b > 0 ? nums2[partition_b - 1] : INT_MIN;
            int min_right_a = partition_a < m ? nums1[partition_a] : INT_MAX;
            int min_right_b = partition_b < n ? nums2[partition_b] : INT_MAX;

            if (max_left_a <= min_right_b && max_left_b <= min_right_a) {
                if ((m + n) % 2 == 0) {
                    return float(max(max_left_a, max_left_b) + min(min_right_a, min_right_b)) / 2;
                } else {
                    return max(max_left_a, max_left_b);
                }
            }

            if (max_left_a > min_right_b) {
                right = partition_a - 1;
            } else {
                left = partition_a + 1;
            }
        }

        return 0.0;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1 - odd total length
    vector<int> nums1_1 = {1, 3};
    vector<int> nums2_1 = {2};
    double result1 = solution.findMedianSortedArrays(nums1_1, nums2_1);
    cout << "Test 1: " << result1 << " (expected: 2.0)\n";

    // Test case 2: Example 2 - even total length
    vector<int> nums1_2 = {1, 2};
    vector<int> nums2_2 = {3, 4};
    double result2 = solution.findMedianSortedArrays(nums1_2, nums2_2);
    cout << "Test 2: " << result2 << " (expected: 2.5)\n";

    // Test case 3: One empty array
    vector<int> nums1_3 = {};
    vector<int> nums2_3 = {1};
    double result3 = solution.findMedianSortedArrays(nums1_3, nums2_3);
    cout << "Test 3: " << result3 << " (expected: 1.0)\n";

    // Test case 4: Both single element
    vector<int> nums1_4 = {2};
    vector<int> nums2_4 = {3};
    double result4 = solution.findMedianSortedArrays(nums1_4, nums2_4);
    cout << "Test 4: " << result4 << " (expected: 2.5)\n";

    // Test case 5: No overlap
    vector<int> nums1_5 = {1, 2};
    vector<int> nums2_5 = {3, 4, 5};
    double result5 = solution.findMedianSortedArrays(nums1_5, nums2_5);
    cout << "Test 5: " << result5 << " (expected: 3.0)\n";

    // Test case 6: Complete overlap
    vector<int> nums1_6 = {1, 3, 5};
    vector<int> nums2_6 = {2, 4, 6};
    double result6 = solution.findMedianSortedArrays(nums1_6, nums2_6);
    cout << "Test 6: " << result6 << " (expected: 3.5)\n";

    // Test case 7: Different sizes
    vector<int> nums1_7 = {1, 2, 3, 4, 5};
    vector<int> nums2_7 = {6};
    double result7 = solution.findMedianSortedArrays(nums1_7, nums2_7);
    cout << "Test 7: " << result7 << " (expected: 3.5)\n";

    // Test case 8: Negative numbers
    vector<int> nums1_8 = {-5, -3, -1};
    vector<int> nums2_8 = {0, 2, 4};
    double result8 = solution.findMedianSortedArrays(nums1_8, nums2_8);
    cout << "Test 8: " << result8 << " (expected: -0.5)\n";

    // Test case 9: All elements in nums1 < nums2
    vector<int> nums1_9 = {1, 2};
    vector<int> nums2_9 = {3, 4, 5, 6};
    double result9 = solution.findMedianSortedArrays(nums1_9, nums2_9);
    cout << "Test 9: " << result9 << " (expected: 3.5)\n";

    // Test case 10: Single element arrays
    vector<int> nums1_10 = {1};
    vector<int> nums2_10 = {2, 3, 4, 5};
    double result10 = solution.findMedianSortedArrays(nums1_10, nums2_10);
    cout << "Test 10: " << result10 << " (expected: 3.0)\n";
}

int main() {
    runTests();
    return 0;
}
