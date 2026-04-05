# 190. Reverse Bits

**Difficulty:** Easy

**Topics:** Bit Manipulation

---

## Problem Description

Reverse the bits of a given 32-bit unsigned integer.

---

## Examples

**Example 1:**
```
Input:  n = 00000010100101000001111010011100
Output: 00111001011110000101010100000010
Explanation: 
The input binary string 00000010100101000001111010011100 represents 
the unsigned integer 43261596, so return 964176192 which its binary 
representation is 00111001011110000101010100000010.
```

**Example 2:**
```
Input:  n = 11111111111111111111111111111101
Output: 10111111111111111111111111111111
Explanation:
The input binary string 11111111111111111111111111111101 represents 
the unsigned integer 4294967293, so return 3221225471 which its binary 
representation is 10111111111111111111111111111111.
```

---

## Constraints

- The input must be a **binary string** of length `32`.

---

## Note

In some languages (such as Java), there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.

In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input is `−3` and the output is `−1073741825`.

---

## Related Problems

- [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/)
- [476. Number Complement](https://leetcode.com/problems/number-complement/)
