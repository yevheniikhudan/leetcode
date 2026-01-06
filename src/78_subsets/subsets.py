from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(first, curr):
            res.append(curr[:])

            for i in range(first, len(nums)):
                curr.append(nums[i])
                backtrack(i + 1, curr)
                curr.pop()

        backtrack(0, [])

        return res


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()

    # Test case 1
    nums1 = [1, 2, 3]
    result1 = sol.subsets(nums1)
    expected1 = [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
    print(
        f"{sorted([sorted(s) for s in result1])} | {sorted([sorted(s) for s in expected1])}"
    )

    # Test case 2
    nums2 = [0]
    result2 = sol.subsets(nums2)
    expected2 = [[], [0]]
    print(
        f"{sorted([sorted(s) for s in result2])} | {sorted([sorted(s) for s in expected2])}"
    )

    # Test case 3
    nums3 = [1]
    result3 = sol.subsets(nums3)
    expected3 = [[], [1]]
    print(
        f"{sorted([sorted(s) for s in result3])} | {sorted([sorted(s) for s in expected3])}"
    )

    # Test case 4
    nums4 = [1, 2]
    result4 = sol.subsets(nums4)
    expected4 = [[], [1], [2], [1, 2]]
    print(
        f"{sorted([sorted(s) for s in result4])} | {sorted([sorted(s) for s in expected4])}"
    )

    # Test case 5
    nums5 = [9, 0, 3, 5, 7]
    result5 = sol.subsets(nums5)
    expected5_len = 2**5  # 32 subsets
    print(f"{len(result5)} | {expected5_len}")
