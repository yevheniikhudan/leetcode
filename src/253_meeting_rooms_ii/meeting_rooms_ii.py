import heapq
from typing import List


class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[0])
        h = []

        for interval in intervals:
            if h and h[0] <= interval[0]:
                heapq.heappop(h)
            heapq.heappush(h, interval[1])

        return len(h)


def run_tests() -> None:
    sol = Solution()
    inputs = [
        [[0, 30], [5, 10], [15, 20]],
        [[7, 10], [2, 4]],
        [[1, 5], [2, 3], [3, 6]],
        [[1, 2], [2, 3], [3, 4]],
        [[1, 10], [2, 9], [3, 8], [4, 7]],
        [[5, 8]],
    ]
    expecteds = [2, 1, 2, 1, 4, 1]

    for i, case in enumerate(inputs):
        intervals = [item[:] for item in case]
        actual = sol.minMeetingRooms(intervals)
        print(f"{actual} | {expecteds[i]}")


if __name__ == "__main__":
    run_tests()
