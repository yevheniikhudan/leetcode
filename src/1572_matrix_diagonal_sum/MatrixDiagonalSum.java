import java.util.*;

public class MatrixDiagonalSum {
    public int diagonalSum(int[][] mat) {
        int sum = 0;
        int l = mat.length;

        for (int i = 0; i < l; i++) {
            sum += mat[i][i];
            if (l - 1 - i != i)
                sum += mat[i][l - 1 - i];
        }

        return sum;
    }

    // Test scaffolding
    public static void main(String[] args) {
        int[][][] testMats = {
                { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } },
                { { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 } },
                { { 5 } },
                { { 1, 2 }, { 3, 4 } },
                { { 7, 0, 0, 7 }, { 0, 7, 7, 0 }, { 0, 7, 7, 0 }, { 7, 0, 0, 7 } }
        };
        int[] expected = { 25, 8, 5, 10, 56 };
        MatrixDiagonalSum sol = new MatrixDiagonalSum();
        for (int i = 0; i < testMats.length; i++) {
            int actual = sol.diagonalSum(testMats[i]);
            System.out.println(actual + " | " + expected[i]);
        }
    }
}
