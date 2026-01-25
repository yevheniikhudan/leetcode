class Solution:
    def countSubstrings(self, s: str) -> int:
        res = 0

        def helper(left, right):
            nonlocal res

            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
                res += 1

        for i in range(len(s)):
            helper(i, i)
            helper(i, i + 1)

        return res


# Test helper
def test_count_substrings():
    solution = Solution()

    # Test case 1: Example 1
    s1 = "abc"
    expected1 = 3
    actual1 = solution.countSubstrings(s1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    s2 = "aaa"
    expected2 = 6
    actual2 = solution.countSubstrings(s2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Single character
    s3 = "a"
    expected3 = 1
    actual3 = solution.countSubstrings(s3)
    print(f"{actual3} | {expected3}")

    # Test case 4: Two same characters
    s4 = "aa"
    expected4 = 3  # "a", "a", "aa"
    actual4 = solution.countSubstrings(s4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Mixed
    s5 = "aba"
    expected5 = 4  # "a", "b", "a", "aba"
    actual5 = solution.countSubstrings(s5)
    print(f"{actual5} | {expected5}")

    # Test case 6: All different
    s6 = "abcd"
    expected6 = 4
    actual6 = solution.countSubstrings(s6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_count_substrings()
