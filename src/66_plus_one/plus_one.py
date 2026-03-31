from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        Add one to the integer represented by the digits array.

        Skeleton: no implementation here. Replace `pass` with actual logic.
        """
        n = len(digits)

        for i in range(n - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits

            digits[i] = 0

        digits.insert(0, 1)
        return digits


def run_tests() -> None:
    sol = Solution()
    test_cases = [
        ([1, 2, 3], [1, 2, 4]),
        ([4, 3, 2, 1], [4, 3, 2, 2]),
        ([9], [1, 0]),
        ([9, 9], [1, 0, 0]),
        ([0], [1]),
        ([1, 9, 9], [2, 0, 0]),
    ]

    for inp, expected in test_cases:
        actual = sol.plusOne(list(inp))
        status = "PASS" if actual == expected else "FAIL"
        print(f"{actual} | {expected} | {status}")


if __name__ == "__main__":
    run_tests()
