class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF
        max_int = 2**31

        while b != 0:
            carry = (a & b) << 1
            a = (a ^ b) & mask
            b = carry & mask

        return a if a <= max_int else ~(a ^ mask)


# ---------- Test Helpers ----------


def check(actual: int, expected: int, label: str = "") -> None:
    ok = actual == expected
    status = "PASS" if ok else "FAIL"
    print(f"{actual} | {expected} | {status}" + (f" ({label})" if label else ""))


# ---------- Tests ----------

if __name__ == "__main__":
    sol = Solution()

    check(sol.getSum(1, 2), 3, "Example 1")
    check(sol.getSum(2, 3), 5, "Example 2")
    check(sol.getSum(-1, 1), 0, "Example 3 (negative)")
    check(sol.getSum(0, 0), 0, "Both zero")
    check(sol.getSum(5, -3), 2, "Mixed signs")
    check(sol.getSum(-5, -3), -8, "Both negative")
    check(sol.getSum(1000, -1000), 0, "Large values cancel")
