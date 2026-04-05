class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0

        for _ in range(32):
            res *= 2  # the same as res <<= 1
            res += n % 2  # the same as res |= n & 1
            n //= 2  # the same as n >>= 1

        return res


# ---------- Test Helpers ----------


def check(actual: int, expected: int, label: str = "") -> None:
    ok = actual == expected
    status = "PASS" if ok else "FAIL"
    print(f"{actual} | {expected} | {status}" + (f" ({label})" if label else ""))


# ---------- Tests ----------

if __name__ == "__main__":
    sol = Solution()

    check(sol.reverseBits(43261596), 964176192, "Example 1")
    check(sol.reverseBits(4294967293), 3221225471, "Example 2")
    check(sol.reverseBits(0), 0, "All zeros")
    check(sol.reverseBits(1), 2147483648, "Single bit at position 0")
    check(sol.reverseBits(2147483648), 1, "Single bit at position 31")
    check(sol.reverseBits(4294967295), 4294967295, "All ones")
    check(sol.reverseBits(2), 1073741824, "00000000000000000000000000000010")
