#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int time = 0, fresh = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 2) q.push({row, col});
                if (grid[row][col] == 1) fresh++;
            }
        }
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [row, col] = q.front();
                q.pop();
                for (auto& d : directions) {
                    int newRow = row + d.first, newCol = col + d.second;
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                        grid[newRow][newCol] == 1) {
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 2;
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : time;
    }
};

// Test scaffolding
int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution sol;
    cout << sol.orangesRotting(grid) << endl;  // 4
    return 0;
}
