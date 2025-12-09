class Solution:
    """
    Product of Array Except Self

    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
    """

    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = [1] * n

        for i in range(1, n):
            ans[i] = ans[i - 1] * nums[i - 1]

        postfix = 1
        for i in range(n - 1, -1, -1):
            ans[i] *= postfix
            postfix *= nums[i]

        return ans


def test_product_of_array_except_self():
    solution = Solution()

    # Test case 1
    nums1 = [1, 2, 3, 4]
    result1 = solution.productExceptSelf(nums1)
    print(f"Test 1: {nums1} -> {result1}")
    assert result1 == [24, 12, 8, 6], f"Expected [24,12,8,6], got {result1}"

    # Test case 2
    nums2 = [-1, 1, 0, -3, 3]
    result2 = solution.productExceptSelf(nums2)
    print(f"Test 2: {nums2} -> {result2}")
    assert result2 == [0, 0, 9, 0, 0], f"Expected [0,0,9,0,0], got {result2}"

    # Test case 3: Zeros
    nums3 = [0, 0, 2, 3]
    result3 = solution.productExceptSelf(nums3)
    print(f"Test 3: {nums3} -> {result3}")
    assert result3 == [0, 0, 0, 0], f"Expected [0,0,0,0], got {result3}"

    # Test case 4: Negative numbers
    nums4 = [-2, -3, -4]
    result4 = solution.productExceptSelf(nums4)
    print(f"Test 4: {nums4} -> {result4}")
    assert result4 == [12, 8, 6], f"Expected [12,8,6], got {result4}"

    print("All test cases passed!")


if __name__ == "__main__":
    test_product_of_array_except_self()
