# Make Sum Divisible by P - Tutorial

## Problem Understanding

Given an array `nums` and an integer `p`, find the **shortest subarray** to remove so that the sum of the remaining elements is divisible by `p`. You cannot remove the entire array.

**Key Insights:**
- We want to remove the **minimum length** subarray
- After removal, the remaining sum should be divisible by `p`
- We cannot remove all elements
- If already divisible, return 0 (remove empty subarray)

## Mathematical Foundation

### Modular Arithmetic Property

If `total_sum % p = target`, we need to find a subarray with `subarray_sum % p = target`.

**Why?**
```
(total_sum - subarray_sum) % p = 0
total_sum % p = subarray_sum % p
```

So if `total % p = target`, we need to find the shortest subarray whose sum also has remainder `target`.

### Prefix Sum Approach

For any subarray `[i, j]`:
```
subarray_sum = prefix[j] - prefix[i-1]
```

We need:
```
(prefix[j] - prefix[i-1]) % p = target
prefix[j] % p - prefix[i-1] % p = target (mod p)
prefix[i-1] % p = (prefix[j] % p - target) % p
```

## Strategy: Hash Map + Prefix Sum

### Algorithm Steps

1. **Calculate target remainder:**
   - `target = total_sum % p`
   - If `target == 0`, array is already divisible, return 0

2. **Use hash map to track prefix remainders:**
   - Map: `remainder → last index where this remainder was seen`
   - Key insight: For each position `j`, look for position `i-1` where:
     ```
     prefix[i-1] % p = (prefix[j] % p - target + p) % p
     ```

3. **Iterate through array:**
   - Calculate running prefix sum modulo `p`
   - Check if complement remainder exists in map
   - If found, update minimum length
   - Store current remainder with current index

4. **Edge case:**
   - If we can't find valid subarray, return -1
   - Make sure we don't remove entire array

### Example Walkthrough

```
nums = [3,1,4,2], p = 6
total_sum = 10, target = 10 % 6 = 4

We need subarray with sum % 6 = 4

Prefix sums: [3, 4, 8, 10]
Prefix % 6:  [3, 4, 2, 4]

Initialize: map = {0: -1}, min_len = infinity

i=0, prefix=3, prefix%6=3
  need = (3 - 4 + 6) % 6 = 5 (not in map)
  map = {0:-1, 3:0}

i=1, prefix=4, prefix%6=4
  need = (4 - 4 + 6) % 6 = 0 (found at index -1)
  length = 1 - (-1) = 2
  min_len = 2
  map = {0:-1, 3:0, 4:1}

i=2, prefix=8, prefix%6=2
  need = (2 - 4 + 6) % 6 = 4 (found at index 1)
  length = 2 - 1 = 1
  min_len = 1
  map = {0:-1, 3:0, 4:1, 2:2}

i=3, prefix=10, prefix%6=4
  need = (4 - 4 + 6) % 6 = 0 (found at index -1)
  length = 3 - (-1) = 4 (entire array, skip)
  map = {0:-1, 3:0, 4:3, 2:2}

Result: min_len = 1
```

The subarray `[4]` at index 2 has sum 4, removing it leaves sum = 6.

### Why We Need `(curr - target + p) % p`

The `+ p` prevents negative remainders in languages where modulo can be negative.

**Example:**
```
curr = 2, target = 4, p = 6
(2 - 4) % 6 could give -2 in some languages
(2 - 4 + 6) % 6 = 4 (always positive)
```

## Algorithm Complexity

**Time Complexity:** O(n)
- Single pass through array
- Hash map operations are O(1)

**Space Complexity:** O(min(n, p))
- Hash map stores at most `min(n, p)` entries
- Only unique remainders modulo `p` are stored

## Key Edge Cases

1. **Already divisible:** `total % p == 0` → return 0
2. **Cannot find valid subarray:** return -1
3. **Would remove entire array:** Skip this case (not allowed)
4. **Single element:** Can remove if it equals the target remainder
5. **Multiple subarrays with same remainder:** Keep the rightmost index (shortest subarray)

## Common Mistakes to Avoid

1. **Forgetting to handle negative modulo:** Always use `(x % p + p) % p`
2. **Not initializing map with {0: -1}:** Handles subarrays starting from index 0
3. **Removing entire array:** Check `length < n`
4. **Integer overflow:** Use appropriate data types for large sums
5. **Not updating map after checking:** Update map with current remainder

## Alternative Approaches

### Brute Force (TLE)
- Try all subarrays: O(n²) or O(n³)
- Not feasible for n = 10⁵

### Sliding Window (Doesn't Work)
- Cannot use traditional sliding window because:
  - Target subarray sum changes as window moves
  - No monotonic property to exploit
  - Need exact remainder, not a range

The **hash map + prefix sum** approach is optimal for this problem.
