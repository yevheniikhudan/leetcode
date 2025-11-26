class Solution:
    """
    Remove Element

    Given an array and a value, remove all instances of that value in-place and return the new length.
    """

    def removeElement(self, nums: list[int], val: int) -> int:
        k = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
            
        return k


def test_remove_element():
    solution = Solution()

    # Test case 1
    nums1 = [3, 2, 2, 3]
    val1 = 3
    k1 = solution.removeElement(nums1, val1)
    print(f"Test 1: {nums1}, val = {val1}, k = {k1}")
    assert k1 == 2 and sorted(nums1[:k1]) == [
        2,
        2,
    ], f"Expected k=2, nums=[2,2], got k={k1}, nums={nums1[:k1]}"

    # Test case 2
    nums2 = [0, 1, 2, 2, 3, 0, 4, 2]
    val2 = 2
    k2 = solution.removeElement(nums2, val2)
    print(f"Test 2: {nums2}, val = {val2}, k = {k2}")
    assert k2 == 5 and sorted(nums2[:k2]) == [
        0,
        0,
        1,
        3,
        4,
    ], f"Expected k=5, nums=[0,0,1,3,4], got k={k2}, nums={nums2[:k2]}"

    # Test case 3: All elements are val
    nums3 = [2, 2, 2, 2, 2]
    val3 = 2
    k3 = solution.removeElement(nums3, val3)
    print(f"Test 3: {nums3}, val = {val3}, k = {k3}")
    assert k3 == 0, f"Expected k=0, got k={k3}"

    # Test case 4: No elements are val
    nums4 = [1, 2, 3, 4, 5]
    val4 = 6
    k4 = solution.removeElement(nums4, val4)
    print(f"Test 4: {nums4}, val = {val4}, k = {k4}")
    assert k4 == 5 and sorted(nums4[:k4]) == [
        1,
        2,
        3,
        4,
        5,
    ], f"Expected k=5, nums=[1,2,3,4,5], got k={k4}, nums={nums4[:k4]}"

    print("All test cases passed!")


if __name__ == "__main__":
    test_remove_element()
