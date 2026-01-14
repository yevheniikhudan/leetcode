#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        function<void(int, int)> dfs = [&](int row, int col) {
            if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') return;
            grid[row][col] = '0';
            for (auto& d : directions) {
                dfs(row + d.first, col + d.second);
            }
        };
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '1') {
                    ++res;
                    dfs(row, col);
                }
            }
        }
        return res;
    }
};

// Test scaffolding
int main() {
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    Solution sol;
    cout << sol.numIslands(grid) << endl;  // 1
    return 0;
}
