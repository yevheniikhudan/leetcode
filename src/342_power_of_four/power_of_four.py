class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False
        while n % 4 == 0:
            n //= 4
        return n == 1


def test():
    sol = Solution()
    print(sol.isPowerOfFour(16), "| True")
    print(sol.isPowerOfFour(5), "| False")
    print(sol.isPowerOfFour(1), "| True")
    print(sol.isPowerOfFour(64), "| True")
    print(sol.isPowerOfFour(0), "| False")
    print(sol.isPowerOfFour(-4), "| False")


if __name__ == "__main__":
    test()
