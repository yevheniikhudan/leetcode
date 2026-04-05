class Solution {

    /**
     * Count the number of '1' bits in the 32-bit representation of n.
     *
     * Skeleton only — no implementation provided.
     *
     * @param n 32-bit integer (interpret as two's-complement bit pattern)
     * @return number of set bits, or null if unimplemented
     */
    public int hammingWeight(int n) {
        int res = 0;

        while (n != 0) {
            n &= n - 1;
            res += 1;
        }

        return res;
    }
}

public class HammingWeight {

    private static void printResult(
        String actualStr,
        int expected,
        boolean pass
    ) {
        System.out.println(
            actualStr + " | " + expected + " | " + (pass ? "PASS" : "FAIL")
        );
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] inputs = {
            0b00000000000000000000000000001011, // 11 -> 3 ones
            0b00000000000000000000000010000000, // 128 -> 1 one
            0, // 0 -> 0
            0xFFFFFFFF, // -1 (all ones) -> 32 ones
            0x80000000, // highest bit only -> 1
            -3, // two's complement -3 -> 31 ones
        };

        int[] expected = { 3, 1, 0, 32, 1, 31 };

        for (int i = 0; i < inputs.length; i++) {
            Integer actual = sol.hammingWeight(inputs[i]);
            String actualStr = (actual == null) ? "null" : actual.toString();
            boolean pass = (actual != null && actual.intValue() == expected[i]);
            printResult(actualStr, expected[i], pass);
        }
    }
}
