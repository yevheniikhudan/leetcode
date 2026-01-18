public class RottingOranges {
    public int orangesRotting(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        java.util.Queue<int[]> q = new java.util.LinkedList<>();
        int time = 0, fresh = 0;
        int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 2)
                    q.offer(new int[] { row, col });
                if (grid[row][col] == 1)
                    fresh++;
            }
        }
        while (!q.isEmpty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] cell = q.poll();
                int row = cell[0], col = cell[1];
                for (int[] d : directions) {
                    int newRow = row + d[0], newCol = col + d[1];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        q.offer(new int[] { newRow, newCol });
                        grid[newRow][newCol] = 2;
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : time;
    }

    // Test scaffolding
    public static void main(String[] args) {
        int[][] grid = {
                { 2, 1, 1 },
                { 1, 1, 0 },
                { 0, 1, 1 }
        };
        System.out.println(new RottingOranges().orangesRotting(grid)); // 4
    }
}
