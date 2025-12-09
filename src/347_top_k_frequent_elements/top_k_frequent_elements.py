class Solution:
    def topKFrequent(self, nums, k):
        counters = {}
        buckets = [[] for _ in range(len(nums) + 1)]

        for num in nums:
            counters[num] = 1 + counters.get(num, 0)

        for num, count in counters.items():
            buckets[count].append(num)

        res = []
        for item in buckets[::-1]:
            for num in item:
                res.append(num)

            if len(res) == k:
                return res

        return res


s = Solution()
nums = [1, 1, 1, 2, 2, 3]
k = 2
print(s.topKFrequent(nums, k), [1, 2])
nums = [1]
k = 1
print(s.topKFrequent(nums, k), [1])
