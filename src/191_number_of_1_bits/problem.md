# 191. Number of 1 Bits

Difficulty: Easy

## Problem

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note: In languages that do not have an unsigned integer type, the input will be given as a signed integer representing the 32-bit binary representation. Treat the input as a 32-bit value.

## Examples

Example 1:
Input: n = 00000000000000000000000000001011 (binary)
Output: 3
Explanation: The binary representation has three '1' bits.

Example 2:
Input: n = 00000000000000000000000010000000 (binary)
Output: 1
Explanation: The binary representation has one '1' bit.

Example 3:
Input: n = 11111111111111111111111111111101 (binary)
Output: 31
Explanation: The binary representation has thirty-one '1' bits.

## Constraints

- The input is a 32-bit integer (interpretation as unsigned for bit counting).
- The function should return an integer in the range [0, 32].
- Aim for O(1) or O(number of 1 bits) time per call; constant extra space.

## Tags

Bit Manipulation, Math

## Related Problems

- 231. Power of Two
- 338. Counting Bits
- Hamming Weight (general / theoretical)