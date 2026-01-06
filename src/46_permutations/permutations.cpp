#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
    void backtrack(vector<int>& nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1, res);
            swap(nums[i], nums[j]);
        }
    }
    // Iterative version
    vector<vector<int>> permuteIterative(vector<int> nums) {
        vector<vector<int>> res = {{}};
        for (int num : nums) {
            vector<vector<int>> nextPerms;
            for (auto& p : res) {
                for (int i = 0; i <= p.size(); ++i) {
                    vector<int> pCopy = p;
                    pCopy.insert(pCopy.begin() + i, num);
                    nextPerms.push_back(pCopy);
                }
            }
            res = nextPerms;
        }
        return res;
    }
};

string formatResult(vector<vector<int>> result) {
    vector<string> sorted;
    for (auto& perm : result) {
        sort(perm.begin(), perm.end());
        string s = "[";
        for (size_t i = 0; i < perm.size(); i++) {
            s += to_string(perm[i]);
            if (i < perm.size() - 1) s += ",";
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
    vector<vector<int>> e1 = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    cout << formatResult(sol.permute(nums1)) << " | " << formatResult(e1) << endl;
    // Test case 2
    vector<int> nums2 = {0, 1};
    vector<vector<int>> e2 = {{0, 1}, {1, 0}};
    cout << formatResult(sol.permute(nums2)) << " | " << formatResult(e2) << endl;
    // Test case 3
    vector<int> nums3 = {1};
    vector<vector<int>> e3 = {{1}};
    cout << formatResult(sol.permute(nums3)) << " | " << formatResult(e3) << endl;
    // Test case 4
    vector<int> nums4 = {2, 1};
    vector<vector<int>> e4 = {{2, 1}, {1, 2}};
    cout << formatResult(sol.permute(nums4)) << " | " << formatResult(e4) << endl;
    // Test case 5
    vector<int> nums5 = {1, 2, 3, 4};
    cout << sol.permute(nums5).size() << " | " << 24 << endl;
    return 0;
}
