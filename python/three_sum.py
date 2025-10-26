from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = set()
        nums.sort()

        for i in range(n - 2):
            num_i = nums[i]

            if i > 0 and num_i == nums[i - 1]:
                continue

            seen = set()
            for j in range(i + 1, n):
                num_j = nums[j]
                target = -(num_i + num_j)
                if target in seen:
                    ans.add((num_i, num_j, target))

                seen.add(num_j)

        return [list(triplet) for triplet in ans]


s = Solution()

nums = [-1, 0, 1, 2, -1, -4]
print(s.threeSum(nums), [[-1, -1, 2], [-1, 0, 1]])

nums = [0, 1, 1]
print(s.threeSum(nums), [])

nums = [0, 0, 0]
print(s.threeSum(nums), [[0, 0, 0]])
