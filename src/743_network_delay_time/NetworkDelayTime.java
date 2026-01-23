import java.util.*;

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++)
            adj.add(new ArrayList<>()); // 1-indexed

        for (int[] t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj.get(u).add(new int[] { v, w });
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.add(new int[] { 0, k }); // {distance, node}
        boolean[] visited = new boolean[n + 1];
        int visitedCount = 0;
        int maxTime = 0;

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int dist = cur[0], u = cur[1];
            if (visited[u])
                continue;
            visited[u] = true;
            visitedCount++;
            maxTime = dist;

            for (int[] nei : adj.get(u)) {
                int v = nei[0], w = nei[1];
                if (!visited[v])
                    pq.add(new int[] { dist + w, v });
            }
        }

        return visitedCount == n ? maxTime : -1;
    }
}

public class NetworkDelayTime {
    public static void main(String[] args) {
        testNetworkDelayTime();
    }

    public static void testNetworkDelayTime() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int[][] times1 = { { 2, 1, 1 }, { 2, 3, 1 }, { 3, 4, 1 } };
        int n1 = 4;
        int k1 = 2;
        int expected1 = 2;
        int actual1 = solution.networkDelayTime(times1, n1, k1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int[][] times2 = { { 1, 2, 1 } };
        int n2 = 2;
        int k2 = 1;
        int expected2 = 1;
        int actual2 = solution.networkDelayTime(times2, n2, k2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Example 3
        int[][] times3 = { { 1, 2, 1 } };
        int n3 = 2;
        int k3 = 2;
        int expected3 = -1;
        int actual3 = solution.networkDelayTime(times3, n3, k3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: Single node
        int[][] times4 = {};
        int n4 = 1;
        int k4 = 1;
        int expected4 = 0;
        int actual4 = solution.networkDelayTime(times4, n4, k4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Disconnected nodes
        int[][] times5 = { { 1, 2, 1 }, { 3, 4, 1 } };
        int n5 = 4;
        int k5 = 1;
        int expected5 = -1;
        int actual5 = solution.networkDelayTime(times5, n5, k5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: All connected
        int[][] times6 = { { 1, 2, 1 }, { 1, 3, 2 }, { 2, 3, 1 }, { 3, 4, 1 } };
        int n6 = 4;
        int k6 = 1;
        int expected6 = 3;
        int actual6 = solution.networkDelayTime(times6, n6, k6);
        System.out.println(actual6 + " | " + expected6);
    }
}
