# 1822. Sign of the Product of an Array - Tutorial

This problem is about determining the sign of the product of an array without actually computing the product (to avoid overflow).

## Approach Outline
1. Initialize a variable to track the sign (start with 1).
2. Iterate through the array:
   - If you find a zero, return 0 immediately.
   - If the number is negative, flip the sign.
3. Return the sign at the end.

This approach is O(n) time and O(1) space, and avoids overflow.
