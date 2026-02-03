import java.util.*;

class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        int lis = 0;
        Map<Integer, Integer> memo = new HashMap<>();

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                lis = Math.max(lis, dfs(row, col, -1, matrix, dirs, memo, n, m));
            }
        }

        return lis;
    }

    private int dfs(int row, int col, int prevValue, int[][] matrix, int[][] dirs, Map<Integer, Integer> memo, int n,
            int m) {
        if (row < 0 || row >= n || col < 0 || col >= m || matrix[row][col] <= prevValue) {
            return 0;
        }

        int key = row * m + col;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        int res = 1;
        for (int[] dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            res = Math.max(res, 1 + dfs(newRow, newCol, matrix[row][col], matrix, dirs, memo, n, m));
        }

        memo.put(key, res);
        return res;
    }
}

public class LongestIncreasingPathInAMatrix {
    public static void main(String[] args) {
        Solution sol = new Solution();
        // Test case 1: Example 1
        System.out.println(sol.longestIncreasingPath(new int[][] { { 9, 9, 4 }, { 6, 6, 8 }, { 2, 1, 1 } }) + " | 4");
        // Test case 2: Example 2
        System.out.println(sol.longestIncreasingPath(new int[][] { { 3, 4, 5 }, { 3, 2, 6 }, { 2, 2, 1 } }) + " | 4");
        // Test case 3: Example 3
        System.out.println(sol.longestIncreasingPath(new int[][] { { 1 } }) + " | 1");
        // Test case 4: All equal
        System.out.println(sol.longestIncreasingPath(new int[][] { { 1, 1 }, { 1, 1 } }) + " | 1");
        // Test case 5: Increasing row
        System.out.println(sol.longestIncreasingPath(new int[][] { { 1, 2, 3 } }) + " | 3");
    }
}
