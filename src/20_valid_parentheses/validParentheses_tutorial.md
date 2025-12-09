# Valid Parentheses - Tutorial

## Problem Understanding

We need to determine if a string containing only parentheses characters `()[]{}` is valid. A valid string means:
- Every opening bracket has a matching closing bracket of the same type
- Brackets are closed in the correct order (most recent opening must be closed first)

**Key Insight:** This is a **Last-In-First-Out (LIFO)** problem, which is perfect for a **stack** data structure.

## Why Use a Stack?

Think about how parentheses work:
- `(())` - The **most recent** opening `(` must be closed first
- `([])` - After opening `(` and `[`, we must close `]` before `)`
- This "most recent first" behavior is exactly what a stack provides!

## Approach: Stack-Based Solution

### Algorithm:

1. **Initialize an empty stack**
2. **Iterate through each character** in the string:
   - **If it's an opening bracket** `(`, `{`, or `[`:
     - Push it onto the stack
   - **If it's a closing bracket** `)`, `}`, or `]`:
     - Check if the stack is empty → if yes, return `false` (no matching opening)
     - Pop the top of the stack
     - Check if it matches the closing bracket → if no, return `false`
3. **After processing all characters**:
   - If the stack is empty → return `true` (all brackets matched)
   - If the stack has elements → return `false` (unmatched opening brackets)

### Example Walkthrough 1: `s = "()[]{}"`

```
Character: '('
Stack: ['(']
Action: Push opening bracket

Character: ')'
Stack: ['(']
Action: Pop '(' - matches ')' ✓
Stack: []

Character: '['
Stack: ['[']
Action: Push opening bracket

Character: ']'
Stack: ['[']
Action: Pop '[' - matches ']' ✓
Stack: []

Character: '{'
Stack: ['{']
Action: Push opening bracket

Character: '}'
Stack: ['{']
Action: Pop '{' - matches '}' ✓
Stack: []

Result: Stack is empty → Valid ✓
```

### Example Walkthrough 2: `s = "([)]"`

```
Character: '('
Stack: ['(']
Action: Push opening bracket

Character: '['
Stack: ['(', '[']
Action: Push opening bracket

Character: ')'
Stack: ['(', '[']
Action: Pop '[' - does NOT match ')' ✗

Result: Invalid ✗
```

### Example Walkthrough 3: `s = "(("`

```
Character: '('
Stack: ['(']
Action: Push opening bracket

Character: '('
Stack: ['(', '(']
Action: Push opening bracket

Result: Stack is NOT empty → Invalid ✗
(Unmatched opening brackets)
```

## Implementation Strategies

### Strategy 1: Direct Matching

When you encounter a closing bracket:
1. Check if stack is empty
2. Pop from stack
3. Compare if popped opening matches the closing

```
Matching pairs:
'(' matches ')'
'[' matches ']'
'{' matches '}'
```

### Strategy 2: Use a HashMap/Dictionary

Store the mapping of closing brackets to opening brackets:
```
mapping = {
    ')': '(',
    ']': '[',
    '}': '{'
}
```

This makes checking easier:
- If character is a closing bracket (exists as key in mapping)
- Pop from stack and check if it equals `mapping[closing_bracket]`

## Edge Cases to Consider

1. **Empty string**: Should return `true` (some interpretations) or `false` (per constraints, length >= 1)
2. **Single character**: Always `false` (can't be matched)
3. **All opening brackets**: `"((("` → `false` (stack not empty at end)
4. **All closing brackets**: `")))"` → `false` (stack empty when trying to match)
5. **Odd length**: Always `false` (can't pair all brackets)
6. **Mismatched types**: `"(]"` → `false`
7. **Wrong order**: `"([)]"` → `false` (correct pairs but wrong nesting)

## Time and Space Complexity

**Time Complexity:** O(n) where n = length of string
- We iterate through the string once
- Each push/pop operation is O(1)

**Space Complexity:** O(n) in worst case
- If all characters are opening brackets, stack will contain all of them
- Example: `"((((("` requires stack size of 5

## Common Mistakes

1. **Forgetting to check if stack is empty** before popping
   - Leads to errors when encountering closing brackets first
   
2. **Not checking if stack is empty at the end**
   - Example: `"((("` would be incorrectly marked as valid
   
3. **Incorrect bracket matching logic**
   - Make sure you're checking the correct pairs
   
4. **Using the wrong data structure**
   - Queue (FIFO) won't work - we need LIFO behavior

5. **Not handling all bracket types**
   - Must handle `()`, `[]`, and `{}` all correctly

## Optimization Notes

- **Early termination**: If string length is odd, immediately return `false`
- **Single pass**: We only need one iteration through the string
- **Constant time operations**: Stack push/pop are O(1)

## Why This Problem is Important

1. **Classic stack application**: Demonstrates perfect use case for LIFO
2. **Foundation for parsing**: Used in compilers, expression evaluation
3. **Real-world application**: JSON/XML validation, code editors
4. **Interview favorite**: Tests understanding of stacks and edge cases

## Related Concepts

- **Balanced expressions**: Similar concept in mathematical expressions
- **Tree traversal**: Parentheses can represent tree structure
- **Recursion**: Can also be solved recursively (less efficient)
- **Parser implementation**: Core concept in language parsing
