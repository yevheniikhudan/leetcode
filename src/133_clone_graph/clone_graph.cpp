#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors() {}
    Node(int _val) : val(_val), neighbors() {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* newNode = new Node(node->val);
        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return newNode;
    }
};

// Helper to build a graph from adjacency list
Node* buildGraph(const vector<vector<int>>& adj) {
    if (adj.empty()) return nullptr;
    vector<Node*> nodes(adj.size(), nullptr);
    for (int i = 0; i < adj.size(); ++i) nodes[i] = new Node(i + 1);
    for (int i = 0; i < adj.size(); ++i)
        for (int n : adj[i]) nodes[i]->neighbors.push_back(nodes[n - 1]);
    return nodes[0];
}
// Helper to print adjacency list
void printGraph(Node* node) {
    if (!node) {
        cout << "[]" << endl;
        return;
    }
    set<int> visited;
    vector<pair<int, vector<int>>> res;
    function<void(Node*)> dfs = [&](Node* n) {
        if (visited.count(n->val)) return;
        visited.insert(n->val);
        vector<int> neigh;
        for (auto x : n->neighbors) neigh.push_back(x->val);
        sort(neigh.begin(), neigh.end());
        res.push_back({n->val, neigh});
        for (auto x : n->neighbors) dfs(x);
    };
    dfs(node);
    sort(res.begin(), res.end());
    for (auto& p : res) {
        cout << "(" << p.first << ", [";
        for (size_t i = 0; i < p.second.size(); ++i) {
            cout << p.second[i];
            if (i + 1 < p.second.size()) cout << ", ";
        }
        cout << "])";
    }
    cout << endl;
}

int main() {
    // Test case 1: Empty graph
    Node* node = buildGraph({});
    Node* cloned = Solution().cloneGraph(node);
    cout << (cloned == nullptr) << endl;  // true

    // Test case 2: Single node, no neighbors
    node = buildGraph({{}});
    cloned = Solution().cloneGraph(node);
    printGraph(cloned);  // (1, [])

    // Test case 3: Two nodes, one edge
    node = buildGraph({{2}, {1}});
    cloned = Solution().cloneGraph(node);
    printGraph(cloned);  // (1, [2])(2, [1])

    // Test case 4: Four nodes, square
    node = buildGraph({{2, 4}, {1, 3}, {2, 4}, {1, 3}});
    cloned = Solution().cloneGraph(node);
    printGraph(cloned);  // (1, [2, 4])(2, [1, 3])(3, [2, 4])(4, [1, 3])

    // Test case 5: Three nodes, chain
    node = buildGraph({{2}, {1, 3}, {2}});
    cloned = Solution().cloneGraph(node);
    printGraph(cloned);  // (1, [2])(2, [1, 3])(3, [2])
    return 0;
}
