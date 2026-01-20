#include <iostream>
#include <vector>
using namespace std;

class DSU {
   public:
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int node) {
        if (parent[node] != node) parent[node] = find(parent[node]);
        return parent[node];
    }
    bool union_(int node1, int node2) {
        int parent1 = find(node1), parent2 = find(node2);
        if (parent1 == parent2) return false;
        if (rank[parent1] < rank[parent2])
            parent[parent1] = parent2;
        else if (rank[parent2] < rank[parent1])
            parent[parent2] = parent1;
        else {
            parent[parent1] = parent2;
            rank[parent1]++;
        }
        return true;
    }
};

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for (const auto& edge : edges) {
            int src = edge[0] - 1, dst = edge[1] - 1;
            if (!dsu.union_(src, dst)) return {edge[0], edge[1]};
        }
        return {};
    }
};

// Test scaffolding
void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

void test() {
    Solution sol;
    vector<vector<int>> e1 = {{1, 2}, {1, 3}, {2, 3}};
    printVec(sol.findRedundantConnection(e1));
    cout << " | [2,3]\n";
    vector<vector<int>> e2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    printVec(sol.findRedundantConnection(e2));
    cout << " | [1,4]\n";
    vector<vector<int>> e3 = {{1, 2}, {2, 3}, {3, 1}};
    printVec(sol.findRedundantConnection(e3));
    cout << " | [3,1]\n";
    vector<vector<int>> e4 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    printVec(sol.findRedundantConnection(e4));
    cout << " | [4,1]\n";
}

int main() {
    test();
    return 0;
}
