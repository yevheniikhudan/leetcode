#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> diff1, diff2;
        for (int n : set1)
            if (!set2.count(n)) diff1.push_back(n);
        for (int n : set2)
            if (!set1.count(n)) diff2.push_back(n);
        return {diff1, diff2};
    }
};

// Test scaffolding
int main() {
    vector<vector<int>> nums1s = {{1, 2, 3}, {1, 2, 3, 3}, {1, 2, 3}, {1, 2, 2, 3}, {1}};
    vector<vector<int>> nums2s = {{2, 4, 6}, {1, 1, 2, 2}, {4, 5, 6}, {3, 4, 4, 5}, {1}};
    vector<vector<vector<int>>> expected = {
        {{1, 3}, {4, 6}}, {{3}, {}}, {{1, 2, 3}, {4, 5, 6}}, {{1, 2}, {4, 5}}, {{}, {}}};
    Solution sol;
    for (int i = 0; i < nums1s.size(); ++i) {
        vector<vector<int>> actual = sol.findDifference(nums1s[i], nums2s[i]);
        cout << "[";
        for (auto& v : actual) {
            cout << "[";
            for (size_t j = 0; j < v.size(); ++j) {
                cout << v[j];
                if (j + 1 < v.size()) cout << ",";
            }
            cout << "]";
        }
        cout << "] | [";
        for (auto& v : expected[i]) {
            cout << "[";
            for (size_t j = 0; j < v.size(); ++j) {
                cout << v[j];
                if (j + 1 < v.size()) cout << ",";
            }
            cout << "]";
        }
        cout << "]" << endl;
    }
    return 0;
}
