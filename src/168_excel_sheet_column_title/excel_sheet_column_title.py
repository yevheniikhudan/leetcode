class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = ""

        while columnNumber > 0:
            offset = (columnNumber - 1) % 26
            res += chr(ord("A") + offset)

            columnNumber = (columnNumber - 1) // 26

        return res[::-1]


def test():
    s = Solution()
    print(s.convertToTitle(1), "| A")
    print(s.convertToTitle(28), "| AB")
    print(s.convertToTitle(701), "| ZY")
    print(s.convertToTitle(52), "| AZ")
    print(s.convertToTitle(2147483647), "| FXSHRXW")


if __name__ == "__main__":
    test()
