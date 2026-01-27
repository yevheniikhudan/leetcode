#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumCostPath(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, 2 * w});
        }

        vector<int> shortest(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            h;  // min-heap
        h.push({0, 0});

        while (!h.empty()) {
            auto [weight, u] = h.top();
            h.pop();

            if (shortest[u] != -1) continue;

            shortest[u] = weight;

            if (u == n - 1) return weight;

            for (auto& adj : adjList[u]) {
                int adjNode = adj.first, adjWeight = adj.second;
                if (shortest[adjNode] != -1) continue;

                h.push({adjWeight + weight, adjNode});
            }
        }

        return shortest[n - 1];
    }
};

// Test helper
void testMinimumCostPath() {
    Solution solution;

    // Test case 1: Example 1
    int n1 = 4;
    vector<vector<int>> edges1 = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
    int expected1 = 5;
    int actual1 = solution.minimumCostPath(n1, edges1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    int n2 = 4;
    vector<vector<int>> edges2 = {{0, 2, 1}, {2, 1, 1}, {1, 3, 1}, {2, 3, 3}};
    int expected2 = 3;
    int actual2 = solution.minimumCostPath(n2, edges2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: No path
    int n3 = 3;
    vector<vector<int>> edges3 = {{0, 1, 1}, {1, 2, 1}};
    int expected3 = 2;
    int actual3 = solution.minimumCostPath(n3, edges3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: Direct path
    int n4 = 2;
    vector<vector<int>> edges4 = {{0, 1, 5}};
    int expected4 = 5;
    int actual4 = solution.minimumCostPath(n4, edges4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: Reversal needed
    int n5 = 3;
    vector<vector<int>> edges5 = {{1, 0, 1}, {1, 2, 1}};
    int expected5 = 3;
    int actual5 = solution.minimumCostPath(n5, edges5);
    cout << actual5 << " | " << expected5 << endl;

    // Test case 6: Impossible
    int n6 = 3;
    vector<vector<int>> edges6 = {{0, 1, 1}};
    int expected6 = -1;
    int actual6 = solution.minimumCostPath(n6, edges6);
    cout << actual6 << " | " << expected6 << endl;
}

int main() {
    testMinimumCostPath();
    return 0;
}
