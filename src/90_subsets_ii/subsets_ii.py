from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def backtrack(start, path):
            res.append(path[:])
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i - 1]:
                    continue
                path.append(nums[i])
                backtrack(i + 1, path)
                path.pop()

        backtrack(0, [])
        return res


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()
    print(
        sorted([sorted(x) for x in sol.subsetsWithDup([1, 2, 2])]),
        "|",
        sorted([sorted(x) for x in [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]]),
    )
    print(
        sorted([sorted(x) for x in sol.subsetsWithDup([0])]),
        "|",
        sorted([sorted(x) for x in [[], [0]]]),
    )
    print(sorted([sorted(x) for x in sol.subsetsWithDup([4, 4, 4, 1, 4])]))
