class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        ans = 0
        k = 0
        mask = 1

        while mask <= n:
            if n & mask:
                ans = 2 ** (k + 1) - 1 - ans

            mask <<= 1
            k += 1

        return ans


s = Solution()
n = 3
print(s.minimumOneBitOperations(n), 2)
n = 6
print(s.minimumOneBitOperations(n), 4)
n = 0
print(s.minimumOneBitOperations(n), 0)
n = 1
print(s.minimumOneBitOperations(n), 1)
