from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows, cols = len(matrix), len(matrix[0])
        firstRowZeroed = False
        firstColumnZeroed = False

        for col in range(cols):
            if matrix[0][col] == 0:
                firstRowZeroed = True
                break

        for row in range(len(matrix)):
            if matrix[row][0] == 0:
                firstColumnZeroed = True
                break

        for row in range(1, rows):
            for col in range(1, cols):
                if matrix[row][col] == 0:
                    matrix[0][col] = 0
                    matrix[row][0] = 0

        for col in range(1, cols):
            if matrix[0][col] == 0:
                for row in range(1, rows):
                    matrix[row][col] = 0

        for row in range(rows):
            if matrix[row][0] == 0:
                for col in range(1, cols):
                    matrix[row][col] = 0

        if firstRowZeroed:
            for col in range(cols):
                matrix[0][col] = 0

        if firstColumnZeroed:
            for row in range(rows):
                matrix[row][0] = 0


def clone_matrix(matrix: List[List[int]]) -> List[List[int]]:
    return [row[:] for row in matrix]


def format_matrix(matrix: List[List[int]]) -> str:
    return str(matrix)


def run_tests() -> None:
    solution = Solution()

    test_cases = [
        (
            [[1, 1, 1], [1, 0, 1], [1, 1, 1]],
            [[1, 0, 1], [0, 0, 0], [1, 0, 1]],
        ),
        (
            [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]],
            [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]],
        ),
        (
            [[1]],
            [[1]],
        ),
        (
            [[0]],
            [[0]],
        ),
        (
            [[1, 2, 3, 4]],
            [[1, 2, 3, 4]],
        ),
        (
            [[1], [0], [3]],
            [[0], [0], [0]],
        ),
    ]

    for matrix, expected in test_cases:
        actual = clone_matrix(matrix)
        solution.setZeroes(actual)
        print(f"{format_matrix(actual)} | {format_matrix(expected)}")


if __name__ == "__main__":
    run_tests()
