/*
239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k
which is moving from the very left of the array to the very right. You can only
see the k numbers in the window. Each time the sliding window moves right by one
position.

Return the max sliding window.
*/

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find the maximum value in each sliding window of size k.
     *
     * @param nums Array of integers
     * @param k Size of the sliding window
     * @return Vector of maximum values for each window position
     *
     * Time Complexity: O(n) where n = nums.size()
     * Space Complexity: O(k) for the deque
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> q;

        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }

            q.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result1 = solution.maxSlidingWindow(nums1, 3);
    cout << "Test 1: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "] (expected: [3, 3, 5, 5, 6, 7])\n";

    // Test case 2: Example 2
    vector<int> nums2 = {1};
    vector<int> result2 = solution.maxSlidingWindow(nums2, 1);
    cout << "Test 2: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << (i < result2.size() - 1 ? ", " : "");
    }
    cout << "] (expected: [1])\n";

    // Test case 3: k equals array length
    vector<int> nums3 = {1, 3, 1, 2, 0, 5};
    vector<int> result3 = solution.maxSlidingWindow(nums3, 6);
    cout << "Test 3: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << result3[i] << (i < result3.size() - 1 ? ", " : "");
    }
    cout << "] (expected: [5])\n";

    // Test case 4: Descending array
    vector<int> nums4 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> result4 = solution.maxSlidingWindow(nums4, 3);
    cout << "Test 4: [";
    for (int i = 0; i < result4.size(); i++) {
        cout << result4[i] << (i < result4.size() - 1 ? ", " : "");
    }
    cout << "] (expected: [9, 8, 7, 6, 5, 4, 3])\n";

    // Test case 5: Ascending array
    vector<int> nums5 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> result5 = solution.maxSlidingWindow(nums5, 3);
    cout << "Test 5: [";
    for (int i = 0; i < result5.size(); i++) {
        cout << result5[i] << (i < result5.size() - 1 ? ", " : "");
    }
    cout << "] (expected: [3, 4, 5, 6, 7, 8, 9])\n";

    // Test case 6: All elements equal
    vector<int> nums6 = {5, 5, 5, 5, 5};
    vector<int> result6 = solution.maxSlidingWindow(nums6, 2);
    cout << "Test 6: [";
    for (int i = 0; i < result6.size(); i++) {
        cout << result6[i] << (i < result6.size() - 1 ? ", " : "");
    }
    cout << "] (expected: [5, 5, 5, 5])\n";

    // Test case 7: k = 1
    vector<int> nums7 = {4, -2, 7, 1};
    vector<int> result7 = solution.maxSlidingWindow(nums7, 1);
    cout << "Test 7: [";
    for (int i = 0; i < result7.size(); i++) {
        cout << result7[i] << (i < result7.size() - 1 ? ", " : "");
    }
    cout << "] (expected: [4, -2, 7, 1])\n";

    // Test case 8: Negative numbers
    vector<int> nums8 = {-7, -8, 7, 5, 7, 1, 6, 0};
    vector<int> result8 = solution.maxSlidingWindow(nums8, 4);
    cout << "Test 8: [";
    for (int i = 0; i < result8.size(); i++) {
        cout << result8[i] << (i < result8.size() - 1 ? ", " : "");
    }
    cout << "] (expected: [7, 7, 7, 7, 7])\n";

    // Test case 9: Mixed positive and negative
    vector<int> nums9 = {1, -1, 2, -2, 3, -3};
    vector<int> result9 = solution.maxSlidingWindow(nums9, 2);
    cout << "Test 9: [";
    for (int i = 0; i < result9.size(); i++) {
        cout << result9[i] << (i < result9.size() - 1 ? ", " : "");
    }
    cout << "] (expected: [1, 2, 2, 3, 3])\n";

    // Test case 10: Large window
    vector<int> nums10 = {9, 11};
    vector<int> result10 = solution.maxSlidingWindow(nums10, 2);
    cout << "Test 10: [";
    for (int i = 0; i < result10.size(); i++) {
        cout << result10[i] << (i < result10.size() - 1 ? ", " : "");
    }
    cout << "] (expected: [11])\n";
}

int main() {
    runTests();
    return 0;
}
