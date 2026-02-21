from typing import List


class Solution:
    def checkValidString(self, s: str) -> bool:
        low, high = 0, 0

        for ch in s:
            if ch == "(":
                low += 1
                high += 1
            elif ch == ")":
                low = max(0, low - 1)
                high -= 1
            else:
                low = max(0, low - 1)
                high += 1

            if high < 0:
                return False

        return low == 0


def test_checkValidString():
    sol = Solution()

    # Test case 1: Example 1
    print(f"{sol.checkValidString('()')} | True")

    # Test case 2: Example 2
    print(f"{sol.checkValidString('(*)')} | True")

    # Test case 3: Example 3
    print(f"{sol.checkValidString('(*))')} | True")

    # Test case 4: Only stars
    print(f"{sol.checkValidString('***')} | True")

    # Test case 5: Invalid
    print(f"{sol.checkValidString(')((')} | False")


if __name__ == "__main__":
    test_checkValidString()
