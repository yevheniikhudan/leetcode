# Find Minimum in Rotated Sorted Array - Tutorial

## Problem Understanding

You have a sorted array that has been **rotated** at some unknown pivot point. Your task is to find the **minimum element** in **O(log n)** time.

**Key Observations:**
1. The array was originally sorted in ascending order
2. It has been rotated 1 to n times (rotation moves last element to front)
3. All elements are unique
4. Must use O(log n) time → Binary Search!

**Rotation Examples:**
- Original: `[1,2,3,4,5]`
- Rotate 1 time: `[5,1,2,3,4]`
- Rotate 2 times: `[4,5,1,2,3]`
- Rotate 3 times: `[3,4,5,1,2]`
- Rotate 5 times: `[1,2,3,4,5]` (back to original)

## Key Insights

### Insight 1: Two Sorted Subarrays

After rotation, the array consists of **two sorted subarrays**:

Example: `[4,5,6,7,0,1,2]`
- Left sorted part: `[4,5,6,7]` (all greater than minimum)
- Right sorted part: `[0,1,2]` (contains the minimum)

The **inflection point** (where it drops) separates these two parts.

### Insight 2: How to Identify Which Half Contains Minimum

At any point during binary search with indices left, mid, right:

**Compare `nums[mid]` with `nums[right]`:**

1. **If `nums[mid] > nums[right]`:**
   - Inflection point is to the right of mid
   - Minimum is in the right half
   - Example: `[4,5,6,7,0,1,2]`, mid=7, right=2
   - Search right: `left = mid + 1`

2. **If `nums[mid] <= nums[right]`:**
   - No inflection between mid and right (sorted)
   - Minimum is at mid or to the left
   - Example: `[6,7,0,1,2,3,4]`, mid=1, right=4
   - Search left: `right = mid`

### Insight 3: Why Compare with Right, Not Left?

Comparing with `nums[right]` is more reliable because:
- It tells us if the right portion is sorted
- If right portion is sorted, minimum must be on the left (including mid)
- If right portion is NOT sorted, minimum must be on the right

### Insight 4: Edge Case - No Rotation

If the array is not rotated at all, it's simply sorted:
- Example: `[1,2,3,4,5]`
- The first element is the minimum
- Binary search will naturally converge to it

## Algorithm: Modified Binary Search

**Goal:** Find the inflection point (where the minimum resides)

**Template:**
1. Initialize left = 0, right = length - 1
2. While left < right:
   - Calculate mid
   - Compare nums[mid] with nums[right]
   - If nums[mid] > nums[right]: minimum is on right, left = mid + 1
   - Else: minimum is at mid or left, right = mid
3. Return nums[left]

**Why `left < right`?**
- We're looking for the minimum position
- When left equals right, we've found it
- No need for `left <= right` since we're not searching for a target value

## Step-by-Step Example

**Input:** `nums = [4,5,6,7,0,1,2]`

**Initial State:**
- Array: `[4,5,6,7,0,1,2]`
- Indices: `[0,1,2,3,4,5,6]`

**Iteration 1:**
- left=0, right=6, mid=3
- nums[mid]=7, nums[right]=2
- 7 > 2 → minimum is on right
- left = mid + 1 = 4

**Iteration 2:**
- left=4, right=6, mid=5
- nums[mid]=1, nums[right]=2
- 1 < 2 → minimum is at mid or left
- right = mid = 5

**Iteration 3:**
- left=4, right=5, mid=4
- nums[mid]=0, nums[right]=1
- 0 < 1 → minimum is at mid or left
- right = mid = 4

**Stop:** left=4, right=4
**Answer:** nums[4] = 0

## Visual Example

Array: `[4,5,6,7,0,1,2]`

The algorithm essentially finds where the "drop" happens:
- Left side: 4 → 5 → 6 → 7 (increasing)
- **Drop here!** 7 → 0 (inflection point)
- Right side: 0 → 1 → 2 (increasing)

The minimum is always at the inflection point.

## Edge Cases

1. **No rotation (already sorted):**
   - Input: `[1,2,3,4,5]`
   - First element is minimum
   - Algorithm still works correctly

2. **Single element:**
   - Input: `[1]`
   - Return that element

3. **Two elements:**
   - Input: `[2,1]` → return 1
   - Input: `[1,2]` → return 1

4. **Rotated once (minimum at start):**
   - Input: `[5,1,2,3,4]`
   - Minimum is at index 1

5. **Rotated n-1 times (minimum at end):**
   - Input: `[2,3,4,5,1]`
   - Minimum is at last position

## Common Mistakes

1. **Comparing with nums[left] instead of nums[right]:**
   - ❌ Doesn't correctly identify which half to search
   - ✓ Always compare nums[mid] with nums[right]

2. **Using `left <= right` instead of `left < right`:**
   - ❌ Can cause infinite loop
   - ✓ Use `left < right` for finding minimum position

3. **Not handling the case when array is not rotated:**
   - ✓ The algorithm naturally handles this case

4. **Using `right = mid - 1` when nums[mid] <= nums[right]:**
   - ❌ Might skip the minimum at mid
   - ✓ Use `right = mid` to include mid in search

## Time and Space Complexity

**Time Complexity:** O(log n)
- Binary search halves the search space each iteration
- Maximum log₂(n) iterations

**Space Complexity:** O(1)
- Only using constant extra space (left, right, mid pointers)
- No additional data structures

## Pattern Recognition

This is a **Modified Binary Search** problem with these characteristics:

1. ✅ Array has some order property (two sorted subarrays)
2. ✅ Need O(log n) time complexity
3. ✅ Can eliminate half of search space each step
4. ✅ Looking for a specific position (minimum), not a target value

**Similar Problems:**
- Search in Rotated Sorted Array (33)
- Find Minimum in Rotated Sorted Array II (154) - with duplicates
- Find Peak Element (162)

## Key Takeaways

1. **Rotated sorted array = two sorted subarrays** separated by an inflection point
2. **Compare mid with right endpoint** to determine which half contains minimum
3. **Use `left < right`** loop for finding minimum position
4. **Binary search works** because we can always eliminate half the array
5. **Minimum is always at or after the inflection point** (where values drop)

This problem beautifully demonstrates how to modify binary search for arrays with special properties beyond simple sorted arrays!
