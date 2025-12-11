/*
74. Search a 2D Matrix

You are given an m x n integer matrix with the following two properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

class Solution {
    /**
     * Search for target in 2D matrix using binary search.
     * 
     * @param matrix 2D matrix with sorted rows and special properties
     * @param target Value to search for
     * @return True if target is found, false otherwise
     * 
     *         Time Complexity: O(log(m * n)) where m = rows, n = cols
     *         Space Complexity: O(1) - only constant extra space
     */
    public boolean searchMatrix(int[][] matrix, int target) {
        int height = matrix.length;
        int width = matrix[0].length;
        int left = 0;
        int right = width * height - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midCol = mid % width;
            int midRow = mid / width;

            if (target > matrix[midRow][midCol])
                left = mid + 1;
            else if (target < matrix[midRow][midCol])
                right = mid - 1;
            else
                return true;
        }

        return false;
    }
}

public class SearchA2dMatrix {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example 1 - target found
        int[][] matrix1 = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
        boolean result1 = solution.searchMatrix(matrix1, 3);
        System.out.println("Test 1: " + result1 + " (expected: true)");

        // Test case 2: Example 2 - target not found
        int[][] matrix2 = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
        boolean result2 = solution.searchMatrix(matrix2, 13);
        System.out.println("Test 2: " + result2 + " (expected: false)");

        // Test case 3: Single element - found
        int[][] matrix3 = { { 5 } };
        boolean result3 = solution.searchMatrix(matrix3, 5);
        System.out.println("Test 3: " + result3 + " (expected: true)");

        // Test case 4: Single element - not found
        int[][] matrix4 = { { 5 } };
        boolean result4 = solution.searchMatrix(matrix4, 1);
        System.out.println("Test 4: " + result4 + " (expected: false)");

        // Test case 5: Single row
        int[][] matrix5 = { { 1, 3, 5, 7, 9 } };
        boolean result5 = solution.searchMatrix(matrix5, 7);
        System.out.println("Test 5: " + result5 + " (expected: true)");

        // Test case 6: Single column
        int[][] matrix6 = { { 1 }, { 3 }, { 5 }, { 7 } };
        boolean result6 = solution.searchMatrix(matrix6, 3);
        System.out.println("Test 6: " + result6 + " (expected: true)");

        // Test case 7: Target at top-left corner
        int[][] matrix7 = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
        boolean result7 = solution.searchMatrix(matrix7, 1);
        System.out.println("Test 7: " + result7 + " (expected: true)");

        // Test case 8: Target at bottom-right corner
        int[][] matrix8 = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
        boolean result8 = solution.searchMatrix(matrix8, 60);
        System.out.println("Test 8: " + result8 + " (expected: true)");

        // Test case 9: Target smaller than all elements
        int[][] matrix9 = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
        boolean result9 = solution.searchMatrix(matrix9, 0);
        System.out.println("Test 9: " + result9 + " (expected: false)");

        // Test case 10: Target larger than all elements
        int[][] matrix10 = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
        boolean result10 = solution.searchMatrix(matrix10, 100);
        System.out.println("Test 10: " + result10 + " (expected: false)");
    }
}
