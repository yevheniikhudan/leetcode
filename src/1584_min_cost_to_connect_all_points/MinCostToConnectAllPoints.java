import java.util.Arrays;
import java.util.List;

class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        if (n == 1)
            return 0;

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;

        boolean[] visit = new boolean[n];
        int edges = 0;
        int cost = 0;

        while (edges < n - 1) {
            int minDist = Integer.MAX_VALUE;
            int u = -1;

            // Find the unvisited node with minimum distance
            for (int i = 0; i < n; i++) {
                if (!visit[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break; // No more nodes to visit

            visit[u] = true;
            cost += minDist;
            edges++;

            // Update distances to unvisited neighbors
            for (int v = 0; v < n; v++) {
                if (!visit[v]) {
                    int manhattan = Math.abs(points[u][0] - points[v][0]) + Math.abs(points[u][1] - points[v][1]);
                    if (manhattan < dist[v]) {
                        dist[v] = manhattan;
                    }
                }
            }
        }

        return cost;
    }

public class MinCostToConnectAllPoints {
    public static void main(String[] args) {
        testMinCostConnectPoints();
    }

    public static void testMinCostConnectPoints() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        List<List<Integer>> points1 = List.of(
                List.of(0, 0),
                List.of(2, 2),
                List.of(3, 10),
                List.of(5, 2),
                List.of(7, 0));
        int expected1 = 20;
        int actual1 = solution.minCostConnectPoints(points1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        List<List<Integer>> points2 = List.of(
                List.of(3, 12),
                List.of(-2, 5),
                List.of(-4, 1));
        int expected2 = 18;
        int actual2 = solution.minCostConnectPoints(points2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Two points
        List<List<Integer>> points3 = List.of(
                List.of(0, 0),
                List.of(1, 1));
        int expected3 = 2;
        int actual3 = solution.minCostConnectPoints(points3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: One point
        List<List<Integer>> points4 = List.of(List.of(0, 0));
        int expected4 = 0;
        int actual4 = solution.minCostConnectPoints(points4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Three points in line
        List<List<Integer>> points5 = List.of(
                List.of(0, 0),
                List.of(1, 0),
                List.of(2, 0));
        int expected5 = 2;
        int actual5 = solution.minCostConnectPoints(points5);
        System.out.println(actual5 + " | " + expected5);
    }
}
