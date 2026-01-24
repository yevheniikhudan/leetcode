import java.util.*;

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int a = cost[0], b = cost[1];

        for (int i = 0; i < cost.length; i++) {
            int next = cost[i] + Math.min(a, b);
            a = b;
            b = next;
        }

        return Math.min(a, b);
    }
}

public class MinCostClimbingStairs {
    public static void main(String[] args) {
        testMinCostClimbingStairs();
    }

    // Test helper
    public static void testMinCostClimbingStairs() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int[] cost1 = { 10, 15, 20 };
        int expected1 = 15;
        int actual1 = solution.minCostClimbingStairs(cost1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int[] cost2 = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
        int expected2 = 6;
        int actual2 = solution.minCostClimbingStairs(cost2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: n=2
        int[] cost3 = { 1, 2 };
        int expected3 = 1;
        int actual3 = solution.minCostClimbingStairs(cost3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: Equal costs
        int[] cost4 = { 5, 5, 5 };
        int expected4 = 5;
        int actual4 = solution.minCostClimbingStairs(cost4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Increasing
        int[] cost5 = { 1, 2, 3, 4 };
        int expected5 = 6;
        int actual5 = solution.minCostClimbingStairs(cost5);
        System.out.println(actual5 + " | " + expected5);
    }
}
