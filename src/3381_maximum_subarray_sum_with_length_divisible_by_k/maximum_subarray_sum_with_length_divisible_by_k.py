"""
3381. Maximum Subarray Sum With Length Divisible by K

You are given an array of integers nums and an integer k.
Return the maximum sum of a subarray of nums, such that the size
of the subarray is divisible by k.
"""

from typing import List


class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        prefix = [float("inf")] * k
        prefix[0] = 0
        total = 0
        res = float("-inf")

        for i, n in enumerate(nums):
            remainder = (i + 1) % k
            total += n
            res = max(res, total - prefix[remainder])
            prefix[remainder] = min(prefix[remainder], total)

        return res


def test_maximum_subarray_sum():
    solution = Solution()

    # Test case 1: Simple case with k=1
    # nums = [1, 2]
    # k = 1
    # result = solution.maxSubarraySum(nums, k)
    # expected = 3
    # print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: All negative numbers
    nums = [-1, -2, -3, -4, -5]
    k = 4
    result = solution.maxSubarraySum(nums, k)
    expected = -10
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: Mixed positive and negative
    nums = [-5, 1, 2, -3, 4]
    k = 2
    result = solution.maxSubarraySum(nums, k)
    expected = 4
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: Single element
    nums = [5]
    k = 1
    result = solution.maxSubarraySum(nums, k)
    expected = 5
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: Entire array
    nums = [1, 2, 3, 4]
    k = 4
    result = solution.maxSubarraySum(nums, k)
    expected = 10
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: k = 2, multiple valid subarrays
    nums = [1, -1, 5, -2, 3]
    k = 2
    result = solution.maxSubarraySum(nums, k)
    expected = 5  # [-1, 5, -2, 3] has length 4 and sum 5
    # Valid subarrays with length divisible by 2:
    # [1, -1]=0, [-1, 5]=4, [5, -2]=3, [-2, 3]=1, [1, -1, 5, -2]=3, [-1, 5, -2, 3]=5
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: Large negative at start
    nums = [-10, 5, 5]
    k = 3
    result = solution.maxSubarraySum(nums, k)
    expected = 0
    print(f"Test 7: {result} (expected: {expected})")


if __name__ == "__main__":
    test_maximum_subarray_sum()
