from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]

        def rob(left: int, right: int) -> int:  # rob left inclusive right exclusive
            a, b = 0, 0
            for i in range(left, right):
                a, b = b, max(nums[i] + a, b)

            return b

        return max(rob(0, n - 1), rob(1, n))


# Test helper
def test_rob():
    solution = Solution()

    # Test case 1: Example 1
    nums1 = [2, 3, 2]
    expected1 = 3
    actual1 = solution.rob(nums1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    nums2 = [1, 2, 3, 1]
    expected2 = 4
    actual2 = solution.rob(nums2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Example 3
    nums3 = [1, 2, 3]
    expected3 = 3
    actual3 = solution.rob(nums3)
    print(f"{actual3} | {expected3}")

    # Test case 4: Single house
    nums4 = [5]
    expected4 = 5
    actual4 = solution.rob(nums4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Two houses
    nums5 = [1, 2]
    expected5 = 2
    actual5 = solution.rob(nums5)
    print(f"{actual5} | {expected5}")

    # Test case 6: All zeros
    nums6 = [0, 0, 0, 0]
    expected6 = 0
    actual6 = solution.rob(nums6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_rob()
