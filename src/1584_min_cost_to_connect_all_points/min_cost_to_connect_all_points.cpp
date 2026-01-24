#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) return 0;

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        vector<bool> visit(n, false);
        int edges = 0;
        int cost = 0;

        while (edges < n - 1) {
            int minDist = INT_MAX;
            int u = -1;

            // Find the unvisited node with minimum distance
            for (int i = 0; i < n; i++) {
                if (!visit[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1) break;  // No more nodes to visit

            visit[u] = true;
            cost += minDist;
            edges++;

            // Update distances to unvisited neighbors
            for (int v = 0; v < n; v++) {
                if (!visit[v]) {
                    int manhattan =
                        abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (manhattan < dist[v]) {
                        dist[v] = manhattan;
                    }
                }
            }
        }

        return cost;
    }
};

// Test helper
void testMinCostConnectPoints() {
    Solution solution;

    // Test case 1: Example 1
    vector<vector<int>> points1 = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    int expected1 = 20;
    int actual1 = solution.minCostConnectPoints(points1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    vector<vector<int>> points2 = {{3, 12}, {-2, 5}, {-4, 1}};
    int expected2 = 18;
    int actual2 = solution.minCostConnectPoints(points2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: Single point
    vector<vector<int>> points3 = {{0, 0}};
    int expected3 = 0;
    int actual3 = solution.minCostConnectPoints(points3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: Two points
    vector<vector<int>> points4 = {{0, 0}, {1, 1}};
    int expected4 = 2;
    int actual4 = solution.minCostConnectPoints(points4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: Three points in line
    vector<vector<int>> points5 = {{0, 0}, {1, 0}, {2, 0}};
    int expected5 = 2;
    int actual5 = solution.minCostConnectPoints(points5);
    cout << actual5 << " | " << expected5 << endl;
}

int main()