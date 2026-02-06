#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int lis = 0;
        unordered_map<int, int> memo;

        // Use a helper function instead of a recursive lambda
        function<int(int, int, int)> dfs = [&](int row, int col, int prevValue) -> int {
            if (row < 0 || row >= n || col < 0 || col >= m || matrix[row][col] <= prevValue) {
                return 0;
            }

            int key = row * m + col;
            if (memo.count(key)) {
                return memo[key];
            }

            int res = 1;
            for (auto& dir : dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                res = max(res, 1 + dfs(newRow, newCol, matrix[row][col]));
            }

            memo[key] = res;
            return res;
        };

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                lis = max(lis, dfs(row, col, -1));
            }
        }
        return lis;
    }
};

int main() {
    Solution sol;
    // Test case 1: Example 1
    std::vector<std::vector<int>> mat1 = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    std::cout << sol.longestIncreasingPath(mat1) << " | 4" << std::endl;
    // Test case 2: Example 2
    std::vector<std::vector<int>> mat2 = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
    std::cout << sol.longestIncreasingPath(mat2) << " | 4" << std::endl;
    // Test case 3: Example 3
    std::vector<std::vector<int>> mat3 = {{1}};
    std::cout << sol.longestIncreasingPath(mat3) << " | 1" << std::endl;
    // Test case 4: All equal
    std::vector<std::vector<int>> mat4 = {{1, 1}, {1, 1}};
    std::cout << sol.longestIncreasingPath(mat4) << " | 1" << std::endl;
    // Test case 5: Increasing row
    std::vector<std::vector<int>> mat5 = {{1, 2, 3}};
    std::cout << sol.longestIncreasingPath(mat5) << " | 3" << std::endl;
    return 0;
}
