"""
153. Find Minimum in Rotated Sorted Array

Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
For example, the array nums = [0,1,2,4,5,6,7] might become:
- [4,5,6,7,0,1,2] if it was rotated 4 times.
- [0,1,2,4,5,6,7] if it was rotated 7 times.

Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
"""

from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        """
        Find minimum element in rotated sorted array.

        Args:
            nums: Rotated sorted array with unique elements

        Returns:
            Minimum element in the array

        Time Complexity: O(log n) - binary search
        Space Complexity: O(1) - constant extra space
        """
        l, r = 0, len(nums) - 1
        while l < r:
            m = l + (r - l) // 2
            if nums[m] < nums[r]:
                r = m
            else:
                l = m + 1
        return nums[l]


def test_find_min():
    solution = Solution()

    # Test case 1: Example 1 - rotated 3 times
    result1 = solution.findMin([3, 4, 5, 1, 2])
    print(f"Test 1: {result1} (expected: 1)")

    # Test case 2: Example 2 - rotated 4 times
    result2 = solution.findMin([4, 5, 6, 7, 0, 1, 2])
    print(f"Test 2: {result2} (expected: 0)")

    # Test case 3: Example 3 - not rotated (or rotated n times)
    result3 = solution.findMin([11, 13, 15, 17])
    print(f"Test 3: {result3} (expected: 11)")

    # Test case 4: Single element
    result4 = solution.findMin([1])
    print(f"Test 4: {result4} (expected: 1)")

    # Test case 5: Two elements - rotated
    result5 = solution.findMin([2, 1])
    print(f"Test 5: {result5} (expected: 1)")

    # Test case 6: Two elements - not rotated
    result6 = solution.findMin([1, 2])
    print(f"Test 6: {result6} (expected: 1)")

    # Test case 7: Minimum at beginning (rotated once)
    result7 = solution.findMin([5, 1, 2, 3, 4])
    print(f"Test 7: {result7} (expected: 1)")

    # Test case 8: Minimum at end
    result8 = solution.findMin([2, 3, 4, 5, 1])
    print(f"Test 8: {result8} (expected: 1)")

    # Test case 9: Large array
    result9 = solution.findMin([6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5])
    print(f"Test 9: {result9} (expected: 1)")

    # Test case 10: Negative numbers
    result10 = solution.findMin([3, 4, 5, -1, 0, 1, 2])
    print(f"Test 10: {result10} (expected: -1)")


if __name__ == "__main__":
    test_find_min()
