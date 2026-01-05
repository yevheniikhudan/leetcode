# Clumsy Factorial - Tutorial

## Understanding the Problem

We need to compute a modified factorial where operations cycle through `*`, `/`, `+`, `-` in a fixed pattern:
- Start with `n`
- Multiply by `n-1`
- Divide by `n-2`
- Add `n-3`
- Subtract `n-4`
- Multiply by `n-5`, divide by `n-6`, add `n-7`, subtract `n-8`
- Continue the pattern until we run out of numbers

**Important:** Follow standard order of operations (multiplication and division before addition and subtraction), and use floor division.

**Example:** `clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1`
- Evaluate: `(10*9/8) + 7 - (6*5/4) + 3 - (2*1)`
- = `90/8 + 7 - 30/4 + 3 - 2`
- = `11 + 7 - 7 + 3 - 2`
- = `12`

## Approaches

### Approach 1: Stack-Based Simulation

**Strategy:**
- Use a stack to handle order of operations
- Process numbers from `n` down to `1`
- Track which operation to apply (cycle through `*`, `/`, `+`, `-`)
- For `*` and `/`, compute immediately with the top of stack
- For `+`, push the positive value onto stack
- For `-`, push the negative value onto stack
- Sum all values in the stack at the end

**Key Concepts:**
- Stack helps manage the order of operations
- Multiplication and division are evaluated immediately
- Addition and subtraction are deferred by pushing to stack
- The pattern repeats every 4 operations

**Time Complexity:** O(n)
**Space Complexity:** O(n) for the stack

### Approach 2: Mathematical Pattern Recognition

**Strategy:**
- Observe the pattern of results for small values of n
- Notice that results follow a predictable pattern
- Derive a mathematical formula based on n mod 4
- Handle edge cases (n ≤ 4) separately

**Key Concepts:**
- For large n, the clumsy factorial approaches n + 1
- Pattern recognition can simplify computation
- Mathematical insight reduces need for simulation
- Groups of 4 numbers tend to cancel out

**Time Complexity:** O(1)
**Space Complexity:** O(1)

### Approach 3: Direct Computation with Variables

**Strategy:**
- Keep track of running result and current chunk
- Process 4 numbers at a time (one full cycle)
- Handle the first group differently (it's added, not subtracted)
- Accumulate results as we go

**Key Concepts:**
- First chunk: `n * (n-1) / (n-2) + (n-3)`
- Subsequent chunks: `- (n-4) * (n-5) / (n-6) + (n-7)`
- Each chunk of 4 follows the same pattern
- Handle remainders when n is not divisible by 4

**Time Complexity:** O(n)
**Space Complexity:** O(1)

## Edge Cases

- `n = 1`: Result is `1`
- `n = 2`: Result is `2` (only multiplication applies: `2 * 1 = 2`)
- `n = 3`: Result is `6` (only multiply and divide: `3 * 2 / 1 = 6`)
- `n = 4`: Result is `7` (`4 * 3 / 2 + 1 = 6 + 1 = 7`)
- Large n: Pattern stabilizes

## Common Pitfalls

- Forgetting order of operations (multiply/divide before add/subtract)
- Not using floor division (integer division)
- Incorrect handling of the operation cycle
- Off-by-one errors when tracking which operation to use
