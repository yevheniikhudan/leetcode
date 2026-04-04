#include <iostream>
#include <cmath>
#include <iomanip>

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0.0;
        }
        if (n == 0) {
            return 1.0;
        }

        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        return fastPow(x, n);
    }
private:
    double fastPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        double result = fastPow(x * x, n / 2);
        return n % 2 == 0 ? result : x * result;
    }
};

// ---------- Test Helpers ----------

void check(double actual, double expected, const std::string& label, double tol = 1e-5) {
    bool ok = std::abs(actual - expected) <= tol;
    std::cout << std::fixed << std::setprecision(5)
              << actual << " | " << expected << " | "
              << (ok ? "PASS" : "FAIL")
              << " (" << label << ")\n";
}

// ---------- Tests ----------

int main() {
    Solution sol;

    check(sol.myPow(2.00000, 10),   1024.00000, "2^10");
    check(sol.myPow(2.10000, 3),    9.26100,    "2.1^3");
    check(sol.myPow(2.00000, -2),   0.25000,    "2^-2");
    check(sol.myPow(1.00000, 2147483647), 1.00000, "1^INT_MAX");
    check(sol.myPow(2.00000, 0),    1.00000,    "2^0");
    check(sol.myPow(-2.00000, 3),  -8.00000,    "-2^3");
    check(sol.myPow(0.00001, 2147483647), 0.00000, "tiny base, large n");

    return 0;
}
