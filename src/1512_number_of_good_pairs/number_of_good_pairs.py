from typing import List
from collections import defaultdict


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        count = defaultdict(int)
        res = 0
        for num in nums:
            res += count[num]
            count[num] += 1
        return res


def test():
    sol = Solution()
    print(sol.numIdenticalPairs([1, 2, 3, 1, 1, 3]), "| 4")
    print(sol.numIdenticalPairs([1, 1, 1, 1]), "| 6")
    print(sol.numIdenticalPairs([1, 2, 3]), "| 0")
    print(sol.numIdenticalPairs([]), "| 0")
    print(sol.numIdenticalPairs([2, 2, 2, 2, 2]), "| 10")


if __name__ == "__main__":
    test()
