#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, curr, 0, candidates, target, res);
        return res;
    }
    void backtrack(int start, vector<int>& curr, int total, vector<int>& candidates, int target,
                   vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (total + candidates[i] > target) break;
            curr.push_back(candidates[i]);
            backtrack(i + 1, curr, total + candidates[i], candidates, target, res);
            curr.pop_back();
        }
    }
};

string formatResult(vector<vector<int>> result) {
    vector<string> sorted;
    for (auto& comb : result) {
        sort(comb.begin(), comb.end());
        string s = "[";
        for (size_t i = 0; i < comb.size(); i++) {
            s += to_string(comb[i]);
            if (i < comb.size() - 1) s += ",";
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
    vector<int> c1 = {10, 1, 2, 7, 6, 1, 5};
    int t1 = 8;
    vector<vector<int>> e1 = {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
    cout << formatResult(sol.combinationSum2(c1, t1)) << " | " << formatResult(e1) << endl;
    // Test case 2
    vector<int> c2 = {2, 5, 2, 1, 2};
    int t2 = 5;
    vector<vector<int>> e2 = {{1, 2, 2}, {5}};
    cout << formatResult(sol.combinationSum2(c2, t2)) << " | " << formatResult(e2) << endl;
    // Test case 3
    vector<int> c3 = {2};
    int t3 = 1;
    vector<vector<int>> e3 = {};
    cout << formatResult(sol.combinationSum2(c3, t3)) << " | " << formatResult(e3) << endl;
    // Test case 4
    vector<int> c4 = {1};
    int t4 = 1;
    vector<vector<int>> e4 = {{1}};
    cout << formatResult(sol.combinationSum2(c4, t4)) << " | " << formatResult(e4) << endl;
    // Test case 5
    vector<int> c5 = {1};
    int t5 = 2;
    vector<vector<int>> e5 = {};
    cout << formatResult(sol.combinationSum2(c5, t5)) << " | " << formatResult(e5) << endl;
    return 0;
}
