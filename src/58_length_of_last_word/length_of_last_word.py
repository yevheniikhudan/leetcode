class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        """
        Find the length of the last word in a string.

        Args:
            s: A string consisting of words and spaces

        Returns:
            The length of the last word
        """
        right = len(s) - 1

        while s[right] == " ":
            right -= 1

        left = right

        while left > 0 and s[left] != " ":
            left -= 1
        if s[left] == " ":
            left += 1

        return right - left + 1


def run_tests():
    """Run test cases for the lengthOfLastWord problem."""
    solution = Solution()

    # Test case 1: Example from problem - basic case with two words
    test1_input = "Hello World"
    test1_expected = 5
    test1_result = solution.lengthOfLastWord(test1_input)
    print(
        f"{test1_result} | {test1_expected} | {'PASS' if test1_result == test1_expected else 'FAIL'}"
    )

    # Test case 2: Multiple spaces and trailing spaces
    test2_input = "   fly me   to   the moon  "
    test2_expected = 4
    test2_result = solution.lengthOfLastWord(test2_input)
    print(
        f"{test2_result} | {test2_expected} | {'PASS' if test2_result == test2_expected else 'FAIL'}"
    )

    # Test case 3: Multiple words with various spacing
    test3_input = "luffy is still joyboy"
    test3_expected = 6
    test3_result = solution.lengthOfLastWord(test3_input)
    print(
        f"{test3_result} | {test3_expected} | {'PASS' if test3_result == test3_expected else 'FAIL'}"
    )

    # Test case 4: Single character
    test4_input = "a"
    test4_expected = 1
    test4_result = solution.lengthOfLastWord(test4_input)
    print(
        f"{test4_result} | {test4_expected} | {'PASS' if test4_result == test4_expected else 'FAIL'}"
    )

    # Test case 5: Single word with trailing spaces
    test5_input = "hello  "
    test5_expected = 5
    test5_result = solution.lengthOfLastWord(test5_input)
    print(
        f"{test5_result} | {test5_expected} | {'PASS' if test5_result == test5_expected else 'FAIL'}"
    )

    # Test case 6: Single word with leading spaces
    test6_input = "   world"
    test6_expected = 5
    test6_result = solution.lengthOfLastWord(test6_input)
    print(
        f"{test6_result} | {test6_expected} | {'PASS' if test6_result == test6_expected else 'FAIL'}"
    )


if __name__ == "__main__":
    run_tests()
