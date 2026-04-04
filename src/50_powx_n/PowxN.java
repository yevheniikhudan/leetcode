class Solution {

    public double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        return fastPow(x, n);
    }

    private double fastPow(double x, long n) {
        if (n == 0) {
            return 1.0;
        }

        return n % 2 == 0 ? fastPow(x * x, n / 2) : x * fastPow(x * x, n / 2);
    }
}

class PowxN {

    // ---------- Test Helpers ----------

    static void check(double actual, double expected, String label) {
        boolean ok = Math.abs(actual - expected) <= 1e-5;
        String status = ok ? "PASS" : "FAIL";
        System.out.printf(
            "%.5f | %.5f | %s (%s)%n",
            actual,
            expected,
            status,
            label
        );
    }

    // ---------- Tests ----------

    public static void main(String[] args) {
        Solution sol = new Solution();

        check(sol.myPow(2.00000, 10), 1024.00000, "2^10");
        check(sol.myPow(2.10000, 3), 9.26100, "2.1^3");
        check(sol.myPow(2.00000, -2), 0.25000, "2^-2");
        check(sol.myPow(1.00000, 2147483647), 1.00000, "1^INT_MAX");
        check(sol.myPow(2.00000, 0), 1.00000, "2^0");
        check(sol.myPow(-2.00000, 3), -8.00000, "-2^3");
        check(sol.myPow(0.00001, 2147483647), 0.00000, "tiny base, large n");
    }
}
