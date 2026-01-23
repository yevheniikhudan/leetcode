class Solution:
    def totalMoney(self, n: int) -> int:
        k = n // 7
        f = 28
        l = f + (k - 1) * 7
        arithmeticSum = k * (f + l) / 2
        monday = 1 + k
        finalWeek = 0
        for day in range(0, n % 7):
            finalWeek += monday + day

        return int(arithmeticSum + finalWeek)


# Test helper
def test_total_money():
    solution = Solution()

    # Test case 1: Example 1
    n1 = 4
    expected1 = 10
    actual1 = solution.totalMoney(n1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    n2 = 10
    expected2 = 37
    actual2 = solution.totalMoney(n2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Example 3
    n3 = 20
    expected3 = 96
    actual3 = solution.totalMoney(n3)
    print(f"{actual3} | {expected3}")

    # Test case 4: n=1
    n4 = 1
    expected4 = 1
    actual4 = solution.totalMoney(n4)
    print(f"{actual4} | {expected4}")

    # Test case 5: n=7
    n5 = 7
    expected5 = 28
    actual5 = solution.totalMoney(n5)
    print(f"{actual5} | {expected5}")

    # Test case 6: n=8
    n6 = 8
    expected6 = 30
    actual6 = solution.totalMoney(n6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_total_money()
