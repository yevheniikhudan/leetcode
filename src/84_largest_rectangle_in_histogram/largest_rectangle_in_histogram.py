"""
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height
where the width of each bar is 1, return the area of the largest rectangle
in the histogram.
"""

from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        """
        Find the largest rectangle area in a histogram using monotonic stack.

        Args:
            heights: List of bar heights

        Returns:
            Maximum rectangle area

        Time Complexity: O(n) where n = len(heights)
        Space Complexity: O(n) for the monotonic stack
        """
        n = len(heights)
        result = 0
        stack = []

        for i in range(n + 1):
            while stack and (i == n or heights[stack[-1]] > heights[i]):
                height = heights[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                result = max(result, width * height)

            stack.append(i)

        return result

    def largestRectangleAreaBruteForce(self, heights: List[int]) -> int:
        """
        Find the largest rectangle area in a histogram (brute force approach).

        Args:
            heights: List of bar heights

        Returns:
            Maximum rectangle area

        Time Complexity: O(n²) where n = len(heights)
        Space Complexity: O(1) - only constant extra space
        """
        n = len(heights)
        result = 0
        for i in range(n):
            h = heights[i]

            right = i + 1
            while right < n and heights[right] >= h:
                right += 1

            left = i
            while left >= 0 and heights[left] >= h:
                left -= 1

            left += 1
            right -= 1

            result = max(result, (right - left + 1) * h)

        return result


def test_largest_rectangle_area():
    solution = Solution()

    # Test case 1: Example 1
    result1 = solution.largestRectangleArea([2, 1, 5, 6, 2, 3])
    print(f"Test 1: {result1} (expected: 10)")

    # Test case 2: Example 2
    result2 = solution.largestRectangleArea([2, 4])
    print(f"Test 2: {result2} (expected: 4)")

    # Test case 3: Single bar
    result3 = solution.largestRectangleArea([5])
    print(f"Test 3: {result3} (expected: 5)")

    # Test case 4: Increasing heights
    result4 = solution.largestRectangleArea([1, 2, 3, 4, 5])
    print(f"Test 4: {result4} (expected: 9)")

    # Test case 5: Decreasing heights
    result5 = solution.largestRectangleArea([5, 4, 3, 2, 1])
    print(f"Test 5: {result5} (expected: 9)")

    # Test case 6: All same height
    result6 = solution.largestRectangleArea([3, 3, 3, 3])
    print(f"Test 6: {result6} (expected: 12)")

    # Test case 7: With zeros
    result7 = solution.largestRectangleArea([2, 0, 2])
    print(f"Test 7: {result7} (expected: 2)")

    # Test case 8: Large rectangle in middle
    result8 = solution.largestRectangleArea([1, 2, 3, 4, 5, 3, 3, 2])
    print(f"Test 8: {result8} (expected: 15)")


if __name__ == "__main__":
    test_largest_rectangle_area()
