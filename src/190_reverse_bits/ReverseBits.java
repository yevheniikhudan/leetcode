class Solution {

    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= n & 1;
            n >>= 1;
        }

        return res;
    }
}

class ReverseBits {

    // ---------- Test Helpers ----------

    static void check(int actual, int expected, String label) {
        boolean ok = actual == expected;
        String status = ok ? "PASS" : "FAIL";
        System.out.println(
            actual + " | " + expected + " | " + status + " (" + label + ")"
        );
    }

    // ---------- Tests ----------

    public static void main(String[] args) {
        Solution sol = new Solution();

        check(sol.reverseBits(43261596), 964176192, "Example 1");
        check(
            sol.reverseBits(-3),
            -1073741825,
            "Example 2 (signed representation)"
        );
        check(sol.reverseBits(0), 0, "All zeros");
        // check(sol.reverseBits(1), 2147483648, "Single bit at position 0");
        check(
            sol.reverseBits(Integer.MIN_VALUE),
            1,
            "Single bit at position 31"
        );
        check(sol.reverseBits(-1), -1, "All ones (signed: -1)");
        check(
            sol.reverseBits(2),
            1073741824,
            "00000000000000000000000000000010"
        );
    }
}
