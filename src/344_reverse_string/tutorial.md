# Tutorial: Reverse String

## Understanding the Problem
Given an array of characters, reverse the array in-place using O(1) extra space.

## Visual Example
- Input: ["h","e","l","l","o"]
- Output: ["o","l","l","e","h"]

## Approaches
### 1. Two-Pointer In-Place Swap (Most Efficient)
- Use two pointers, one at the start and one at the end of the array.
- Swap the characters at these pointers and move them towards each other until they meet.
- Time: O(n), Space: O(1)

### 2. Built-in Reverse (Not allowed for in-place constraint)
- Use language built-ins to reverse, but this does not meet the in-place requirement.

## Complexity
- O(n) time, O(1) space for the two-pointer approach.

## Edge Cases
- Empty array: do nothing.
- Single character: do nothing.

## Optimization Notes
- The two-pointer approach is optimal for in-place reversal.
