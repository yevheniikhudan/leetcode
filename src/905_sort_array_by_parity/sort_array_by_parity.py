from typing import List


class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        insertIndex = 0

        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                nums[insertIndex], nums[i] = nums[i], nums[insertIndex]
                insertIndex += 1

        return nums


def test():
    sol = Solution()
    print(sol.sortArrayByParity([3, 1, 2, 4]), "| [2, 4, 3, 1]")
    print(sol.sortArrayByParity([0]), "| [0]")
    print(sol.sortArrayByParity([1, 2, 3, 4, 5, 6]), "| [2, 4, 6, 1, 3, 5]")
    print(sol.sortArrayByParity([2, 4, 6, 8]), "| [2, 4, 6, 8]")
    print(sol.sortArrayByParity([1, 3, 5, 7]), "| [1, 3, 5, 7]")


if __name__ == "__main__":
    test()
