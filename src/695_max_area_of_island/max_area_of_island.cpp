#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    res = max(res, dfs(grid, row, col, rows, cols, directions));
                }
            }
        }
        return res;
    }

   private:
    int dfs(vector<vector<int>>& grid, int row, int col, int rows, int cols,
            vector<pair<int, int>>& directions) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        int area = 1;
        for (auto& d : directions) {
            area += dfs(grid, row + d.first, col + d.second, rows, cols, directions);
        }
        return area;
    }
};

// Test scaffolding
int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;  // 6
    return 0;
}
