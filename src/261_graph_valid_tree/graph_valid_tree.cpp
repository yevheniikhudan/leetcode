#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            int src = edge[0], dest = edge[1];
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited[0] = true;
        int count = 1;
        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            for (int adj : adjList[node]) {
                if (adj == parent) continue;
                if (visited[adj]) return false;
                visited[adj] = true;
                ++count;
                q.push({adj, node});
            }
        }
        return count == n;
    }
};

// Test scaffolding
void test() {
    Solution sol;
    vector<vector<int>> e1 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << boolalpha << sol.validTree(5, e1) << " | true" << endl;
    vector<vector<int>> e2 = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << boolalpha << sol.validTree(5, e2) << " | false" << endl;
    vector<vector<int>> e3 = {};
    cout << boolalpha << sol.validTree(1, e3) << " | true" << endl;
    vector<vector<int>> e4 = {{0, 1}};
    cout << boolalpha << sol.validTree(2, e4) << " | true" << endl;
    vector<vector<int>> e5 = {};
    cout << boolalpha << sol.validTree(2, e5) << " | false" << endl;
}

int main() {
    test();
    return 0;
}
