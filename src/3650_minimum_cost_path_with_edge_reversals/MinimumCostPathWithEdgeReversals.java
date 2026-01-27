import java.util.*;

class Solution {
    public int minimumCostPath(int n, int[][] edges) {
        List<List<int[]>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++)
            adjList.add(new ArrayList<>());

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adjList.get(u).add(new int[] { v, w });
            adjList.get(v).add(new int[] { u, 2 * w });
        }

        int[] shortest = new int[n];
        Arrays.fill(shortest, -1);
        PriorityQueue<int[]> h = new PriorityQueue<>(Comparator.comparingInt(a -> a[0])); // min-heap
        h.add(new int[] { 0, 0 });

        while (!h.isEmpty()) {
            int[] curr = h.poll();
            int weight = curr[0], u = curr[1];

            if (shortest[u] != -1)
                continue;

            shortest[u] = weight;

            if (u == n - 1)
                return weight;

            for (int[] adj : adjList.get(u)) {
                int adjNode = adj[0], adjWeight = adj[1];
                if (shortest[adjNode] != -1)
                    continue;

                h.add(new int[] { adjWeight + weight, adjNode });
            }
        }

        return shortest[n - 1];
    }
}

public class MinimumCostPathWithEdgeReversals {
    public static void main(String[] args) {
        testMinimumCostPath();
    }

    // Test helper
    public static void testMinimumCostPath() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int n1 = 4;
        int[][] edges1 = { { 0, 1, 3 }, { 3, 1, 1 }, { 2, 3, 4 }, { 0, 2, 2 } };
        int expected1 = 5;
        int actual1 = solution.minimumCostPath(n1, edges1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int n2 = 4;
        int[][] edges2 = { { 0, 2, 1 }, { 2, 1, 1 }, { 1, 3, 1 }, { 2, 3, 3 } };
        int expected2 = 3;
        int actual2 = solution.minimumCostPath(n2, edges2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: No path
        int n3 = 3;
        int[][] edges3 = { { 0, 1, 1 }, { 1, 2, 1 } };
        int expected3 = 2; // Direct path 0->1->2
        int actual3 = solution.minimumCostPath(n3, edges3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: Direct path
        int n4 = 2;
        int[][] edges4 = { { 0, 1, 5 } };
        int expected4 = 5;
        int actual4 = solution.minimumCostPath(n4, edges4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Reversal needed
        int n5 = 3;
        int[][] edges5 = { { 1, 0, 1 }, { 1, 2, 1 } };
        int expected5 = 3;
        int actual5 = solution.minimumCostPath(n5, edges5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: Impossible
        int n6 = 3;
        int[][] edges6 = { { 0, 1, 1 } };
        int expected6 = -1;
        int actual6 = solution.minimumCostPath(n6, edges6);
        System.out.println(actual6 + " | " + expected6);
    }
}
