import heapq
from typing import List


class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        # define interval size helper function
        # use heap to find the minimum interval
        intervals.sort(key=lambda x: x[0])

        res = {}
        i = 0
        heap = []
        for query in sorted(queries):
            while i < len(intervals) and intervals[i][0] <= query:
                heapq.heappush(heap, [self.intervalSize(intervals[i]), intervals[i][1]])
                i += 1

            while heap and heap[0][1] < query:
                heapq.heappop(heap)

            res[query] = heap[0][0] if heap else -1

        return [res[q] for q in queries]

    def intervalSize(self, interval):
        return interval[1] - interval[0] + 1


def copy_2d(values: List[List[int]]) -> List[List[int]]:
    return [row[:] for row in values]


def run_tests() -> None:
    sol = Solution()
    interval_inputs = [
        [[1, 4], [2, 4], [3, 6], [4, 4]],
        [[2, 3], [2, 5], [1, 8], [20, 25]],
        [[1, 2]],
        [[5, 10], [1, 3]],
        [[1, 1], [2, 2], [3, 3]],
        [[1, 10_000_000]],
    ]
    query_inputs = [
        [2, 3, 4, 5],
        [2, 19, 5, 22],
        [1, 2, 3],
        [4, 5, 6],
        [1, 2, 3],
        [1, 5_000_000, 10_000_000],
    ]
    expecteds = [
        [3, 3, 1, 4],
        [2, -1, 4, 6],
        [2, 2, -1],
        [-1, 6, 6],
        [1, 1, 1],
        [10_000_000, 10_000_000, 10_000_000],
    ]

    for i in range(len(interval_inputs)):
        actual = sol.minInterval(copy_2d(interval_inputs[i]), query_inputs[i][:])
        print(f"{actual} | {expecteds[i]}")


if __name__ == "__main__":
    run_tests()
