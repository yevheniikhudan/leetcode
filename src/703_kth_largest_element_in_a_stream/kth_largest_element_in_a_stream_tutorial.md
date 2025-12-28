# 703. Kth Largest Element in a Stream — Tutorial

## Approach

The optimal solution uses a min-heap (priority queue) of size k. The heap always contains the k largest elements seen so far. The root of the heap is the kth largest element.

- On initialization, add all elements from `nums` to the heap. If the heap size exceeds k, remove the smallest.
- On each `add(val)`, insert `val` into the heap. If the heap size exceeds k, remove the smallest. Return the root (top) of the heap.

## Complexity
- Initialization: O(n log k) for n = nums.length
- Each add: O(log k)

## Example
```
k = 3, nums = [4,5,8,2]
Initial heap: [4,5,8]
add(3): [4,5,8] -> returns 4
add(5): [5,5,8] -> returns 5
add(10): [5,8,10] -> returns 5
add(9): [8,9,10] -> returns 8
```

## Edge Cases
- k > nums.length: heap will be filled as new elements are added.
- Negative numbers and duplicates are handled naturally by the heap.
