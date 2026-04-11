"""
LeetCode Problem 422: Valid Word Square
https://leetcode.com/problems/valid-word-square/
"""


class Solution:
    def validWordSquare(self, words: list[str]) -> bool:
        """
        Determine if the given array of strings forms a valid word square.

        A valid word square means that the k-th row and k-th column
        read the same string for all k.

        Args:
            words: List of strings to check

        Returns:
            True if valid word square, False otherwise
        """
        n = len(words)

        for row in range(n):
            for col in range(len(words[row])):
                if (
                    col >= n
                    or row >= len(words[col])
                    or words[row][col] != words[col][row]
                ):
                    return False

        return True


# ============================================================================
# Test Cases
# ============================================================================


def test_valid_word_square():
    """Run all test cases"""
    solution = Solution()

    # Test Case 1: Valid square with equal length words
    words1 = ["abcd", "bnrt", "crmy", "dtye"]
    result1 = solution.validWordSquare(words1)
    expected1 = True
    print(f"{result1} | {expected1} | {'PASS' if result1 == expected1 else 'FAIL'}")

    # Test Case 2: Valid square with unequal length words
    words2 = ["abcd", "bnrt", "crm", "dt"]
    result2 = solution.validWordSquare(words2)
    expected2 = True
    print(f"{result2} | {expected2} | {'PASS' if result2 == expected2 else 'FAIL'}")

    # Test Case 3: Invalid square - mismatch in row/column
    words3 = ["ball", "area", "read", "lady"]
    result3 = solution.validWordSquare(words3)
    expected3 = False
    print(f"{result3} | {expected3} | {'PASS' if result3 == expected3 else 'FAIL'}")

    # Test Case 4: Single word (always valid)
    words4 = ["a"]
    result4 = solution.validWordSquare(words4)
    expected4 = True
    print(f"{result4} | {expected4} | {'PASS' if result4 == expected4 else 'FAIL'}")

    # Test Case 5: Two identical words
    words5 = ["ab", "ba"]
    result5 = solution.validWordSquare(words5)
    expected5 = True
    print(f"{result5} | {expected5} | {'PASS' if result5 == expected5 else 'FAIL'}")

    # Test Case 6: Invalid - different characters at symmetric positions
    words6 = ["abc", "bda", "cec"]
    result6 = solution.validWordSquare(words6)
    expected6 = False
    print(f"{result6} | {expected6} | {'PASS' if result6 == expected6 else 'FAIL'}")

    # Test Case 7: Invalid - different characters at symmetric positions
    words7 = ["ball", "asee", "let", "lep"]
    result7 = solution.validWordSquare(words7)
    expected7 = False
    print(f"{result7} | {expected7} | {'PASS' if result7 == expected7 else 'FAIL'}")


if __name__ == "__main__":
    test_valid_word_square()
