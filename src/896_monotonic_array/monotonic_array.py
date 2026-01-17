from typing import List


class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        inc = dec = True
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                dec = False
            if nums[i] < nums[i - 1]:
                inc = False
        return inc or dec


def test():
    sol = Solution()
    print(sol.isMonotonic([1, 2, 2, 3]), "| True")
    print(sol.isMonotonic([6, 5, 4, 4]), "| True")
    print(sol.isMonotonic([1, 3, 2]), "| False")
    print(sol.isMonotonic([1, 1, 1]), "| True")
    print(sol.isMonotonic([1]), "| True")
    print(sol.isMonotonic([]), "| True")


if __name__ == "__main__":
    test()
