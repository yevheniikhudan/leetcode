#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }

        return a;
    }
};

// ---------- Test Helpers ----------

void check(int actual, int expected, const std::string& label) {
    bool ok = actual == expected;
    std::cout << actual << " | " << expected << " | "
              << (ok ? "PASS" : "FAIL")
              << " (" << label << ")\n";
}

// ---------- Tests ----------

int main() {
    Solution sol;

    check(sol.getSum(1, 2), 3, "Example 1");
    check(sol.getSum(2, 3), 5, "Example 2");
    check(sol.getSum(-1, 1), 0, "Example 3 (negative)");
    check(sol.getSum(0, 0), 0, "Both zero");
    check(sol.getSum(5, -3), 2, "Mixed signs");
    check(sol.getSum(-5, -3), -8, "Both negative");
    check(sol.getSum(1000, -1000), 0, "Large values cancel");

    return 0;
}
