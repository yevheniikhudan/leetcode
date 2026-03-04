from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        res = 0
        last = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] < last:
                res += 1
            else:
                last = intervals[i][1]

        return res


# Helper test scaffolding
def run_tests() -> None:
    cases = [
        ([[1, 2], [2, 3], [3, 4], [1, 3]], 1),
        ([[1, 2], [1, 2], [1, 2]], 2),
        ([[1, 2], [2, 3]], 0),
        ([[1, 100], [11, 22], [1, 11], [2, 12]], 2),
        ([[1, 2]], 0),
    ]

    sol = Solution()
    for intervals, expected in cases:
        actual = sol.eraseOverlapIntervals(intervals)
        print(f"{actual} | {expected}")


if __name__ == "__main__":
    run_tests()
