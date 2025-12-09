"""
239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k
which is moving from the very left of the array to the very right. You can only
see the k numbers in the window. Each time the sliding window moves right by one
position.

Return the max sliding window.
"""

from collections import deque
from typing import List


class Solution:

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []
        q = deque()

        for right, right_num in enumerate(nums):
            while q and q[0] <= right - k:
                q.popleft()

            while q and nums[q[-1]] < right_num:
                q.pop()

            q.append(right)

            if right + 1 >= k:
                result.append(nums[q[0]])

        return result

    def maxSlidingWindowBruteForce(self, nums: List[int], k: int) -> List[int]:
        result = []

        for left in range(len(nums) - k + 1):
            window_max = nums[left]
            for right in range(left, left + k):
                window_max = max(window_max, nums[right])
            result.append(window_max)

        return result


def test_sliding_window_maximum():
    solution = Solution()

    # Test case 1: Example 1
    nums = [1, 3, -1, -3, 5, 3, 6, 7]
    k = 3
    result = solution.maxSlidingWindow(nums, k)
    expected = [3, 3, 5, 5, 6, 7]
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2
    nums = [1]
    k = 1
    result = solution.maxSlidingWindow(nums, k)
    expected = [1]
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: k equals array length
    nums = [1, 3, 1, 2, 0, 5]
    k = 6
    result = solution.maxSlidingWindow(nums, k)
    expected = [5]
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: Descending array
    nums = [9, 8, 7, 6, 5, 4, 3, 2, 1]
    k = 3
    result = solution.maxSlidingWindow(nums, k)
    expected = [9, 8, 7, 6, 5, 4, 3]
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: Ascending array
    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    k = 3
    result = solution.maxSlidingWindow(nums, k)
    expected = [3, 4, 5, 6, 7, 8, 9]
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: All elements equal
    nums = [5, 5, 5, 5, 5]
    k = 2
    result = solution.maxSlidingWindow(nums, k)
    expected = [5, 5, 5, 5]
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: k = 1
    nums = [4, -2, 7, 1]
    k = 1
    result = solution.maxSlidingWindow(nums, k)
    expected = [4, -2, 7, 1]
    print(f"Test 7: {result} (expected: {expected})")

    # Test case 8: Negative numbers
    nums = [-7, -8, 7, 5, 7, 1, 6, 0]
    k = 4
    result = solution.maxSlidingWindow(nums, k)
    expected = [7, 7, 7, 7, 7]
    print(f"Test 8: {result} (expected: {expected})")

    # Test case 9: Mixed positive and negative
    nums = [1, -1, 2, -2, 3, -3]
    k = 2
    result = solution.maxSlidingWindow(nums, k)
    expected = [1, 2, 2, 3, 3]
    print(f"Test 9: {result} (expected: {expected})")

    # Test case 10: Large window
    nums = [9, 11]
    k = 2
    result = solution.maxSlidingWindow(nums, k)
    expected = [11]
    print(f"Test 10: {result} (expected: {expected})")


if __name__ == "__main__":
    test_sliding_window_maximum()
