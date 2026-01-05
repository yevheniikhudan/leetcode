#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1;
        int carry = 0;
        vector<int> res;
        while (k > 0 || carry > 0 || i >= 0) {
            int sum = carry + (k % 10);
            if (i >= 0) sum += num[i];
            res.push_back(sum % 10);
            k /= 10;
            carry = sum / 10;
            i--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{1, 2, 0, 0}, 34}, {{2, 7, 4}, 181}, {{2, 1, 5}, 806}, {{0}, 23}, {{9, 9, 9, 9, 9}, 1}};
    vector<vector<int>> expected = {
        {1, 2, 3, 4}, {4, 5, 5}, {1, 0, 2, 1}, {2, 3}, {1, 0, 0, 0, 0, 0}};
    Solution sol;
    for (int i = 0; i < tests.size(); ++i) {
        auto actual = sol.addToArrayForm(tests[i].first, tests[i].second);
        cout << "[";
        for (size_t j = 0; j < actual.size(); ++j) {
            cout << actual[j];
            if (j + 1 < actual.size()) cout << ",";
        }
        cout << "] | [";
        for (size_t j = 0; j < expected[i].size(); ++j) {
            cout << expected[i][j];
            if (j + 1 < expected[i].size()) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
