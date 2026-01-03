from typing import List


class NumArray:
    def __init__(self, nums: List[int]):
        self.prefSum = []
        self.prefSum.append(nums[0])

        for i in range(1, len(nums)):
            self.prefSum.append(self.prefSum[i - 1] + nums[i])

    def sumRange(self, left: int, right: int) -> int:
        sum = self.prefSum[right]
        if left > 0:
            sum -= self.prefSum[left - 1]

        return sum


# Test scaffolding
if __name__ == "__main__":
    numArray = NumArray([-2, 0, 3, -5, 2, -1])
    tests = [
        ((0, 2), 1),
        ((2, 5), -1),
        ((0, 5), -3),
        ((3, 3), -5),
        ((1, 1), 0),
    ]
    for (left, right), expected in tests:
        actual = numArray.sumRange(left, right)
        print(f"{actual} | {expected}")
