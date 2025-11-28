/*
2872. Maximum Number of K-Divisible Components

There is an undirected tree with n nodes. Split the tree by removing edges
such that each resulting component has a sum of values divisible by k.
Return the maximum number of components possible.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n, vector<int>());
        res = 0;

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(adj, values, k, 0, -1);
        return res;
    }

   private:
    int res;

    int dfs(vector<vector<int>>& adj, vector<int>& values, int k, int cur_node, int parent) {
        int subtree_sum = values[cur_node] % k;

        for (int adj_node : adj[cur_node]) {
            if (adj_node != parent) {
                subtree_sum = (subtree_sum + dfs(adj, values, k, adj_node, cur_node)) % k;
            }
        }

        if (subtree_sum == 0) {
            res += 1;
        }

        return subtree_sum;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    int n1 = 5;
    vector<vector<int>> edges1 = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> values1 = {1, 8, 1, 4, 4};
    int k1 = 6;
    int result1 = solution.maxKDivisibleComponents(n1, edges1, values1, k1);
    cout << "Test 1: " << result1 << " (expected: 2)\n";

    // Test case 2: Example 2
    int n2 = 7;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    vector<int> values2 = {3, 0, 6, 1, 5, 2, 1};
    int k2 = 3;
    int result2 = solution.maxKDivisibleComponents(n2, edges2, values2, k2);
    cout << "Test 2: " << result2 << " (expected: 3)\n";

    // Test case 3: Single node
    int n3 = 1;
    vector<vector<int>> edges3 = {};
    vector<int> values3 = {10};
    int k3 = 5;
    int result3 = solution.maxKDivisibleComponents(n3, edges3, values3, k3);
    cout << "Test 3: " << result3 << " (expected: 1)\n";

    // Test case 4: All zeros
    int n4 = 4;
    vector<vector<int>> edges4 = {{0, 1}, {1, 2}, {2, 3}};
    vector<int> values4 = {0, 0, 0, 0};
    int k4 = 3;
    int result4 = solution.maxKDivisibleComponents(n4, edges4, values4, k4);
    cout << "Test 4: " << result4 << " (expected: 4)\n";

    // Test case 5: Linear tree
    int n5 = 3;
    vector<vector<int>> edges5 = {{0, 1}, {1, 2}};
    vector<int> values5 = {3, 6, 3};
    int k5 = 3;
    int result5 = solution.maxKDivisibleComponents(n5, edges5, values5, k5);
    cout << "Test 5: " << result5 << " (expected: 3)\n";
}

int main() {
    runTests();
    return 0;
}
