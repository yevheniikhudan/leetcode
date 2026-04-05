from typing import List


class Solution:
    def hammingWeight(self, n: int) -> int:
        """
        Return the number of '1' bits in the 32-bit representation of n.

        Skeleton: no implementation here. Replace `pass` with actual logic.
        """
        res = 0

        while n:
            n &= n - 1
            res += 1

        return res


def format_result(actual: int, expected: int) -> str:
    status = "PASS" if actual == expected else "FAIL"
    return f"{actual} | {expected} | {status}"


def run_tests() -> None:
    sol = Solution()

    # Test cases: (input, expected)
    test_cases = [
        (0b00000000000000000000000000001011, 3),  # 11 -> 3 ones
        (0b00000000000000000000000010000000, 1),  # 128 -> 1 one
        (0b00000000000000000000000000000000, 0),  # 0 -> 0
        (0b11111111111111111111111111111111, 32),  # all ones -> 32
        # For negative numbers, interpret as 32-bit two's complement:
        # e.g., -3 -> 0xFFFFFFFD -> 31 ones
        (-3, 31),
        # random examples
        (0b10101010101010101010101010101010, 16),
    ]

    for n, expected in test_cases:
        actual = sol.hammingWeight(n)
        print(format_result(actual, expected))


if __name__ == "__main__":
    run_tests()
