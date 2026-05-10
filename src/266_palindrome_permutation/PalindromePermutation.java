class Solution {
    public boolean canPermutePalindrome(String s) {
        // TODO: Implement the solution.
        return false;
    }
}

public class PalindromePermutation {

    private static void runTest(String s, boolean expected) {
        Solution solution = new Solution();
        boolean actual = solution.canPermutePalindrome(s);
        String status = actual == expected ? "PASS" : "FAIL";
        System.out.println(actual + " | " + expected + " | " + status);
    }

    public static void main(String[] args) {
        runTest("code", false);
        runTest("aab", true);
        runTest("carerac", true);
        runTest("a", true);
        runTest("abc", false);
    }
}
