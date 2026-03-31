# leetcode/src/202_happy_number/happy_number.py
# Skeleton for LeetCode 202. Happy Number
# Follow-up implementations should replace the `pass` in Solution.isHappy
# Test scaffolding prints: actual | expected | PASS/FAIL

from typing import List


class Solution:
    def isHappy(self, n: int) -> bool:
        """
        Determine if a number n is a happy number.

        Uses Floyd's cycle detection (tortoise and hare). Ensure we check
        for the accepting state (1) before deciding that a meeting point
        indicates a non-happy cycle (avoids false negative when both
        pointers reach 1 in the same iteration).
        """
        slow, fast = n, n

        while True:
            slow = self.sumOfSquares(slow)
            fast = self.sumOfSquares(self.sumOfSquares(fast))

            if slow == 1 or fast == 1:
                return True

            if slow == fast:
                return False

    def sumOfSquares(self, n: int) -> int:
        res = 0
        while n > 0:
            num = n % 10
            res += num**2
            n //= 10
        return res


def run_tests() -> None:
    solution = Solution()

    test_cases = [
        (19, True),
        (2, False),
        (1, True),
        (7, True),
        (116, False),
        (100, True),
    ]

    for n, expected in test_cases:
        actual = solution.isHappy(n)
        status = "PASS" if actual == expected else "FAIL"
        print(f"{actual} | {expected} | {status}")


if __name__ == "__main__":
    run_tests()
