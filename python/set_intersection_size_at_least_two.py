class Solution:
    def intersectionSizeTwo(self, intervals):
        intervals.sort(key=lambda i : (i[1], -i[0]))
        p1, p2 = -1, -1
        res = 0
        
        for left, right in intervals:
            if p2 < left:
                res += 2
                p1, p2 = right - 1, right
            elif p1 < left:
                res += 1
                p1, p2 = p2, right
        
        return res


s = Solution()
intervals = [[1, 3], [3, 7], [8, 9]]
print(s.intersectionSizeTwo(intervals), 5)
intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
print(s.intersectionSizeTwo(intervals), 3)
intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
print(s.intersectionSizeTwo(intervals), 5)
