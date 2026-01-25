class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s == "":
            return ""

        n = len(s)
        indices = [0, 0]

        def expand(left, right):
            nonlocal indices

            if s[left] != s[right]:
                return

            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1

            left += 1
            right -= 1

            if right - left + 1 > indices[1] - indices[0] + 1:
                indices = [left, right]

        for i in range(1, n):
            expand(i, i)
            expand(i - 1, i)

        return s[indices[0] : indices[1] + 1]


# Test helper
def test_longest_palindrome():
    solution = Solution()

    # Test case 1: Example 1
    s1 = "babad"
    expected1 = "bab"  # or "aba"
    actual1 = solution.longestPalindrome(s1)
    print(f'"{actual1}" | "{expected1}"')

    # Test case 2: Example 2
    s2 = "cbbd"
    expected2 = "bb"
    actual2 = solution.longestPalindrome(s2)
    print(f'"{actual2}" | "{expected2}"')

    # Test case 3: Single character
    s3 = "a"
    expected3 = "a"
    actual3 = solution.longestPalindrome(s3)
    print(f'"{actual3}" | "{expected3}"')

    # Test case 4: All same characters
    s4 = "aaa"
    expected4 = "aaa"
    actual4 = solution.longestPalindrome(s4)
    print(f'"{actual4}" | "{expected4}"')

    # Test case 5: No palindrome longer than 1
    s5 = "abc"
    expected5 = "a"  # or "b" or "c"
    actual5 = solution.longestPalindrome(s5)
    print(f'"{actual5}" | "{expected5}"')

    # Test case 6: Even length
    s6 = "abba"
    expected6 = "abba"
    actual6 = solution.longestPalindrome(s6)
    print(f'"{actual6}" | "{expected6}"')


if __name__ == "__main__":
    test_longest_palindrome()
