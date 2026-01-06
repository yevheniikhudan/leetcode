from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        n = len(candidates)

        def backtrack(i: int, cur: List[int], total):
            if total == target:
                res.append(cur[:])
                return

            for j in range(i, n):
                candidate = candidates[j]

                if j > i and candidates[j] == candidates[j - 1]:
                    continue
                if candidate + total > target:
                    return

                cur.append(candidate)
                backtrack(j + 1, cur, candidate + total)
                cur.pop()

        backtrack(0, [], 0)

        return res


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()
    # Test case 1
    print(
        sorted([sorted(x) for x in sol.combinationSum2([10, 1, 2, 7, 6, 1, 5], 8)]),
        "|",
        sorted([sorted(x) for x in [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]]),
    )
    # Test case 2
    print(
        sorted([sorted(x) for x in sol.combinationSum2([2, 5, 2, 1, 2], 5)]),
        "|",
        sorted([sorted(x) for x in [[1, 2, 2], [5]]]),
    )
    # Test case 3
    print(
        sorted([sorted(x) for x in sol.combinationSum2([2], 1)]),
        "|",
        sorted([sorted(x) for x in []]),
    )
    # Test case 4
    print(
        sorted([sorted(x) for x in sol.combinationSum2([1], 1)]),
        "|",
        sorted([sorted(x) for x in [[1]]]),
    )
    # Test case 5
    print(
        sorted([sorted(x) for x in sol.combinationSum2([1], 2)]),
        "|",
        sorted([sorted(x) for x in []]),
    )
