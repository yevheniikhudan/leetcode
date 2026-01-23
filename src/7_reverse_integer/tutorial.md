# Tutorial: Reverse Integer

## Understanding the Problem
Reverse digits of a 32-bit signed integer. Handle overflow by returning 0. No 64-bit integers allowed.

## Key Concepts
- **Digit Extraction:** Use modulo 10 to get last digit, divide by 10 to remove it.
- **Overflow Check:** Check if result * 10 + digit would overflow before adding.
- **Sign Handling:** Reverse absolute value, then apply sign.

## Approaches

### 1. Iterative Reversal
- Extract digits one by one, build reversed number.
- Check for overflow at each step.

**Time Complexity:** O(log n) (digits in number)  
**Space Complexity:** O(1)

### 2. String Conversion (Not Recommended)
- Convert to string, reverse, convert back.
- But problem implies no string operations for efficiency.

**Time Complexity:** O(log n)  
**Space Complexity:** O(log n)

## Visual Example
For x = 123:
- 123 % 10 = 3, result = 0*10 + 3 = 3
- 12 % 10 = 2, result = 3*10 + 2 = 32
- 1 % 10 = 1, result = 32*10 + 1 = 321

## Edge Cases
- x = 0: 0
- x = -1: -1
- x = 2147483647 (INT_MAX): may overflow
- x = -2147483648 (INT_MIN): may overflow

## Common Pitfalls
- Forgetting overflow check.
- Negative numbers: reverse positive, then negate.
- Leading zeros: 120 -> 21 (not 021)

## Optimization Notes
- Iterative is best: O(log n) time, O(1) space.
- Overflow check: if result > INT_MAX/10 or (result == INT_MAX/10 and digit > 7)
