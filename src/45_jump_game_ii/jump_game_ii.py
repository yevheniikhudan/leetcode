from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps, end, farthest = 0, 0, 0
        for i in range(len(nums) - 1):
            farthest = max(farthest, i + nums[i])
            if i == end:
                jumps += 1
                end = farthest

        return jumps


def test_jump():
    sol = Solution()
    print(f"{sol.jump([2,3,1,1,4])} | 2")
    print(f"{sol.jump([2,3,0,1,4])} | 2")
    print(f"{sol.jump([0])} | 0")
    print(f"{sol.jump([1,2])} | 1")
    print(f"{sol.jump([2,3,1,1,4,0,0])} | 2")


if __name__ == "__main__":
    test_jump()
