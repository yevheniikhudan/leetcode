from typing import List


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        dp = [[n] for n in nums]
        res = []

        for i in range(len(nums)):
            for j in range(0, i):
                if nums[i] % nums[j] == 0 and len(dp[j]) + 1 > len(dp[i]):
                    dp[i] = dp[j] + [nums[i]]
            if len(dp[i]) > len(res):
                res = dp[i]

        return res

    def largestDivisibleSubsetRecursive(self, nums: List[int]) -> List[int]:
        nums.sort()
        memo = {}

        def dfs(i, prev):
            if i == len(nums):
                return []

            key = (i, prev)

            if key in memo:
                return memo[key]

            skip = dfs(i + 1, prev)
            take = (
                [nums[i]] + dfs(i + 1, i)
                if prev == -1 or nums[i] % nums[prev] == 0
                else []
            )

            memo[key] = take if len(take) > len(skip) else skip
            return memo[key]

        return dfs(0, -1)


# Test scaffolding
def test():
    sol = Solution()
    print(sol.largestDivisibleSubset([1, 2, 3]), "| [1,2] or [1,3]")
    print(sol.largestDivisibleSubset([1, 2, 4, 8]), "| [1,2,4,8]")
    print(sol.largestDivisibleSubset([4, 8, 10, 240]), "| [4,8,240] or [10,240]")
    print(sol.largestDivisibleSubset([2, 3, 4, 9, 8]), "| [2,4,8] or [3,9]")
    print(sol.largestDivisibleSubset([1]), "| [1]")


if __name__ == "__main__":
    test()
