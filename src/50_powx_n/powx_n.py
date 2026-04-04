from typing import Optional


class Solution:
    def myPow(self, x: float, n: int) -> float:
        def helper(x, n):
            if x == 0:
                return 0
            if n == 0:
                return 1

            res = helper(x * x, n // 2)
            return x * res if n % 2 else res

        res = helper(x, abs(n))
        return res if n >= 0 else 1 / res


# ---------- Test Helpers ----------


def check(actual: float, expected: float, label: str = "", tol: float = 1e-5) -> None:
    ok = abs(actual - expected) <= tol
    status = "PASS" if ok else "FAIL"
    print(
        f"{actual:.5f} | {expected:.5f} | {status}" + (f" ({label})" if label else "")
    )


# ---------- Tests ----------

if __name__ == "__main__":
    sol = Solution()

    check(sol.myPow(2.00000, 10), 1024.00000, "2^10")
    check(sol.myPow(2.10000, 3), 9.26100, "2.1^3")
    check(sol.myPow(2.00000, -2), 0.25000, "2^-2")
    check(sol.myPow(1.00000, 2147483647), 1.00000, "1^INT_MAX")
    check(sol.myPow(2.00000, 0), 1.00000, "2^0")
    check(sol.myPow(-2.00000, 3), -8.00000, "-2^3")
    check(sol.myPow(0.00001, 2147483647), 0.00000, "tiny base, large n")
