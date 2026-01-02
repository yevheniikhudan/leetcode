import java.util.*;

public class KClosestPointsToOrigin {
    private class Point {
        double dist;
        int x;
        int y;

        public Point(double dist, int x, int y) {
            this.dist = dist;
            this.x = x;
            this.y = y;
        }
    }

    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Point> pq = new PriorityQueue<>(Comparator.comparingDouble(p -> -p.dist));

        for (int[] point : points) {
            double dist = Math.pow(point[0], 2) + Math.pow(point[1], 2);
            pq.add(new Point(dist, point[0], point[1]));

            if (pq.size() > k) {
                pq.poll();
            }
        }

        ArrayList<int[]> res = new ArrayList<>();
        for (Point point : pq) {
            res.add(new int[] { point.x, point.y });
        }
        return res.toArray(new int[res.size()][]);
    }

    // Test scaffolding
    public static void main(String[] args) {
        KClosestPointsToOrigin sol = new KClosestPointsToOrigin();
        int[][][] testPoints = {
                { { 1, 3 }, { -2, 2 } },
                { { 3, 3 }, { 5, -1 }, { -2, 4 } },
                { { 0, 1 }, { 1, 0 } },
                { { 2, 2 }, { 2, 2 }, { 2, 2 } },
                { { 1, 2 }, { 2, 1 }, { 0, 0 } }
        };
        int[] ks = { 1, 2, 2, 2, 1 };
        int[][][] expected = {
                { { -2, 2 } },
                { { 3, 3 }, { -2, 4 } },
                { { 0, 1 }, { 1, 0 } },
                { { 2, 2 }, { 2, 2 } },
                { { 0, 0 } }
        };
        for (int i = 0; i < testPoints.length; i++) {
            int[][] actual = sol.kClosest(testPoints[i], ks[i]);
            System.out.println(Arrays.deepToString(actual) + " | " + Arrays.deepToString(expected[i]));
        }
    }
}
