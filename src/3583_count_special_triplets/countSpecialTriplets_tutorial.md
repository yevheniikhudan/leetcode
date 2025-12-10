# Count Special Triplets - Tutorial

## Problem Understanding

We need to find triplets `(i, j, k)` where:
1. `i < j < k` (strictly increasing indices)
2. `nums[i] = nums[j] * 2` (element at i is double the middle element)
3. `nums[k] = nums[j] * 2` (element at k is also double the middle element)

In other words: **nums[i] = nums[k] = nums[j] * 2**

## Key Insights

### 1. Fix the Middle Element

The most efficient approach is to iterate through each index `j` as the **middle element** of the triplet:
- Count how many elements **before** `j` equal `nums[j] * 2`
- Count how many elements **after** `j` equal `nums[j] * 2`
- Multiply these counts (for each combination of left and right)

### 2. Use Frequency Maps

For each position `j`:
- **Left frequency map**: Count occurrences of each value from index `0` to `j-1`
- **Right frequency map**: Count occurrences of each value from index `j+1` to `n-1`

### 3. Multiplication Principle

If there are:
- `left_count` elements equal to `nums[j] * 2` before index `j`
- `right_count` elements equal to `nums[j] * 2` after index `j`

Then the number of special triplets with `j` as the middle is:
**`left_count * right_count`**

## Algorithm Strategy

### Approach 1: Brute Force O(n³)
```
For each i from 0 to n-3:
    For each j from i+1 to n-2:
        For each k from j+1 to n-1:
            If nums[i] == nums[j] * 2 and nums[k] == nums[j] * 2:
                count++
```
**Time**: O(n³), **Space**: O(1)

### Approach 2: Hash Map Optimization O(n²)

**Step 1: Precompute Right Frequencies**
- Create a frequency map of all elements from index 1 to n-1

**Step 2: Iterate Through Middle Elements**
- For each `j` from 1 to n-2:
  - Get `target = nums[j] * 2`
  - Get `leftCount = freqLeft[target]` (how many targets before j)
  - Get `rightCount = freqRight[target]` (how many targets after j)
  - Add `leftCount * rightCount` to the answer
  - Update maps: move `nums[j-1]` from left map, remove `nums[j]` from right map

**Time**: O(n), **Space**: O(n)

## Example Walkthrough

**Input:** nums = [8, 4, 2, 8, 4]

**Initial State:**
- `freqRight` = {4: 1, 2: 1, 8: 1, 4: 1} → {2: 1, 4: 2, 8: 1}

**Process each j:**

**j = 1** (nums[1] = 4, target = 8):
- `freqLeft` = {8: 1}
- `freqRight` = {2: 1, 8: 1, 4: 1}
- leftCount = 1 (one 8 before)
- rightCount = 1 (one 8 after)
- count += 1 * 1 = 1

**j = 2** (nums[2] = 2, target = 4):
- `freqLeft` = {8: 1, 4: 1}
- `freqRight` = {8: 1, 4: 1}
- leftCount = 1 (one 4 before)
- rightCount = 1 (one 4 after)
- count += 1 * 1 = 1

**j = 3** (nums[3] = 8, target = 16):
- `freqLeft` = {8: 1, 4: 1, 2: 1}
- `freqRight` = {4: 1}
- leftCount = 0 (no 16 before)
- rightCount = 0 (no 16 after)
- count += 0

**Total:** 2 triplets ✓

## Edge Cases

1. **Zero values**: `0 * 2 = 0`, so triplets like (0, 0, 0) are valid
2. **No valid triplets**: Return 0
3. **Minimum length (n=3)**: Only one possible triplet to check
4. **All same values**: Only valid if all are 0

## Complexity Analysis

### Optimized Approach:
- **Time Complexity**: O(n) - single pass through array
- **Space Complexity**: O(n) - for frequency maps

### Why This is Optimal:
- We must examine each potential middle element → at least O(n)
- Using hash maps allows O(1) lookups
- Total: O(n) time with O(n) space
