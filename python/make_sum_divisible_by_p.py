"""
1590. Make Sum Divisible by P

Given an array of positive integers nums, remove the smallest subarray
(possibly empty) such that the sum of the remaining elements is divisible by p.
It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if
it's impossible.
"""

from typing import List


class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total_sum = sum(nums)
        remain = total_sum % p

        if remain == 0:
            return 0

        cur_sum = 0
        seen = {0: -1}
        res = len(nums)

        for index, num in enumerate(nums):
            cur_sum = (cur_sum + num) % p
            prefix = (cur_sum - remain + p) % p
            if prefix in seen:
                length = index - seen[prefix]
                res = min(res, length)

            seen[cur_sum] = index

        return -1 if res == len(nums) else res


def test_make_sum_divisible_by_p():
    solution = Solution()

    nums = [3, 1, 4, 2]
    p = 6
    result = solution.minSubarray(nums, p)
    expected = 1
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2
    nums = [6, 3, 5, 2]
    p = 9
    result = solution.minSubarray(nums, p)
    expected = 2
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: Example 3 - already divisible
    nums = [1, 2, 3]
    p = 3
    result = solution.minSubarray(nums, p)
    expected = 0
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: Single element - impossible
    nums = [5]
    p = 3
    result = solution.minSubarray(nums, p)
    expected = -1
    print(
        f"Test 4: {result} (expected: {expected})"
    )  # Test case 5: Already divisible (sum = 10)
    nums = [1, 2, 3, 4]
    p = 5
    result = solution.minSubarray(nums, p)
    expected = 0
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: Remove last element (sum = 11, remove 1)
    nums = [1, 2, 3, 5]
    p = 5
    result = solution.minSubarray(nums, p)
    expected = 1
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: Cannot remove entire array
    nums = [26, 19, 11, 14, 18, 4, 7, 1, 30, 23, 19, 8, 10, 6, 26, 3]
    p = 26
    result = solution.minSubarray(nums, p)
    expected = 3
    print(f"Test 7: {result} (expected: {expected})")

    # Test case 8: Large numbers
    nums = [1000000000, 1000000000, 1000000000]
    p = 3
    result = solution.minSubarray(nums, p)
    expected = 0
    print(f"Test 8: {result} (expected: {expected})")


if __name__ == "__main__":
    test_make_sum_divisible_by_p()
