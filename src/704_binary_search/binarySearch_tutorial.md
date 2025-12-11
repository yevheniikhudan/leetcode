# Binary Search - Tutorial

## Problem Understanding

Binary Search is a fundamental algorithm used to efficiently search for a target value in a **sorted array**. Instead of checking every element (linear search), binary search repeatedly divides the search space in half, achieving logarithmic time complexity.

## The Core Idea

Think of how you find a word in a dictionary:
1. Open the dictionary in the middle
2. If your word comes before the middle word, search the left half
3. If your word comes after the middle word, search the right half
4. Repeat until you find the word or run out of pages

This is exactly how binary search works!

## Algorithm Explanation

### Step-by-Step Process:

1. **Initialize two pointers:**
   - `left = 0` (start of array)
   - `right = n - 1` (end of array)

2. **While left ≤ right:**
   - Calculate middle index: `mid = left + (right - left) / 2`
   - Compare `nums[mid]` with `target`:
     - If `nums[mid] == target`: Found! Return `mid`
     - If `nums[mid] < target`: Search right half (`left = mid + 1`)
     - If `nums[mid] > target`: Search left half (`right = mid - 1`)

3. **If loop ends:** Target not found, return `-1`

### Why `left + (right - left) / 2`?

While `(left + right) / 2` seems simpler, it can cause integer overflow when `left + right` exceeds the maximum integer value. The formula `left + (right - left) / 2` is mathematically equivalent but avoids overflow.

## Visual Example

Search for `target = 9` in `nums = [-1, 0, 3, 5, 9, 12]`:

```
Initial: left = 0, right = 5
         [-1, 0, 3, 5, 9, 12]
          L        M        R

Step 1: mid = 2, nums[2] = 3
        3 < 9, so search right half
        left = 3

         [-1, 0, 3, 5, 9, 12]
                    L  M  R

Step 2: mid = 4, nums[4] = 9
        9 == 9, found! Return 4
```

## Search for `target = 2` (not in array):

```
Initial: left = 0, right = 5
         [-1, 0, 3, 5, 9, 12]
          L        M        R

Step 1: mid = 2, nums[2] = 3
        3 > 2, so search left half
        right = 1

         [-1, 0, 3, 5, 9, 12]
          L  M  R

Step 2: mid = 0, nums[0] = -1
        -1 < 2, so search right half
        left = 1

         [-1, 0, 3, 5, 9, 12]
              L/R

Step 3: mid = 1, nums[1] = 0
        0 < 2, so search right half
        left = 2

         [-1, 0, 3, 5, 9, 12]
                 R L

Now left > right, loop ends. Return -1 (not found)
```

## Loop Invariants

Understanding loop invariants helps ensure correctness:

### Invariant 1: Search space is `[left, right]` (inclusive)
- Initially: entire array `[0, n-1]`
- Each iteration: reduce search space by half
- When `left > right`: search space is empty, target not found

### Invariant 2: Target, if exists, is within `[left, right]`
- We only move `left` or `right` when we know target is NOT in the excluded half
- This guarantees we never "skip over" the target

## Common Variations

### 1. Different Mid Calculation
```python
# Method 1: Avoid overflow (recommended)
mid = left + (right - left) // 2

# Method 2: Simple but may overflow
mid = (left + right) // 2

# Method 3: Bit shift (same as method 1)
mid = left + ((right - left) >> 1)
```

### 2. Different Loop Conditions

**Variation A: `while left <= right`** (Most common)
- Search space: `[left, right]` inclusive
- Exit: `left > right`
- Update: `left = mid + 1` or `right = mid - 1`

**Variation B: `while left < right`**
- Search space: `[left, right)` right-exclusive
- Exit: `left == right`
- Update: `left = mid + 1` or `right = mid`
- Need to check `nums[left]` after loop

### 3. Finding Lower/Upper Bound

Binary search can be adapted to find:
- First occurrence of target (leftmost)
- Last occurrence of target (rightmost)
- Insertion position

## Edge Cases

1. **Empty array**: Not possible per constraints (`nums.length >= 1`)
2. **Single element**: Works correctly
   - If match: return 0
   - If no match: return -1
3. **Target at boundaries**:
   - First element: `nums[0]`
   - Last element: `nums[n-1]`
4. **Target smaller than all elements**: Returns -1
5. **Target larger than all elements**: Returns -1
6. **Two elements**: Works correctly

## Common Pitfalls

1. **Off-by-one errors:**
   - Using `right = n` instead of `right = n - 1`
   - Updating with `left = mid` or `right = mid` (infinite loop!)

2. **Integer overflow:**
   - Using `(left + right) / 2` with large indices

3. **Wrong loop condition:**
   - Using `while left < right` but updating with `mid + 1` / `mid - 1`
   - Inconsistent with loop invariant

4. **Not handling target not found:**
   - Forgetting to return -1 after loop

## Time and Space Complexity

**Time Complexity:** O(log n)
- Each iteration reduces search space by half
- After k iterations: n / 2^k elements remain
- When 1 element remains: n / 2^k = 1 → k = log₂(n)

**Space Complexity:** O(1)
- Only uses constant extra space (pointers and variables)
- Iterative approach (recursive would be O(log n) for call stack)

## When to Use Binary Search

Binary search applies when:
1. ✅ Array is **sorted** (or can be sorted)
2. ✅ Need **O(log n)** search time
3. ✅ Array has **random access** (indexed access)

Don't use when:
1. ❌ Array is unsorted and can't be sorted
2. ❌ Linked list (no O(1) random access)
3. ❌ Small array where O(n) is acceptable

## Key Takeaways

1. **Binary search is O(log n)** - Extremely efficient for large arrays
2. **Array must be sorted** - Essential prerequisite
3. **Use `left + (right - left) / 2`** - Avoids overflow
4. **Be consistent with loop invariants** - Prevents off-by-one errors
5. **Master the pattern** - Foundation for many advanced problems

Binary search is one of the most important algorithms in computer science. Master this pattern, as it appears in countless variations in interviews and real-world applications!
