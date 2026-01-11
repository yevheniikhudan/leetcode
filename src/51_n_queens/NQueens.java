import java.util.*;

// Solution class for logic
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        char[][] board = new char[n][n];
        for (char[] row : board)
            Arrays.fill(row, '.');
        boolean[] cols = new boolean[n];
        boolean[] diag1 = new boolean[2 * n - 1];
        boolean[] diag2 = new boolean[2 * n - 1];
        backtrack(0, n, board, res, cols, diag1, diag2);
        return res;
    }

    private void backtrack(int row, int n, char[][] board, List<List<String>> res, boolean[] cols, boolean[] diag1,
            boolean[] diag2) {
        if (row == n) {
            List<String> solution = new ArrayList<>();
            for (char[] r : board)
                solution.add(new String(r));
            res.add(solution);
            return;
        }
        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1, d2 = row + col;
            if (cols[col] || diag1[d1] || diag2[d2])
                continue;
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1, n, board, res, cols, diag1, diag2);
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
}

// Main/test class
public class NQueens {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] tests = { 4, 1, 2, 3, 5 };
        for (int n : tests) {
            List<List<String>> result = sol.solveNQueens(n);
            System.out.println("n=" + n + ": " + result);
        }
    }
}
