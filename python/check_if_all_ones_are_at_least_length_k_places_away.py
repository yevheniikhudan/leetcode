class Solution:
    def kLengthApart(self, nums, k):
        previousId = -1

        for i in range(len(nums)):
            if nums[i] == 1:
                if previousId != -1 and i - previousId - 1 < k:
                    return False
                previousId = i

        return True

s = Solution()
nums = [1, 0, 0, 0, 1, 0, 0, 1]
k = 2
print(s.kLengthApart(nums, k), True)
nums = [1, 0, 0, 1, 0, 1]
k = 2
print(s.kLengthApart(nums, k), False)
