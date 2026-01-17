# Tutorial: Pascal's Triangle II

## Understanding the Problem
Given a row index, return the corresponding row of Pascal's Triangle.

## Visual Example
- Input: 3 → Output: [1, 3, 3, 1]
- Input: 0 → Output: [1]
- Input: 1 → Output: [1, 1]

## Approaches
### 1. Iterative Construction (Most Efficient)
- Build rows of Pascal's Triangle up to the given index.
- Each row is constructed from the previous row.
- Time: O(n^2), Space: O(n)

### 2. Combinatorial Formula
- Use the binomial coefficient formula to compute each element directly.
- Time: O(n), Space: O(n)

## Complexity
- Iterative: O(n^2) time, O(n) space.
- Combinatorial: O(n) time, O(n) space.

## Edge Cases
- rowIndex = 0 or 1: return [1] or [1, 1].

## Optimization Notes
- The combinatorial approach is optimal for space and time.
