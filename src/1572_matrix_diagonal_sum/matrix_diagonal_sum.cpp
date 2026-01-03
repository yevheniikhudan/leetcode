#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int l = mat.size();

        for (int i = 0; i < l; i++) {
            sum += mat[i][i];
            if (l - 1 - i != i) sum += mat[i][l - 1 - i];
        }

        return sum;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> tests = {
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 25},
        {{{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}, 8},
        {{{5}}, 5},
        {{{1, 2}, {3, 4}}, 10},
        {{{7, 0, 0, 7}, {0, 7, 7, 0}, {0, 7, 7, 0}, {7, 0, 0, 7}}, 56}};
    Solution sol;
    for (auto& [mat, expected] : tests) {
        int actual = sol.diagonalSum(mat);
        cout << actual << " | " << expected << endl;
    }
    return 0;
}
