class Solution:
    def scoreOfAString(self, s: str) -> int:
        """
        Calculate the score of a string as the sum of absolute differences
        of ASCII values of consecutive characters.

        Args:
            s: A string of lowercase English letters

        Returns:
            The score of the string
        """
        codes = [ord(_) for _ in s]
        res = 0

        for i in range(1, len(codes)):
            res += abs(codes[i] - codes[i - 1])

        return res


def run_tests():
    """Run test cases for scoreOfAString."""
    solution = Solution()

    # Test case 1: Basic example with "hello"
    s1 = "hello"
    result1 = solution.scoreOfAString(s1)
    expected1 = 13
    status1 = "PASS" if result1 == expected1 else "FAIL"
    print(f"{result1} | {expected1} | {status1}")

    # Test case 2: All identical characters
    s2 = "aaaa"
    result2 = solution.scoreOfAString(s2)
    expected2 = 0
    status2 = "PASS" if result2 == expected2 else "FAIL"
    print(f"{result2} | {expected2} | {status2}")

    # Test case 3: Two different characters
    s3 = "ab"
    result3 = solution.scoreOfAString(s3)
    expected3 = 1
    status3 = "PASS" if result3 == expected3 else "FAIL"
    print(f"{result3} | {expected3} | {status3}")

    # Test case 4: Ascending sequence
    s4 = "abc"
    result4 = solution.scoreOfAString(s4)
    expected4 = 2
    status4 = "PASS" if result4 == expected4 else "FAIL"
    print(f"{result4} | {expected4} | {status4}")

    # Test case 5: Maximum difference (a to z)
    s5 = "az"
    result5 = solution.scoreOfAString(s5)
    expected5 = 25
    status5 = "PASS" if result5 == expected5 else "FAIL"
    print(f"{result5} | {expected5} | {status5}")

    # Test case 6: Alternating pattern
    s6 = "aabbcc"
    result6 = solution.scoreOfAString(s6)
    expected6 = 2
    status6 = "PASS" if result6 == expected6 else "FAIL"
    print(f"{result6} | {expected6} | {status6}")


if __name__ == "__main__":
    run_tests()
