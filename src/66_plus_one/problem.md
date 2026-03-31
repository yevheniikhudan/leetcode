# 66. Plus One

Difficulty: Easy

## Problem

Given a non-empty array of decimal digits representing a non-negative integer, increment the integer by one and return the resulting array of digits.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit. You may assume the integer does not contain any leading zero, except the number 0 itself.

Return the resulting array of digits after adding one.

## Examples

Example 1:
Input: [1, 2, 3]  
Output: [1, 2, 4]  
Explanation: 123 + 1 = 124.

Example 2:
Input: [4, 3, 2, 1]  
Output: [4, 3, 2, 2]  
Explanation: 4321 + 1 = 4322.

Example 3:
Input: [9]  
Output: [1, 0]  
Explanation: 9 + 1 = 10.

Example 4:
Input: [9, 9]  
Output: [1, 0, 0]  
Explanation: 99 + 1 = 100.

Example 5:
Input: [0]  
Output: [1]  
Explanation: 0 + 1 = 1.

## Constraints

- 1 <= digits.length <= 100  
- 0 <= digits[i] <= 9  
- digits does not contain leading zeros except for the number 0 itself.

## Tags

Array, Math, Simulation

## Related Problems

- 67. Add Binary  
- 989. Add to Array-Form of Integer  
- 66. (this problem) — typical in-place carry propagation

## Notes & Approaches (conceptual, tutorial-style)

1. In-place right-to-left carry propagation (recommended)
   - Traverse the array from the last index to the first. Add 1 to the current digit and compute new digit and carry:
     - new_digit = (digit + carry) % 10
     - carry = (digit + carry) // 10
   - Update the digit in place. Stop early once carry becomes 0.
   - If a carry remains after processing the most significant digit, insert 1 at the front (or construct a new array beginning with 1 followed by the current digits).
   - Time: O(n), Space: O(1) additional (in-place).

2. Build a new array in reverse
   - If immutability is preferred, build the result by processing digits from right to left, pushing computed digits to a temporary vector/list, then reverse it.
   - Time: O(n), Space: O(n).

3. Edge cases
   - Single-digit input 9 → [1, 0].
   - All 9s → [1, 0, 0, ..., 0].
   - Input [0] → [1].

4. Implementation tips
   - Avoid converting the entire digits list into a numeric type; this can overflow and is unnecessary.
   - Keep arithmetic and array manipulation simple and constant-space where possible.

## Example I/O for Local Testing

A typical test harness prints results in the format:

```
actual | expected | PASS/FAIL
```

For example:
```
[1,2,4] | [1,2,4] | PASS
[1,0] | [1,0] | PASS
```

(End of file)