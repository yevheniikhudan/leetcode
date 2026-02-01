class Solution {
    public int maxProfit(int[] prices) {
        long hold = Long.MIN_VALUE;
        int sold = 0;
        int rest = 0;

        for (int price : prices) {
            int prevSold = sold;
            sold = (int) (hold + price);
            hold = Math.max(hold, rest - price);
            rest = Math.max(rest, prevSold);
        }

        return Math.max(sold, rest);
    }
}

class BestTimeToBuyAndSellStockWithCooldown {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // Test cases
        testCase(sol, new int[] { 1, 2, 3, 0, 2 }, 3);
        testCase(sol, new int[] { 1 }, 0);
        testCase(sol, new int[] { 1, 2 }, 1);
        testCase(sol, new int[] { 2, 1 }, 0);
        testCase(sol, new int[] { 1, 2, 4 }, 3);
        testCase(sol, new int[] { 1, 3, 2, 4 }, 4);
    }

    private static void testCase(Solution sol, int[] prices, int expected) {
        int actual = sol.maxProfit(prices);
        System.out.println(actual + " | " + expected);
    }
}
