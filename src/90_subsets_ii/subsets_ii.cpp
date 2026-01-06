#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, path, res);
        return res;
    }

   private:
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, res);
            path.pop_back();
        }
    }
};

// Test scaffolding
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 2};
    vector<vector<int>> res1 = sol.subsetsWithDup(nums1);
    for (auto& v : res1) {
        cout << "[";
        for (int n : v) cout << n << ",";
        cout << "] ";
    }
    cout << endl;
    vector<int> nums2 = {0};
    vector<vector<int>> res2 = sol.subsetsWithDup(nums2);
    for (auto& v : res2) {
        cout << "[";
        for (int n : v) cout << n << ",";
        cout << "] ";
    }
    cout << endl;
    return 0;
}
