#include <iostream>

class Solution {
   public:
    int totalMoney(int n) {
        int k = n / 7;
        int f = 28;
        int l = f + (k - 1) * 7;
        int arithmeticSum = k * (f + l) / 2;
        int monday = 1 + k;
        int finalWeek = 0;
        for (int day = 0; day < n % 7; day++) {
            finalWeek += monday + day;
        }
        return arithmeticSum + finalWeek;
    }
};

// Test helper
void testTotalMoney() {
    Solution solution;

    // Test case 1: Example 1
    int n1 = 4;
    int expected1 = 10;
    int actual1 = solution.totalMoney(n1);
    std::cout << actual1 << " | " << expected1 << std::endl;

    // Test case 2: Example 2
    int n2 = 10;
    int expected2 = 37;
    int actual2 = solution.totalMoney(n2);
    std::cout << actual2 << " | " << expected2 << std::endl;

    // Test case 3: Example 3
    int n3 = 20;
    int expected3 = 96;
    int actual3 = solution.totalMoney(n3);
    std::cout << actual3 << " | " << expected3 << std::endl;

    // Test case 4: n=1
    int n4 = 1;
    int expected4 = 1;
    int actual4 = solution.totalMoney(n4);
    std::cout << actual4 << " | " << expected4 << std::endl;

    // Test case 5: n=7
    int n5 = 7;
    int expected5 = 28;
    int actual5 = solution.totalMoney(n5);
    std::cout << actual5 << " | " << expected5 << std::endl;

    // Test case 6: n=8
    int n6 = 8;
    int expected6 = 30;
    int actual6 = solution.totalMoney(n6);
    std::cout << actual6 << " | " << expected6 << std::endl;
}

int main() {
    testTotalMoney();
    return 0;
}
