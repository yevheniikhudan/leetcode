# Tutorial: Sort Array By Parity

## Problem Understanding
Given an array of integers, the goal is to reorder the array so that all even numbers appear before all odd numbers. The relative order within even and odd groups does not matter.

## Visual Example
Input: [3, 1, 2, 4]
Possible Output: [2, 4, 3, 1] (other valid outputs: [4, 2, 3, 1], [2, 4, 1, 3], etc.)

## Approaches
### 1. Extra Array
- Create two lists: one for evens, one for odds.
- Traverse the input, append each number to the appropriate list.
- Concatenate evens and odds for the result.
- Time: O(n), Space: O(n)

### 2. In-Place Two-Pointer
- Use two pointers: one from the start, one from the end.
- Swap even numbers to the front and odd numbers to the back.
- Continue until pointers meet.
- Time: O(n), Space: O(1)

### 3. Stable Partition (if order matters)
- Use a stable partition algorithm to keep the relative order of evens and odds.
- May require extra space or more complex logic.

## Time and Space Complexity
- All approaches run in O(n) time.
- Extra array uses O(n) space; in-place uses O(1) space.

## Edge Cases
- Empty array: return []
- All even or all odd: return original array
- Single element: return original array

## Optimization Notes
- In-place is preferred for large arrays to save space.
- If stability is required, use extra array or stable partition.

## Common Pitfalls
- Forgetting to handle empty or single-element arrays.
- Not considering that the order within even/odd groups does not matter unless specified.
