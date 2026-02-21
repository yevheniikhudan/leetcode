# Tutorial: Valid Parenthesis String (LeetCode 678)

## Understanding the problem
We need to determine whether a string containing `(`, `)`, and `*` can be interpreted as a valid parentheses string. The wildcard `*` is flexible: it can be treated as `(`, `)`, or an empty string. The goal is to decide if any assignment of `*` yields a valid parentheses sequence.

## Key ideas
- A valid parentheses sequence must have matching open and close parentheses in order.
- The wildcard `*` introduces ambiguity; treat it as a resource that can help balance parentheses as needed.

## Approaches (conceptual, no code)

1. Greedy range tracking
- Maintain a range `[low, high]` representing the possible number of unmatched `(` after processing a prefix:
  - `low` is the minimum possible unmatched `(` (treating `*` as `)` where helpful).
  - `high` is the maximum possible unmatched `(` (treating `*` as `(`).
- Update the range for each character:
  - If char is `(`: `low += 1`, `high += 1`.
  - If char is `)`: `low = max(0, low - 1)`, `high -= 1`.
  - If char is `*`: `low = max(0, low - 1)`, `high += 1`.
- If `high < 0` at any point, return false (too many `)` even under best-case `*`).
- After processing all characters, string is valid if `low == 0` (there exists an assignment making unmatched `(` zero).

This approach is O(n) time and O(1) space and is the most efficient.

2. Two-pass greedy (left-to-right and right-to-left)
- First pass: Treat `*` as `)` when possible and ensure not too many `)`.
- Second pass: Reverse roles and ensure not too many `(`.
- If both passes succeed, string is valid.

3. Stack-based approach
- Use stacks to track positions of `(` and `*`.
- When encountering `)` try to match with `(`, otherwise use a `*` as `(`.
- After processing, ensure remaining `(` can be matched by `*` to their right (index comparison).
- This is O(n) time and O(n) space.

4. Dynamic programming
- DP can model possibilities but is overkill here and typically O(n^2) or worse.

## Time and Space Complexity
- Optimal greedy: O(n) time, O(1) space.
- Stack solution: O(n) time, O(n) space.
- DP: higher time/space complexity.

## Edge Cases and Pitfalls
- Strings with length 1: `*` is valid, `(` or `)` are invalid.
- Excessive `)` early in the string should return false quickly.
- Making sure `low` never goes below 0 after adjustments.

## Optimization Notes
- Prefer the greedy `[low, high]` approach: simple and optimal.
- Validate indices carefully in stack method to avoid mismatching order.

## When to use which approach
- Use greedy range tracking for production due to minimal memory and linear time.
- Use stack approach if explicit matching is needed for debugging or tracing assignments.
