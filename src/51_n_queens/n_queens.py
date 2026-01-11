from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        board = [["."] * n for _ in range(n)]
        cols = set()
        diag1 = set()
        diag2 = set()

        def backtrack(row):
            if row == n:
                res.append(["".join(r) for r in board])
                return
            for col in range(n):
                if col in cols or (row - col) in diag1 or (row + col) in diag2:
                    continue
                board[row][col] = "Q"
                cols.add(col)
                diag1.add(row - col)
                diag2.add(row + col)
                backtrack(row + 1)
                board[row][col] = "."
                cols.remove(col)
                diag1.remove(row - col)
                diag2.remove(row + col)

        backtrack(0)
        return res


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()
    tests = [4, 1, 2, 3, 5]
    for n in tests:
        result = sol.solveNQueens(n)
        print(f"n={n}: {result}")
