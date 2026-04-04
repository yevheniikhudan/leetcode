# Multiply Strings — Tutorial

Difficulty: Medium

This tutorial explains the conceptual approaches to solving LeetCode 43 "Multiply Strings". No code is included — only explanations, strategies, and trade-offs.

## Problem recap
Given two non-negative integers represented as strings, multiply them and return the product as a string. Do not use any built-in big-integer libraries or convert the entire strings to integers (which may exceed language limits).

Examples:
- "123" × "456" = "56088"
- "0" × "123" = "0"
- "999" × "999" = "998001"

## Key insight
Mimic grade-school multiplication: multiply each digit of the first number by each digit of the second number, keeping track of place values (positions), and sum the partial products.

## Approaches

1. Grade-school multiplication (standard, recommended)
   - Create a result array of size len(num1) + len(num2) (max product length).
   - For each digit at position i in num1 and position j in num2, multiply them and add the product to result[i+j] and result[i+j+1], handling carries.
   - Convert the result array back to a string.
   - Time: O(m × n) where m = len(num1), n = len(num2).
   - Space: O(m + n) for the result array.

2. Built-in multiplication (avoid in interviews)
   - Convert strings to integers, multiply, convert back to string.
   - Not allowed per problem statement (defeats the purpose).
   - Doesn't demonstrate understanding of digit-level arithmetic.

3. Alternative: Repeated addition (inefficient)
   - Parse num1 and repeatedly add num2 to an accumulator.
   - Time: O(num1 × num2) in the worst case, very slow.
   - Avoid; only useful for understanding.

## Conceptual walkthrough (grade-school multiplication)

Example: "123" × "456"

```
        1 2 3
      ×     4 5 6
      ---------
        7 3 8  (123 × 6)
      6 1 5    (123 × 5, shifted one position left)
    4 9 2      (123 × 4, shifted two positions left)
    ---------
    5 6 0 8 8
```

In the array-based approach:
- Position i+j in the result array holds the contribution from digit[i] of num1 and digit[j] of num2.
- Carries propagate left as needed.

## Edge cases
- Either number is "0" → result is "0".
- Single-digit numbers → straightforward multiplication.
- Leading zeros in input: not expected per problem constraints (inputs are valid non-negative integers represented as strings).
- Very large numbers: the array approach handles this well without overflow.

## Complexity analysis
- Time: O(m × n) — every digit in num1 is multiplied by every digit in num2.
- Space: O(m + n) — the result array can have at most m + n digits.

## Key concepts
- Place value: position in the result array corresponds to magnitude (10^k).
- Carry propagation: when a partial sum at position i exceeds 9, the carry moves to position i+1.
- Array indexing: understanding how to map digit positions to result array indices is crucial.

## Common pitfalls
- Forgetting to handle carries correctly.
- Not initializing the result array to the correct size (m + n).
- Confusing index positions (multiplying digits at positions i and j contributes to result[i+j] and result[i+j+1]).
- Not converting the final result array back to a string correctly, or including leading zeros.
- Special case of "0": must return "0", not an empty string or "00...".

## Optimization notes
- The grade-school approach is already optimal in terms of time complexity.
- Space can't be reduced below O(m + n) because the result itself can be that large.
- Minor optimization: skip leading zeros when converting the result array to a string.

## Recommended approach
Grade-school multiplication using an array to store intermediate results. It's intuitive, efficient, and demonstrates understanding of digit-level arithmetic and place values.

(End of tutorial)