#include <iostream>

class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 1;
        for (int i = 2; i < n + 1; i++) {
            int next = a + b;
            a = b;
            b = next;
        }

        return b;
    }
};

// Test helper
void testClimbStairs() {
    Solution solution;

    // Test case 1: n=2
    int n1 = 2;
    int expected1 = 2;
    int actual1 = solution.climbStairs(n1);
    std::cout << actual1 << " | " << expected1 << std::endl;

    // Test case 2: n=3
    int n2 = 3;
    int expected2 = 3;
    int actual2 = solution.climbStairs(n2);
    std::cout << actual2 << " | " << expected2 << std::endl;

    // Test case 3: n=1
    int n3 = 1;
    int expected3 = 1;
    int actual3 = solution.climbStairs(n3);
    std::cout << actual3 << " | " << expected3 << std::endl;

    // Test case 4: n=4
    int n4 = 4;
    int expected4 = 5;
    int actual4 = solution.climbStairs(n4);
    std::cout << actual4 << " | " << expected4 << std::endl;

    // Test case 5: n=5
    int n5 = 5;
    int expected5 = 8;
    int actual5 = solution.climbStairs(n5);
    std::cout << actual5 << " | " << expected5 << std::endl;
}

int main() {
    testClimbStairs();
    return 0;
}
