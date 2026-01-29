from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxSoFar = 1
        minSoFar = 1
        result = nums[0]

        for num in nums:
            nextMax = num * maxSoFar
            nextMin = num * minSoFar
            maxSoFar = max(num, nextMax, nextMin)
            minSoFar = min(num, nextMax, nextMin)
            result = max(result, maxSoFar)

        return result


# Test helper
def test_max_product():
    solution = Solution()

    # Test case 1: Example 1
    nums1 = [2, 3, -2, 4]
    expected1 = 6
    actual1 = solution.maxProduct(nums1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    nums2 = [-2, 0, -1]
    expected2 = 0
    actual2 = solution.maxProduct(nums2)
    print(f"{actual2} | {expected2}")

    # Test case 3: All positive
    nums3 = [1, 2, 3, 4]
    expected3 = 24
    actual3 = solution.maxProduct(nums3)
    print(f"{actual3} | {expected3}")

    # Test case 4: All negative
    nums4 = [-1, -2, -3]
    expected4 = -1
    actual4 = solution.maxProduct(nums4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Single element
    nums5 = [5]
    expected5 = 5
    actual5 = solution.maxProduct(nums5)
    print(f"{actual5} | {expected5}")

    # Test case 6: With zero
    nums6 = [2, 0, 3, -1]
    expected6 = 3
    actual6 = solution.maxProduct(nums6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_max_product()
