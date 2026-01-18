import java.util.*;

public class PacificAtlanticWaterFlow {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> res = new ArrayList<>();
        if (heights == null || heights.length == 0 || heights[0].length == 0)
            return res;
        int ROWS = heights.length, COLS = heights[0].length;
        boolean[][] pac = new boolean[ROWS][COLS];
        boolean[][] atl = new boolean[ROWS][COLS];
        int[][] dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        Queue<int[]> q = new LinkedList<>();
        // Pacific
        for (int c = 0; c < COLS; c++)
            q.offer(new int[] { 0, c });
        for (int r = 0; r < ROWS; r++)
            q.offer(new int[] { r, 0 });
        bfs(heights, q, pac, dirs);
        // Atlantic
        q.clear();
        for (int c = 0; c < COLS; c++)
            q.offer(new int[] { ROWS - 1, c });
        for (int r = 0; r < ROWS; r++)
            q.offer(new int[] { r, COLS - 1 });
        bfs(heights, q, atl, dirs);
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac[r][c] && atl[r][c])
                    res.add(Arrays.asList(r, c));
            }
        }
        return res;
    }

    private void bfs(int[][] heights, Queue<int[]> q, boolean[][] vis, int[][] dirs) {
        int ROWS = heights.length, COLS = heights[0].length;
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int r = cell[0], c = cell[1];
            if (vis[r][c])
                continue;
            vis[r][c] = true;
            for (int[] d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    q.offer(new int[] { nr, nc });
                }
            }
        }
    }

    public static void main(String[] args) {
        PacificAtlanticWaterFlow sol = new PacificAtlanticWaterFlow();
        System.out
                .println(sol
                        .pacificAtlantic(new int[][] { { 1, 2, 2, 3, 5 }, { 3, 2, 3, 4, 4 }, { 2, 4, 5, 3, 1 },
                                { 6, 7, 1, 4, 5 }, { 5, 1, 1, 2, 4 } })
                        + " | [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]");
        System.out.println(sol.pacificAtlantic(new int[][] { { 1 } }) + " | [[0,0]]");
        System.out.println(sol.pacificAtlantic(new int[][] {}) + " | []");
        System.out.println(sol.pacificAtlantic(new int[][] { { 1, 2 }, { 4, 3 } }) + " | [[0,1],[1,0],[1,1]]");
        System.out.println(sol.pacificAtlantic(new int[][] { { 2, 1 }, { 1, 2 } }) + " | [[0,0],[0,1],[1,0],[1,1]]");
    }
}
