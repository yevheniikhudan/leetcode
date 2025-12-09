class Solution:
    def numSub(self, s: str) -> int:
        MOD = 10**9 + 7

        total, consecutive = 0, 0

        for char in s:
            if char == "1":
                consecutive += 1
            else:
                total += consecutive * (consecutive + 1) // 2
                consecutive = 0

        total += consecutive * (consecutive + 1) // 2
        total %= MOD

        return total


s = Solution()
assert s.numSub("0110111") == 9
assert s.numSub("101") == 2
assert s.numSub("1111") == 10
print("All test cases passed!")
