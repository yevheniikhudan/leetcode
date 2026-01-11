#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        backtrack(0, n, board, res, cols, diag1, diag2);
        return res;
    }
private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& res,
                  vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1, d2 = row + col;
            if (cols[col] || diag1[d1] || diag2[d2]) continue;
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1, n, board, res, cols, diag1, diag2);
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};

int main() {
    Solution sol;
    vector<int> tests = {4, 1, 2, 3, 5};
    for (int n : tests) {
        vector<vector<string>> result = sol.solveNQueens(n);
        cout << "n=" << n << ": [";
        for (const auto& board : result) {
            cout << "[";
            for (const auto& row : board) cout << row << ",";
            cout << "] ";
        }
        cout << "]" << endl;
    }
    return 0;
}
