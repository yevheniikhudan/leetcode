class Solution:
    def largestGoodInteger(self, num: str) -> str:
        maxDigit = "\0"

        for i in range(2, len(num)):
            if num[i - 2] == num[i - 1] == num[i]:
                maxDigit = max(maxDigit, num[i])

        return "" if maxDigit == "\0" else maxDigit * 3


# Test helper
def test_largest_good_integer():
    solution = Solution()

    # Test case 1: Example 1
    num1 = "6777133339"
    expected1 = "777"
    actual1 = solution.largestGoodInteger(num1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    num2 = "2300019"
    expected2 = "000"
    actual2 = solution.largestGoodInteger(num2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Example 3
    num3 = "42352338"
    expected3 = ""
    actual3 = solution.largestGoodInteger(num3)
    print(f"{actual3} | {expected3}")

    # Test case 4: All same
    num4 = "111"
    expected4 = "111"
    actual4 = solution.largestGoodInteger(num4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Multiple, choose largest
    num5 = "999888"
    expected5 = "999"
    actual5 = solution.largestGoodInteger(num5)
    print(f"{actual5} | {expected5}")

    # Test case 6: No good
    num6 = "123456"
    expected6 = ""
    actual6 = solution.largestGoodInteger(num6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_largest_good_integer()
