import java.util.Arrays;

class Solution {
    public void rotate(int[][] matrix) {
        transpose(matrix);
        reverse(matrix);
    }

    private void reverse(int[][] matrix) {
        for (int[] row : matrix) {
            int left = 0, right = row.length - 1;
            while (left < right) {
                int temp = row[left];
                row[left] = row[right];
                row[right] = temp;
                left += 1;
                right -= 1;
            }
        }
    }

    private void transpose(int[][] matrix) {
        for (int row = 0; row < matrix.length; row++) {
            for (int col = row + 1; col < matrix[row].length; col++) {
                swap(matrix, row, col);
            }
        }
    }

    private void swap(int[][] matrix, int row, int col) {
        int temp = matrix[row][col];
        matrix[row][col] = matrix[col][row];
        matrix[col][row] = temp;
    }
}

public class RotateImage {
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
                {
                        { 1, 2, 3 },
                        { 4, 5, 6 },
                        { 7, 8, 9 }
                },
                {
                        { 5, 1, 9, 11 },
                        { 2, 4, 8, 10 },
                        { 13, 3, 6, 7 },
                        { 15, 14, 12, 16 }
                },
                {
                        { 1 }
                },
                {
                        { 1, 2 },
                        { 3, 4 }
                },
                {
                        { -1, -2, -3 },
                        { -4, -5, -6 },
                        { -7, -8, -9 }
                },
                {
                        { 1, 1, 1 },
                        { 2, 2, 2 },
                        { 3, 3, 3 }
                }
        };

        int[][][] expected = {
                {
                        { 7, 4, 1 },
                        { 8, 5, 2 },
                        { 9, 6, 3 }
                },
                {
                        { 15, 13, 2, 5 },
                        { 14, 3, 4, 1 },
                        { 12, 6, 8, 9 },
                        { 16, 7, 10, 11 }
                },
                {
                        { 1 }
                },
                {
                        { 3, 1 },
                        { 4, 2 }
                },
                {
                        { -7, -4, -1 },
                        { -8, -5, -2 },
                        { -9, -6, -3 }
                },
                {
                        { 3, 2, 1 },
                        { 3, 2, 1 },
                        { 3, 2, 1 }
                }
        };

        for (int i = 0; i < inputs.length; i++) {
            int[][] actual = cloneMatrix(inputs[i]);
            solution.rotate(actual);
            System.out.println(formatMatrix(actual) + " | " + formatMatrix(expected[i]));
        }
    }
}
