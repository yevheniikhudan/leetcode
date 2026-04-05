# Tutorial: Replace Elements with Greatest Element on Right Side

## Understanding the Problem

We need to transform an array so that each element is replaced by the **maximum value to its right**. The rightmost element becomes `-1` since there are no elements to its right.

### Visual Example

```
Input:  [17, 18,  5,  4,  6,  1]
Output: [18,  6,  6,  6,  1, -1]
         ↓   ↓   ↓   ↓   ↓   ↓
        18   6   6   6   1  -1
        (max right)
```

## Approach 1: Brute Force (Naive) - O(n²)

**Concept:** For each element, scan all elements to its right and find the maximum.

```
For each index i from 0 to n-2:
  - Find maximum in arr[i+1...n-1]
  - Replace arr[i] with that maximum
- Replace arr[n-1] with -1
```

**Why it works:** Simple but inefficient because we're repeating maximum calculations.

**Time Complexity:** O(n²) - nested loops  
**Space Complexity:** O(1) - modifying in-place

---

## Approach 2: Single Pass from Right to Left - O(n) ⭐ OPTIMAL

**Concept:** Traverse the array backwards while keeping track of the maximum seen so far.

```
Key insight: If we go right-to-left, we know all elements to the right of current position!

1. Start from the rightmost element
2. Keep a variable `max_so_far` initialized to -1
3. For each position i (right to left):
   - Store current element value
   - Replace arr[i] with max_so_far (the max of all elements to its right)
   - Update max_so_far = max(max_so_far, current_element)
```

**Why it works:**
- Right-to-left traversal ensures we've already processed all elements to the right
- Single variable tracks the running maximum, so no need to re-scan

**Time Complexity:** O(n) - single pass  
**Space Complexity:** O(1) - in-place modification

---

## Step-by-Step Walkthrough

Given: `[17, 18, 5, 4, 6, 1]`

```
Start: max_so_far = -1

Step 1: i=5 (value=1)
  Replace arr[5] with -1
  Update max_so_far = max(-1, 1) = 1
  Array: [17, 18, 5, 4, 6, -1]

Step 2: i=4 (value=6)
  Replace arr[4] with 1
  Update max_so_far = max(1, 6) = 6
  Array: [17, 18, 5, 4, 1, -1]

Step 3: i=3 (value=4)
  Replace arr[3] with 6
  Update max_so_far = max(6, 4) = 6
  Array: [17, 18, 5, 6, 1, -1]

Step 4: i=2 (value=5)
  Replace arr[2] with 6
  Update max_so_far = max(6, 5) = 6
  Array: [17, 18, 6, 6, 1, -1]

Step 5: i=1 (value=18)
  Replace arr[1] with 6
  Update max_so_far = max(6, 18) = 18
  Array: [17, 6, 6, 6, 1, -1]

Step 6: i=0 (value=17)
  Replace arr[0] with 18
  Update max_so_far = max(18, 17) = 18
  Array: [18, 6, 6, 6, 1, -1]
```

Final Result: `[18, 6, 6, 6, 1, -1]` ✓

---

## Key Concepts

### 1. Right-to-Left Traversal
- Eliminates the need for nested loops
- Ensures all elements to the right are already processed

### 2. In-Place Modification
- Save the current element before overwriting
- Update max_so_far after assignment

### 3. Swapping Values Trick
Some languages allow simultaneous assignment to avoid temp variables:
```
current, max_so_far = max_so_far, max(current, max_so_far)
```

---

## Time & Space Complexity

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(1) | Too slow for large inputs |
| Right-to-Left | O(n) | O(1) | Optimal, single pass |

---

## Edge Cases

1. **Single Element Array:** `[5]` → `[-1]`
   - Only element becomes -1

2. **All Same Elements:** `[3, 3, 3, 3]` → `[3, 3, 3, -1]`
   - Each element equals the max to its right until the end

3. **Strictly Decreasing:** `[5, 4, 3, 2, 1]` → `[4, 3, 2, 1, -1]`
   - Each element is simply the next one

4. **Strictly Increasing:** `[1, 2, 3, 4, 5]` → `[5, 5, 5, 5, -1]`
   - All elements become 5 (the global maximum)

---

## Common Pitfalls

❌ **Pitfall 1:** Overwriting elements before saving them
```
// Wrong: loses the original value
arr[i] = max_so_far
max_so_far = arr[i]  // Uses new value, not original
```

✅ **Fix:** Save the value first
```
current = arr[i]
arr[i] = max_so_far
max_so_far = max(current, max_so_far)
```

❌ **Pitfall 2:** Forgetting to initialize last element to -1
- The loop naturally handles this if max_so_far starts as -1

❌ **Pitfall 3:** Left-to-right traversal
- Won't work because you don't yet know the maximums to the right

---

## Optimization Notes

- The algorithm is already optimal in time complexity (O(n) is the lower bound since we must visit each element)
- Space complexity is already optimal (O(1) modifying in-place)
- No additional data structures (no stack, queue, heap) needed
- Works for both positive and non-negative integers (handle negative values carefully if needed)
