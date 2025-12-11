"""
704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an
integer target, write a function to search target in nums. If target exists,
then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
"""

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """
        Binary search for target in sorted array.

        Args:
            nums: Sorted array in ascending order
            target: Value to search for

        Returns:
            Index of target if found, -1 otherwise

        Time Complexity: O(log n) where n = len(nums)
        Space Complexity: O(1) - only constant extra space
        """
        left = 0
        right = len(nums) - 1

        while left <= right:
            middle = left + (right - left) // 2

            if nums[middle] == target:
                return middle
            elif nums[middle] < target:
                left = middle + 1
            else:
                right = middle - 1

        return -1


def test_binary_search():
    solution = Solution()

    # Test case 1: Example 1 - target found in middle-right
    result1 = solution.search([-1, 0, 3, 5, 9, 12], 9)
    print(f"Test 1: {result1} (expected: 4)")

    # Test case 2: Example 2 - target not found
    result2 = solution.search([-1, 0, 3, 5, 9, 12], 2)
    print(f"Test 2: {result2} (expected: -1)")

    # Test case 3: Single element - found
    result3 = solution.search([5], 5)
    print(f"Test 3: {result3} (expected: 0)")

    # Test case 4: Single element - not found
    result4 = solution.search([5], -5)
    print(f"Test 4: {result4} (expected: -1)")

    # Test case 5: Target at beginning
    result5 = solution.search([-1, 0, 3, 5, 9, 12], -1)
    print(f"Test 5: {result5} (expected: 0)")

    # Test case 6: Target at end
    result6 = solution.search([-1, 0, 3, 5, 9, 12], 12)
    print(f"Test 6: {result6} (expected: 5)")

    # Test case 7: Target smaller than all elements
    result7 = solution.search([1, 2, 3, 4, 5], 0)
    print(f"Test 7: {result7} (expected: -1)")

    # Test case 8: Target larger than all elements
    result8 = solution.search([1, 2, 3, 4, 5], 6)
    print(f"Test 8: {result8} (expected: -1)")

    # Test case 9: Two elements - target is first
    result9 = solution.search([1, 3], 1)
    print(f"Test 9: {result9} (expected: 0)")

    # Test case 10: Two elements - target is second
    result10 = solution.search([1, 3], 3)
    print(f"Test 10: {result10} (expected: 1)")


if __name__ == "__main__":
    test_binary_search()
