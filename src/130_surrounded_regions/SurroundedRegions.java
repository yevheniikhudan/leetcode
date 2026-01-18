import java.util.*;

public class SurroundedRegions {
    public void solve(char[][] board) {
        int rows = board.length;
        int cols = board[0].length;
        int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
        Queue<int[]> q = new ArrayDeque<>();
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if ((row == 0 || col == 0 || row == rows - 1 || col == cols - 1) && board[row][col] == 'O') {
                    q.offer(new int[] { row, col });
                }
            }
        }
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int row = cell[0], col = cell[1];
            if (board[row][col] != 'S') {
                board[row][col] = 'S';
                for (int[] d : dirs) {
                    int newRow = row + d[0], newCol = col + d[1];
                    if (0 <= newRow && newRow < rows && 0 <= newCol && newCol < cols && board[newRow][newCol] == 'O') {
                        q.offer(new int[] { newRow, newCol });
                    }
                }
            }
        }
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == 'O')
                    board[row][col] = 'X';
                if (board[row][col] == 'S')
                    board[row][col] = 'O';
            }
        }
    }

    public static void main(String[] args) {
        SurroundedRegions sol = new SurroundedRegions();
        char[][] board1 = { { 'X', 'X', 'X', 'X' }, { 'X', 'O', 'O', 'X' }, { 'X', 'X', 'O', 'X' },
                { 'X', 'O', 'X', 'X' } };
        sol.solve(board1);
        System.out.println(Arrays.deepToString(board1)
                + " | [[\"X\",\"X\",\"X\",\"X\"],[\"X\",\"X\",\"X\",\"X\"],[\"X\",\"X\",\"X\",\"X\"],[\"X\",\"O\",\"X\",\"X\"]]");
        char[][] board2 = { { 'X' } };
        sol.solve(board2);
        System.out.println(Arrays.deepToString(board2) + " | [[\"X\"]]");
        char[][] board3 = { { 'O', 'O' }, { 'O', 'O' } };
        sol.solve(board3);
        System.out.println(Arrays.deepToString(board3) + " | [[\"O\",\"O\"],[\"O\",\"O\"]]");
        char[][] board4 = { { 'X', 'O', 'X' }, { 'O', 'X', 'O' }, { 'X', 'O', 'X' } };
        sol.solve(board4);
        System.out.println(
                Arrays.deepToString(board4) + " | [[\"X\",\"O\",\"X\"],[\"O\",\"X\",\"O\"],[\"X\",\"O\",\"X\"]]");
        char[][] board5 = { { 'O' } };
        sol.solve(board5);
        System.out.println(Arrays.deepToString(board5) + " | [[\"O\"]]");
    }
}
