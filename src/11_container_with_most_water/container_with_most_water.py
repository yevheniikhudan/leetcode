"""
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the
container contains the most water.

Return the maximum amount of water a container can store.
"""

from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        res = 0
        left, right = 0, len(height) - 1

        while left < right:
            res = max(res, min(height[left], height[right]) * (right - left))

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return res


def test_container_with_most_water():
    solution = Solution()

    # Test case 1: Example 1
    height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    result = solution.maxArea(height)
    expected = 49
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2
    height = [1, 1]
    result = solution.maxArea(height)
    expected = 1
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: Increasing heights
    height = [1, 2, 3, 4, 5]
    result = solution.maxArea(height)
    expected = (
        6  # indices 0 and 4: (4-0) * min(1,5) = 4, or 1 and 4: (4-1) * min(2,5) = 6
    )
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: Decreasing heights
    height = [5, 4, 3, 2, 1]
    result = solution.maxArea(height)
    expected = 6  # indices 0 and 3: (3-0) * min(5,2) = 6
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: All same height
    height = [3, 3, 3, 3]
    result = solution.maxArea(height)
    expected = 9  # indices 0 and 3: (3-0) * min(3,3) = 9
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: Two tall lines far apart
    height = [10, 1, 1, 1, 1, 1, 1, 1, 1, 10]
    result = solution.maxArea(height)
    expected = 90  # indices 0 and 9: (9-0) * min(10,10) = 90
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: Peak in middle
    height = [1, 3, 5, 4, 2]
    result = solution.maxArea(height)
    expected = 6  # indices 1 and 4: (4-1) * min(3,2) = 6
    print(f"Test 7: {result} (expected: {expected})")


if __name__ == "__main__":
    test_container_with_most_water()
