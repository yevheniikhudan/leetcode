# Sliding Window Maximum - Tutorial

## Problem Understanding

Given an array and a window size k, we need to find the maximum value in each possible window of size k as it slides from left to right through the array.

**Key Observations:**
- The window moves one position at a time
- We need to return an array of maximums (one for each window position)
- The number of windows = `nums.length - k + 1`
- We need an efficient way to track the maximum as elements enter/exit the window

## Approach 1: Brute Force (Not Optimal)

**Idea:** For each window position, scan all k elements to find the maximum.

**Time Complexity:** O(n * k) - Too slow for large inputs  
**Space Complexity:** O(1) excluding output array

**Why it's inefficient:** We recalculate the maximum from scratch for each window, even though consecutive windows share k-1 elements.

## Approach 2: Using Max Heap/Priority Queue

**Idea:** Maintain a max heap of elements in the current window.

**Process:**
1. Add elements to the heap as the window expands
2. Remove elements that fall outside the window
3. The top of the heap is the window maximum

**Challenges:**
- Most heap implementations don't support efficient removal of arbitrary elements
- Need to track indices along with values to know when elements leave the window
- May contain "stale" elements that are outside the current window

**Time Complexity:** O(n log k) for heap operations  
**Space Complexity:** O(k) for the heap

## Approach 3: Monotonic Deque (Optimal)

**Idea:** Use a deque (double-ended queue) to maintain indices of potentially useful elements in decreasing order of their values.

### What is a Monotonic Deque?

A monotonic deque maintains elements in a specific order (increasing or decreasing). For this problem, we maintain a **decreasing monotonic deque** where:
- Elements are stored in decreasing order of their values
- We store **indices**, not values (to check if they're in the current window)

### Key Properties:

1. **Front of deque = Maximum**: The front always contains the index of the maximum element in the current window
2. **Decreasing order**: If we peek at elements from front to back, their values are in decreasing order
3. **Only useful elements**: We remove elements that can never be the maximum

### Algorithm Steps:

For each element at index `i`:

1. **Remove outdated indices**: Remove indices from the front that are outside the current window (index <= i - k)

2. **Maintain decreasing order**: Remove indices from the back whose values are smaller than the current element (they can never be maximums)

3. **Add current index**: Add the current index to the back of the deque

4. **Record maximum**: Once we've processed at least k elements, the front of the deque is the maximum for this window

### Why This Works:

**Removing smaller elements from the back:**
- If element A enters before element B, and A is smaller than B, A can never be the maximum while B is in the window
- Example: Window [1, 3, -1]. When 3 enters, we remove 1 because:
  - 3 > 1
  - 3 entered later, so it will stay in the window longer
  - While both are in the window, 3 will always be the maximum

**Storing indices instead of values:**
- We need indices to check if elements are still in the current window
- We can look up the value using `nums[index]`

### Example Walkthrough:

```
nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3

i=0, num=1:
  deque: [0]  (value: 1)
  
i=1, num=3:
  Remove 0 (value 1 < 3)
  deque: [1]  (value: 3)
  
i=2, num=-1:
  deque: [1, 2]  (values: 3, -1)
  Window complete! Max = nums[1] = 3 → Output: [3]

i=3, num=-3:
  deque: [1, 2, 3]  (values: 3, -1, -3)
  Max = nums[1] = 3 → Output: [3, 3]

i=4, num=5:
  Remove 1, 2, 3 (all values < 5)
  deque: [4]  (value: 5)
  Max = nums[4] = 5 → Output: [3, 3, 5]

i=5, num=3:
  deque: [4, 5]  (values: 5, 3)
  Max = nums[4] = 5 → Output: [3, 3, 5, 5]

i=6, num=6:
  Remove 4 (outside window: 6-3=3, index 4 > 3 but let's check: i-k=6-3=3, 4>3 ✓)
  Remove 5 (value 3 < 6)
  deque: [6]  (value: 6)
  Max = nums[6] = 6 → Output: [3, 3, 5, 5, 6]

i=7, num=7:
  Remove 6 (value 6 < 7)
  deque: [7]  (value: 7)
  Max = nums[7] = 7 → Output: [3, 3, 5, 5, 6, 7]
```

### Invariants to Maintain:

1. **Front index is in window**: `deque.front() >= i - k + 1`
2. **Decreasing values**: For any two consecutive indices in deque, `nums[earlier] > nums[later]`
3. **All useful candidates**: Every element in deque could potentially be a maximum for some future window

## Time and Space Complexity

**Monotonic Deque Approach:**
- **Time Complexity:** O(n)
  - Each element is added to deque exactly once
  - Each element is removed from deque at most once
  - Total operations: O(n)
  
- **Space Complexity:** O(k)
  - Deque stores at most k indices
  - Output array size is O(n-k+1) but that's required

## Edge Cases to Consider

1. **k = 1**: Each element is its own maximum
2. **k = n**: Only one window containing all elements
3. **All elements equal**: All outputs are the same
4. **Sorted ascending**: Maximum keeps moving right
5. **Sorted descending**: First element is always maximum
6. **Negative numbers**: Algorithm works the same way

## Common Mistakes

1. **Storing values instead of indices**: Can't check if elements are in the window
2. **Not removing outdated indices**: Leads to wrong maximums
3. **Wrong window start condition**: Remember to start outputting after processing k elements (i >= k-1)
4. **Off-by-one errors**: Window boundaries are [i-k+1, i]

## Implementation Tips

1. Use language-specific deque implementations (efficient for both ends)
2. Always store indices in the deque, look up values as needed
3. Process elements in order: remove outdated → maintain monotonic → add current → record result
4. Double-check the window starting position (when i >= k-1)
