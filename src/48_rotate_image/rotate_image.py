from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        def transpose() -> None:
            for row in range(len(matrix)):
                for col in range(row + 1, len(matrix[row])):
                    matrix[row][col], matrix[col][row] = (
                        matrix[col][row],
                        matrix[row][col],
                    )

        def reverse() -> None:
            for row in matrix:
                row.reverse()

        transpose()
        reverse()


def clone_matrix(matrix: List[List[int]]) -> List[List[int]]:
    return [row[:] for row in matrix]


def format_matrix(matrix: List[List[int]]) -> str:
    return str(matrix)


def run_tests() -> None:
    solution = Solution()

    test_cases = [
        (
            [[1, 2, 3], [4, 5, 6], [7, 8, 9]],
            [[7, 4, 1], [8, 5, 2], [9, 6, 3]],
        ),
        (
            [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]],
            [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]],
        ),
        (
            [[1]],
            [[1]],
        ),
        (
            [[1, 2], [3, 4]],
            [[3, 1], [4, 2]],
        ),
        (
            [[-1, -2, -3], [-4, -5, -6], [-7, -8, -9]],
            [[-7, -4, -1], [-8, -5, -2], [-9, -6, -3]],
        ),
        (
            [[1, 1, 1], [2, 2, 2], [3, 3, 3]],
            [[3, 2, 1], [3, 2, 1], [3, 2, 1]],
        ),
    ]

    for matrix, expected in test_cases:
        actual = clone_matrix(matrix)
        solution.rotate(actual)
        print(f"{format_matrix(actual)} | {format_matrix(expected)}")


if __name__ == "__main__":
    run_tests()
