"""
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
"""

from typing import List


class Solution:
    def isValid(self, s: str) -> bool:
        """
        Determine if a string of parentheses is valid.

        Args:
            s: String containing only '()[]{}'

        Returns:
            True if the string is valid, False otherwise

        Time Complexity: O(n) where n = len(s)
        Space Complexity: O(n) for the stack in worst case
        """
        stack = []
        match = {"{": "}", "(": ")", "[": "]"}

        for ch in s:
            if ch in match:
                stack.append(ch)
            else:
                if not stack or match[stack.pop()] != ch:
                    return False

        return len(stack) == 0


def test_valid_parentheses():
    solution = Solution()

    # Test case 1: Example 1
    s = "()"
    result = solution.isValid(s)
    expected = True
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2
    s = "()[]{}"
    result = solution.isValid(s)
    expected = True
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: Example 3
    s = "(]"
    result = solution.isValid(s)
    expected = False
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: Example 4
    s = "([])"
    result = solution.isValid(s)
    expected = True
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: Example 5
    s = "([)]"
    result = solution.isValid(s)
    expected = False
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: Single character
    s = "("
    result = solution.isValid(s)
    expected = False
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: All opening brackets
    s = "((("
    result = solution.isValid(s)
    expected = False
    print(f"Test 7: {result} (expected: {expected})")

    # Test case 8: All closing brackets
    s = ")))"
    result = solution.isValid(s)
    expected = False
    print(f"Test 8: {result} (expected: {expected})")

    # Test case 9: Complex nested valid
    s = "{[()]}"
    result = solution.isValid(s)
    expected = True
    print(f"Test 9: {result} (expected: {expected})")

    # Test case 10: Complex nested invalid
    s = "{[(])}"
    result = solution.isValid(s)
    expected = False
    print(f"Test 10: {result} (expected: {expected})")


if __name__ == "__main__":
    test_valid_parentheses()
