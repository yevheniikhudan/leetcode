from collections import Counter, deque
import heapq
from typing import List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counters = Counter(tasks)
        maxHeap = [-cnt for cnt in counters.values()]
        heapq.heapify(maxHeap)
        q = deque()
        time = 0

        while maxHeap or q:
            time += 1
            if not maxHeap:
                time = q[0][1]
            else:
                cnt = -heapq.heappop(maxHeap) - 1
                if cnt:
                    q.append([cnt, time + n])

            if q and q[0][1] <= time:
                heapq.heappush(maxHeap, -q.popleft()[0])

        return time


# Test scaffolding
if __name__ == "__main__":
    tests = [
        ((["A", "A", "A", "B", "B", "B"], 2), 8),
        ((["A", "A", "A", "B", "B", "B"], 0), 6),
        ((["A", "A", "A", "A", "A", "A", "B", "C", "D", "E", "F", "G"], 2), 16),
        ((["A"], 100), 1),
        ((["A", "B", "C", "D"], 2), 4),
    ]
    sol = Solution()
    for (tasks, n), expected in tests:
        actual = sol.leastInterval(tasks, n)
        print(f"{actual} | {expected}")
