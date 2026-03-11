from typing import List


class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1

        mask = 0
        value = n
        while value > 0:
            mask = (mask << 1) | 1
            value >>= 1

        return n ^ mask


def run_tests() -> None:
    sol = Solution()
    inputs: List[int] = [5, 7, 10, 0, 1, 8]
    expecteds: List[int] = [2, 0, 5, 1, 0, 7]

    for i, n in enumerate(inputs):
        actual = sol.bitwiseComplement(n)
        print(f"{actual} | {expecteds[i]}")


if __name__ == "__main__":
    run_tests()
