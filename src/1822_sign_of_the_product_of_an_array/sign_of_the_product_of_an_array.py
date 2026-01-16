from typing import List


class Solution:
    def arraySign(self, nums: List[int]) -> int:
        product = 1

        for num in nums:
            if num == 0:
                return 0

            if num > 0:
                product *= 1
            else:
                product *= -1

        return product


# Test scaffolding
if __name__ == "__main__":
    print(Solution().arraySign([-1, -2, -3, -4, 3, 2, 1]))  # 1
    print(Solution().arraySign([1, 5, 0, 2, -3]))  # 0
    print(Solution().arraySign([-1, 1, -1, 1, -1]))  # -1
    print(Solution().arraySign([1, 2, 3, 4, 5]))  # 1
    print(Solution().arraySign([-1]))  # -1
