from typing import List


class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort(key=lambda x: x[0])
        res = True

        for i in range(1, len(intervals)):
            if intervals[i][0] < intervals[i - 1][1]:
                return False

        return res


def run_tests() -> None:
    sol = Solution()
    inputs = [
        [[0, 30], [5, 10], [15, 20]],
        [[7, 10], [2, 4]],
        [[1, 2], [2, 3], [3, 4]],
        [[1, 5], [2, 3], [5, 6]],
        [[1, 2]],
        [[5, 8], [9, 15], [15, 20], [21, 22]],
    ]
    expecteds = [False, True, True, False, True, True]

    for i, case in enumerate(inputs):
        intervals = [item[:] for item in case]
        actual = sol.canAttendMeetings(intervals)
        print(f"{actual} | {expecteds[i]}")


if __name__ == "__main__":
    run_tests()
