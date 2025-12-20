# 2. Add Two Numbers

**Difficulty:** Medium

## Problem Statement

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

## Examples

### Example 1:

**Input:** l1 = [2,4,3], l2 = [5,6,4]

**Output:** [7,0,8]

**Explanation:** 342 + 465 = 807.

```
  2 → 4 → 3  (represents 342)
+ 5 → 6 → 4  (represents 465)
-----------
  7 → 0 → 8  (represents 807)
```

### Example 2:

**Input:** l1 = [0], l2 = [0]

**Output:** [0]

### Example 3:

**Input:** l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]

**Output:** [8,9,9,9,0,0,0,1]

**Explanation:** 9999999 + 9999 = 10009998

```
  9 → 9 → 9 → 9 → 9 → 9 → 9  (represents 9999999)
+ 9 → 9 → 9 → 9              (represents 9999)
-----------------------------
  8 → 9 → 9 → 9 → 0 → 0 → 0 → 1  (represents 10009998)
```

## Constraints

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

## Topics

- Linked List
- Math
- Recursion

## Hints

1. Pay attention to the carry when adding digits.
2. Handle different list lengths carefully.
3. Don't forget about the final carry.
