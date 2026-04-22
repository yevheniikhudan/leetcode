#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Union-Find helper class
class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
};

class Solution {
public:
    int minimumHammingDistance(
        vector<int>& source,
        vector<int>& target,
        vector<vector<int>>& allowedSwaps
    ) {
        int ans = 0;
        int n = source.size();
        UnionFind uf(n);
        map<pair<int, int>, int> sets;

        for (int i = 0; i < allowedSwaps.size(); i++) {
            uf.unite(allowedSwaps[i][0], allowedSwaps[i][1]);
        }

        for (int i = 0; i < source.size(); i++) {
            int parent = uf.find(source[i]);
            sets[{parent, source[i]}] += 1;
        }

        for (int i = 0; i < target.size(); i++) {
            int parent = uf.find(target[i]);
            if (sets[{parent, target[i]}] > 0) {
                sets[{parent, target[i]}] -= 1;
            } else {
                ans += 1;
            }
        }

        return ans;
    }
};

void printResult(int actual, int expected) {
    cout << actual << " | " << expected;
    if (actual == expected) {
        cout << " | PASS" << endl;
    } else {
        cout << " | FAIL" << endl;
    }
}

int main() {
    Solution solution;

    // Test case 1: Simple case with swap pairs
    vector<int> source1 = {1, 2, 3, 4};
    vector<int> target1 = {2, 1, 4, 5};
    vector<vector<int>> allowedSwaps1 = {{0, 1}, {2, 3}};
    int expected1 = 1;
    int result1 = solution.minimumHammingDistance(source1, target1, allowedSwaps1);
    cout << "Test 1: Simple swap pairs | ";
    printResult(result1, expected1);

    // Test case 2: No swaps allowed
    vector<int> source2 = {1, 2, 3};
    vector<int> target2 = {4, 5, 6};
    vector<vector<int>> allowedSwaps2 = {};
    int expected2 = 3;
    int result2 = solution.minimumHammingDistance(source2, target2, allowedSwaps2);
    cout << "Test 2: No swaps allowed | ";
    printResult(result2, expected2);

    // Test case 3: All elements connected
    vector<int> source3 = {1, 2, 3, 4};
    vector<int> target3 = {2, 1, 4, 3};
    vector<vector<int>> allowedSwaps3 = {{0, 1}, {1, 2}, {2, 3}};
    int expected3 = 0;
    int result3 = solution.minimumHammingDistance(source3, target3, allowedSwaps3);
    cout << "Test 3: All elements connected | ";
    printResult(result3, expected3);

    // Test case 4: Identical arrays
    vector<int> source4 = {1, 2, 3};
    vector<int> target4 = {1, 2, 3};
    vector<vector<int>> allowedSwaps4 = {};
    int expected4 = 0;
    int result4 = solution.minimumHammingDistance(source4, target4, allowedSwaps4);
    cout << "Test 4: Identical arrays | ";
    printResult(result4, expected4);

    // Test case 5: Single element
    vector<int> source5 = {1};
    vector<int> target5 = {2};
    vector<vector<int>> allowedSwaps5 = {};
    int expected5 = 1;
    int result5 = solution.minimumHammingDistance(source5, target5, allowedSwaps5);
    cout << "Test 5: Single element | ";
    printResult(result5, expected5);

    // Test case 6: Transitive connections
    vector<int> source6 = {5, 1, 2, 4, 3};
    vector<int> target6 = {1, 5, 4, 2, 3};
    vector<vector<int>> allowedSwaps6 = {{0, 4}, {4, 2}, {1, 3}, {1, 4}};
    int expected6 = 0;
    int result6 = solution.minimumHammingDistance(source6, target6, allowedSwaps6);
    cout << "Test 6: Transitive connections | ";
    printResult(result6, expected6);

    return 0;
}
