#include <iostream>
#include <vector>

class Solution {
   public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        // TODO: Implement the solution
        return -1;
    }
};

// Test helper
void testSwimInWater() {
    Solution solution;

    // Test case 1: Example 1
    std::vector<std::vector<int>> grid1 = {{0, 2}, {1, 3}};
    int expected1 = 3;
    int actual1 = solution.swimInWater(grid1);
    std::cout << actual1 << " | " << expected1 << std::endl;

    // Test case 2: Example 2
    std::vector<std::vector<int>> grid2 = {{0, 1, 2, 3, 4},
                                           {24, 23, 22, 21, 5},
                                           {12, 13, 14, 15, 16},
                                           {11, 17, 18, 19, 20},
                                           {10, 9, 8, 7, 6}};
    int expected2 = 16;
    int actual2 = solution.swimInWater(grid2);
    std::cout << actual2 << " | " << expected2 << std::endl;

    // Test case 3: n=1
    std::vector<std::vector<int>> grid3 = {{5}};
    int expected3 = 5;
    int actual3 = solution.swimInWater(grid3);
    std::cout << actual3 << " | " << expected3 << std::endl;

    // Test case 4: 2x2 simple
    std::vector<std::vector<int>> grid4 = {{0, 1}, {2, 3}};
    int expected4 = 3;
    int actual4 = solution.swimInWater(grid4);
    std::cout << actual4 << " | " << expected4 << std::endl;

    // Test case 5: Already connected
    std::vector<std::vector<int>> grid5 = {{0, 0}, {0, 0}};
    int expected5 = 0;
    int actual5 = solution.swimInWater(grid5);
    std::cout << actual5 << " | " << expected5 << std::endl;
}

int main() {
    testSwimInWater();
    return 0;
}
