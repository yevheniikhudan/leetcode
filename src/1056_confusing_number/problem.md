# 1056. Confusing Number

**Difficulty:** Easy

**Topics/Tags:** Math, String

---

## Problem Description

A **confusing number** is a number that, when rotated 180 degrees, becomes a different number.

When rotating a number 180 degrees:
- 0 → 0
- 1 → 1
- 6 → 9
- 8 → 8
- 9 → 6

Any other digit (2, 3, 4, 5, 7) cannot be rotated and does not have a valid transformation.

The number is read from right to left after rotation. Leading zeros are ignored.

Given an integer `n`, return `true` if it is a confusing number, or `false` otherwise.

---

## Examples

### Example 1:
**Input:** `n = 6`  
**Output:** `true`  
**Explanation:** When rotated 180 degrees, 6 becomes 9, which is different from 6.

### Example 2:
**Input:** `n = 89`  
**Output:** `true`  
**Explanation:** When rotated 180 degrees, 89 becomes 68, which is different from 89.

### Example 3:
**Input:** `n = 11`  
**Output:** `false`  
**Explanation:** When rotated 180 degrees, 11 remains 11, which is the same number.

### Example 4:
**Input:** `n = 25`  
**Output:** `false`  
**Explanation:** The digit 2 and 5 cannot be rotated to valid digits.

---

## Constraints

- `0 <= n <= 10^9`

---

## Related Problems

- [Confusing Number II](https://leetcode.com/problems/confusing-number-ii/) (Count confusing numbers up to N)
- [Number to Words](https://leetcode.com/problems/number-to-words/) (Number transformation)
- [Rotate String](https://leetcode.com/problems/rotate-string/) (String rotation)
