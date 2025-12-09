public class MinimumOneBitOperations {
    /**
     * Given an integer n, transform it into 0 using minimum operations.
     * 
     * Operations allowed:
     * 1. Change the rightmost (0th) bit
     * 2. Change the ith bit if (i-1)th bit is 1 and (i-2)th through 0th bits are 0
     * 
     * @param n Integer to transform (0 <= n <= 10^9)
     * @return Minimum number of operations to make n equal to 0
     */
    public int minimumOneBitOperations(int n) {
        int ans = 0;
        int k = 0;
        int mask = 1;

        while (mask <= n) {
            if ((n & mask) != 0) {
                ans = (1 << (k + 1)) - 1 - ans;
            }

            mask <<= 1;
            k++;
        }

        return ans;
    }

    public static void testMinimumOneBitOperations() {
        MinimumOneBitOperations solution = new MinimumOneBitOperations();

        // Test case 1: n = 3
        assert solution.minimumOneBitOperations(3) == 2 : "Test case 1 failed";
        System.out.println("✓ Test case 1 passed");

        // Test case 2: n = 6
        assert solution.minimumOneBitOperations(6) == 4 : "Test case 2 failed";
        System.out.println("✓ Test case 2 passed");

        // Test case 3: n = 0
        assert solution.minimumOneBitOperations(0) == 0 : "Test case 3 failed";
        System.out.println("✓ Test case 3 passed");

        // Test case 4: n = 1
        assert solution.minimumOneBitOperations(1) == 1 : "Test case 4 failed";
        System.out.println("✓ Test case 4 passed");

        System.out.println("All test cases passed!");
    }

    public static void main(String[] args) {
        testMinimumOneBitOperations();
    }
}
