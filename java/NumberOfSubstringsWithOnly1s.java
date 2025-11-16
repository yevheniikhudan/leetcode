public class NumberOfSubstringsWithOnly1s {
    public int numSub(String s) {
        final int MOD = (int) Math.pow(10, 9) + 7;
        int consecutive = 0;
        long ans = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '1') {
                consecutive += 1;
            } else {
                ans += consecutive * ((long) consecutive + 1) / 2;
                consecutive = 0;
            }
        }
        ans += consecutive * ((long) consecutive + 1) / 2;
        ans %= MOD;

        return (int) ans;
    }

    public static void main(String[] args) {
        NumberOfSubstringsWithOnly1s sol = new NumberOfSubstringsWithOnly1s();
        assert sol.numSub("0110111") == 9;
        assert sol.numSub("101") == 2;
        assert sol.numSub("1111") == 10;
        System.out.println("All test cases passed!");
    }
}
