class Solution:
    def containsDuplicate(self, nums):
        seen = set()

        for num in nums:
            if num in seen:
                return True

            seen.add(num)

        return False


s = Solution()
nums = [1, 2, 3, 1]
print(s.containsDuplicate(nums), True)
nums = [1, 2, 3, 4]
print(s.containsDuplicate(nums), False)
nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
print(s.containsDuplicate(nums), True)
