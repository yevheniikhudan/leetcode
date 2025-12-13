"""
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
"""

from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """
        Find median of two sorted arrays using binary search on partition.

        Args:
            nums1: First sorted array
            nums2: Second sorted array

        Returns:
            Median of combined arrays

        Time Complexity: O(log min(m, n)) - binary search on smaller array
        Space Complexity: O(1) - constant extra space
        """
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)

        m, n = len(nums1), len(nums2)
        left, right = 0, m

        while left <= right:
            partition_a = left + (right - left) // 2
            partition_b = (m + n + 1) // 2 - partition_a

            max_left_a = nums1[partition_a - 1] if partition_a > 0 else float("-inf")
            max_left_b = nums2[partition_b - 1] if partition_b > 0 else float("-inf")
            min_right_a = nums1[partition_a] if partition_a < m else float("inf")
            min_right_b = nums2[partition_b] if partition_b < n else float("inf")

            if max_left_a > min_right_b:
                right = partition_a - 1
            elif max_left_b > min_right_a:
                left = partition_a + 1
            else:
                if (m + n) % 2 == 0:
                    return (
                        max(max_left_a, max_left_b) + min(min_right_a, min_right_b)
                    ) / 2
                else:
                    return max(max_left_a, max_left_b)


def test_find_median():
    solution = Solution()

    # Test case 1: Example 1 - odd total length
    result1 = solution.findMedianSortedArrays([1, 3], [2])
    print(f"Test 1: {result1} (expected: 2.0)")

    # Test case 2: Example 2 - even total length
    result2 = solution.findMedianSortedArrays([1, 2], [3, 4])
    print(f"Test 2: {result2} (expected: 2.5)")

    # Test case 3: One empty array
    result3 = solution.findMedianSortedArrays([], [1])
    print(f"Test 3: {result3} (expected: 1.0)")

    # Test case 4: Both single element
    result4 = solution.findMedianSortedArrays([2], [3])
    print(f"Test 4: {result4} (expected: 2.5)")

    # Test case 5: No overlap
    result5 = solution.findMedianSortedArrays([1, 2], [3, 4, 5])
    print(f"Test 5: {result5} (expected: 3.0)")

    # Test case 6: Complete overlap
    result6 = solution.findMedianSortedArrays([1, 3, 5], [2, 4, 6])
    print(f"Test 6: {result6} (expected: 3.5)")

    # Test case 7: Different sizes
    result7 = solution.findMedianSortedArrays([1, 2, 3, 4, 5], [6])
    print(f"Test 7: {result7} (expected: 3.5)")

    # Test case 8: Negative numbers
    result8 = solution.findMedianSortedArrays([-5, -3, -1], [0, 2, 4])
    print(f"Test 8: {result8} (expected: -0.5)")

    # Test case 9: All elements in nums1 < nums2
    result9 = solution.findMedianSortedArrays([1, 2], [3, 4, 5, 6])
    print(f"Test 9: {result9} (expected: 3.5)")

    # Test case 10: Single element arrays
    result10 = solution.findMedianSortedArrays([1], [2, 3, 4, 5])
    print(f"Test 10: {result10} (expected: 3.0)")


if __name__ == "__main__":
    test_find_median()
