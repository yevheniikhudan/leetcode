class Solution:
    """
    Remove Duplicates from Sorted Array

    Given a sorted array, remove duplicates in-place so that each unique element appears only once.
    """

    def removeDuplicates(self, nums: list[int]) -> int:
        if not nums:
            return 0

        k = 0
        for i in range(1, len(nums)):
            if nums[k] != nums[i]:
                k += 1
                nums[k] = nums[i]

        return k + 1


def test_remove_duplicates_from_sorted_array():
    solution = Solution()

    # Test case 1
    nums1 = [1, 1, 2]
    k1 = solution.removeDuplicates(nums1)
    print(f"Test 1: {nums1}, k = {k1}")
    assert k1 == 2 and nums1[:k1] == [
        1,
        2,
    ], f"Expected k=2, nums=[1,2], got k={k1}, nums={nums1[:k1]}"

    # Test case 2
    nums2 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    k2 = solution.removeDuplicates(nums2)
    print(f"Test 2: {nums2}, k = {k2}")
    assert k2 == 5 and nums2[:k2] == [
        0,
        1,
        2,
        3,
        4,
    ], f"Expected k=5, nums=[0,1,2,3,4], got k={k2}, nums={nums2[:k2]}"

    # Test case 3: All elements same
    nums3 = [2, 2, 2, 2, 2]
    k3 = solution.removeDuplicates(nums3)
    print(f"Test 3: {nums3}, k = {k3}")
    assert k3 == 1 and nums3[:k3] == [
        2
    ], f"Expected k=1, nums=[2], got k={k3}, nums={nums3[:k3]}"

    # Test case 4: No duplicates
    nums4 = [1, 2, 3, 4, 5]
    k4 = solution.removeDuplicates(nums4)
    print(f"Test 4: {nums4}, k = {k4}")
    assert k4 == 5 and nums4[:k4] == [
        1,
        2,
        3,
        4,
        5,
    ], f"Expected k=5, nums=[1,2,3,4,5], got k={k4}, nums={nums4[:k4]}"

    print("All test cases passed!")


if __name__ == "__main__":
    test_remove_duplicates_from_sorted_array()
