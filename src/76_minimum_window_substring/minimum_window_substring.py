"""
76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum
window substring of s such that every character in t (including duplicates) is
included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
"""

from collections import defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        dict_t = {}
        dict_s = {}
        for ch in t:
            dict_t[ch] = 1 + dict_t.get(ch, 0)

        required = len(dict_t)
        matched = 0
        min_len = float("infinity")
        best_indexes = [-1, -1]
        left = 0
        
        for right in range(len(s)):
            ch = s[right]
            dict_s[ch] = 1 + dict_s.get(ch, 0)
            
            if ch in dict_t and dict_s[ch] == dict_t[ch]:
                matched += 1
                
            while matched == required:
                if right - left + 1 < min_len:
                    best_indexes = [left, right] # Found better!
                    min_len = right - left + 1
                    
                left_char = s[left]
                if left_char in dict_t and dict_s[left_char] == dict_t[left_char]:
                    matched -= 1
                    
                dict_s[s[left]] -= 1
                left += 1
            
        return (
            ""
            if min_len == float("infinity")
            else s[best_indexes[0] : best_indexes[1] + 1]
        )

    def minWindowNotOptimized(self, s: str, t: str) -> str:
        def isValidWindow():
            matched = 0
            for ch in dict_t:
                if ch in dict_s and dict_s[ch] >= dict_t[ch]:
                    matched += 1
            return matched == required
        dict_t = {}
        dict_s = {}
        for ch in t:
            dict_t[ch] = 1 + dict_t.get(ch, 0)

        required = len(dict_t)
        min_len = float("infinity")
        best_indexes = [-1, -1]
        left = 0
        
        for right in range(len(s)):
            ch = s[right]
            dict_s[ch] = 1 + dict_s.get(ch, 0)
            
            while isValidWindow():
                if right - left + 1 < min_len:
                    best_indexes = [left, right]
                    min_len = right - left + 1
                    
                dict_s[s[left]] -= 1
                left += 1
            
        return (
            ""
            if min_len == float("infinity")
            else s[best_indexes[0] : best_indexes[1] + 1]
        )

    def minWindowBruteForce(self, s: str, t: str) -> str:
        dict_t = {}
        for ch in t:
            dict_t[ch] = 1 + dict_t.get(ch, 0)

        required = len(dict_t)
        min_len = float("infinity")
        best_indexes = [-1, -1]

        def isValidWindow(dict_s):
            matched = 0
            for ch in dict_t:
                if ch in dict_s and dict_s[ch] >= dict_t[ch]:
                    matched += 1
            return matched == required

        for i in range(len(s)):
            dict_s = {}
            for j in range(i, len(s)):
                ch = s[j]
                dict_s[ch] = 1 + dict_s.get(ch, 0)

                if isValidWindow(dict_s):
                    window_len = j - i + 1
                    if window_len < min_len:
                        min_len = window_len # Found better!
                        best_indexes = [i, j]
                        break  # Found minimum from this starting point

        return (
            ""
            if min_len == float("infinity")
            else s[best_indexes[0] : best_indexes[1] + 1]
        )


def test_minimum_window_substring():
    solution = Solution()

    # Test case 1: Example 1
    s = "EBANC"
    t = "ABC"
    result = solution.minWindow(s, t)
    expected = "BANC"
    print(f"Test 1: '{result}' (expected: '{expected}')")

    # Test case 2: Example 2
    s = "a"
    t = "a"
    result = solution.minWindow(s, t)
    expected = "a"
    print(f"Test 2: '{result}' (expected: '{expected}')")

    # Test case 3: Example 3 - impossible
    s = "a"
    t = "aa"
    result = solution.minWindow(s, t)
    expected = ""
    print(f"Test 3: '{result}' (expected: '{expected}')")

    # Test case 4: t longer than s
    s = "abc"
    t = "abcd"
    result = solution.minWindow(s, t)
    expected = ""
    print(f"Test 4: '{result}' (expected: '{expected}')")

    # Test case 5: Multiple occurrences - need 2 A's
    s = "ADOBECODEBANC"
    t = "AABC"
    result = solution.minWindow(s, t)
    expected = "ADOBECODEBA"  # Fixed: need 2 A's, so must span to index 10
    print(f"Test 5: '{result}' (expected: '{expected}')")

    # Test case 6: Entire string is minimum
    s = "abc"
    t = "abc"
    result = solution.minWindow(s, t)
    expected = "abc"
    print(f"Test 6: '{result}' (expected: '{expected}')")

    # Test case 7: Window at beginning
    s = "cabwefgewcwaefgcf"
    t = "cae"
    result = solution.minWindow(s, t)
    expected = "cwae"
    print(f"Test 7: '{result}' (expected: '{expected}')")

    # Test case 8: Duplicates in t
    s = "aaaaaaaaaaaabbbbbcdd"
    t = "abcdd"
    result = solution.minWindow(s, t)
    expected = "abbbbbcdd"
    print(f"Test 8: '{result}' (expected: '{expected}')")

    # Test case 9: Case sensitive
    s = "Aa"
    t = "Aa"
    result = solution.minWindow(s, t)
    expected = "Aa"
    print(f"Test 9: '{result}' (expected: '{expected}')")

    # Test case 10: No common characters
    s = "abc"
    t = "def"
    result = solution.minWindow(s, t)
    expected = ""
    print(f"Test 10: '{result}' (expected: '{expected}')")


if __name__ == "__main__":
    test_minimum_window_substring()
