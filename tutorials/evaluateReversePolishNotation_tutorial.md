# Evaluate Reverse Polish Notation - Tutorial

## Problem Understanding

**Reverse Polish Notation (RPN)**, also known as postfix notation, is a mathematical notation where operators come **after** their operands.

### Notation Comparison:

| Infix (Normal) | RPN (Postfix) | Result |
|----------------|---------------|--------|
| `2 + 3` | `2 3 +` | 5 |
| `(2 + 3) * 4` | `2 3 + 4 *` | 20 |
| `2 + (3 * 4)` | `2 3 4 * +` | 14 |

**Why RPN?**
- No need for parentheses
- No operator precedence ambiguity
- Easy to evaluate using a stack
- Used in some calculators and programming languages (Forth, PostScript)

## Key Insight: Use a Stack!

RPN is **perfect for stack-based evaluation** because:
- When we see a number, we don't know what to do with it yet → push to stack
- When we see an operator, we know we need the last two operands → pop from stack

## Algorithm

### Steps:

1. **Initialize an empty stack**
2. **Iterate through each token**:
   - **If it's a number**: Push it onto the stack
   - **If it's an operator** (`+`, `-`, `*`, `/`):
     - Pop two operands from the stack (order matters!)
     - Apply the operator
     - Push the result back onto the stack
3. **Return the final value** (only element left in stack)

### Example Walkthrough: `["2", "1", "+", "3", "*"]`

```
Token: "2"
Action: Push number
Stack: [2]

Token: "1"
Action: Push number
Stack: [2, 1]

Token: "+"
Action: Pop 1 and 2, compute 2 + 1 = 3, push result
Stack: [3]

Token: "3"
Action: Push number
Stack: [3, 3]

Token: "*"
Action: Pop 3 and 3, compute 3 * 3 = 9, push result
Stack: [9]

Result: 9
```

This represents: `((2 + 1) * 3) = 9`

### Detailed Example: `["4", "13", "5", "/", "+"]`

```
Token: "4"
Stack: [4]

Token: "13"
Stack: [4, 13]

Token: "5"
Stack: [4, 13, 5]

Token: "/"
Pop: 5, 13
Compute: 13 / 5 = 2 (integer division, truncates toward zero)
Push: 2
Stack: [4, 2]

Token: "+"
Pop: 2, 4
Compute: 4 + 2 = 6
Push: 6
Stack: [6]

Result: 6
```

This represents: `(4 + (13 / 5)) = 6`

## Important Details

### 1. Order of Operands Matters!

When popping for operators like `-` and `/`, **order is crucial**:

```python
# Pop order for "a b -"
second = stack.pop()  # b (top of stack)
first = stack.pop()   # a (second from top)
result = first - second  # a - b (NOT b - a!)
```

**Example:** `["5", "3", "-"]`
- Pop 3 (second operand)
- Pop 5 (first operand)
- Compute: 5 - 3 = 2 ✓ (NOT 3 - 5 = -2 ✗)

### 2. Integer Division Truncates Toward Zero

Python's `//` truncates toward negative infinity, but the problem requires truncation toward zero.

```python
# Python behavior:
7 // -3 = -3  # Truncates toward negative infinity

# Problem requirement:
7 / -3 = -2  # Truncates toward zero (use int(a / b))

Examples:
13 / 5 = 2.6 → 2
-13 / 5 = -2.6 → -2
13 / -5 = -2.6 → -2
-13 / -5 = 2.6 → 2
```

**Solution in Python:**
```python
int(first / second)  # Truncates toward zero
```

**C++ and Java:**
```cpp
first / second  // Already truncates toward zero
```

### 3. Negative Numbers

Tokens can include negative numbers like `"-11"`:
- This is a **number**, not an operator
- Need to distinguish between `"-"` (operator) and `"-11"` (number)
- Check if token is an operator using a set or conditional

## Implementation Strategies

### Strategy 1: Check Operators with Set

```python
operators = {'+', '-', '*', '/'}

for token in tokens:
    if token in operators:
        # Apply operator
    else:
        # It's a number
        stack.append(int(token))
```

### Strategy 2: Check Operators with Conditions

```python
for token in tokens:
    if token in ['+', '-', '*', '/'] and len(token) == 1:
        # Apply operator (len check handles negative numbers like "-11")
    else:
        # It's a number
        stack.append(int(token))
```

### Strategy 3: Try-Except (Python)

```python
for token in tokens:
    try:
        stack.append(int(token))  # Try to parse as number
    except ValueError:
        # Must be an operator
        # Apply operator
```

## Edge Cases to Consider

1. **Single number**: `["42"]` → `42`
2. **Negative numbers**: `["-3", "2", "+"]` → `-1`
3. **Division truncation**: `["7", "-3", "/"]` → `-2` (not `-3`)
4. **Complex expressions**: Long chains of operations
5. **All operators used**: `["2", "3", "+", "4", "*", "5", "-"]`

## Time and Space Complexity

**Time Complexity:** O(n) where n = number of tokens
- Process each token exactly once
- Each operation (push/pop) is O(1)

**Space Complexity:** O(n) in worst case
- Stack can grow to size n in worst case (all numbers, then operators)
- Example: `["1", "2", "3", "4", "+", "+", "+"]` has stack size 4

## Common Mistakes

1. **Wrong operand order**
   - `first - second` not `second - first`
   
2. **Wrong division method in Python**
   - Use `int(a / b)` not `a // b`
   
3. **Not handling negative numbers**
   - `-11` is a number, not operator `-` followed by `11`
   
4. **Forgetting to convert strings to integers**
   - `int(token)` when pushing numbers
   
5. **Not pushing result back to stack**
   - After computing, must push result for future operations

## Why This Problem is Important

1. **Classic stack application**: Perfect use case for LIFO structure
2. **Compiler design**: How expressions are evaluated internally
3. **Calculator implementation**: RPN calculators (HP calculators)
4. **Expression parsing**: Foundation for more complex parsing problems
5. **Interview favorite**: Tests stack understanding and attention to detail

## RPN to Infix Conversion (Mental Model)

To understand RPN, think of how to convert back to infix:

```
RPN: ["2", "3", "+", "4", "*"]

Step 1: "2 3 +" → (2 + 3)
Step 2: Replace "2 3 +" with "5" → ["5", "4", "*"]
Step 3: "5 4 *" → (5 * 4)
Step 4: Result = 20

Infix: ((2 + 3) * 4)
```

## Related Concepts

- **Expression trees**: RPN can build expression trees
- **Stack machines**: Virtual machines that use stack for computation
- **Postfix calculators**: HP calculators use RPN
- **Compiler optimization**: Intermediate representations often use postfix
