class Solution:
    def numberOfMatches(self, n: int) -> int:
        return n - 1


# Test helper
def test_number_of_matches():
    solution = Solution()

    # Test case 1: Example 1
    n1 = 7
    expected1 = 6
    actual1 = solution.numberOfMatches(n1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    n2 = 14
    expected2 = 13
    actual2 = solution.numberOfMatches(n2)
    print(f"{actual2} | {expected2}")

    # Test case 3: n=1
    n3 = 1
    expected3 = 0
    actual3 = solution.numberOfMatches(n3)
    print(f"{actual3} | {expected3}")

    # Test case 4: n=2
    n4 = 2
    expected4 = 1
    actual4 = solution.numberOfMatches(n4)
    print(f"{actual4} | {expected4}")

    # Test case 5: n=3
    n5 = 3
    expected5 = 2
    actual5 = solution.numberOfMatches(n5)
    print(f"{actual5} | {expected5}")

    # Test case 6: n=4
    n6 = 4
    expected6 = 3
    actual6 = solution.numberOfMatches(n6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_number_of_matches()
