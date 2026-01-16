from typing import List


class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)

        return [list(set1 - set2), list(set2 - set1)]


# Test scaffolding
if __name__ == "__main__":
    tests = [
        ([1, 2, 3], [2, 4, 6], [[1, 3], [4, 6]]),
        ([1, 2, 3, 3], [1, 1, 2, 2], [[3], []]),
        ([1, 2, 3], [4, 5, 6], [[1, 2, 3], [4, 5, 6]]),
        ([1, 2, 2, 3], [3, 4, 4, 5], [[1, 2], [4, 5]]),
        ([1], [1], [[], []]),
    ]
    for nums1, nums2, expected in tests:
        actual = Solution().findDifference(nums1, nums2)
        print(f"{actual} | {expected}")
