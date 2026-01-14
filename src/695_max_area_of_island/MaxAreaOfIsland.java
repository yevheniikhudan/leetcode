public class MaxAreaOfIsland {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        int rows = grid.length, cols = grid[0].length;
        int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    res = Math.max(res, dfs(grid, row, col, rows, cols, directions));
                }
            }
        }
        return res;
    }

    private int dfs(int[][] grid, int row, int col, int rows, int cols, int[][] directions) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0)
            return 0;
        grid[row][col] = 0;
        int area = 1;
        for (int[] d : directions) {
            area += dfs(grid, row + d[0], col + d[1], rows, cols, directions);
        }
        return area;
    }

    // Test scaffolding
    public static void main(String[] args) {
        int[][] grid = {
                { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
                { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
                { 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }
        };
        System.out.println(new MaxAreaOfIsland().maxAreaOfIsland(grid)); // 6
    }
}
