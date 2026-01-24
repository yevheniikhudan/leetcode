#include <vector>

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        vector<vector<pair<int, int>>> adjList(n);
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], cst = flight[2];
            adjList[u].push_back({v, cst});
        }

        queue<tuple<int, int, int>> q;  // {cost, node, stops}
        q.push({0, src, 0});

        while (!q.empty()) {
            auto [cst, node, stops] = q.front();
            q.pop();
            if (stops > k) continue;

            for (auto& adj : adjList[node]) {
                int adjNode = adj.first, adjCost = adj.second;
                int newCost = cst + adjCost;
                if (newCost < prices[adjNode]) {
                    prices[adjNode] = newCost;
                    q.push({newCost, adjNode, stops + 1});
                }
            }
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};

// Test helper
void testFindCheapestPrice() {
    Solution solution;

    // Test case 1: Example 1
    int n1 = 4;
    std::vector<std::vector<int>> flights1 = {
        {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src1 = 0, dst1 = 3, k1 = 1;
    int expected1 = 700;
    int actual1 = solution.findCheapestPrice(n1, flights1, src1, dst1, k1);
    std::cout << actual1 << " | " << expected1 << std::endl;

    // Test case 2: Example 2
    int n2 = 3;
    std::vector<std::vector<int>> flights2 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src2 = 0, dst2 = 2, k2 = 1;
    int expected2 = 200;
    int actual2 = solution.findCheapestPrice(n2, flights2, src2, dst2, k2);
    std::cout << actual2 << " | " << expected2 << std::endl;

    // Test case 3: Example 3
    int n3 = 3;
    std::vector<std::vector<int>> flights3 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src3 = 0, dst3 = 2, k3 = 0;
    int expected3 = 500;
    int actual3 = solution.findCheapestPrice(n3, flights3, src3, dst3, k3);
    std::cout << actual3 << " | " << expected3 << std::endl;

    // Test case 4: No path
    int n4 = 3;
    std::vector<std::vector<int>> flights4 = {{0, 1, 100}, {1, 2, 100}};
    int src4 = 0, dst4 = 2, k4 = 0;
    int expected4 = -1;
    int actual4 = solution.findCheapestPrice(n4, flights4, src4, dst4, k4);
    std::cout << actual4 << " | " << expected4 << std::endl;

    // Test case 5: Direct flight cheaper
    int n5 = 2;
    std::vector<std::vector<int>> flights5 = {{0, 1, 50}, {0, 1, 100}};
    int src5 = 0, dst5 = 1, k5 = 1;
    int expected5 = 50;
    int actual5 = solution.findCheapestPrice(n5, flights5, src5, dst5, k5);
    std::cout << actual5 << " | " << expected5 << std::endl;
}

int main() {
    testFindCheapestPrice();
    return 0;
}
