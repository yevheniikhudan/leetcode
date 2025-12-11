"""
74. Search a 2D Matrix

You are given an m x n integer matrix with the following two properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
"""

from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        """
        Search for target in 2D matrix using binary search.

        Args:
            matrix: 2D matrix with sorted rows and special properties
            target: Value to search for

        Returns:
            True if target is found, False otherwise

        Time Complexity: O(log(m * n)) where m = rows, n = cols
        Space Complexity: O(1) - only constant extra space
        """
        height = len(matrix)
        width = len(matrix[0])
        left, right = 0, height * width - 1

        while left <= right:
            mid = left + (right - left) // 2
            mid_col = mid % width
            mid_row = mid // width

            if target > matrix[mid_row][mid_col]:
                left = mid + 1
            elif target < matrix[mid_row][mid_col]:
                right = mid - 1
            else:
                return True

        return False


def test_search_matrix():
    solution = Solution()

    # Test case 1: Example 1 - target found
    matrix1 = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    result1 = solution.searchMatrix(matrix1, 3)
    print(f"Test 1: {result1} (expected: True)")

    # Test case 2: Example 2 - target not found
    matrix2 = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    result2 = solution.searchMatrix(matrix2, 13)
    print(f"Test 2: {result2} (expected: False)")

    # Test case 3: Single element - found
    matrix3 = [[5]]
    result3 = solution.searchMatrix(matrix3, 5)
    print(f"Test 3: {result3} (expected: True)")

    # Test case 4: Single element - not found
    matrix4 = [[5]]
    result4 = solution.searchMatrix(matrix4, 1)
    print(f"Test 4: {result4} (expected: False)")

    # Test case 5: Single row
    matrix5 = [[1, 3, 5, 7, 9]]
    result5 = solution.searchMatrix(matrix5, 7)
    print(f"Test 5: {result5} (expected: True)")

    # Test case 6: Single column
    matrix6 = [[1], [3], [5], [7]]
    result6 = solution.searchMatrix(matrix6, 3)
    print(f"Test 6: {result6} (expected: True)")

    # Test case 7: Target at top-left corner
    matrix7 = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    result7 = solution.searchMatrix(matrix7, 1)
    print(f"Test 7: {result7} (expected: True)")

    # Test case 8: Target at bottom-right corner
    matrix8 = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    result8 = solution.searchMatrix(matrix8, 60)
    print(f"Test 8: {result8} (expected: True)")

    # Test case 9: Target smaller than all elements
    matrix9 = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    result9 = solution.searchMatrix(matrix9, 0)
    print(f"Test 9: {result9} (expected: False)")

    # Test case 10: Target larger than all elements
    matrix10 = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    result10 = solution.searchMatrix(matrix10, 100)
    print(f"Test 10: {result10} (expected: False)")


if __name__ == "__main__":
    test_search_matrix()
