from collections import defaultdict
from typing import List


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = defaultdict(int)
        dp[0] = 1

        for num in nums:
            next_dp = defaultdict(int)

            for total, count in dp.items():
                next_dp[total - num] += count
                next_dp[total + num] += count

            dp = next_dp

        return dp[target]

    def findTargetSumWaysTopDown(self, nums: List[int], target: int) -> int:
        memo = {}

        def dfs(i: int, total: int) -> int:
            if (i, total) in memo:
                return memo[(i, total)]
            if i == len(nums):
                if total == target:
                    return 1
                else:
                    return 0

            res = 0
            # assign minus
            res += dfs(i + 1, total - nums[i])
            # assign plus
            res += dfs(i + 1, total + nums[i])
            memo[(i, total)] = res

            return res

        return dfs(0, 0)


def test_findTargetSumWays():
    sol = Solution()
    # Test case 1: Example 1
    print(f"{sol.findTargetSumWays([1,1,1,1,1], 3)} | 5")
    # Test case 2: Example 2
    print(f"{sol.findTargetSumWays([1], 1)} | 1")
    # Test case 3: No ways
    print(f"{sol.findTargetSumWays([1], 2)} | 0")
    # Test case 4: Target 0
    print(f"{sol.findTargetSumWays([1,1], 0)} | 2")
    # Test case 5: Larger numbers
    print(f"{sol.findTargetSumWays([1,2,3], 0)} | 2")
    # Test case 6: All zeros
    print(f"{sol.findTargetSumWays([0,0], 0)} | 4")


if __name__ == "__main__":
    test_findTargetSumWays()
