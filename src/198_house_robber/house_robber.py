from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        a, b = nums[0], nums[0]

        if len(nums) >= 2:
            b = max(a, nums[1])

        for i in range(2, len(nums)):
            a, b = b, max(b, a + nums[i])

        return b


# Test helper
def test_rob():
    solution = Solution()

    # Test case 1: Example 1
    nums1 = [1, 2, 3, 1]
    expected1 = 4
    actual1 = solution.rob(nums1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    nums2 = [2, 7, 9, 3, 1]
    expected2 = 12
    actual2 = solution.rob(nums2)
    print(f"{actual2} | {expected2}")

    # Test case 3: n=1
    nums3 = [5]
    expected3 = 5
    actual3 = solution.rob(nums3)
    print(f"{actual3} | {expected3}")

    # Test case 4: n=2
    nums4 = [1, 2]
    expected4 = 2
    actual4 = solution.rob(nums4)
    print(f"{actual4} | {expected4}")

    # Test case 5: All zeros
    nums5 = [0, 0, 0]
    expected5 = 0
    actual5 = solution.rob(nums5)
    print(f"{actual5} | {expected5}")


if __name__ == "__main__":
    test_rob()
