# Median of Two Sorted Arrays - Tutorial

## Problem Understanding

Find the median of two sorted arrays with **O(log(m+n))** time complexity.

**What is a Median?**
- **Odd total length:** The middle element
- **Even total length:** Average of two middle elements

**Examples:**
- `[1,2,3]` → median = 2
- `[1,2,3,4]` → median = (2+3)/2 = 2.5

**Challenge:** Can't use O(m+n) merge - need O(log) → Binary Search!

## Key Insights

### Insight 1: Partition Concept

Instead of merging, **partition** both arrays into left and right halves:

```
Combined array (conceptual): [left_elements] | [right_elements]
                              ← half →       ← half →
```

**Goal:** Find partition such that:
1. `len(left) == len(right)` (or differ by 1 for odd length)
2. `max(left) <= min(right)` (valid partition)

Then median is:
- Odd: `max(left_elements)`
- Even: `(max(left_elements) + min(right_elements)) / 2`

### Insight 2: Partition Both Arrays Simultaneously

```
nums1: [a1, a2, a3 | a4, a5]     (partition after a3)
nums2: [b1 | b2, b3, b4]         (partition after b1)

Left:  [a1, a2, a3, b1]          (4 elements)
Right: [a4, a5, b2, b3, b4]      (5 elements)
```

**Key:** If we partition nums1 at position `i`, we can calculate where to partition nums2!

### Insight 3: Valid Partition Condition

A partition is valid when:
```
left1_max <= right2_min  (max of nums1 left ≤ min of nums2 right)
AND
left2_max <= right1_min  (max of nums2 left ≤ min of nums1 right)
```

This ensures all left elements ≤ all right elements.

### Insight 4: Binary Search on Partition Position

Binary search on the smaller array to find correct partition:
- If `left1_max > right2_min`: partition nums1 too far right → search left
- If `left2_max > right1_min`: partition nums1 too far left → search right

## Algorithm: Binary Search on Partition

**Setup:**
1. Always binary search on the **smaller array** (optimization)
2. Calculate partition of second array based on first array's partition

**Steps:**

1. Ensure nums1 is smaller (swap if needed)
2. Binary search on nums1 partition position `i` (0 to m)
3. Calculate nums2 partition position: `j = (m+n+1)/2 - i`
4. Get boundary elements:
   - `left1 = nums1[i-1]`, `right1 = nums1[i]`
   - `left2 = nums2[j-1]`, `right2 = nums2[j]`
5. Check if partition is valid:
   - If `left1 <= right2 AND left2 <= right1`: Found it!
   - If `left1 > right2`: search left in nums1
   - Else: search right in nums1
6. Calculate median from boundary elements

## Why the Formula j = (m+n+1)/2 - i Works

This is the **key insight** that makes the binary search solution possible!

**Goal:** We want to partition both arrays so that:
- All elements on the LEFT side of the partition are ≤ all elements on the RIGHT side
- The LEFT side has exactly half the elements (or one more than half for odd totals)

**The Formula:**
```
j = (m + n + 1) / 2 - i
```

Where:
- `m` = length of nums1
- `n` = length of nums2
- `i` = number of elements from nums1 on the LEFT side (0 ≤ i ≤ m)
- `j` = number of elements from nums2 on the LEFT side (0 ≤ j ≤ n)

**Why it works:**

1. **Total elements on left side must be half:**
   - Total elements: `m + n`
   - We want: `i + j = (m + n + 1) / 2`
   - The `+1` handles both odd and even cases:
     - Even total: `(m+n+1)/2` rounds down to `(m+n)/2`
     - Odd total: `(m+n+1)/2` gives us the middle position

2. **Solving for j:**
   - Start with: `i + j = (m + n + 1) / 2`
   - Rearrange: `j = (m + n + 1) / 2 - i`

**Visual Example:**

```
nums1 = [1, 3, 8, 9, 15]  (m=5)
nums2 = [7, 11, 19, 21, 24, 25]  (n=6)
Total = 11 elements (odd)

We want (11+1)/2 = 6 elements on the left side.

If i=2 (take 2 from nums1):
  j = (5+6+1)/2 - 2 = 6 - 2 = 4 (take 4 from nums2)

Left side:  [1, 3] from nums1 + [7, 11, 19, 21] from nums2 = 6 elements ✓
Right side: [8, 9, 15] from nums1 + [24, 25] from nums2 = 5 elements ✓

Median is at position 6: max(left) = max(3, 21) = 21 would be incorrect!
We need to check if this partition is valid: left1 ≤ right2 AND left2 ≤ right1

Actually: 3 ≤ 24 ✓ but 21 > 8 ✗
So this partition is invalid, we need to search differently.
```

**Why +1 in the numerator?**

The `+1` ensures that for odd-length arrays, the left partition gets the extra element:

- **Even total** (e.g., 8 elements):
  - `(8+1)/2 = 9/2 = 4` (integer division)
  - Left: 4, Right: 4 ✓

- **Odd total** (e.g., 7 elements):
  - `(7+1)/2 = 8/2 = 4` (integer division)
  - Left: 4, Right: 3 ✓
  - The median is `max(left_elements)`

Without the `+1`, for odd totals we'd have equal partitions and the median position would be ambiguous.

**Key Insight:** By choosing `i` (binary search), we automatically determine `j` to maintain the half-partition requirement!

## Step-by-Step Example

**Input:** `nums1 = [1,3]`, `nums2 = [2]`

**Goal:** Find median of merged `[1,2,3]` → 2

### Setup:
- m = 2, n = 1
- Total = 3 (odd)
- Need left partition with 2 elements

### Binary Search:

**Iteration 1:**
- Partition nums1: i = 1 (between 1 and 3)
  - `nums1: [1 | 3]`
- Calculate j: `(2+1+1)/2 - 1 = 2 - 1 = 1`
  - `nums2: [2 |]`
- Boundaries:
  - left1 = nums1[0] = 1
  - right1 = nums1[1] = 3
  - left2 = nums2[0] = 2
  - right2 = infinity (no element)
- Check: `1 <= inf` ✓ and `2 <= 3` ✓ → **Valid!**

**Result:**
- Odd length: median = max(left1, left2) = max(1, 2) = 2 ✓

## Another Example

**Input:** `nums1 = [1,2]`, `nums2 = [3,4]`

**Goal:** Find median of merged `[1,2,3,4]` → 2.5

### Setup:
- m = 2, n = 2
- Total = 4 (even)
- Need left partition with 2 elements

### Binary Search:

**Iteration 1:**
- Partition nums1: i = 1
  - `nums1: [1 | 2]`
- Calculate j: `(2+2+1)/2 - 1 = 2 - 1 = 1`
  - `nums2: [3 | 4]`
- Boundaries:
  - left1 = 1, right1 = 2
  - left2 = 3, right2 = 4
- Check: `1 <= 4` ✓ but `3 <= 2` ✗ → Invalid!
- Since left2 > right1: search right in nums1

**Iteration 2:**
- Partition nums1: i = 2
  - `nums1: [1, 2 |]`
- Calculate j: `2 - 2 = 0`
  - `nums2: [| 3, 4]`
- Boundaries:
  - left1 = 2, right1 = inf
  - left2 = -inf, right2 = 3
- Check: `2 <= 3` ✓ and `-inf <= inf` ✓ → **Valid!**

**Result:**
- Even length: median = (max(left) + min(right)) / 2
- max(2, -inf) = 2, min(inf, 3) = 3
- Median = (2 + 3) / 2 = 2.5 ✓

## Edge Cases

1. **One array is empty:**
   - Return median of non-empty array

2. **Partition at array boundaries:**
   - Use `-infinity` for left boundary when partition at start
   - Use `+infinity` for right boundary when partition at end

3. **All elements of nums1 < all elements of nums2:**
   - Partition will be at end of nums1, start of nums2

4. **Arrays of very different sizes:**
   - Binary search on smaller array ensures O(log min(m,n))

## Common Mistakes

1. **Not handling edge cases with infinity:**
   - ❌ Accessing out of bounds
   - ✓ Use INT_MIN/INT_MAX for boundaries

2. **Wrong partition size calculation:**
   - ❌ `j = (m+n)/2 - i`
   - ✓ `j = (m+n+1)/2 - i` (handles both odd and even)

3. **Binary searching on larger array:**
   - ❌ Can cause j to be negative
   - ✓ Always search on smaller array

4. **Incorrect median calculation:**
   - ❌ Not distinguishing odd vs even
   - ✓ Check total length % 2

5. **Wrong binary search adjustment:**
   - ❌ Confusing which direction to search
   - ✓ If left1 > right2, partition is too far right

## Time and Space Complexity

**Time Complexity:** O(log min(m, n))
- Binary search on the smaller array
- Each iteration is O(1)

**Space Complexity:** O(1)
- Only using constant extra space
- No merge or auxiliary arrays

## Pattern Recognition

This is an **Advanced Binary Search** problem:

1. ✅ Need O(log n) solution → binary search
2. ✅ Not searching for a value, but for a partition position
3. ✅ Binary search on answer/position rather than on array elements
4. ✅ Requires careful handling of edge cases and boundaries

**Similar Advanced Binary Search Problems:**
- Find K-th Smallest Element in Sorted Matrix
- Split Array Largest Sum
- Koko Eating Bananas (binary search on answer)

## Key Takeaways

1. **Partition thinking** - divide problem into left/right halves
2. **Binary search on position** - not just on values
3. **Smaller array optimization** - always search on min(m,n)
4. **Infinity boundaries** - handle edge cases elegantly
5. **Two arrays, one partition** - partitioning one determines the other
6. **Valid partition condition** - max(left) <= min(right)

This is one of the most challenging binary search problems because it requires thinking about partitions rather than searching for a specific value!
