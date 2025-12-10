"""
3583. Count Special Triplets

You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:
- 0 <= i < j < k < n, where n = nums.length
- nums[i] == nums[j] * 2
- nums[k] == nums[j] * 2

Return the total number of special triplets in the array.
Since the answer may be large, return it modulo 10^9 + 7.
"""

from collections import Counter


class Solution:
    def countSpecialTriplets(self, nums: list[int]) -> int:
        """
        Count the number of special triplets in the array.

        Args:
            nums: List of integers

        Returns:
            Number of special triplets modulo 10^9 + 7

        Time Complexity: O(n) where n = len(nums)
        Space Complexity: O(n) for frequency maps
        """
        mod = 10**9 + 7
        result = 0

        freq_prev, freq_next = Counter(), Counter(nums)
        for num in nums:
            freq_next[num] -= 1
            result += freq_prev[num * 2] * freq_next[num * 2]
            freq_prev[num] += 1

        return result % mod


def test_count_special_triplets():
    solution = Solution()

    # Test case 1: Example 1
    result1 = solution.countSpecialTriplets([6, 3, 6])
    print(f"Test 1: {result1} (expected: 1)")

    # Test case 2: Example 2 - with zeros
    result2 = solution.countSpecialTriplets([0, 1, 0, 0])
    print(f"Test 2: {result2} (expected: 1)")

    # Test case 3: Example 3
    result3 = solution.countSpecialTriplets([8, 4, 2, 8, 4])
    print(f"Test 3: {result3} (expected: 2)")

    # Test case 4: No valid triplets
    result4 = solution.countSpecialTriplets([1, 2, 3])
    print(f"Test 4: {result4} (expected: 0)")

    # Test case 5: Minimum length
    result5 = solution.countSpecialTriplets([4, 2, 4])
    print(f"Test 5: {result5} (expected: 1)")

    # Test case 6: All zeros
    result6 = solution.countSpecialTriplets([0, 0, 0, 0])
    print(f"Test 6: {result6} (expected: 4)")

    # Test case 7: Multiple valid triplets
    result7 = solution.countSpecialTriplets([10, 5, 10, 5, 10])
    print(f"Test 7: {result7} (expected: 4)")

    # Test case 8: Large numbers
    result8 = solution.countSpecialTriplets([100, 50, 100, 50, 100, 50, 100])
    print(f"Test 8: {result8} (expected: 10)")


if __name__ == "__main__":
    test_count_special_triplets()
