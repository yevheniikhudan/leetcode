/*
121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock 
on the ith day. You want to maximize your profit by choosing a single day to 
buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot 
achieve any profit, return 0.
*/

public class BestTimeToBuyAndSellStock {
    /**
     * Find maximum profit from single buy and sell transaction.
     * 
     * @param prices Array of stock prices by day
     * @return Maximum profit achievable
     * 
     *         Time Complexity: O(n)
     *         Space Complexity: O(1)
     */
    public int maxProfit(int[] prices) {
        int res = 0;
        int minPrice = Integer.MAX_VALUE;

        for (int price : prices) {
            minPrice = Math.min(minPrice, price);
            res = Math.max(res, price - minPrice);
        }

        return res;
    }

    public static void main(String[] args) {
        BestTimeToBuyAndSellStock solution = new BestTimeToBuyAndSellStock();

        // Test case 1: Example 1
        int[] prices1 = { 7, 1, 5, 3, 6, 4 };
        int result1 = solution.maxProfit(prices1);
        System.out.printf("Test 1: %d (expected: 5)%n", result1);

        // Test case 2: Example 2 - prices decreasing
        int[] prices2 = { 7, 6, 4, 3, 1 };
        int result2 = solution.maxProfit(prices2);
        System.out.printf("Test 2: %d (expected: 0)%n", result2);

        // Test case 3: Single element
        int[] prices3 = { 5 };
        int result3 = solution.maxProfit(prices3);
        System.out.printf("Test 3: %d (expected: 0)%n", result3);

        // Test case 4: Prices increasing
        int[] prices4 = { 1, 2, 3, 4, 5 };
        int result4 = solution.maxProfit(prices4);
        System.out.printf("Test 4: %d (expected: 4)%n", result4);

        // Test case 5: All same price
        int[] prices5 = { 3, 3, 3, 3 };
        int result5 = solution.maxProfit(prices5);
        System.out.printf("Test 5: %d (expected: 0)%n", result5);

        // Test case 6: Two elements
        int[] prices6 = { 2, 4 };
        int result6 = solution.maxProfit(prices6);
        System.out.printf("Test 6: %d (expected: 2)%n", result6);

        // Test case 7: Buy at end
        int[] prices7 = { 3, 2, 6, 5, 0, 3 };
        int result7 = solution.maxProfit(prices7);
        System.out.printf("Test 7: %d (expected: 4)%n", result7);

        // Test case 8: Large dataset simulation
        int[] prices8 = { 2, 1, 4, 5, 2, 9, 7 };
        int result8 = solution.maxProfit(prices8);
        System.out.printf("Test 8: %d (expected: 8)%n", result8);
    }
}
