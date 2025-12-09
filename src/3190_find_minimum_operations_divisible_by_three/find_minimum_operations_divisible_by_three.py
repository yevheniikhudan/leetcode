class Solution:
    def minimumOperations(self, nums):
        return sum(num % 3 != 0 for num in nums)


s = Solution()
nums = [1, 2, 3, 4]
print(s.minimumOperations(nums), 3)
nums = [3, 6, 9]
print(s.minimumOperations(nums), 0)
