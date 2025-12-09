/*
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
*/

import java.util.*;

public class EvaluateReversePolishNotation {
    /**
     * Evaluate Reverse Polish Notation expression.
     * 
     * @param tokens Array of strings representing RPN expression
     * @return Integer result of the expression
     * 
     *         Time Complexity: O(n) where n = tokens.length
     *         Space Complexity: O(n) for the stack
     */
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new ArrayDeque<>();

        for (String token : tokens) {
            if (token.equals("+")) {
                stack.add(stack.pop() + stack.pop());
            } else if (token.equals("-")) {
                int a = stack.pop();
                int b = stack.pop();
                stack.push(b - a);
            } else if (token.equals("*")) {
                stack.add(stack.pop() * stack.pop());
            } else if (token.equals("/")) {
                int a = stack.pop();
                int b = stack.pop();
                stack.push(b / a);
            } else {
                stack.add(Integer.parseInt(token));
            }
        }
        return stack.getLast();
    }

    public static void main(String[] args) {
        EvaluateReversePolishNotation solution = new EvaluateReversePolishNotation();

        // Test case 1: Example 1
        int result1 = solution.evalRPN(new String[] { "2", "1", "+", "3", "*" });
        System.out.println("Test 1: " + result1 + " (expected: 9)");

        // Test case 2: Example 2
        int result2 = solution.evalRPN(new String[] { "4", "13", "5", "/", "+" });
        System.out.println("Test 2: " + result2 + " (expected: 6)");

        // Test case 3: Example 3
        int result3 = solution
                .evalRPN(new String[] { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" });
        System.out.println("Test 3: " + result3 + " (expected: 22)");

        // Test case 4: Single number
        int result4 = solution.evalRPN(new String[] { "42" });
        System.out.println("Test 4: " + result4 + " (expected: 42)");

        // Test case 5: Simple subtraction
        int result5 = solution.evalRPN(new String[] { "5", "3", "-" });
        System.out.println("Test 5: " + result5 + " (expected: 2)");

        // Test case 6: Division truncates toward zero (positive result)
        int result6 = solution.evalRPN(new String[] { "13", "5", "/" });
        System.out.println("Test 6: " + result6 + " (expected: 2)");

        // Test case 7: Division truncates toward zero (negative result)
        int result7 = solution.evalRPN(new String[] { "7", "-3", "/" });
        System.out.println("Test 7: " + result7 + " (expected: -2)");

        // Test case 8: Negative numbers
        int result8 = solution.evalRPN(new String[] { "-3", "2", "+" });
        System.out.println("Test 8: " + result8 + " (expected: -1)");

        // Test case 9: Multiple operations
        int result9 = solution.evalRPN(new String[] { "2", "3", "+", "4", "*", "5", "-" });
        System.out.println("Test 9: " + result9 + " (expected: 15)");

        // Test case 10: Complex expression
        int result10 = solution.evalRPN(new String[] { "1", "2", "+", "3", "+", "4", "+", "5", "+" });
        System.out.println("Test 10: " + result10 + " (expected: 15)");
    }
}
