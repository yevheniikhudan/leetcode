import java.util.*;

// Solution class for logic
class Solution {
    public boolean exist(char[][] board, String word) {
        int ROWS = board.length, COLS = board[0].length;
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                if (dfs(board, word, row, col, 0))
                    return true;
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, String word, int row, int col, int pathLength) {
        int ROWS = board.length, COLS = board[0].length;
        if (pathLength >= word.length())
            return true;
        if (row < 0 || col < 0 || row == ROWS || col == COLS)
            return false;
        if (board[row][col] == '#')
            return false;
        if (board[row][col] != word.charAt(pathLength))
            return false;
        char orig = board[row][col];
        board[row][col] = '#';
        int[] dr = { -1, 0, 1, 0 };
        int[] dc = { 0, -1, 0, 1 };
        boolean found = false;
        for (int d = 0; d < 4; ++d) {
            found |= dfs(board, word, row + dr[d], col + dc[d], pathLength + 1);
            if (found)
                break;
        }
        board[row][col] = orig;
        return found;
    }
}

// Main/test class
public class WordSearch {
    private static char[][] buildBoard(String[] rows) {
        char[][] board = new char[rows.length][rows[0].length()];
        for (int i = 0; i < rows.length; ++i) {
            board[i] = rows[i].toCharArray();
        }
        return board;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        Object[][] tests = {
                { buildBoard(new String[] { "ABCE", "SFCS", "ADEE" }), "ABCCED", true },
                { buildBoard(new String[] { "ABCE", "SFCS", "ADEE" }), "SEE", true },
                { buildBoard(new String[] { "ABCE", "SFCS", "ADEE" }), "ABCB", false },
                { buildBoard(new String[] { "A" }), "A", true },
                { buildBoard(new String[] { "A" }), "B", false },
                { buildBoard(new String[] { "A" }), "AA", false },
        };
        for (int i = 0; i < tests.length; ++i) {
            char[][] board = (char[][]) tests[i][0];
            String word = (String) tests[i][1];
            boolean expected = (boolean) tests[i][2];
            boolean result = sol.exist(board, word);
            System.out.println("Test " + (i + 1) + ": " + result + " | " + expected);
        }
    }
}
