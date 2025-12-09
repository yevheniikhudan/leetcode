# Remove Duplicates from Sorted Array - Tutorial

## Problem Understanding

Given a sorted array, remove duplicates in-place so that each unique element appears only once. Return the number of unique elements. The first k elements of the array should contain the unique elements in sorted order.

## Key Insights

1. **Sorted Array**: Duplicates are adjacent, so you can process the array in one pass.
2. **In-place Modification**: You must not use extra space for another array.
3. **Two-Pointer Technique**: Use one pointer to track the position to write the next unique element, and another to scan the array.

## Approach

- Initialize a write pointer `k = 0`.
- Iterate through the array with a read pointer `i`.
- For each element, if it is different from the previous unique element, write it at position `k` and increment `k`.
- Return `k` at the end.

## Example Walkthrough

nums = [0,0,1,1,1,2,2,3,3,4]

- Start: k = 0
- i = 0: nums[0] = 0 (write 0 at k=0, k++)
- i = 1: nums[1] = 0 (skip)
- i = 2: nums[2] = 1 (write 1 at k=1, k++)
- i = 3: nums[3] = 1 (skip)
- i = 4: nums[4] = 1 (skip)
- i = 5: nums[5] = 2 (write 2 at k=2, k++)
- i = 6: nums[6] = 2 (skip)
- i = 7: nums[7] = 3 (write 3 at k=3, k++)
- i = 8: nums[8] = 3 (skip)
- i = 9: nums[9] = 4 (write 4 at k=4, k++)
- End: k = 5

## Edge Cases
- Array of length 1: Always return 1
- All elements are the same: Return 1
- No duplicates: Return length of array

## Common Mistakes
- Not handling the first element correctly
- Using extra space
- Not updating the write pointer

## Optimization Tips
- Only write when a new unique element is found
- Use the sorted property to skip duplicates efficiently

## Time Complexity
- O(n) for one pass

## Space Complexity
- O(1) extra space
