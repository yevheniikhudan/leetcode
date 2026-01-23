class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        result = 0
        x = abs(x)
        while x:
            result *= 10
            result += x % 10
            x //= 10
            if result > 2**31 - 1:
                return 0
        return sign * result


# Test helper
def test_reverse():
    solution = Solution()

    # Test case 1: Example 1
    x1 = 123
    expected1 = 321
    actual1 = solution.reverse(x1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    x2 = -123
    expected2 = -321
    actual2 = solution.reverse(x2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Example 3
    x3 = 120
    expected3 = 21
    actual3 = solution.reverse(x3)
    print(f"{actual3} | {expected3}")

    # Test case 4: x=0
    x4 = 0
    expected4 = 0
    actual4 = solution.reverse(x4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Positive overflow
    x5 = 1534236469
    expected5 = 0
    actual5 = solution.reverse(x5)
    print(f"{actual5} | {expected5}")

    # Test case 6: Negative overflow
    x6 = -1534236469
    expected6 = 0
    actual6 = solution.reverse(x6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_reverse()
