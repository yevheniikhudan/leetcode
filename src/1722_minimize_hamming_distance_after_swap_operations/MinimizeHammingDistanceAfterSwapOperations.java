import java.util.*;

class Solution {

    class DSU {

        int[] parent;
        int[] rank;

        public DSU(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        public int find(int n) {
            if (this.parent[n] != n) {
                this.parent[n] = find(this.parent[n]);
            }

            return this.parent[n];
        }

        public boolean union(int n1, int n2) {
            int x = this.find(n1);
            int y = this.find(n2);
            if (x == y) {
                return false;
            }

            if (this.rank[x] < this.rank[y]) {
                int temp = x;
                x = y;
                y = temp;
            }
            this.parent[y] = x;
            if (this.rank[x] == this.rank[y]) {
                this.rank[x] += 1;
            }

            return true;
        }
    }

    public int minimumHammingDistance(
        int[] source,
        int[] target,
        int[][] allowedSwaps
    ) {
        int n = source.length;
        DSU dsu = new DSU(n);

        for (int i = 0; i < allowedSwaps.length; i++) {
            dsu.union(allowedSwaps[i][0], allowedSwaps[i][1]);
        }

        Map<String, Integer> sets = new HashMap<>();
        for (int i = 0; i < source.length; i++) {
            int parent = dsu.find(i);
            String key = parent + "#" + source[i];
            sets.put(key, sets.getOrDefault(key, 0) + 1);
        }

        int ans = 0;

        for (int i = 0; i < target.length; i++) {
            int parent = dsu.find(i);
            String key = parent + "#" + target[i];
            if (sets.getOrDefault(key, 0) > 0) {
                sets.put(key, sets.get(key) - 1);
            } else {
                ans += 1;
            }
        }

        return ans;
    }
}

public class MinimizeHammingDistanceAfterSwapOperations {

    static void printTestResult(int actual, int expected) {
        String status = actual == expected ? "PASS" : "FAIL";
        System.out.println(actual + " | " + expected + " | " + status);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test Case 1: Simple case with swap pairs
        int[] source1 = { 1, 2, 3, 4 };
        int[] target1 = { 2, 1, 4, 5 };
        int[][] allowedSwaps1 = { { 0, 1 }, { 2, 3 } };
        int expected1 = 1;
        int result1 = solution.minimumHammingDistance(
            source1,
            target1,
            allowedSwaps1
        );
        System.out.println("Test 1: Simple swap pairs");
        printTestResult(result1, expected1);
        System.out.println();

        // Test Case 2: No swaps allowed
        int[] source2 = { 1, 2, 3 };
        int[] target2 = { 4, 5, 6 };
        int[][] allowedSwaps2 = {};
        int expected2 = 3;
        int result2 = solution.minimumHammingDistance(
            source2,
            target2,
            allowedSwaps2
        );
        System.out.println("Test 2: No swaps allowed");
        printTestResult(result2, expected2);
        System.out.println();

        // Test Case 3: All elements connected through swaps
        int[] source3 = { 1, 2, 3, 4 };
        int[] target3 = { 2, 1, 4, 3 };
        int[][] allowedSwaps3 = { { 0, 1 }, { 1, 2 }, { 2, 3 } };
        int expected3 = 0;
        int result3 = solution.minimumHammingDistance(
            source3,
            target3,
            allowedSwaps3
        );
        System.out.println("Test 3: All elements connected");
        printTestResult(result3, expected3);
        System.out.println();

        // Test Case 4: Identical source and target
        int[] source4 = { 1, 2, 3 };
        int[] target4 = { 1, 2, 3 };
        int[][] allowedSwaps4 = {};
        int expected4 = 0;
        int result4 = solution.minimumHammingDistance(
            source4,
            target4,
            allowedSwaps4
        );
        System.out.println("Test 4: Identical arrays");
        printTestResult(result4, expected4);
        System.out.println();

        // Test Case 5: Single element arrays
        int[] source5 = { 1 };
        int[] target5 = { 2 };
        int[][] allowedSwaps5 = {};
        int expected5 = 1;
        int result5 = solution.minimumHammingDistance(
            source5,
            target5,
            allowedSwaps5
        );
        System.out.println("Test 5: Single element");
        printTestResult(result5, expected5);
        System.out.println();

        // Test Case 6: Multiple components with transitive connections
        int[] source6 = { 5, 1, 2, 4, 3 };
        int[] target6 = { 1, 5, 4, 2, 3 };
        int[][] allowedSwaps6 = { { 0, 4 }, { 4, 2 }, { 1, 3 }, { 1, 4 } };
        int expected6 = 0;
        int result6 = solution.minimumHammingDistance(
            source6,
            target6,
            allowedSwaps6
        );
        System.out.println("Test 6: Transitive connections");
        printTestResult(result6, expected6);
        System.out.println();
    }
}
