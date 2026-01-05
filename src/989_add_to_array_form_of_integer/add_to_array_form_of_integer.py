from typing import List


class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        carry = 0
        i = len(num) - 1
        res = []

        while k or carry or i >= 0:
            sum = carry + (k % 10)
            if i >= 0:
                sum += num[i]

            res.append(sum % 10)
            k //= 10
            carry = sum // 10
            i -= 1

        res.reverse()

        return res


# Test scaffolding
if __name__ == "__main__":
    tests = [
        (([1, 2, 0, 0], 34), [1, 2, 3, 4]),
        (([2, 7, 4], 181), [4, 5, 5]),
        (([2, 1, 5], 806), [1, 0, 2, 1]),
        (([0], 23), [2, 3]),
        (([9, 9, 9, 9, 9], 1), [1, 0, 0, 0, 0, 0]),
    ]
    sol = Solution()
    for (num, k), expected in tests:
        actual = sol.addToArrayForm(num, k)
        print(f"{actual} | {expected}")
