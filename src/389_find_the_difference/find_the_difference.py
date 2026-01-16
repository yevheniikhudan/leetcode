class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        sSum = 0
        tSum = 0

        lenT = len(t)

        for i in range(lenT):
            if i < lenT - 1:
                sSum += ord(s[i])

            tSum += ord(t[i])

        return chr(tSum - sSum)


def test():
    sol = Solution()
    print(sol.findTheDifference("abcd", "abcde"), "| e")
    print(sol.findTheDifference("", "y"), "| y")
    print(sol.findTheDifference("a", "aa"), "| a")
    print(sol.findTheDifference("ae", "aea"), "| a")
    print(sol.findTheDifference("xyz", "xzyq"), "| q")


if __name__ == "__main__":
    test()
