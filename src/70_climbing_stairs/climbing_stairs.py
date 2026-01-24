class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1
        a, b = 1, 1
        for _ in range(2, n + 1):
            a, b = b, a + b
        return b


# Test helper
def test_climb_stairs():
    solution = Solution()

    # Test case 1: n=2
    n1 = 2
    expected1 = 2
    actual1 = solution.climbStairs(n1)
    print(f"{actual1} | {expected1}")

    # Test case 2: n=3
    n2 = 3
    expected2 = 3
    actual2 = solution.climbStairs(n2)
    print(f"{actual2} | {expected2}")

    # Test case 3: n=1
    n3 = 1
    expected3 = 1
    actual3 = solution.climbStairs(n3)
    print(f"{actual3} | {expected3}")

    # Test case 4: n=4
    n4 = 4
    expected4 = 5
    actual4 = solution.climbStairs(n4)
    print(f"{actual4} | {expected4}")

    # Test case 5: n=5
    n5 = 5
    expected5 = 8
    actual5 = solution.climbStairs(n5)
    print(f"{actual5} | {expected5}")


if __name__ == "__main__":
    test_climb_stairs()
