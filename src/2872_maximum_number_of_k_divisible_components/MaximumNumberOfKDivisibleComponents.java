/*
2872. Maximum Number of K-Divisible Components

There is an undirected tree with n nodes. Split the tree by removing edges
such that each resulting component has a sum of values divisible by k.
Return the maximum number of components possible.
*/

import java.util.ArrayList;
import java.util.List;

public class MaximumNumberOfKDivisibleComponents {
    private int res = 0;
    private List<List<Integer>> adj;

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        adj = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        dfs(values, k, 0, -1);

        return res;

    }

    private int dfs(int[] values, int k, int curNode, int parentNode) {
        int subtreeSum = values[curNode] % k;

        for (int adjNode : adj.get(curNode)) {
            if (adjNode != parentNode) {
                subtreeSum = (subtreeSum + dfs(values, k, adjNode, curNode)) % k;
            }
        }

        if (subtreeSum == 0) {
            res += 1;
        }
        return subtreeSum;
    }

    public static void main(String[] args) {
        MaximumNumberOfKDivisibleComponents solution = new MaximumNumberOfKDivisibleComponents();

        // Test case 1: Example 1
        int n1 = 5;
        int[][] edges1 = { { 0, 2 }, { 1, 2 }, { 1, 3 }, { 2, 4 } };
        int[] values1 = { 1, 8, 1, 4, 4 };
        int k1 = 6;
        int result1 = solution.maxKDivisibleComponents(n1, edges1, values1, k1);
        System.out.printf("Test 1: %d (expected: 2)%n", result1);

        // Test case 2: Example 2
        int n2 = 7;
        int[][] edges2 = { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 1, 4 }, { 2, 5 }, { 2, 6 } };
        int[] values2 = { 3, 0, 6, 1, 5, 2, 1 };
        int k2 = 3;
        int result2 = solution.maxKDivisibleComponents(n2, edges2, values2, k2);
        System.out.printf("Test 2: %d (expected: 3)%n", result2);

        // Test case 3: Single node
        int n3 = 1;
        int[][] edges3 = {};
        int[] values3 = { 10 };
        int k3 = 5;
        int result3 = solution.maxKDivisibleComponents(n3, edges3, values3, k3);
        System.out.printf("Test 3: %d (expected: 1)%n", result3);

        // Test case 4: All zeros
        int n4 = 4;
        int[][] edges4 = { { 0, 1 }, { 1, 2 }, { 2, 3 } };
        int[] values4 = { 0, 0, 0, 0 };
        int k4 = 3;
        int result4 = solution.maxKDivisibleComponents(n4, edges4, values4, k4);
        System.out.printf("Test 4: %d (expected: 4)%n", result4);

        // Test case 5: Linear tree
        int n5 = 3;
        int[][] edges5 = { { 0, 1 }, { 1, 2 } };
        int[] values5 = { 3, 6, 3 };
        int k5 = 3;
        int result5 = solution.maxKDivisibleComponents(n5, edges5, values5, k5);
        System.out.printf("Test 5: %d (expected: 3)%n", result5);
    }
}
