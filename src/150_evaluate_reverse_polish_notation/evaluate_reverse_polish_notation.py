"""
150. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic expression
in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the
expression.

Note that:
- The valid operators are '+', '-', '*', and '/'.
- Each operand may be an integer or another expression.
- The division between two integers always truncates toward zero.
- There will not be any division by zero.
- The input represents a valid arithmetic expression in a reverse polish notation.
- The answer and all the intermediate calculations can be represented in a 32-bit
  integer.
"""

from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        """
        Evaluate Reverse Polish Notation expression.

        Args:
            tokens: List of strings representing RPN expression

        Returns:
            Integer result of the expression

        Time Complexity: O(n) where n = len(tokens)
        Space Complexity: O(n) for the stack
        """
        stack = []
        
        for token in tokens:
            if token == '+':
                stack.append(stack.pop() + stack.pop())
            elif token == '-':
                a, b = stack.pop(), stack.pop()
                stack.append(b - a)
            elif token == '*':
                 stack.append(stack.pop() * stack.pop())
            elif token == '/':
                a, b = stack.pop(), stack.pop()
                stack.append(int(b / a))
            else:
                stack.append(int(token))
                
        return stack[0]


def test_evaluate_rpn():
    solution = Solution()

    # Test case 1: Example 1
    tokens = ["2", "1", "+", "3", "*"]
    result = solution.evalRPN(tokens)
    expected = 9
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2
    tokens = ["4", "13", "5", "/", "+"]
    result = solution.evalRPN(tokens)
    expected = 6
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: Example 3
    tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
    result = solution.evalRPN(tokens)
    expected = 22
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: Single number
    tokens = ["42"]
    result = solution.evalRPN(tokens)
    expected = 42
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: Simple subtraction
    tokens = ["5", "3", "-"]
    result = solution.evalRPN(tokens)
    expected = 2
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: Division truncates toward zero (positive result)
    tokens = ["13", "5", "/"]
    result = solution.evalRPN(tokens)
    expected = 2
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: Division truncates toward zero (negative result)
    tokens = ["7", "-3", "/"]
    result = solution.evalRPN(tokens)
    expected = -2
    print(f"Test 7: {result} (expected: {expected})")

    # Test case 8: Negative numbers
    tokens = ["-3", "2", "+"]
    result = solution.evalRPN(tokens)
    expected = -1
    print(f"Test 8: {result} (expected: {expected})")

    # Test case 9: Multiple operations
    tokens = ["2", "3", "+", "4", "*", "5", "-"]
    result = solution.evalRPN(tokens)
    expected = 15
    print(f"Test 9: {result} (expected: {expected})")

    # Test case 10: Complex expression
    tokens = ["1", "2", "+", "3", "+", "4", "+", "5", "+"]
    result = solution.evalRPN(tokens)
    expected = 15
    print(f"Test 10: {result} (expected: {expected})")


if __name__ == "__main__":
    test_evaluate_rpn()
