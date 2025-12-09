/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
*/

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    /**
     * Determine if a string of parentheses is valid.
     *
     * @param s String containing only '()[]{}'
     * @return True if the string is valid, false otherwise
     *
     * Time Complexity: O(n) where n = s.length()
     * Space Complexity: O(n) for the stack in worst case
     */
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> match = {{'{', '}'}, {'(', ')'}, {'[', ']'}};

        for (char ch : s) {
            if (match.count(ch)) {
                stk.push(ch);
            } else {
                if (stk.empty() || match[stk.top()] != ch) {
                    return false;
                }
                stk.pop();
            }
        }

        return stk.empty();
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    bool result1 = solution.isValid("()");
    cout << "Test 1: " << (result1 ? "true" : "false") << " (expected: true)\n";

    // Test case 2: Example 2
    bool result2 = solution.isValid("()[]{}");
    cout << "Test 2: " << (result2 ? "true" : "false") << " (expected: true)\n";

    // Test case 3: Example 3
    bool result3 = solution.isValid("(]");
    cout << "Test 3: " << (result3 ? "true" : "false") << " (expected: false)\n";

    // Test case 4: Example 4
    bool result4 = solution.isValid("([])");
    cout << "Test 4: " << (result4 ? "true" : "false") << " (expected: true)\n";

    // Test case 5: Example 5
    bool result5 = solution.isValid("([)]");
    cout << "Test 5: " << (result5 ? "true" : "false") << " (expected: false)\n";

    // Test case 6: Single character
    bool result6 = solution.isValid("(");
    cout << "Test 6: " << (result6 ? "true" : "false") << " (expected: false)\n";

    // Test case 7: All opening brackets
    bool result7 = solution.isValid("(((");
    cout << "Test 7: " << (result7 ? "true" : "false") << " (expected: false)\n";

    // Test case 8: All closing brackets
    bool result8 = solution.isValid(")))");
    cout << "Test 8: " << (result8 ? "true" : "false") << " (expected: false)\n";

    // Test case 9: Complex nested valid
    bool result9 = solution.isValid("{[()]}");
    cout << "Test 9: " << (result9 ? "true" : "false") << " (expected: true)\n";

    // Test case 10: Complex nested invalid
    bool result10 = solution.isValid("{[(])}");
    cout << "Test 10: " << (result10 ? "true" : "false") << " (expected: false)\n";
}

int main() {
    runTests();
    return 0;
}
