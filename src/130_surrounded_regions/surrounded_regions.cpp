#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if ((row == 0 || col == 0 || row == rows - 1 || col == cols - 1) &&
                    board[row][col] == 'O') {
                    q.emplace(row, col);
                }
            }
        }
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            if (board[row][col] != 'S') {
                board[row][col] = 'S';
                for (auto [dR, dC] : dirs) {
                    int newRow = row + dR, newCol = col + dC;
                    if (0 <= newRow && newRow < rows && 0 <= newCol && newCol < cols &&
                        board[newRow][newCol] == 'O') {
                        q.emplace(newRow, newCol);
                    }
                }
            }
        }
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 'O') board[row][col] = 'X';
                if (board[row][col] == 'S') board[row][col] = 'O';
            }
        }
    }
};

void printBoard(const vector<vector<char>>& board) {
    cout << "[";
    for (size_t i = 0; i < board.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < board[i].size(); ++j) {
            cout << '"' << board[i][j] << '"';
            if (j + 1 < board[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < board.size()) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    sol.solve(board1);
    printBoard(board1);
    cout << " | "
            "[[\"X\",\"X\",\"X\",\"X\"],[\"X\",\"X\",\"X\",\"X\"],[\"X\",\"X\",\"X\",\"X\"],[\"X\","
            "\"O\",\"X\",\"X\"]]"
         << endl;
    vector<vector<char>> board2 = {{'X'}};
    sol.solve(board2);
    printBoard(board2);
    cout << " | [[\"X\"]]" << endl;
    vector<vector<char>> board3 = {{'O', 'O'}, {'O', 'O'}};
    sol.solve(board3);
    printBoard(board3);
    cout << " | [[\"O\",\"O\"],[\"O\",\"O\"]]" << endl;
    vector<vector<char>> board4 = {{'X', 'O', 'X'}, {'O', 'X', 'O'}, {'X', 'O', 'X'}};
    sol.solve(board4);
    printBoard(board4);
    cout << " | [[\"X\",\"O\",\"X\"],[\"O\",\"X\",\"O\"],[\"X\",\"O\",\"X\"]]" << endl;
    vector<vector<char>> board5 = {{'O'}};
    sol.solve(board5);
    printBoard(board5);
    cout << " | [[\"O\"]]" << endl;
    return 0;
}
