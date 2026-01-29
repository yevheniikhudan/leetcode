# Tutorial: Maximum Product Subarray

## Understanding the Problem
The Maximum Product Subarray problem asks to find the contiguous subarray within a one-dimensional array of numbers that has the largest product. Unlike the maximum sum subarray, negative numbers complicate this because two negatives can make a positive product, and zeros can reset the product.

This is a variation of the classic maximum subarray problem but with multiplication instead of addition, requiring careful handling of negative numbers and zeros.

## Visual Examples
- **Example 1:** nums = [2,3,-2,4]
  - Subarrays: [2]→2, [2,3]→6, [2,3,-2]→-12, [2,3,-2,4]→24, [3]→3, [3,-2]→-6, [3,-2,4]→-24, [-2]→-2, [-2,4]→-8, [4]→4
  - Maximum is 6 from [2,3]

- **Example 2:** nums = [-2,0,-1]
  - Subarrays: [-2]→-2, [-2,0]→0, [-2,0,-1]→0, [0]→0, [0,-1]→0, [-1]→-1
  - Maximum is 0 from [0] or subarrays including 0

## Multiple Approaches

### 1. Dynamic Programming (Optimal) - Most Efficient
Track the maximum and minimum product ending at each position.
- Use two variables: max_so_far and min_so_far
- For each number, update max_so_far and min_so_far considering the current number and its products with previous max/min
- Time: O(n), Space: O(1)

### 2. Brute Force
Check all possible subarrays and compute their products.
- Nested loops to generate all subarrays
- Keep track of the maximum product
- Time: O(n^2), Space: O(1) - too slow for n=2*10^4

### 3. Divide and Conquer
Split the array and find maximum in left, right, and crossing subarrays.
- Recursively solve for halves
- Handle crossing by multiplying from center outwards
- Time: O(n log n), Space: O(log n) - more complex than DP

## Time/Space Complexity Analysis
- **DP:** O(n) time, O(1) space - best for interviews
- **Brute Force:** O(n^2) time, O(1) space - acceptable for small n
- **Divide and Conquer:** O(n log n) time, O(log n) space - overkill

## Key Concepts and Patterns
- **Negative Numbers:** Can turn minimum into maximum (two negatives)
- **Zeros:** Reset products, subarrays can't cross zeros unless zero is included
- **Single Elements:** Always consider individual elements as valid subarrays
- **Kadane's Algorithm Variation:** Similar to maximum sum but with product logic

## Edge Cases and Common Pitfalls
- **All Positive:** Simple, just the whole array
- **All Negative:** The largest single negative number
- **Contains Zero:** Zero is a candidate, splits the array
- **Single Element:** Just that element
- **Empty Array:** Not possible per constraints
- **Large Numbers:** Products fit in 32-bit, no overflow worries
- **Pitfall:** Forgetting to reset on zero or handle negatives properly

## Optimization Notes
- DP is the way to go for efficiency and simplicity
- Handle negatives by tracking both max and min products
- Zeros naturally reset the running products
- For very large arrays, O(n) is necessary
