from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1]

        for line in range(1, rowIndex + 1):
            nextLine = [0] * (line + 1)

            for i in range(len(res)):
                nextLine[i] += res[i]
                nextLine[i + 1] += res[i]

            res = nextLine

        return res


def test():
    sol = Solution()
    print(sol.getRow(3), "| [1, 3, 3, 1]")
    print(sol.getRow(0), "| [1]")
    print(sol.getRow(1), "| [1, 1]")
    print(sol.getRow(4), "| [1, 4, 6, 4, 1]")
    print(sol.getRow(5), "| [1, 5, 10, 10, 5, 1]")


if __name__ == "__main__":
    test()
