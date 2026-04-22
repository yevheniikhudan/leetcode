from typing import Counter


class Solution:
    def largestUniqueNumber(self, nums: list[int]) -> int:
        counts = Counter(nums)

        uniqueNums = [num for num, freq in counts.items() if freq == 1]
        return max(uniqueNums) if uniqueNums else -1


# Test cases
def test_solution():
    solution = Solution()

    # Test case 1
    nums1 = [5, 7, 3, 9, 4, 9, 8, 3, 1]
    result1 = solution.largestUniqueNumber(nums1)
    expected1 = 8
    print(f"{result1} | {expected1} | {'PASS' if result1 == expected1 else 'FAIL'}")

    # Test case 2
    nums2 = [9, 9, 8, 8]
    result2 = solution.largestUniqueNumber(nums2)
    expected2 = -1
    print(f"{result2} | {expected2} | {'PASS' if result2 == expected2 else 'FAIL'}")

    # Test case 3
    nums3 = [1, 1, 1, 1, 2, 2, 2, 3]
    result3 = solution.largestUniqueNumber(nums3)
    expected3 = 3
    print(f"{result3} | {expected3} | {'PASS' if result3 == expected3 else 'FAIL'}")

    # Test case 4
    nums4 = [5]
    result4 = solution.largestUniqueNumber(nums4)
    expected4 = 5
    print(f"{result4} | {expected4} | {'PASS' if result4 == expected4 else 'FAIL'}")

    # Test case 5
    nums5 = [0, 1, 0, 2, 3, 3]
    result5 = solution.largestUniqueNumber(nums5)
    expected5 = 2
    print(f"{result5} | {expected5} | {'PASS' if result5 == expected5 else 'FAIL'}")


if __name__ == "__main__":
    test_solution()
