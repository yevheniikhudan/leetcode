# Tutorial: Monotonic Array

## Understanding the Problem
A monotonic array is one that is entirely non-increasing or non-decreasing. The task is to check if the input array satisfies either property.

## Visual Example
- [1, 2, 2, 3] → monotone increasing (true)
- [6, 5, 4, 4] → monotone decreasing (true)
- [1, 3, 2] → not monotonic (false)

## Approaches
### 1. Single Pass with Flags (Most Efficient)
- Use two boolean flags: one for increasing, one for decreasing.
- Traverse the array once, updating flags based on adjacent comparisons.
- If both flags become false, the array is not monotonic.
- Time: O(n), Space: O(1)

### 2. Two Separate Passes
- Check for monotone increasing in one pass, then monotone decreasing in another.
- Return true if either check passes.
- Time: O(n), Space: O(1)

## Complexity
- All approaches: O(n) time, O(1) space.

## Edge Cases
- Arrays of length 0 or 1 are monotonic by definition.
- Arrays with all equal elements are monotonic.

## Optimization Notes
- The single-pass approach is preferred for efficiency and clarity.
