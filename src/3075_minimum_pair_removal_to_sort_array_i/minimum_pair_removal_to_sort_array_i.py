from typing import List


class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        nums = nums[:]
        count = 0
        while True:
            n = len(nums)
            if n <= 1:
                break
            # Check if already non-decreasing
            if all(nums[i] <= nums[i + 1] for i in range(n - 1)):
                break
            # Find leftmost adjacent pair with minimum sum
            min_sum = float("inf")
            min_idx = -1
            for i in range(n - 1):
                pair_sum = nums[i] + nums[i + 1]
                if pair_sum < min_sum:
                    min_sum = pair_sum
                    min_idx = i
            # Replace the pair with their sum
            nums = (
                nums[:min_idx]
                + [nums[min_idx] + nums[min_idx + 1]]
                + nums[min_idx + 2 :]
            )
            count += 1
        return count


# Test scaffolding
def test():
    sol = Solution()
    print(sol.minimumPairRemoval([5, 2, 3, 1]), "| 2")
    print(sol.minimumPairRemoval([1, 2, 2]), "| 0")
    print(sol.minimumPairRemoval([1]), "| 0")
    print(sol.minimumPairRemoval([2, 1]), "| 1")
    print(sol.minimumPairRemoval([3, 1, 2]), "| 1")


if __name__ == "__main__":
    test()
