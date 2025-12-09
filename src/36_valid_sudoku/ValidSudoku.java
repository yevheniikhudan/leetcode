public class ValidSudoku {
    /**
     * Valid Sudoku
     *
     * @param board 9x9 Sudoku board
     * @return True if valid, False otherwise
     */
    public boolean isValidSudoku(char[][] board) {
        int[] rows = new int[9];
        int[] cols = new int[9];
        int[] boxes = new int[9];

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char cell = board[row][col];
                if (cell == '.') {
                    continue;
                }

                int val = 1 << ((cell - '0') - 1);
                if (((rows[row] & val) != 0) || ((cols[col] & val) != 0)
                        || ((boxes[row / 3 * 3 + col / 3] & val) != 0)) {
                    return false;
                }

                rows[row] |= val;
                cols[col] |= val;
                boxes[row / 3 * 3 + col / 3] |= val;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        ValidSudoku solution = new ValidSudoku();

        // Test case 1: Valid board
        char[][] board1 = {
                { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
                { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        boolean result1 = solution.isValidSudoku(board1);
        System.out.println("Test 1: " + result1);
        assert result1 == true : "Expected true, got " + result1;

        // Test case 2: Invalid board (duplicate in sub-box)
        char[][] board2 = {
                { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
                { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        boolean result2 = solution.isValidSudoku(board2);
        System.out.println("Test 2: " + result2);
        assert result2 == false : "Expected false, got " + result2;

        // Test case 3: Invalid board (duplicate in row)
        char[][] board3 = {
                { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
                { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                { '5', '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        boolean result3 = solution.isValidSudoku(board3);
        System.out.println("Test 3: " + result3);
        assert result3 == false : "Expected false, got " + result3;

        // Test case 4: All empty
        char[][] board4 = {
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' }
        };
        boolean result4 = solution.isValidSudoku(board4);
        System.out.println("Test 4: " + result4);
        assert result4 == true : "Expected true, got " + result4;

        System.out.println("All test cases passed!");
    }
}
