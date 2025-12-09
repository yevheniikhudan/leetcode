class Solution:
    def prefixesDivBy5(self, nums):
        ans = []
        cur = 0

        for num in nums:
            cur = (cur * 2 + num) % 5
            ans.append(cur % 5 == 0)

        return ans

s = Solution()
nums = [0, 1, 1]
print(s.prefixesDivBy5(nums), [True, False, False])
nums = [1, 1, 1]
print(s.prefixesDivBy5(nums), [False, False, False])
