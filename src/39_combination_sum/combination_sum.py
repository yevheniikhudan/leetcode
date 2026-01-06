from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def backtrack(i, cur, total):
            if total == target:
                res.append(cur.copy())

            for j in range(i, len(candidates)):
                if total + candidates[j] > target:
                    return
                cur.append(candidates[j])
                backtrack(j, cur, total + candidates[j])
                cur.pop()

        backtrack(0, [], 0)

        return res

    def combinationSumDPTabulation(
        self, candidates: List[int], target: int
    ) -> List[List[int]]:
        tab = [set() for _ in range(target + 1)]
        tab[0].add(())
        candidates = sorted(candidates)
        for i in range(target + 1):
            for cand in candidates:
                for comb in tab[i]:
                    if cand + i <= target and (not comb or cand >= comb[-1]):
                        tab[cand + i].add(comb + (cand,))
        return [list(t) for t in tab[target]]


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()
    # Test case 1
    print(
        sorted([sorted(x) for x in sol.combinationSum([2, 3, 6, 7], 7)]),
        "|",
        sorted([sorted(x) for x in [[2, 2, 3], [7]]]),
    )
    # Test case 2
    print(
        sorted([sorted(x) for x in sol.combinationSum([2, 3, 5], 8)]),
        "|",
        sorted([sorted(x) for x in [[2, 2, 2, 2], [2, 3, 3], [3, 5]]]),
    )
    # Test case 3
    print(
        sorted([sorted(x) for x in sol.combinationSum([2], 1)]),
        "|",
        sorted([sorted(x) for x in []]),
    )
    # Test case 4
    print(
        sorted([sorted(x) for x in sol.combinationSum([1], 1)]),
        "|",
        sorted([sorted(x) for x in [[1]]]),
    )
    # Test case 5
    print(
        sorted([sorted(x) for x in sol.combinationSum([1], 2)]),
        "|",
        sorted([sorted(x) for x in [[1, 1]]]),
    )
