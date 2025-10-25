from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        return []

s = Solution()

nums = [2,7,11,15]
target = 9
print(s.twoSum(nums, target), [0,1])

nums = [3,2,4]
target = 6
print(s.twoSum(nums, target), [1,2])

nums = [3,3]
target = 6
print(s.twoSum(nums, target), [0,1])
