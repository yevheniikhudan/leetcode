# 1009. Complement of Base 10 Integer

- Difficulty: Easy
- Topics: Bit Manipulation

## Problem Description
The complement of an integer is the integer you get when you flip all the `0` bits to `1` and all the `1` bits to `0` in its binary representation.

For example, `5` is `101` in binary, and its complement is `010`, which equals `2`.

Given an integer `n`, return its complement.

## Examples

### Example 1
Input: `n = 5`

Output: `2`

Explanation: `5` is `101` in binary. Flipping each bit gives `010`, which is `2`.

### Example 2
Input: `n = 7`

Output: `0`

Explanation: `7` is `111` in binary. Flipping each bit gives `000`, which is `0`.

### Example 3
Input: `n = 10`

Output: `5`

Explanation: `10` is `1010` in binary. Flipping each bit gives `0101`, which is `5`.

## Constraints
- `0 <= n < 10^9`

## Notes
- This problem is the same as 476. Number Complement.

## Related Problems
- 476. Number Complement
- 190. Reverse Bits
- 191. Number of 1 Bits