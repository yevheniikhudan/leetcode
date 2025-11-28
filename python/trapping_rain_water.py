"""
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width
of each bar is 1, compute how much water it can trap after raining.
"""

from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        res, max_left, max_right, left, right = 0, 0, 0, 0, len(height) - 1

        while (left < right):
            h_l, h_r = height[left], height[right]
            if h_l < h_r:
                max_left = max(max_left, h_l)
                res += max_left - h_l
                left += 1
            else:
                max_right = max(max_right, h_r)
                res += max_right - h_r
                right -= 1
        
        return res


def test_trapping_rain_water():
    solution = Solution()

    # Test case 1: Example 1
    height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    result = solution.trap(height)
    expected = 6
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2
    height = [4, 2, 0, 3, 2, 5]
    result = solution.trap(height)
    expected = 9
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: No water trapped (flat)
    height = [3, 3, 3, 3]
    result = solution.trap(height)
    expected = 0
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: No water trapped (increasing)
    height = [1, 2, 3, 4, 5]
    result = solution.trap(height)
    expected = 0
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: No water trapped (decreasing)
    height = [5, 4, 3, 2, 1]
    result = solution.trap(height)
    expected = 0
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: Simple valley
    height = [3, 0, 2]
    result = solution.trap(height)
    expected = 2
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: Multiple valleys
    height = [3, 0, 2, 0, 4]
    result = solution.trap(height)
    expected = 7
    print(f"Test 7: {result} (expected: {expected})")

    # Test case 8: Two elements
    height = [2, 1]
    result = solution.trap(height)
    expected = 0
    print(f"Test 8: {result} (expected: {expected})")


if __name__ == "__main__":
    test_trapping_rain_water()
