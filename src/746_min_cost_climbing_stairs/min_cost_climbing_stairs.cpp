#include <iostream>
#include <vector>

class Solution {
   public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int a = cost[0], b = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            int next = cost[i] + min(a, b);
            a = b;
            b = next;
        }

        return min(a, b);
    }
};

// Test helper
void testMinCostClimbingStairs() {
    Solution solution;

    // Test case 1: Example 1
    std::vector<int> cost1 = {10, 15, 20};
    int expected1 = 15;
    int actual1 = solution.minCostClimbingStairs(cost1);
    std::cout << actual1 << " | " << expected1 << std::endl;

    // Test case 2: Example 2
    std::vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int expected2 = 6;
    int actual2 = solution.minCostClimbingStairs(cost2);
    std::cout << actual2 << " | " << expected2 << std::endl;

    // Test case 3: n=2
    std::vector<int> cost3 = {1, 2};
    int expected3 = 1;
    int actual3 = solution.minCostClimbingStairs(cost3);
    std::cout << actual3 << " | " << expected3 << std::endl;

    // Test case 4: Equal costs
    std::vector<int> cost4 = {5, 5, 5};
    int expected4 = 5;
    int actual4 = solution.minCostClimbingStairs(cost4);
    std::cout << actual4 << " | " << expected4 << std::endl;

    // Test case 5: Increasing
    std::vector<int> cost5 = {1, 2, 3, 4};
    int expected5 = 6;
    int actual5 = solution.minCostClimbingStairs(cost5);
    std::cout << actual5 << " | " << expected5 << std::endl;
}

int main() {
    testMinCostClimbingStairs();
    return 0;
}
