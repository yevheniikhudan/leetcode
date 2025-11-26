class Solution:
    """
    Longest Consecutive Sequence

    Given an unsorted array of integers, return the length of the longest consecutive elements sequence.
    """

    def longestConsecutive(self, nums: list[int]) -> int:
        


def test_longest_consecutive_sequence():
    solution = Solution()

    # Test case 1
    nums1 = [100, 4, 200, 1, 3, 2]
    result1 = solution.longestConsecutive(nums1)
    print(f"Test 1: {nums1} -> {result1}")
    assert result1 == 4, f"Expected 4, got {result1}"

    # Test case 2
    nums2 = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
    result2 = solution.longestConsecutive(nums2)
    print(f"Test 2: {nums2} -> {result2}")
    assert result2 == 9, f"Expected 9, got {result2}"

    # Test case 3
    nums3 = [1, 0, 1, 2]
    result3 = solution.longestConsecutive(nums3)
    print(f"Test 3: {nums3} -> {result3}")
    assert result3 == 3, f"Expected 3, got {result3}"

    # Test case 4: Empty array
    nums4 = []
    result4 = solution.longestConsecutive(nums4)
    print(f"Test 4: {nums4} -> {result4}")
    assert result4 == 0, f"Expected 0, got {result4}"

    # Test case 5: Single element
    nums5 = [1]
    result5 = solution.longestConsecutive(nums5)
    print(f"Test 5: {nums5} -> {result5}")
    assert result5 == 1, f"Expected 1, got {result5}"

    # Test case 6: No consecutive
    nums6 = [1, 3, 5, 7, 9]
    result6 = solution.longestConsecutive(nums6)
    print(f"Test 6: {nums6} -> {result6}")
    assert result6 == 1, f"Expected 1, got {result6}"

    print("All test cases passed!")


if __name__ == "__main__":
    test_longest_consecutive_sequence()
