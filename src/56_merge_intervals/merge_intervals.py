from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])

        res = []

        for interval in intervals:
            if not res or interval[0] > res[-1][1]:
                res.append(interval)
            else:
                res[-1][1] = max(res[-1][1], interval[1])

        return res


# Helper test scaffolding
def run_tests() -> None:
    cases = [
        ([[1, 3], [2, 6], [8, 10], [15, 18]], [[1, 6], [8, 10], [15, 18]]),
        ([[1, 4], [4, 5]], [[1, 5]]),
        ([[4, 7], [1, 4]], [[1, 7]]),
        ([[1, 3]], [[1, 3]]),
        ([[1, 2], [3, 4], [5, 6]], [[1, 2], [3, 4], [5, 6]]),
        ([[1, 10], [2, 3], [4, 5], [6, 7]], [[1, 10]]),
        # Adding a basic test case to the test scaffolding
        (
            [[1, 3], [2, 6], [8, 10], [15, 18]],
            [[1, 6], [8, 10], [15, 18]],
        ),  # Basic test case
    ]

    sol = Solution()
    for intervals, expected in cases:
        actual = sol.merge(intervals)
        print(f"{actual} | {expected}")


if __name__ == "__main__":
    run_tests()
