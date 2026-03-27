import java.util.Arrays;

class Solution {

    public void setZeroes(int[][] matrix) {
        int ROWS = matrix.length,
            COLS = matrix[0].length;
        boolean rowZero = false;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    if (r > 0) {
                        matrix[r][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }

        for (int r = 1; r < ROWS; r++) {
            for (int c = 1; c < COLS; c++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int r = 0; r < ROWS; r++) {
                matrix[r][0] = 0;
            }
        }

        if (rowZero) {
            for (int c = 0; c < COLS; c++) {
                matrix[0][c] = 0;
            }
        }
    }
}

public class SetMatrixZeroes {

    private static int[][] cloneMatrix(int[][] matrix) {
        int[][] copy = new int[matrix.length][];
        for (int i = 0; i < matrix.length; i++) {
            copy[i] = Arrays.copyOf(matrix[i], matrix[i].length);
        }
        return copy;
    }

    private static String formatMatrix(int[][] matrix) {
        return Arrays.deepToString(matrix);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[][][] inputs = {
            { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } },
            { { 0, 1, 2, 0 }, { 3, 4, 5, 2 }, { 1, 3, 1, 5 } },
            { { 1 } },
            { { 0 } },
            { { 1, 2, 3, 4 } },
            { { 1 }, { 0 }, { 3 } },
        };

        int[][][] expected = {
            { { 1, 0, 1 }, { 0, 0, 0 }, { 1, 0, 1 } },
            { { 0, 0, 0, 0 }, { 0, 4, 5, 0 }, { 0, 3, 1, 0 } },
            { { 1 } },
            { { 0 } },
            { { 1, 2, 3, 4 } },
            { { 0 }, { 0 }, { 0 } },
        };

        for (int i = 0; i < inputs.length; i++) {
            int[][] actual = cloneMatrix(inputs[i]);
            solution.setZeroes(actual);
            System.out.println(
                formatMatrix(actual) + " | " + formatMatrix(expected[i])
            );
        }
    }
}
