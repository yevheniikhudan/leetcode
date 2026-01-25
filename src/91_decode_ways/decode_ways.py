class Solution:
    def numDecodings(self, s: str) -> int:
        dpI, dpIMinus1, dpIMinus2 = 1, 1, 1

        for i in range(1, len(s) + 1):
            dpI = 0 if s[i - 1] == "0" else dpIMinus1

            if i >= 2 and 10 <= int(s[i - 2 : i]) <= 26:
                dpI += dpIMinus2

            dpIMinus2, dpIMinus1 = dpIMinus1, dpI

        return dpI


# Test helper
def test_num_decodings():
    solution = Solution()

    # Test case 1: Example 1
    s1 = "12"
    expected1 = 2
    actual1 = solution.numDecodings(s1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    s2 = "226"
    expected2 = 3
    actual2 = solution.numDecodings(s2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Example 3
    s3 = "06"
    expected3 = 0
    actual3 = solution.numDecodings(s3)
    print(f"{actual3} | {expected3}")

    # Test case 4: Single digit
    s4 = "1"
    expected4 = 1
    actual4 = solution.numDecodings(s4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Leading zero
    s5 = "10"
    expected5 = 1
    actual5 = solution.numDecodings(s5)
    print(f"{actual5} | {expected5}")

    # Test case 6: Invalid
    s6 = "00"
    expected6 = 0
    actual6 = solution.numDecodings(s6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_num_decodings()
