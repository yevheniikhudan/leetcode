/*
74. Search a 2D Matrix

You are given an m x n integer matrix with the following two properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Search for target in 2D matrix using binary search.
     *
     * @param matrix 2D matrix with sorted rows and special properties
     * @param target Value to search for
     * @return True if target is found, false otherwise
     *
     * Time Complexity: O(log(m * n)) where m = rows, n = cols
     * Space Complexity: O(1) - only constant extra space
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        int left = 0, right = cols * rows - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_col = mid % cols;
            int mid_row = mid / cols;
            if (target > matrix[mid_row][mid_col]) {
                left = mid + 1;
            } else if (target < matrix[mid_row][mid_col]) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1 - target found
    vector<vector<int>> matrix1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool result1 = solution.searchMatrix(matrix1, 3);
    cout << "Test 1: " << (result1 ? "true" : "false") << " (expected: true)\n";

    // Test case 2: Example 2 - target not found
    vector<vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool result2 = solution.searchMatrix(matrix2, 13);
    cout << "Test 2: " << (result2 ? "true" : "false") << " (expected: false)\n";

    // Test case 3: Single element - found
    vector<vector<int>> matrix3 = {{5}};
    bool result3 = solution.searchMatrix(matrix3, 5);
    cout << "Test 3: " << (result3 ? "true" : "false") << " (expected: true)\n";

    // Test case 4: Single element - not found
    vector<vector<int>> matrix4 = {{5}};
    bool result4 = solution.searchMatrix(matrix4, 1);
    cout << "Test 4: " << (result4 ? "true" : "false") << " (expected: false)\n";

    // Test case 5: Single row
    vector<vector<int>> matrix5 = {{1, 3, 5, 7, 9}};
    bool result5 = solution.searchMatrix(matrix5, 7);
    cout << "Test 5: " << (result5 ? "true" : "false") << " (expected: true)\n";

    // Test case 6: Single column
    vector<vector<int>> matrix6 = {{1}, {3}, {5}, {7}};
    bool result6 = solution.searchMatrix(matrix6, 3);
    cout << "Test 6: " << (result6 ? "true" : "false") << " (expected: true)\n";

    // Test case 7: Target at top-left corner
    vector<vector<int>> matrix7 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool result7 = solution.searchMatrix(matrix7, 1);
    cout << "Test 7: " << (result7 ? "true" : "false") << " (expected: true)\n";

    // Test case 8: Target at bottom-right corner
    vector<vector<int>> matrix8 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool result8 = solution.searchMatrix(matrix8, 60);
    cout << "Test 8: " << (result8 ? "true" : "false") << " (expected: true)\n";

    // Test case 9: Target smaller than all elements
    vector<vector<int>> matrix9 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool result9 = solution.searchMatrix(matrix9, 0);
    cout << "Test 9: " << (result9 ? "true" : "false") << " (expected: false)\n";

    // Test case 10: Target larger than all elements
    vector<vector<int>> matrix10 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool result10 = solution.searchMatrix(matrix10, 100);
    cout << "Test 10: " << (result10 ? "true" : "false") << " (expected: false)\n";
}

int main() {
    runTests();
    return 0;
}
