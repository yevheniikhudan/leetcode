# Tutorial: Power of Four

## Understanding the Problem
Given an integer n, determine if it is a power of four (i.e., 4^x for some integer x >= 0).

## Visual Example
- Input: 16 → Output: true (4^2)
- Input: 5 → Output: false
- Input: 1 → Output: true (4^0)

## Approaches
### 1. Iterative Division (Most Efficient & Robust)
- Repeatedly divide n by 4. If you reach 1, it's a power of four; if not, it's not.
- Time: O(log n), Space: O(1)

### 2. Bit Manipulation
- Check if n is a power of two (n > 0 and n & (n-1) == 0) and the only set bit is in an even position.
- Time: O(1), Space: O(1)

### 3. Recursive Division
- Recursively divide n by 4 and check if you reach 1.
- Time: O(log n), Space: O(log n) (due to recursion stack)

## Complexity
- All approaches: O(log n) time, O(1) or O(log n) space.

## Edge Cases
- n <= 0: always false.
- n == 1: always true.

## Optimization Notes
- Iterative or bit manipulation approaches are preferred for efficiency and reliability.
