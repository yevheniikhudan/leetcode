#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        unordered_set<int> visited;
        int maxTime = 0;
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            if (visited.count(u)) continue;
            visited.insert(u);
            maxTime = dist;
            for (auto& p : adj[u]) {
                int v = p.first, w = p.second;
                if (visited.count(v) == 0) {
                    pq.push({dist + w, v});
                }
            }
        }
        return visited.size() == n ? maxTime : -1;
    }
};

// Test helper
void testNetworkDelayTime() {
    Solution solution;

    // Test case 1: Example 1
    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n1 = 4;
    int k1 = 2;
    int expected1 = 2;
    int actual1 = solution.networkDelayTime(times1, n1, k1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    vector<vector<int>> times2 = {{1, 2, 1}};
    int n2 = 2;
    int k2 = 1;
    int expected2 = 1;
    int actual2 = solution.networkDelayTime(times2, n2, k2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: Example 3
    vector<vector<int>> times3 = {{1, 2, 1}};
    int n3 = 2;
    int k3 = 2;
    int expected3 = -1;
    int actual3 = solution.networkDelayTime(times3, n3, k3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: Single node
    vector<vector<int>> times4 = {};
    int n4 = 1;
    int k4 = 1;
    int expected4 = 0;
    int actual4 = solution.networkDelayTime(times4, n4, k4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: Disconnected nodes
    vector<vector<int>> times5 = {{1, 2, 1}, {3, 4, 1}};
    int n5 = 4;
    int k5 = 1;
    int expected5 = -1;
    int actual5 = solution.networkDelayTime(times5, n5, k5);
    cout << actual5 << " | " << expected5 << endl;

    // Test case 6: All connected
    vector<vector<int>> times6 = {{1, 2, 1}, {1, 3, 2}, {2, 3, 1}, {3, 4, 1}};
    int n6 = 4;
    int k6 = 1;
    int expected6 = 3;
    int actual6 = solution.networkDelayTime(times6, n6, k6);
    cout << actual6 << " | " << expected6 << endl;
}

int main() {
    testNetworkDelayTime();
    return 0;
}
