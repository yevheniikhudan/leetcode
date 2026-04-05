# leetcode/src/136_single_number/single_number.py
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        """
        Return the element that appears only once in the array where every other element appears twice.

        Skeleton: no implementation here. Replace `pass` with actual logic.
        """
        ans = 0

        for num in nums:
            ans ^= num

        return ans


def clone_list(lst: List[int]) -> List[int]:
    return lst[:]


def format_result(actual: int, expected: int) -> str:
    status = "PASS" if actual == expected else "FAIL"
    return f"{actual} | {expected} | {status}"


def run_tests() -> None:
    solution = Solution()

    test_cases = [
        ([2, 2, 1], 1),
        ([4, 1, 2, 1, 2], 4),
        ([1], 1),
        ([0, 1, 0], 1),
        ([-1, -1, -2], -2),
        ([17, 12, 5, 12, 5], 17),
    ]

    for nums, expected in test_cases:
        actual = solution.singleNumber(clone_list(nums))
        print(format_result(actual, expected))


if __name__ == "__main__":
    run_tests()
