import java.util.*;

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] prices = new int[n];
        Arrays.fill(prices, Integer.MAX_VALUE);
        prices[src] = 0;

        List<List<int[]>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++)
            adjList.add(new ArrayList<>());
        for (int[] flight : flights) {
            int u = flight[0], v = flight[1], cst = flight[2];
            adjList.get(u).add(new int[] { v, cst });
        }

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] { 0, src, 0 }); // {cost, node, stops}

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int cst = curr[0], node = curr[1], stops = curr[2];
            if (stops > k)
                continue;

            for (int[] adj : adjList.get(node)) {
                int adjNode = adj[0], adjCost = adj[1];
                int newCost = cst + adjCost;
                if (newCost < prices[adjNode]) {
                    prices[adjNode] = newCost;
                    q.add(new int[] { newCost, adjNode, stops + 1 });
                }
            }
        }

        return prices[dst] == Integer.MAX_VALUE ? -1 : prices[dst];
    }
}

public class CheapestFlightsWithinKStops {
    public static void main(String[] args) {
        testFindCheapestPrice();
    }

    // Test helper
    public static void testFindCheapestPrice() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int n1 = 4;
        int[][] flights1 = { { 0, 1, 100 }, { 1, 2, 100 }, { 2, 0, 100 }, { 1, 3, 600 }, { 2, 3, 200 } };
        int src1 = 0, dst1 = 3, k1 = 1;
        int expected1 = 700;
        int actual1 = solution.findCheapestPrice(n1, flights1, src1, dst1, k1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int n2 = 3;
        int[][] flights2 = { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } };
        int src2 = 0, dst2 = 2, k2 = 1;
        int expected2 = 200;
        int actual2 = solution.findCheapestPrice(n2, flights2, src2, dst2, k2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Example 3
        int n3 = 3;
        int[][] flights3 = { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } };
        int src3 = 0, dst3 = 2, k3 = 0;
        int expected3 = 500;
        int actual3 = solution.findCheapestPrice(n3, flights3, src3, dst3, k3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: No path
        int n4 = 3;
        int[][] flights4 = { { 0, 1, 100 }, { 1, 2, 100 } };
        int src4 = 0, dst4 = 2, k4 = 0;
        int expected4 = -1;
        int actual4 = solution.findCheapestPrice(n4, flights4, src4, dst4, k4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Direct flight cheaper
        int n5 = 2;
        int[][] flights5 = { { 0, 1, 50 }, { 0, 1, 100 } };
        int src5 = 0, dst5 = 1, k5 = 1;
        int expected5 = 50;
        int actual5 = solution.findCheapestPrice(n5, flights5, src5, dst5, k5);
        System.out.println(actual5 + " | " + expected5);
    }
}
