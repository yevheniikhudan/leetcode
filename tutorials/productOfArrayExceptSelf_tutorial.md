# Product of Array Except Self - Tutorial

## Problem Understanding

Given an array, for each index, return the product of all other elements except itself. You must do this in O(n) time and without using division.

## Key Insights

1. **Prefix and Suffix Products**: For each index, the answer is the product of all elements to the left (prefix) and all elements to the right (suffix).
2. **No Division**: You cannot compute the total product and divide by nums[i].
3. **O(n) Time, O(1) Extra Space**: You can compute prefix products in one pass, then suffix products in another pass, reusing the output array.

## Approach

### Step 1: Compute Prefix Products
- For each index i, store the product of all elements to the left of i.
- Initialize answer[0] = 1 (no elements to the left).
- For i from 1 to n-1: answer[i] = answer[i-1] * nums[i-1]

### Step 2: Compute Suffix Products
- Traverse from right to left, maintaining a running product of all elements to the right.
- Multiply answer[i] by the running suffix product.
- Initialize suffix = 1.
- For i from n-1 to 0: answer[i] *= suffix; suffix *= nums[i]

### Example Walkthrough

nums = [1,2,3,4]

- Prefix pass:
  - answer = [1, 1, 2, 6]
- Suffix pass:
  - i = 3: answer[3] *= 1 → 6
  - i = 2: answer[2] *= 4 → 8
  - i = 1: answer[1] *= 12 → 12
  - i = 0: answer[0] *= 24 → 24
- Final answer: [24, 12, 8, 6]

### Edge Cases
- Zeros in the array: If there are multiple zeros, all products are zero. If one zero, only the position of the zero is nonzero.
- Negative numbers: Handled naturally by multiplication.

## Common Mistakes
- Using division (not allowed)
- Not handling zeros correctly
- Not reusing the output array for space optimization

## Optimization Tips
- Use the output array for prefix products
- Use a single variable for suffix products
- Avoid extra arrays for O(1) space

## Time Complexity
- O(n) for two passes

## Space Complexity
- O(1) extra space (output array not counted)
