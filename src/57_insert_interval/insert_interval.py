from typing import List


class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        res = []

        for i in range(len(intervals)):
            if newInterval[1] < intervals[i][0]:
                res.append(newInterval)
                return res + intervals[i:]
            elif newInterval[0] > intervals[i][1]:
                res.append(intervals[i])
            else:
                newInterval = [
                    min(newInterval[0], intervals[i][0]),
                    max(newInterval[1], intervals[i][1]),
                ]
        res.append(newInterval)
        return res


def test_insert():
    sol = Solution()

    # Test case 1
    print(f"{sol.insert([[1,3],[6,9]],[2,5])} | [[1,5],[6,9]]")

    # Test case 2
    print(
        f"{sol.insert([[1,2],[3,5],[6,7],[8,10],[12,16]],[4,8])} | [[1,2],[3,10],[12,16]]"
    )

    # Test case 3
    print(f"{sol.insert([], [5,7])} | [[5,7]]")

    # Test case 4
    print(f"{sol.insert([[1,5]],[2,3])} | [[1,5]]")

    # Test case 5
    print(f"{sol.insert([[1,2],[3,4]],[5,6])} | [[1,2],[3,4],[5,6]]")


if __name__ == "__main__":
    test_insert()
