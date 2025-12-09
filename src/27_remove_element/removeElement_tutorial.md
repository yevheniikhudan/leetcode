# Remove Element - Tutorial

## Problem Understanding

Given an array and a value, remove all instances of that value in-place and return the new length. The order of elements can change, and elements beyond the new length do not matter.

## Key Insights

1. **In-place Modification**: You must not use extra space for another array.
2. **Two-Pointer Technique**: Use one pointer to track the position to write the next non-val element, and another to scan the array.
3. **Order Doesn't Matter**: You can overwrite elements freely as long as the first k elements are correct.

## Approach

- Initialize a write pointer `k = 0`.
- Iterate through the array with a read pointer `i`.
- For each element, if it is not equal to `val`, write it at position `k` and increment `k`.
- Return `k` at the end.

## Example Walkthrough

nums = [0,1,2,2,3,0,4,2], val = 2

- Start: k = 0
- i = 0: nums[0] = 0 (write 0 at k=0, k++)
- i = 1: nums[1] = 1 (write 1 at k=1, k++)
- i = 2: nums[2] = 2 (skip)
- i = 3: nums[3] = 2 (skip)
- i = 4: nums[4] = 3 (write 3 at k=2, k++)
- i = 5: nums[5] = 0 (write 0 at k=3, k++)
- i = 6: nums[6] = 4 (write 4 at k=4, k++)
- i = 7: nums[7] = 2 (skip)
- End: k = 5

## Edge Cases
- Array of length 0: Always return 0
- All elements are val: Return 0
- No elements are val: Return length of array

## Common Mistakes
- Not handling the first element correctly
- Using extra space
- Not updating the write pointer

## Optimization Tips
- Only write when a non-val element is found
- Use the order-doesn't-matter property to simplify logic

## Time Complexity
- O(n) for one pass

## Space Complexity
- O(1) extra space
