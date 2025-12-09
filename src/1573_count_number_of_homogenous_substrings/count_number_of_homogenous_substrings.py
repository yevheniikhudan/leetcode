class Solution:
    def countHomogenous(self, s: str) -> int:
        MOD = 10**9 + 7
        ans = 0
        streak = 0

        for i in range(len(s)):
            if i == 0 or s[i] == s[i - 1]:
                streak += 1
            else:
                streak = 1

            ans = (ans + streak) % MOD

        return ans

sol = Solution()
assert sol.countHomogenous("abbcccaa") == 13
assert sol.countHomogenous("xy") == 2
assert sol.countHomogenous("zzzzz") == 15
print("All test cases passed!")
