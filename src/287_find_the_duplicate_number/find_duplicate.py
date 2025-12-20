"""
287. Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer
is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only
constant extra space.

Difficulty: Medium
"""

from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        """
        Find the duplicate number in the array.

        Args:
            nums: List of integers with n+1 elements in range [1, n]

        Returns:
            The duplicate number

        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        slow, fast = 0, 0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break

        slow = 0
        while True:
            slow = nums[slow]
            fast = nums[fast]
            if slow == fast:
                return slow


def test_find_duplicate():
    solution = Solution()

    # Test case 1: Example 1 - basic case
    nums1 = [1, 3, 4, 2, 2]
    result1 = solution.findDuplicate(nums1)
    print(f"Test 1: {result1} (expected: 2)")

    # Test case 2: Example 2 - duplicate at different position
    nums2 = [3, 1, 3, 4, 2]
    result2 = solution.findDuplicate(nums2)
    print(f"Test 2: {result2} (expected: 3)")

    # Test case 3: Example 3 - all same number
    nums3 = [3, 3, 3, 3, 3]
    result3 = solution.findDuplicate(nums3)
    print(f"Test 3: {result3} (expected: 3)")

    # Test case 4: Duplicate at start
    nums4 = [1, 1]
    result4 = solution.findDuplicate(nums4)
    print(f"Test 4: {result4} (expected: 1)")

    # Test case 5: Duplicate at end
    nums5 = [1, 2, 3, 4, 4]
    result5 = solution.findDuplicate(nums5)
    print(f"Test 5: {result5} (expected: 4)")

    # Test case 6: Larger array
    nums6 = [2, 5, 9, 6, 9, 3, 8, 9, 7, 1, 4]
    result6 = solution.findDuplicate(nums6)
    print(f"Test 6: {result6} (expected: 9)")

    # Test case 7: Sequential with duplicate in middle
    nums7 = [1, 2, 3, 3, 4, 5, 6]
    result7 = solution.findDuplicate(nums7)
    print(f"Test 7: {result7} (expected: 3)")


if __name__ == "__main__":
    test_find_duplicate()
