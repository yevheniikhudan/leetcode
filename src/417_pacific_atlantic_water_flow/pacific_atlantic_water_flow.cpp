#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if (heights.empty() || heights[0].empty()) return res;
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& vis) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                if (vis[r][c]) continue;
                vis[r][c] = true;
                for (auto& d : dirs) {
                    int nr = r + d.first, nc = c + d.second;
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !vis[nr][nc] &&
                        heights[nr][nc] >= heights[r][c]) {
                        q.push({nr, nc});
                    }
                }
            }
        };
        queue<pair<int, int>> q;
        // Pacific
        for (int c = 0; c < COLS; ++c) q.push({0, c});
        for (int r = 0; r < ROWS; ++r) q.push({r, 0});
        bfs(q, pac);
        // Atlantic
        q = queue<pair<int, int>>();
        for (int c = 0; c < COLS; ++c) q.push({ROWS - 1, c});
        for (int r = 0; r < ROWS; ++r) q.push({r, COLS - 1});
        bfs(q, atl);
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) res.push_back({r, c});
            }
        }
        return res;
    }
};

void printVec(const vector<vector<int>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "[" << v[i][0] << "," << v[i][1] << "]";
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;
    vector<vector<int>> t1 = {
        {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    printVec(sol.pacificAtlantic(t1));
    cout << " | [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]" << endl;
    vector<vector<int>> t2 = {{1}};
    printVec(sol.pacificAtlantic(t2));
    cout << " | [[0,0]]" << endl;
    vector<vector<int>> t3 = {};
    printVec(sol.pacificAtlantic(t3));
    cout << " | []" << endl;
    vector<vector<int>> t4 = {{1, 2}, {4, 3}};
    printVec(sol.pacificAtlantic(t4));
    cout << " | [[0,1],[1,0],[1,1]]" << endl;
    vector<vector<int>> t5 = {{2, 1}, {1, 2}};
    printVec(sol.pacificAtlantic(t5));
    cout << " | [[0,0],[0,1],[1,0],[1,1]]" << endl;
    return 0;
}
