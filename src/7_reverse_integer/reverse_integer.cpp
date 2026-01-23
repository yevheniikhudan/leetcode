#include <climits>
#include <iostream>

class Solution {
   public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int digit = x % 10;
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0;
            }
            ans = (ans * 10) + digit;
            x = x / 10;
        }

        return ans;
    }
};

// Test helper
void testReverse() {
    Solution solution;

    // Test case 1: Example 1
    int x1 = 123;
    int expected1 = 321;
    int actual1 = solution.reverse(x1);
    std::cout << actual1 << " | " << expected1 << std::endl;

    // Test case 2: Example 2
    int x2 = -123;
    int expected2 = -321;
    int actual2 = solution.reverse(x2);
    std::cout << actual2 << " | " << expected2 << std::endl;

    // Test case 3: Example 3
    int x3 = 120;
    int expected3 = 21;
    int actual3 = solution.reverse(x3);
    std::cout << actual3 << " | " << expected3 << std::endl;

    // Test case 4: x=0
    int x4 = 0;
    int expected4 = 0;
    int actual4 = solution.reverse(x4);
    std::cout << actual4 << " | " << expected4 << std::endl;

    // Test case 5: Positive overflow
    int x5 = 1534236469;
    int expected5 = 0;
    int actual5 = solution.reverse(x5);
    std::cout << actual5 << " | " << expected5 << std::endl;

    // Test case 6: Negative overflow
    int x6 = -1534236469;
    int expected6 = 0;
    int actual6 = solution.reverse(x6);
    std::cout << actual6 << " | " << expected6 << std::endl;
}

int main() {
    testReverse();
    return 0;
}
