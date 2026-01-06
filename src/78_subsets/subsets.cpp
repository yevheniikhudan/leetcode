#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, curr, nums, res);
        return res;
    }
    void backtrack(int first, vector<int>& curr, vector<int>& nums, vector<vector<int>>& res) {
        res.push_back(curr);
        for (int i = first; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, curr, nums, res);
            curr.pop_back();
        }
    }
};

// Helper function to format results for comparison
string formatResult(vector<vector<int>>& result) {
    vector<string> sorted;
    for (auto& subset : result) {
        sort(subset.begin(), subset.end());
        string s = "[";
        for (size_t i = 0; i < subset.size(); i++) {
            s += to_string(subset[i]);
            if (i < subset.size() - 1) s += ",";
        }
        s += "]";
        sorted.push_back(s);
    }
    sort(sorted.begin(), sorted.end());
    string res = "[";
    for (size_t i = 0; i < sorted.size(); i++) {
        res += sorted[i];
        if (i < sorted.size() - 1) res += ",";
    }
    res += "]";
    return res;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    auto result1 = sol.subsets(nums1);
    vector<vector<int>> expected1 = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
    cout << formatResult(result1) << " | " << formatResult(expected1) << endl;

    // Test case 2
    vector<int> nums2 = {0};
    auto result2 = sol.subsets(nums2);
    vector<vector<int>> expected2 = {{}, {0}};
    cout << formatResult(result2) << " | " << formatResult(expected2) << endl;

    // Test case 3
    vector<int> nums3 = {1};
    auto result3 = sol.subsets(nums3);
    vector<vector<int>> expected3 = {{}, {1}};
    cout << formatResult(result3) << " | " << formatResult(expected3) << endl;

    // Test case 4
    vector<int> nums4 = {1, 2};
    auto result4 = sol.subsets(nums4);
    vector<vector<int>> expected4 = {{}, {1}, {2}, {1, 2}};
    cout << formatResult(result4) << " | " << formatResult(expected4) << endl;

    // Test case 5
    vector<int> nums5 = {9, 0, 3, 5, 7};
    auto result5 = sol.subsets(nums5);
    int expectedLen = 32;  // 2^5 subsets
    cout << result5.size() << " | " << expectedLen << endl;

    return 0;
}
