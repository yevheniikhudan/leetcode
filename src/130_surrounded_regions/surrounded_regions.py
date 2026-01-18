from collections import deque
from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows, cols = len(board), len(board[0])
        dirs = ((-1, 0), (1, 0), (0, 1), (0, -1))
        q = deque()

        for row in range(rows):
            for col in range(cols):
                if (
                    row == 0 or col == 0 or row == rows - 1 or col == cols - 1
                ) and board[row][col] == "O":
                    q.append((row, col))

        while q:
            row, col = q.popleft()
            board[row][col] = "S"
            for dR, dC in dirs:
                newRow = row + dR
                newCol = col + dC
                if (
                    0 <= newRow < rows
                    and 0 <= newCol < cols
                    and board[newRow][newCol] == "O"
                ):
                    q.append((newRow, newCol))

        for row in range(rows):
            for col in range(cols):
                if board[row][col] == "O":
                    board[row][col] = "X"
                if board[row][col] == "S":
                    board[row][col] = "O"


def test():
    sol = Solution()
    board1 = [
        ["X", "X", "X", "X"],
        ["X", "O", "O", "X"],
        ["X", "X", "O", "X"],
        ["X", "O", "X", "X"],
    ]
    sol.solve(board1)
    print(
        board1,
        '| [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]',
    )
    board2 = [["X"]]
    sol.solve(board2)
    print(board2, '| [["X"]]')
    board3 = [["O", "O"], ["O", "O"]]
    sol.solve(board3)
    print(board3, '| [["O","O"],["O","O"]]')
    board4 = [["X", "O", "X"], ["O", "X", "O"], ["X", "O", "X"]]
    sol.solve(board4)
    print(board4, '| [["X","O","X"],["O","X","O"],["X","O","X"]]')
    board5 = [["O"]]
    sol.solve(board5)
    print(board5, '| [["O"]]')


if __name__ == "__main__":
    test()
