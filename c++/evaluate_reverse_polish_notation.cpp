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

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Evaluate Reverse Polish Notation expression.
     *
     * @param tokens Vector of strings representing RPN expression
     * @return Integer result of the expression
     *
     * Time Complexity: O(n) where n = tokens.size()
     * Space Complexity: O(n) for the stack
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (const string& c : tokens) {
            if (c.length() == 1 && std::string("+-*/").find(c) != std::string::npos) {
                stack.push(applyOperator(stack, c[0]));
            } else {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }

   private:
    int applyOperator(stack<int>& stk, char op) {
        int second = stk.top();
        stk.pop();
        int first = stk.top();
        stk.pop();

        switch (op) {
            case '+':
                return first + second;
            case '-':
                return first - second;
            case '*':
                return first * second;
            case '/':
                return first / second;
        }
        return 0;
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    int result1 = solution.evalRPN(tokens1);
    cout << "Test 1: " << result1 << " (expected: 9)\n";

    // Test case 2: Example 2
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    int result2 = solution.evalRPN(tokens2);
    cout << "Test 2: " << result2 << " (expected: 6)\n";

    // Test case 3: Example 3
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int result3 = solution.evalRPN(tokens3);
    cout << "Test 3: " << result3 << " (expected: 22)\n";

    // Test case 4: Single number
    vector<string> tokens4 = {"42"};
    int result4 = solution.evalRPN(tokens4);
    cout << "Test 4: " << result4 << " (expected: 42)\n";

    // Test case 5: Simple subtraction
    vector<string> tokens5 = {"5", "3", "-"};
    int result5 = solution.evalRPN(tokens5);
    cout << "Test 5: " << result5 << " (expected: 2)\n";

    // Test case 6: Division truncates toward zero (positive result)
    vector<string> tokens6 = {"13", "5", "/"};
    int result6 = solution.evalRPN(tokens6);
    cout << "Test 6: " << result6 << " (expected: 2)\n";

    // Test case 7: Division truncates toward zero (negative result)
    vector<string> tokens7 = {"7", "-3", "/"};
    int result7 = solution.evalRPN(tokens7);
    cout << "Test 7: " << result7 << " (expected: -2)\n";

    // Test case 8: Negative numbers
    vector<string> tokens8 = {"-3", "2", "+"};
    int result8 = solution.evalRPN(tokens8);
    cout << "Test 8: " << result8 << " (expected: -1)\n";

    // Test case 9: Multiple operations
    vector<string> tokens9 = {"2", "3", "+", "4", "*", "5", "-"};
    int result9 = solution.evalRPN(tokens9);
    cout << "Test 9: " << result9 << " (expected: 15)\n";

    // Test case 10: Complex expression
    vector<string> tokens10 = {"1", "2", "+", "3", "+", "4", "+", "5", "+"};
    int result10 = solution.evalRPN(tokens10);
    cout << "Test 10: " << result10 << " (expected: 15)\n";
}

int main() {
    runTests();
    return 0;
}
