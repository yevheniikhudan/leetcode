#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i) dp[i] = {nums[i]};
        vector<int> res;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] % nums[i] == 0) {
                    if (dp[j].size() + 1 > dp[i].size()) {
                        dp[i] = {nums[i]};
                        dp[i].insert(dp[i].end(), dp[j].begin(), dp[j].end());
                    }
                }
            }
            if (dp[i].size() > res.size()) {
                res = dp[i];
            }
        }
        return res;
    }
};

// Test scaffolding
void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

void test() {
    Solution sol;
    vector<int> v1 = {1, 2, 3};
    printVec(sol.largestDivisibleSubset(v1));
    cout << " | [1,2] or [1,3]\n";
    vector<int> v2 = {1, 2, 4, 8};
    printVec(sol.largestDivisibleSubset(v2));
    cout << " | [1,2,4,8]\n";
    vector<int> v3 = {4, 8, 10, 240};
    printVec(sol.largestDivisibleSubset(v3));
    cout << " | [4,8,240] or [10,240]\n";
    vector<int> v4 = {2, 3, 4, 9, 8};
    printVec(sol.largestDivisibleSubset(v4));
    cout << " | [2,4,8] or [3,9]\n";
    vector<int> v5 = {1};
    printVec(sol.largestDivisibleSubset(v5));
    cout << " | [1]\n";
}

int main() {
    test();
    return 0;
}
