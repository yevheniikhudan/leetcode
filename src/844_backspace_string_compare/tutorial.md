# Tutorial: Backspace String Compare

## Understanding the Problem
Given two strings, determine if they are equal after simulating backspace operations (where '#' means backspace).

## Visual Example
- s = "ab#c", t = "ad#c" → both become "ac" (true)
- s = "ab##", t = "c#d#" → both become "" (true)
- s = "a#c", t = "b" → "c" vs "b" (false)

## Approaches
### 1. Stack Simulation (Most Efficient)
- Use a stack to simulate typing and backspacing for each string.
- Compare the final results.
- Time: O(n + m), Space: O(n + m)

### 2. Two Pointer (Optimal Space)
- Use two pointers from the end of each string, skipping characters as needed.
- Compare characters one by one.
- Time: O(n + m), Space: O(1)

## Complexity
- Both approaches: O(n + m) time.
- Stack: O(n + m) space. Two pointer: O(1) space.

## Edge Cases
- Empty strings.
- Strings with only backspaces.
- More backspaces than characters.

## Optimization Notes
- The two-pointer approach is optimal for space.
