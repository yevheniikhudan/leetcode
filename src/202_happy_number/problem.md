# 202. Happy Number

Difficulty: Easy  
Topics: Math, Hash Table, Cycle Detection

Problem link: https://leetcode.com/problems/happy-number/description/

## Problem

Write an algorithm to determine if a number n is "happy."

A happy number is defined by the following process:

- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle that does not include 1.
- Those numbers for which this process ends in 1 are happy numbers.

Return true if n is a happy number, and false if not.

## Examples

Example 1:
Input: 19  
Output: true  
Explanation:
- 1^2 + 9^2 = 1 + 81 = 82  
- 8^2 + 2^2 = 64 + 4 = 68  
- 6^2 + 8^2 = 36 + 64 = 100  
- 1^2 + 0^2 + 0^2 = 1 → reaches 1, so 19 is happy.

Example 2:
Input: 2  
Output: false  
Explanation: The sequence enters a cycle that never reaches 1.

Example 3:
Input: 1  
Output: true

## Constraints

- 1 <= n <= 2^31 - 1 (n is a positive integer)

## Notes & Approaches

Common approaches to detect whether the sequence reaches 1 or cycles:

1. Set / Hash Table:
   - Track seen values produced by the sum-of-squares transformation.
   - If you see 1 → return true.
   - If a value repeats (seen before) → a cycle exists → return false.
   - Time: O(k) where k is number of steps until termination; Space: O(k).

2. Floyd's Cycle Detection (Tortoise and Hare):
   - Use two pointers advancing at different speeds (one applies the transform once, the other twice).
   - If they meet at 1 → happy; if they meet at some other value → cycle → not happy.
   - Time: O(k); Space: O(1).

3. Observations / Optimization:
   - For base-10, sums eventually fall into small ranges; typical sequences collapse quickly.
   - Implement a helper function to compute the next number (sum of squares of digits).

## Follow-up

- Could you implement an algorithm that uses O(1) extra space? (Yes — Floyd's cycle detection.)

## Related Problems

- Detect cycle in linked list (Floyd's algorithm)
- Problems involving digit manipulations and transformations

## Example I/O Format (for local testing)

Given the LeetCode-style single integer input, return/print `true` or `false`.  
For local main/test harnesses you might print:
```
19 -> true
2  -> false
```

(End of file)