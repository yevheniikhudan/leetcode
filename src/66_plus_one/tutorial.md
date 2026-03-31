# Plus One — Tutorial

Difficulty: Easy

This tutorial explains the conceptual approaches to solving LeetCode 66 "Plus One". It intentionally contains no code — only explanations, trade-offs, and guidance for implementing and testing correct solutions.

## Problem recap
You are given a non-empty array of digits representing a non-negative integer. The most significant digit is at index 0. Add one to the integer and return the resulting array of digits. The input contains no leading zeros except for the number zero itself.

Example behavior:
- [1, 2, 3] → [1, 2, 4] (123 + 1 = 124)
- [9, 9] → [1, 0, 0] (99 + 1 = 100)

## Key idea
Perform addition with carry starting from the least significant digit (the end of the array). Propagate any carry leftwards. If a carry survives past the most significant digit, allocate a new leading digit (1) and set the rest accordingly.

Because each element stores a single decimal digit (0–9), adding one produces at most a single-digit increment and a carry of 0 or 1 at each step. You do not need big-integer arithmetic; a single-pass, constant-space algorithm is sufficient.

## Approaches (conceptual)

1. In-place right-to-left with carry (recommended)
   - Start from the last index and add one to that digit.
   - Compute new digit and carry: new_digit = (digit + carry) % 10, carry = (digit + carry) // 10.
   - Write the computed digit back into the array.
   - Move left until carry is 0 or you processed all digits.
   - If carry remains after processing index 0, insert 1 at the front (or construct a new array with leading 1).
   - Complexity: O(n) time, O(1) extra space if modifying in place (ignoring output size).

2. Build a new array in reverse
   - Iterate from the end, compute digits with carry and push them into a result list.
   - After processing, reverse the result to get the final digits.
   - This is simple and avoids in-place modifications but uses O(n) extra space.
   - Complexity: O(n) time, O(n) space.

3. Convert to number, add 1, convert back (not recommended)
   - Convert digits to a numeric type (string or integer), add one, then convert back to digits.
   - This approach is fragile due to overflow and unnecessary for this problem's constraints; avoid in interviews.

## Edge cases and gotchas
- Single-digit zero: [0] → [1].
- All nines: [9], [9,9], [9,9,9] → should produce an extra leading digit [1,0], [1,0,0], [1,0,0,0].
- Leading zeros are not expected in input (except [0]); do not try to preserve or normalize them.
- Very long arrays: algorithm must be linear in length; avoid numeric conversions that might overflow.
- Mutating input: If test harness reuses input arrays, clone before modifying when necessary.

## Complexity
- Time: O(n), where n is the number of digits. Each digit is visited at most once.
- Space: O(1) extra space for in-place approach (excluding the returned array). O(n) extra space if creating a new array.

## Testing suggestions
Include tests that cover:
- Typical case: [1,2,3] → [1,2,4]
- Trailing carry but not full overflow: [1,2,9] → [1,3,0]
- Full overflow: [9,9] → [1,0,0]
- Single-digit cases: [0] → [1], [9] → [1,0]
- Large input length to validate performance and no overflow

When writing test scaffolding, print results in the project's expected format:
actual | expected | PASS/FAIL

## Implementation tips
- Prefer iterating with integer indices rather than converting to strings for performance and clarity.
- When inserting at the front for the all-9 case, prefer constructing a new array [1] + zeros or using vector/list insert operations that are efficient for the target language.
- Keep code short and readable; the algorithm is simple and intended to be straightforward in interviews.

## When to choose which approach
- Interview / in-place preference: use the in-place carry propagation (best balance of clarity and efficiency).
- When immutability / pure functions are required: use the reverse-build approach and return a new array.
- Avoid numeric conversion approaches except for quick prototyping in non-constrained settings.

(End of tutorial)