import heapq
from typing import List


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = [-x for x in stones]
        heapq.heapify(heap)
        while len(heap) > 1:
            y = -heapq.heappop(heap)
            x = -heapq.heappop(heap)
            if y != x:
                heapq.heappush(heap, -(y - x))
        return -heap[0] if heap else 0


# Helper functions for testing
def run_tests():
    sol = Solution()
    print(sol.lastStoneWeight([2, 7, 4, 1, 8, 1]))  # 1
    print(sol.lastStoneWeight([1]))  # 1
    print(sol.lastStoneWeight([3, 3, 3, 3]))  # 0
    print(sol.lastStoneWeight([10, 4, 2, 10]))  # 2
    print(sol.lastStoneWeight([5, 5, 5, 1]))  # 2


if __name__ == "__main__":
    run_tests()
