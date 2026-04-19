from typing import List


class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        Find the mapping of elements from nums1 to their indices in nums2.

        Args:
            nums1: First array of unique integers
            nums2: Second array which is an anagram of nums1

        Returns:
            A list where mapping[i] is the index of nums1[i] in nums2
        """
        mapping = {}

        for index, num in enumerate(nums2):
            mapping[num] = index

        res = []

        for num in nums1:
            res.append(mapping[num])

        return res


def test_anagramMappings():
    """
    Test suite for anagramMappings function.
    Tests various cases including:
    - Basic mapping
    - Single element
    - Already ordered
    - Reversed order
    - Random permutation
    """
    solution = Solution()

    # Test Case 1: Basic example with different order
    nums1_1 = [12, 28, 46, 32, 50]
    nums2_1 = [50, 12, 32, 46, 28]
    expected1 = [1, 4, 3, 2, 0]
    actual1 = solution.anagramMappings(nums1_1, nums2_1)
    result1 = "PASS" if actual1 == expected1 else "FAIL"
    print(f"{actual1} | {expected1} | {result1}")

    # Test Case 2: Single element
    nums1_2 = [1]
    nums2_2 = [1]
    expected2 = [0]
    actual2 = solution.anagramMappings(nums1_2, nums2_2)
    result2 = "PASS" if actual2 == expected2 else "FAIL"
    print(f"{actual2} | {expected2} | {result2}")

    # Test Case 3: Two elements in order
    nums1_3 = [84, 46]
    nums2_3 = [84, 46]
    expected3 = [0, 1]
    actual3 = solution.anagramMappings(nums1_3, nums2_3)
    result3 = "PASS" if actual3 == expected3 else "FAIL"
    print(f"{actual3} | {expected3} | {result3}")

    # Test Case 4: Two elements reversed
    nums1_4 = [1, 2]
    nums2_4 = [2, 1]
    expected4 = [1, 0]
    actual4 = solution.anagramMappings(nums1_4, nums2_4)
    result4 = "PASS" if actual4 == expected4 else "FAIL"
    print(f"{actual4} | {expected4} | {result4}")

    # Test Case 5: Three elements with random order
    nums1_5 = [3, 5, 7]
    nums2_5 = [7, 5, 3]
    expected5 = [2, 1, 0]
    actual5 = solution.anagramMappings(nums1_5, nums2_5)
    result5 = "PASS" if actual5 == expected5 else "FAIL"
    print(f"{actual5} | {expected5} | {result5}")

    # Test Case 6: Larger array with mixed order
    nums1_6 = [1, 2, 3, 4, 5]
    nums2_6 = [5, 4, 3, 2, 1]
    expected6 = [4, 3, 2, 1, 0]
    actual6 = solution.anagramMappings(nums1_6, nums2_6)
    result6 = "PASS" if actual6 == expected6 else "FAIL"
    print(f"{actual6} | {expected6} | {result6}")

    # Test Case 7: Array with larger numbers
    nums1_7 = [10, 20, 30]
    nums2_7 = [30, 10, 20]
    expected7 = [1, 2, 0]
    actual7 = solution.anagramMappings(nums1_7, nums2_7)
    result7 = "PASS" if actual7 == expected7 else "FAIL"
    print(f"{actual7} | {expected7} | {result7}")


if __name__ == "__main__":
    test_anagramMappings()
