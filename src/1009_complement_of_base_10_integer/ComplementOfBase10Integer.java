class Solution {
    public int bitwiseComplement(int n) {
        if (n == 0) {
            return 0;
        }

        int value = n;
        int mask = 0;

        while (value > 0) {
            mask = (mask << 1) | 1;
            value >>= 1;
        }

        return mask ^ n;
    }
}

public class ComplementOfBase10Integer {
    private static void runTests() {
        Solution sol = new Solution();
        int[] inputs = { 5, 7, 10, 0, 1, 8 };
        int[] expecteds = { 2, 0, 5, 1, 0, 7 };

        for (int i = 0; i < inputs.length; i++) {
            int actual = sol.bitwiseComplement(inputs[i]);
            System.out.println(actual + " | " + expecteds[i]);
        }
    }

    public static void main(String[] args) {
        runTests();
    }
}