from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(i: int):
            if i == len(nums):
                res.append(nums[:])
                return

            for j in range(i, len(nums)):
                nums[j], nums[i] = nums[i], nums[j]
                backtrack(i + 1)
                nums[j], nums[i] = nums[i], nums[j]

        backtrack(0)
        return res

    def permuteIterative(self, nums: List[int]) -> List[List[int]]:
        res = [[]]

        for num in nums:
            nextPerms = []

            for p in res:
                for i in range(len(p) + 1):
                    pCopy = p[:]
                    pCopy.insert(i, num)
                    nextPerms.append(pCopy)

            res = nextPerms

        return res


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()
    # Test case 1
    print(
        sorted([sorted(x) for x in sol.permute([1, 2, 3])]),
        "|",
        sorted(
            [
                sorted(x)
                for x in [
                    [1, 2, 3],
                    [1, 3, 2],
                    [2, 1, 3],
                    [2, 3, 1],
                    [3, 1, 2],
                    [3, 2, 1],
                ]
            ]
        ),
    )
    # Test case 2
    print(
        sorted([sorted(x) for x in sol.permute([0, 1])]),
        "|",
        sorted([sorted(x) for x in [[0, 1], [1, 0]]]),
    )
    # Test case 3
    print(
        sorted([sorted(x) for x in sol.permute([1])]),
        "|",
        sorted([sorted(x) for x in [[1]]]),
    )
    # Test case 4
    print(
        sorted([sorted(x) for x in sol.permute([2, 1])]),
        "|",
        sorted([sorted(x) for x in [[2, 1], [1, 2]]]),
    )
    # Test case 5
    print(len(sol.permute([1, 2, 3, 4])), "|", 24)  # 4! = 24
