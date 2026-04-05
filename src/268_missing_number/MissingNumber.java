class Solution {

    public int missingNumber(int[] nums) {
        int res = 0;

        for (int i = 0; i < nums.length; i++) {
            res ^= i + 1;
            res ^= nums[i];
        }

        return res;
    }
}

class MissingNumber {

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

        check(sol.missingNumber(new int[] { 3, 0, 1 }), 2, "Example 1");
        check(sol.missingNumber(new int[] { 0, 1 }), 2, "Example 2");
        check(
            sol.missingNumber(new int[] { 9, 6, 4, 2, 3, 5, 7, 0, 1 }),
            8,
            "Example 3"
        );
        check(sol.missingNumber(new int[] { 0 }), 1, "Missing last element");
        check(sol.missingNumber(new int[] { 1 }), 0, "Missing first element");
        check(sol.missingNumber(new int[] { 2, 0, 1 }), 3, "Missing at end");
        check(
            sol.missingNumber(new int[] { 0, 1, 2, 3, 4, 5, 6, 7, 8 }),
            9,
            "Large range"
        );
    }
}
