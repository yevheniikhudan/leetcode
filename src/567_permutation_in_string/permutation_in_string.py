"""
567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1,
or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
"""


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_counts = [0] * 26
        s2_counts = [0] * 26
        
        for ch in s1:
            s1_counts[ord(ch) - ord('a')] += 1

        left = 0
        right = 0
        
        while right < len(s2):
            while right - left < len(s1) and right < len(s2):
                s2_counts[ord(s2[right]) - ord('a')] += 1
                right += 1
                
            if s1_counts == s2_counts:
                return True
                
            s2_counts[ord(s2[left]) - ord('a')] -= 1
            left += 1

        return False


def test_permutation_in_string():
    solution = Solution()

    # Test case 1: Example 1
    s1 = "ab"
    s2 = "eidbaooo"
    result = solution.checkInclusion(s1, s2)
    expected = True
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2
    s1 = "ab"
    s2 = "eidboaoo"
    result = solution.checkInclusion(s1, s2)
    expected = False
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: s1 longer than s2
    s1 = "hello"
    s2 = "hi"
    result = solution.checkInclusion(s1, s2)
    expected = False
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: Exact match
    s1 = "ab"
    s2 = "ab"
    result = solution.checkInclusion(s1, s2)
    expected = True
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: Permutation at start
    s1 = "abc"
    s2 = "baxyzabc"
    result = solution.checkInclusion(s1, s2)
    expected = True
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: Permutation at end
    s1 = "abc"
    s2 = "xyzabc"
    result = solution.checkInclusion(s1, s2)
    expected = True
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: No permutation
    s1 = "abc"
    s2 = "xyz"
    result = solution.checkInclusion(s1, s2)
    expected = False
    print(f"Test 7: {result} (expected: {expected})")

    # Test case 8: Duplicate characters
    s1 = "aab"
    s2 = "cbaebabacd"
    result = solution.checkInclusion(s1, s2)
    expected = True
    print(f"Test 8: {result} (expected: {expected})")

    # Test case 9: Single character
    s1 = "a"
    s2 = "ab"
    result = solution.checkInclusion(s1, s2)
    expected = True
    print(f"Test 9: {result} (expected: {expected})")

    # Test case 10: All same characters
    s1 = "aa"
    s2 = "aaa"
    result = solution.checkInclusion(s1, s2)
    expected = True
    print(f"Test 10: {result} (expected: {expected})")


if __name__ == "__main__":
    test_permutation_in_string()
