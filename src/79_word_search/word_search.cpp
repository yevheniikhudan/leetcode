#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size(), COLS = board[0].size();
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                if (dfs(board, word, row, col, 0)) return true;
            }
        }
        return false;
    }

   private:
    bool dfs(vector<vector<char>>& board, const string& word, int row, int col, int pathLength) {
        int ROWS = board.size(), COLS = board[0].size();
        if (pathLength >= word.size()) return true;
        if (row < 0 || col < 0 || row == ROWS || col == COLS) return false;
        if (board[row][col] == '#') return false;
        if (board[row][col] != word[pathLength]) return false;
        char orig = board[row][col];
        board[row][col] = '#';
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        bool found = false;
        for (int d = 0; d < 4; ++d) {
            found |= dfs(board, word, row + dr[d], col + dc[d], pathLength + 1);
            if (found) break;
        }
        board[row][col] = orig;
        return found;
    }
};

vector<vector<char>> buildBoard(const vector<string>& rows) {
    vector<vector<char>> board;
    for (const auto& row : rows) {
        board.push_back(vector<char>(row.begin(), row.end()));
    }
    return board;
}

int main() {
    Solution sol;
    struct Test {
        vector<vector<char>> board;
        string word;
        bool expected;
    } tests[] = {
        {buildBoard({"ABCE", "SFCS", "ADEE"}), "ABCCED", true},
        {buildBoard({"ABCE", "SFCS", "ADEE"}), "SEE", true},
        {buildBoard({"ABCE", "SFCS", "ADEE"}), "ABCB", false},
        {buildBoard({"A"}), "A", true},
        {buildBoard({"A"}), "B", false},
        {buildBoard({"A"}), "AA", false},
    };
    for (int i = 0; i < 6; ++i) {
        bool result = sol.exist(tests[i].board, tests[i].word);
        cout << "Test " << (i + 1) << ": " << result << " | " << tests[i].expected << endl;
    }
    return 0;
}
