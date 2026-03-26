import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int left = 0, right = matrix[0].length;
        int top = 0, bottom = matrix.length;

        while (left < right && top < bottom) {
            for (int i = left; i < right; i++) {
                res.add(matrix[top][i]);
            }
            top++;
            for (int i = top; i < bottom; i++) {
                res.add(matrix[i][right - 1]);
            }
            right--;
            if (!(left < right && top < bottom)) {
                break;
            }
            for (int i = right - 1; i >= left; i--) {
                res.add(matrix[bottom - 1][i]);
            }
            bottom--;
            for (int i = bottom - 1; i >= top; i--) {
                res.add(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
}

public class SpiralMatrix {
    private static String formatResult(List<Integer> result) {
        return result.toString();
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
                        { 1, 2, 3, 4 },
                        { 5, 6, 7, 8 },
                        { 9, 10, 11, 12 }
                },
                {
                        { 1 }
                },
                {
                        { 1, 2, 3, 4, 5 }
                },
                {
                        { 1 },
                        { 2 },
                        { 3 },
                        { 4 },
                        { 5 }
                },
                {
                        { 1, 2 },
                        { 3, 4 }
                }
        };

        int[][] expected_arrays = {
                { 1, 2, 3, 6, 9, 8, 7, 4, 5 },
                { 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 },
                { 1 },
                { 1, 2, 3, 4, 5 },
                { 1, 2, 3, 4, 5 },
                { 1, 2, 4, 3 }
        };

        List<List<Integer>> expected = new ArrayList<>();
        for (int[] arr : expected_arrays) {
            List<Integer> list = new ArrayList<>();
            for (int val : arr) {
                list.add(val);
            }
            expected.add(list);
        }

        for (int i = 0; i < inputs.length; i++) {
            List<Integer> actual = solution.spiralOrder(inputs[i]);
            System.out.println(formatResult(actual) + " | " + formatResult(expected.get(i)));
        }
    }
}
