# Tutorial: Minimum Distance Between Three Equal Elements II

## Understanding the Problem

We need to find **three occurrences of the same value** in an array and minimize the distance between the first and last occurrence. The distance is defined as: `rightmost_index - leftmost_index`.

**Core insight:** For any three equal elements at indices `i < j < k`, the distance is `k - i`. The middle position `j` doesn't directly affect the distance—it just validates that we have at least three occurrences.

**Goal:** Among all possible triplets of equal values, find the one with the smallest distance.

---

## Approach 1: Grouped Indices with Sliding Window (OPTIMAL ✅)

### Concept

1. **Group all indices by their values** in a hash map or dictionary
2. For each unique value that appears **at least 3 times**:
   - Extract the list of indices where that value appears
   - Use a **sliding window of size 3** over these indices
   - For each window, calculate: `distance = last_index - first_index`
3. Track the **minimum distance** across all values and windows

### Why This Approach Works

- **Key optimization:** We only need to check **consecutive triplets** in each value's index list
- Why? If we skip any occurrences, the distance can only increase
- **Pruning:** If a value appears fewer than 3 times, skip it entirely
- **Sliding window principle:** For indices `[a, b, c, d, e]`, windows are `(a,b,c)`, `(b,c,d)`, `(c,d,e)`—each window captures the tightest span for that specific position

### Visual Example 1: Basic Case
```
Array: [1, 1, 1, 1, 1]
Indices of value 1: [0, 1, 2, 3, 4]

Sliding windows of size 3:
  Window 1: indices [0, 1, 2] → distance = 2 - 0 = 2
  Window 2: indices [1, 2, 3] → distance = 3 - 1 = 2
  Window 3: indices [2, 3, 4] → distance = 4 - 2 = 2

Minimum distance = 2
```

### Visual Example 2: Mixed Values
```
Array: [3, 1, 3, 2, 3, 1, 3, 1]
Index:  [0, 1, 2, 3, 4, 5, 6, 7]

Indices of 1: [1, 5, 7]
  Single window: [1, 5, 7] → distance = 7 - 1 = 6

Indices of 2: [3]
  Only 1 occurrence, skip

Indices of 3: [0, 2, 4, 6]
  Window 1: [0, 2, 4] → distance = 4 - 0 = 4
  Window 2: [2, 4, 6] → distance = 6 - 2 = 4

Minimum distance = 4 (from value 3)
```

### Complexity Analysis

**Time Complexity: O(n)**
- Single pass to group indices: O(n)
- For each unique value with 3+ occurrences, slide through its indices: O(count)
- Total sliding across all values: O(n)
- Overall: O(n)

**Space Complexity: O(n)**
- Hash map stores all indices for each unique value
- Worst case: all elements are unique or all are the same
- In either case: O(n) space

### Why This Is Optimal

For this problem, you cannot do better than O(n) because you must examine every element at least once to determine which values appear three or more times.

---

## Approach 2: Two-Pointer Tracking (Space-Optimized Alternative)

### Concept

Instead of storing all indices upfront, maintain **rolling pointers** as you iterate through the array:
- For each unique value, track the **positions of its last two occurrences**
- When you encounter that value a third time, calculate the distance immediately
- Update your tracking as you continue iterating

### How It Works (Conceptually)

For each element in the array:
1. Check if we've seen this value at least twice before
2. If yes, calculate: `current_index - oldest_tracked_index`
3. Update the tracking pointers for this value:
   - Shift the oldest pointer to the second-most-recent
   - Shift the second pointer to the current position
4. Continue until you've processed the entire array

### Visual Example
```
Array: [1, 2, 1, 2, 1, 2]
Index:  [0, 1, 2, 3, 4, 5]

Processing:
- Index 0 (value 1): First occurrence, track position 0
- Index 1 (value 2): First occurrence, track position 1
- Index 2 (value 1): Second occurrence, track position 2
- Index 3 (value 2): Second occurrence, track position 3
- Index 4 (value 1): THIRD occurrence! Distance = 4 - 0 = 4. Update tracking to [2, 4]
- Index 5 (value 2): THIRD occurrence! Distance = 5 - 1 = 4. Update tracking to [3, 5]

Minimum distance = 4
```

### Complexity Analysis

**Time Complexity: O(n)**
- Single pass through the array
- Constant-time operations per element

**Space Complexity: O(1) or O(100)**
- Since `1 ≤ nums[i] ≤ 100`, use a fixed-size array
- Each entry stores two indices: previous position and current position
- Total: 100 × 2 = 200 integers = O(1) space

### When to Use

This approach is ideal when:
- Space is critical (embedded systems, memory constraints)
- You want to minimize auxiliary storage
- You prefer a more elegant, single-pass solution

---

## Approach 3: Brute Force (Not Recommended ❌)

### Concept

Check all possible triplets `(i, j, k)` where `i < j < k` and `nums[i] == nums[j] == nums[k]`.

### How It Works

Three nested loops:
- Outer loop: `i` from 0 to n-3
- Middle loop: `j` from i+1 to n-2
- Inner loop: `k` from j+1 to n-1
- If all three values match, calculate distance and track minimum

### Complexity Analysis

**Time Complexity: O(n³)**
- Three nested loops in worst case (all elements are the same)
- Impractical for arrays with up to 500,000 elements

**Space Complexity: O(1)**
- Only a few variables to track minimum distance

### Why It's Inefficient

For an array of 500,000 identical elements:
- Brute force: ~1.25 × 10¹⁶ operations 🐢
- Optimal approaches: ~500,000 operations 🚀

---

## Key Concepts and Patterns

### 1. **Index Grouping**
Group indices by value to independently process each unique element. This reduces the problem size for sparse data.

### 2. **Sliding Window on Indices**
Apply a fixed-size window to the **sequence of indices**, not the original array. This guarantees we find the tightest span.

### 3. **The Middle Element Doesn't Matter**
For three elements at indices `a < b < c`:
- Distance = `c - a`
- The value at `b` only matters for validation (ensuring we have three equal values)
- It doesn't minimize or maximize the distance

### 4. **Greedy Minimization**
Once we identify positions where a value appears, the **consecutive triplets** form the only candidates we need to check. Skipping positions only increases distance.

---

## Edge Cases and Common Pitfalls

### Edge Case 1: Fewer Than Three Equal Elements
```
Array: [1, 2, 3, 4, 5]
Result: -1 (no value appears 3+ times)
```
**Pitfall:** Forgetting to return -1 if no valid triplet exists.

### Edge Case 2: Exactly Three Equal Elements
```
Array: [1, 1, 1]
Result: 2 (distance = 2 - 0 = 2)
```
**Pitfall:** Calculating distance incorrectly. It's NOT the count of elements but the index difference.

### Edge Case 3: Very Large Arrays with Few Duplicates
```
Array: [1, 2, 3, ..., 100, 1, 2, 3, ..., 100, 1]
Result: Depends on the span of triplets
```
**Pitfall:** Using brute force here will timeout. Must use Approach 1 or 2.

### Edge Case 4: Minimum Possible Distance
```
Array: [1, 1, 1, ...]
Result: 2 (three consecutive elements at indices 0, 1, 2)
```
**Optimization:** If you ever find a distance of 2, you can return immediately—it's impossible to do better.

### Edge Case 5: All Elements Are Different
```
Array: [1, 2, 3, 4, 5, 6]
Result: -1 (no duplicates at all)
```
**Pitfall:** Handling the no-duplicates case correctly.

---

## Common Mistakes

### Mistake 1: Checking All Combinations
❌ **Wrong:** Loop through all triplets in the index list
```
For value with indices [0, 5, 10, 15]:
  Check (0, 5, 10), (0, 5, 15), (0, 10, 15), (5, 10, 15)
```
✅ **Right:** Only check consecutive triplets
```
  Check (0, 5, 10), (5, 10, 15)
```

### Mistake 2: Confusing Distance Formula
❌ **Wrong:** `distance = j - i + k - j` (adds distances separately)
✅ **Right:** `distance = k - i` (span from first to last)

### Mistake 3: Not Handling the -1 Case
❌ **Wrong:** Return any non-negative number even if no triplet exists
✅ **Right:** Explicitly return -1 if no value appears 3+ times

### Mistake 4: Off-by-One Errors in Sliding Window
❌ **Wrong:** Window goes from index 0 to length-2 (missing last valid window)
✅ **Right:** Window goes from index 0 to length-3 (inclusive)

---

## Optimization Notes

### Optimization 1: Early Exit
```
Once minimum distance = 2, return immediately.
Why? Three consecutive elements at indices i, i+1, i+2 have distance 2.
No triplet can have a smaller distance.
```

### Optimization 2: Value Range Constraint
Since `1 ≤ nums[i] ≤ 100`:
- Use a fixed-size array instead of a hash map
- Provides better cache locality
- Slightly faster than dictionary lookups

### Optimization 3: Single Pass with Rolling Pointers
Avoid building the entire index list upfront—track positions as you scan.
This reduces memory usage and can terminate earlier in some cases.

### Optimization 4: Prune Small Counts Early
If you've grouped indices and a value has fewer than 3 occurrences, don't create a window—skip it entirely.

---

## Complexity Comparison

| Approach | Time | Space | Practical |
|----------|------|-------|-----------|
| Grouped + Sliding Window | O(n) | O(n) | ✅ Excellent |
| Two-Pointer Tracking | O(n) | O(1) | ✅ Excellent |
| Brute Force | O(n³) | O(1) | ❌ Only small n |

---

## Summary Strategy

1. **Use Approach 1** for clarity and straightforward implementation
2. **Use Approach 2** if space is a constraint or you want elegance
3. **Avoid Approach 3** unless solving on paper or for very small inputs

**Recommended:** Approach 1 (Grouped Indices with Sliding Window)
- Easy to understand and debug
- Optimal time complexity
- Clear separation of concerns (grouping, then calculating)