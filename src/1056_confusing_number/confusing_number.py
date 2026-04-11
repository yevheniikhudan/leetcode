"""
LeetCode Problem 1056: Confusing Number
https://leetcode.com/problems/confusing-number/
"""


class Solution:
    def confusingNumber(self, n: int) -> bool:
        """
        Determine if the given number is a confusing number.

        A confusing number becomes a different number when rotated 180 degrees.
        Valid rotations: 0→0, 1→1, 6→9, 8→8, 9→6

        Args:
            n: Integer to check (0 <= n <= 10^9)

        Returns:
            True if n is a confusing number, False otherwise
        """
        invertMap = {0: 0, 1: 1, 8: 8, 6: 9, 9: 6}
        invertNumber = 0
        nCopy = n

        while nCopy:
            temp = nCopy % 10
            if temp not in invertMap:
                return False

            invertNumber = invertNumber * 10 + invertMap[temp]
            nCopy //= 10

        return invertNumber != n


# ============================================================================
# Test Cases
# ============================================================================


def test_confusing_number():
    """Run all test cases"""
    solution = Solution()

    # Test Case 1: Single digit confusing (6 -> 9)
    n1 = 6
    result1 = solution.confusingNumber(n1)
    expected1 = True
    print(f"{result1} | {expected1} | {'PASS' if result1 == expected1 else 'FAIL'}")

    # Test Case 2: Multi-digit confusing (89 -> 68)
    n2 = 89
    result2 = solution.confusingNumber(n2)
    expected2 = True
    print(f"{result2} | {expected2} | {'PASS' if result2 == expected2 else 'FAIL'}")

    # Test Case 3: Palindromic rotation (11 -> 11)
    n3 = 11
    result3 = solution.confusingNumber(n3)
    expected3 = False
    print(f"{result3} | {expected3} | {'PASS' if result3 == expected3 else 'FAIL'}")

    # Test Case 4: Contains invalid digit (25)
    n4 = 25
    result4 = solution.confusingNumber(n4)
    expected4 = False
    print(f"{result4} | {expected4} | {'PASS' if result4 == expected4 else 'FAIL'}")

    # Test Case 5: Zero (0 -> 0, not confusing)
    n5 = 0
    result5 = solution.confusingNumber(n5)
    expected5 = False
    print(f"{result5} | {expected5} | {'PASS' if result5 == expected5 else 'FAIL'}")

    # Test Case 6: Confusing with valid digits (96 -> 96, not confusing)
    n6 = 96
    result6 = solution.confusingNumber(n6)
    expected6 = False
    print(f"{result6} | {expected6} | {'PASS' if result6 == expected6 else 'FAIL'}")


if __name__ == "__main__":
    test_confusing_number()
