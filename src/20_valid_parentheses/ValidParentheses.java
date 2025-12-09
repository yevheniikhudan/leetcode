/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
*/

import java.util.*;

public class ValidParentheses {
    /**
     * Determine if a string of parentheses is valid.
     * 
     * @param s String containing only '()[]{}'
     * @return True if the string is valid, false otherwise
     * 
     *         Time Complexity: O(n) where n = s.length()
     *         Space Complexity: O(n) for the stack in worst case
     */
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        Map<Character, Character> match = Map.of(
                '{', '}',
                '(', ')',
                '[', ']');
        int N = s.length();

        for (int i = 0; i < N; i++) {
            char ch = s.charAt(i);
            if (match.containsKey(ch)) {
                stack.push(ch);
            } else {
                if (stack.isEmpty() || !match.get(stack.pop()).equals(ch)) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }

    public static void main(String[] args) {
        ValidParentheses solution = new ValidParentheses();

        // Test case 1: Example 1
        boolean result1 = solution.isValid("()");
        System.out.println("Test 1: " + result1 + " (expected: true)");

        // Test case 2: Example 2
        boolean result2 = solution.isValid("()[]{}");
        System.out.println("Test 2: " + result2 + " (expected: true)");

        // Test case 3: Example 3
        boolean result3 = solution.isValid("(]");
        System.out.println("Test 3: " + result3 + " (expected: false)");

        // Test case 4: Example 4
        boolean result4 = solution.isValid("([])");
        System.out.println("Test 4: " + result4 + " (expected: true)");

        // Test case 5: Example 5
        boolean result5 = solution.isValid("([)]");
        System.out.println("Test 5: " + result5 + " (expected: false)");

        // Test case 6: Single character
        boolean result6 = solution.isValid("(");
        System.out.println("Test 6: " + result6 + " (expected: false)");

        // Test case 7: All opening brackets
        boolean result7 = solution.isValid("(((");
        System.out.println("Test 7: " + result7 + " (expected: false)");

        // Test case 8: All closing brackets
        boolean result8 = solution.isValid(")))");
        System.out.println("Test 8: " + result8 + " (expected: false)");

        // Test case 9: Complex nested valid
        boolean result9 = solution.isValid("{[()]}");
        System.out.println("Test 9: " + result9 + " (expected: true)");

        // Test case 10: Complex nested invalid
        boolean result10 = solution.isValid("{[(])}");
        System.out.println("Test 10: " + result10 + " (expected: false)");
    }
}
