class Solution:
    def maxSumDivThree(self, nums):
        dp = [0, 0, 0]
        for a in nums:
            for i in dp[:]:
                dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a)
        return dp[0]


s = Solution()
nums = [3, 6, 5, 1, 8]
print(s.maxSumDivThree(nums), 18)
nums = [4]
print(s.maxSumDivThree(nums), 0)
nums = [1, 2, 3, 4, 4]
print(s.maxSumDivThree(nums), 12)
