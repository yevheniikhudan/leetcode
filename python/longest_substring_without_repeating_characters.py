"""
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate
characters.
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, res = 0, 0
        seen = {}

        for right, ch in enumerate(s):
            if ch in seen:
                left = max(seen[ch] + 1, left)

            seen[ch] = right
            res = max(res, right - left + 1)

        return res


def test_longest_substring_without_repeating_characters():
    solution = Solution()

    # Test case 1: Example 1
    s = "abcabcbb"
    result = solution.lengthOfLongestSubstring(s)
    expected = 3
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2 - all same characters
    s = "bbbbb"
    result = solution.lengthOfLongestSubstring(s)
    expected = 1
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: Example 3
    s = "pwwkew"
    result = solution.lengthOfLongestSubstring(s)
    expected = 3
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: Empty string
    s = ""
    result = solution.lengthOfLongestSubstring(s)
    expected = 0
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: All unique characters
    s = "abcdef"
    result = solution.lengthOfLongestSubstring(s)
    expected = 6
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: Single character
    s = "a"
    result = solution.lengthOfLongestSubstring(s)
    expected = 1
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: With spaces and special characters
    s = "a b!c"
    result = solution.lengthOfLongestSubstring(s)
    expected = 5
    print(f"Test 7: {result} (expected: {expected})")

    # Test case 8: Duplicate at start and end
    s = "dvdf"
    result = solution.lengthOfLongestSubstring(s)
    expected = 3
    print(f"Test 8: {result} (expected: {expected})")

    # Test case 9: Two characters alternating
    s = "au"
    result = solution.lengthOfLongestSubstring(s)
    expected = 2
    print(f"Test 9: {result} (expected: {expected})")

    # Test case 10: Complex case
    s = "tmmzuxt"
    result = solution.lengthOfLongestSubstring(s)
    expected = 5
    print(f"Test 10: {result} (expected: {expected})")


if __name__ == "__main__":
    test_longest_substring_without_repeating_characters()
