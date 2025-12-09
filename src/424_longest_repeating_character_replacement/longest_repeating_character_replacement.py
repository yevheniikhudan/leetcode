"""
424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of
the string and change it to any other uppercase English character. You can
perform this operation at most k times.

Return the length of the longest substring containing the same letter you can
get after performing the above operations.
"""


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        res = 0
        left = 0
        max_frequency = 0
        counts = {}

        for right in range(len(s)):
            counts[s[right]] = 1 + counts.get(s[right], 0)
            max_frequency = max(max_frequency, counts[s[right]])

            while (right - left + 1) - max_frequency > k:
                counts[s[left]] -= 1
                left += 1

            res = max(res, right - left + 1)

        return res


def test_longest_repeating_character_replacement():
    solution = Solution()

    # Test case 1: Example 1
    s = "ABAB"
    k = 2
    result = solution.characterReplacement(s, k)
    expected = 4
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2
    s = "AABABBA"
    k = 1
    result = solution.characterReplacement(s, k)
    expected = 4
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: No replacements needed - all same
    s = "AAAA"
    k = 0
    result = solution.characterReplacement(s, k)
    expected = 4
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: Single character
    s = "A"
    k = 1
    result = solution.characterReplacement(s, k)
    expected = 1
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: Can replace entire string
    s = "ABCD"
    k = 3
    result = solution.characterReplacement(s, k)
    expected = 4
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: No replacements allowed
    s = "ABAB"
    k = 0
    result = solution.characterReplacement(s, k)
    expected = 1
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: Longer string with pattern
    s = "AAABBBCCC"
    k = 2
    result = solution.characterReplacement(s, k)
    expected = 5
    print(f"Test 7: {result} (expected: {expected})")

    # Test case 8: Complex case
    s = "ABCDE"
    k = 1
    result = solution.characterReplacement(s, k)
    expected = 2
    print(f"Test 8: {result} (expected: {expected})")


if __name__ == "__main__":
    test_longest_repeating_character_replacement()
