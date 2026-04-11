from collections import defaultdict
from typing import List


class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        """
        Find the minimum distance between any three equal elements in the array.

        Args:
            nums: List of integers where 1 <= nums[i] <= 100

        Returns:
            Minimum distance (rightmost_index - leftmost_index) between three equal elements.
            Returns -1 if no three equal elements exist.
        """
        occur = defaultdict(list)
        res = 2**32

        for i in range(len(nums)):
            occur[nums[i]].append(i)

        for _, indices in occur.items():
            if len(indices) < 3:
                continue

            for i in range(2, len(indices)):
                res = min(res, indices[i] - indices[i - 2])
        return -1 if res == 2**32 else res * 2


def test_minimumDistance():
    """
    Test suite for minimumDistance function.
    Tests various cases including:
    - Basic cases with three equal elements
    - Cases with no three equal elements
    - Cases with multiple values
    - Minimum possible distance
    - Large distances
    """
    solution = Solution()

    # Test Case 1: All elements are the same
    nums1 = [1, 1, 1, 1, 1]
    expected1 = 4
    actual1 = solution.minimumDistance(nums1)
    result1 = "PASS" if actual1 == expected1 else "FAIL"
    print(f"{actual1} | {expected1} | {result1}")

    # Test Case 2: No three equal elements - should return -1
    nums2 = [1, 2, 3, 4, 5]
    expected2 = -1
    actual2 = solution.minimumDistance(nums2)
    result2 = "PASS" if actual2 == expected2 else "FAIL"
    print(f"{actual2} | {expected2} | {result2}")

    # Test Case 3: Multiple values, only one has 3+ occurrences
    nums3 = [1, 1, 2, 1, 1]
    expected3 = 6
    actual3 = solution.minimumDistance(nums3)
    result3 = "PASS" if actual3 == expected3 else "FAIL"
    print(f"{actual3} | {expected3} | {result3}")

    # Test Case 4: Three consecutive equal elements
    nums4 = [1, 1, 1]
    expected4 = 4
    actual4 = solution.minimumDistance(nums4)
    result4 = "PASS" if actual4 == expected4 else "FAIL"
    print(f"{actual4} | {expected4} | {result4}")

    # Test Case 5: Mixed values with different distances
    nums5 = [3, 3, 3, 3, 3]
    expected5 = 4
    actual5 = solution.minimumDistance(nums5)
    result5 = "PASS" if actual5 == expected5 else "FAIL"
    print(f"{actual5} | {expected5} | {result5}")

    # Test Case 6: Two values with 3+ occurrences - should return minimum
    nums6 = [1, 1, 2, 1, 2, 2, 1, 2]
    expected6 = 6
    actual6 = solution.minimumDistance(nums6)
    result6 = "PASS" if actual6 == expected6 else "FAIL"
    print(f"{actual6} | {expected6} | {result6}")

    # Test Case 7: Only two equal elements, another value with 3+ occurrences
    nums7 = [5, 5, 10, 10, 10]
    expected7 = 4
    actual7 = solution.minimumDistance(nums7)
    result7 = "PASS" if actual7 == expected7 else "FAIL"
    print(f"{actual7} | {expected7} | {result7}")

    # Test Case 8: Larger distance between three equal elements
    nums8 = [1, 2, 3, 1, 4, 5, 1]
    expected8 = 12
    actual8 = solution.minimumDistance(nums8)
    result8 = "PASS" if actual8 == expected8 else "FAIL"
    print(f"{actual8} | {expected8} | {result8}")


if __name__ == "__main__":
    test_minimumDistance()
