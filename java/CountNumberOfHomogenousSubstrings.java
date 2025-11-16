public class CountNumberOfHomogenousSubstrings {
    public int countHomogenous(String s) {
        int MOD = (int) 1e9 + 7;

        int ans = 0;
        int streak = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s.charAt(i) == s.charAt(i - 1)) {
                streak += 1;
            } else {
                streak = 1;
            }

            ans = (ans + streak) % MOD;
        }

        return ans;
    }

    public static void main(String[] args) {
        CountNumberOfHomogenousSubstrings sol = new CountNumberOfHomogenousSubstrings();
        assert sol.countHomogenous("abbcccaa") == 13;
        assert sol.countHomogenous("xy") == 2;
        assert sol.countHomogenous("zzzzz") == 15;
        System.out.println("All test cases passed!");
    }
}
