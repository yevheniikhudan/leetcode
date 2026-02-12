from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        res, cur, total = 0, 0, 0

        for i in range(len(gas)):
            diff = gas[i] - cost[i]

            total += diff
            cur += diff
            if cur < 0:
                res = i + 1
                cur = 0

        return -1 if total < 0 else res


def test_canCompleteCircuit():
    sol = Solution()
    print(f"{sol.canCompleteCircuit([1,2,3,4,5], [3,4,5,1,2])} | 3")
    print(f"{sol.canCompleteCircuit([2,3,4], [3,4,3])} | -1")
    print(f"{sol.canCompleteCircuit([5], [4])} | 0")
    print(f"{sol.canCompleteCircuit([0,0], [0,0])} | 0")
    print(f"{sol.canCompleteCircuit([1,2,3,4], [2,2,2,2])} | 1")


if __name__ == "__main__":
    test_canCompleteCircuit()
