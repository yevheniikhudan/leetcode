class Solution:
    def findFinalValue(self, nums, original):
        nums_set = set(nums)
        
        while original in nums_set:
            original *= 2

        return original

s = Solution()
nums = [5,3,6,1,12]
original = 3
print(s.findFinalValue(nums, original), 24)
nums = [2,7,9]
original = 4
print(s.findFinalValue(nums, original), 4)
