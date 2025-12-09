#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * Longest Consecutive Sequence
     *
     * @param nums List of integers
     * @return Length of longest consecutive sequence
     */
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cache;
        int result = 0;

        for (int num : nums) {
            cache.insert(num);
        }

        for (int num : cache) {
            if (cache.count(num - 1)) {
                continue;
            }

            int cur = cur;
            while (cache.count(num + cur)) {
                cur += 1;
            }
            result = max(result, cur);
        }

        return result;
    }
};

void test_longest_consecutive_sequence() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    int result1 = solution.longestConsecutive(nums1);
    cout << "Test 1: [100,4,200,1,3,2] -> " << result1 << endl;
    assert(result1 == 4);

    // Test case 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int result2 = solution.longestConsecutive(nums2);
    cout << "Test 2: [0,3,7,2,5,8,4,6,0,1] -> " << result2 << endl;
    assert(result2 == 9);

    // Test case 3
    vector<int> nums3 = {1, 0, 1, 2};
    int result3 = solution.longestConsecutive(nums3);
    cout << "Test 3: [1,0,1,2] -> " << result3 << endl;
    assert(result3 == 3);

    // Test case 4: Empty array
    vector<int> nums4 = {};
    int result4 = solution.longestConsecutive(nums4);
    cout << "Test 4: [] -> " << result4 << endl;
    assert(result4 == 0);

    // Test case 5: Single element
    vector<int> nums5 = {1};
    int result5 = solution.longestConsecutive(nums5);
    cout << "Test 5: [1] -> " << result5 << endl;
    assert(result5 == 1);

    // Test case 6: No consecutive
    vector<int> nums6 = {1, 3, 5, 7, 9};
    int result6 = solution.longestConsecutive(nums6);
    cout << "Test 6: [1,3,5,7,9] -> " << result6 << endl;
    assert(result6 == 1);

    cout << "All test cases passed!" << endl;
}

int main() {
    test_longest_consecutive_sequence();
    return 0;
}
