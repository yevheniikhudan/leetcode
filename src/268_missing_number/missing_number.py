from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0

        for i in range(0, len(nums)):
            res ^= i + 1
            res ^= nums[i]

        return res


# ---------- Test Helpers ----------


def check(actual: int, expected: int, label: str = "") -> None:
    ok = actual == expected
    status = "PASS" if ok else "FAIL"
    print(f"{actual} | {expected} | {status}" + (f" ({label})" if label else ""))


# ---------- Tests ----------

if __name__ == "__main__":
    sol = Solution()

    check(sol.missingNumber([3, 0, 1]), 2, "Example 1")
    check(sol.missingNumber([0, 1]), 2, "Example 2")
    check(sol.missingNumber([9, 6, 4, 2, 3, 5, 7, 0, 1]), 8, "Example 3")
    check(sol.missingNumber([0]), 1, "Missing last element")
    check(sol.missingNumber([1]), 0, "Missing first element")
    check(sol.missingNumber([2, 0, 1]), 3, "Missing at end")
    check(sol.missingNumber([0, 1, 2, 3, 4, 5, 6, 7, 8]), 9, "Large range")
