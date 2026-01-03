from typing import List


class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        sum = 0

        l = len(mat)

        for i in range(l):
            sum += mat[i][i]
            if l - 1 - i != i:
                sum += mat[i][l - 1 - i]

        return sum


# Test scaffolding
if __name__ == "__main__":
    tests = [
        ([[1, 2, 3], [4, 5, 6], [7, 8, 9]], 25),
        ([[1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1]], 8),
        ([[5]], 5),
        ([[1, 2], [3, 4]], 10),
        ([[7, 0, 0, 7], [0, 7, 7, 0], [0, 7, 7, 0], [7, 0, 0, 7]], 56),
    ]
    sol = Solution()
    for mat, expected in tests:
        actual = sol.diagonalSum(mat)
        print(f"{actual} | {expected}")
