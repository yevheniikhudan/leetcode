"""
33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown
pivot index k (1 <= k < nums.length) such that the resulting array is
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).

Given the array nums after the possible rotation and an integer target, return
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
"""

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """
        Search for target in rotated sorted array.

        Args:
            nums: Rotated sorted array with unique elements
            target: Value to search for

        Returns:
            Index of target if found, -1 otherwise

        Time Complexity: O(log n) - binary search
        Space Complexity: O(1) - constant extra space
        """
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if target == nums[mid]:
                return mid

            if nums[right] > nums[mid]:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1

        return -1


def test_search():
    solution = Solution()

    # Test case 1: Example 1 - target found
    result1 = solution.search([4, 5, 6, 7, 0, 1, 2], 0)
    print(f"Test 1: {result1} (expected: 4)")

    # Test case 2: Example 2 - target not found
    result2 = solution.search([4, 5, 6, 7, 0, 1, 2], 3)
    print(f"Test 2: {result2} (expected: -1)")

    # Test case 3: Example 3 - single element, not found
    result3 = solution.search([1], 0)
    print(f"Test 3: {result3} (expected: -1)")

    # Test case 4: Single element, found
    result4 = solution.search([1], 1)
    print(f"Test 4: {result4} (expected: 0)")

    # Test case 5: No rotation, target found
    result5 = solution.search([1, 2, 3, 4, 5], 3)
    print(f"Test 5: {result5} (expected: 2)")

    # Test case 6: Target at beginning
    result6 = solution.search([4, 5, 6, 7, 0, 1, 2], 4)
    print(f"Test 6: {result6} (expected: 0)")

    # Test case 7: Target at end
    result7 = solution.search([4, 5, 6, 7, 0, 1, 2], 2)
    print(f"Test 7: {result7} (expected: 6)")

    # Test case 8: Target at inflection point
    result8 = solution.search([4, 5, 6, 7, 0, 1, 2], 7)
    print(f"Test 8: {result8} (expected: 3)")

    # Test case 9: Two elements - rotated
    result9 = solution.search([3, 1], 1)
    print(f"Test 9: {result9} (expected: 1)")

    # Test case 10: Large array with rotation
    result10 = solution.search([6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5], 3)
    print(f"Test 10: {result10} (expected: 8)")

    # Test case 11: Target smaller than all in left portion
    result11 = solution.search([4, 5, 6, 7, 0, 1, 2], 1)
    print(f"Test 11: {result11} (expected: 5)")

    # Test case 12: Target larger than all in right portion
    result12 = solution.search([4, 5, 6, 7, 0, 1, 2], 6)
    print(f"Test 12: {result12} (expected: 2)")


if __name__ == "__main__":
    test_search()
