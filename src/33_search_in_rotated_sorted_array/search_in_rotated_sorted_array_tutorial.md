# Search in Rotated Sorted Array - Tutorial

## Problem Understanding

You have a sorted array that has been **rotated** at some unknown pivot point, and you need to **search for a target value** and return its index (or -1 if not found) in **O(log n)** time.

**Key Facts:**
1. Array was originally sorted in ascending order
2. It has been rotated at some pivot (or not rotated at all)
3. All elements are unique
4. Must use O(log n) time → Binary Search!
5. Unlike "Find Minimum", we need to find a **specific target value**

**Example:**
- Original: `[0,1,2,4,5,6,7]`
- Rotated: `[4,5,6,7,0,1,2]`
- Search for 0 → should return index 4

## Key Insights

### Insight 1: Two Sorted Subarrays

After rotation, the array consists of **two sorted portions**:

Example: `[4,5,6,7,0,1,2]`
- Left sorted: `[4,5,6,7]`
- Right sorted: `[0,1,2]`

The inflection point separates these two portions.

### Insight 2: At Least One Half is Always Sorted

At any midpoint during binary search, **at least one half** of the array is guaranteed to be properly sorted (no rotation).

**Why?** Because there's only one inflection point in the entire array.

### Insight 3: Strategy - Identify Sorted Half, Then Decide

At each step with left, mid, right:

1. **Determine which half is sorted** (left or right)
2. **Check if target is in the sorted half**
3. If yes → search that half
4. If no → search the other half

### Insight 4: How to Identify Which Half is Sorted

**Compare `nums[left]` with `nums[mid]`:**

1. **If `nums[left] <= nums[mid]`:**
   - Left half is sorted: `[left...mid]`
   - Example: `[4,5,6,7,0,1,2]`, left=0 (4), mid=3 (7) → left half sorted

2. **Otherwise:**
   - Right half is sorted: `[mid...right]`
   - Example: `[6,7,0,1,2,3,4]`, left=0 (6), mid=3 (1) → right half sorted

## Algorithm: Modified Binary Search

**Template:**

1. Initialize left = 0, right = length - 1
2. While left <= right:
   - Calculate mid
   - If nums[mid] == target, return mid (found it!)
   - Determine which half is sorted:
     - If left half is sorted (nums[left] <= nums[mid]):
       - Check if target is in range [nums[left], nums[mid]]
       - If yes: search left (right = mid - 1)
       - If no: search right (left = mid + 1)
     - Else right half is sorted:
       - Check if target is in range [nums[mid], nums[right]]
       - If yes: search right (left = mid + 1)
       - If no: search left (right = mid - 1)
3. Return -1 (not found)

**Why `left <= right`?**
- We're searching for a target value (might not exist)
- Need to check every position
- When left > right, we've exhausted the search space

## Step-by-Step Example

**Input:** `nums = [4,5,6,7,0,1,2]`, `target = 0`

**Initial State:**
- Array: `[4,5,6,7,0,1,2]`
- Indices: `[0,1,2,3,4,5,6]`
- left=0, right=6

**Iteration 1:**
- left=0, right=6, mid=3
- nums[mid]=7 ≠ target (0)
- Is left half sorted? nums[0]=4 <= nums[3]=7 → Yes!
- Is target in [4,7]? No (0 < 4)
- Search right half: left = 4

**Iteration 2:**
- left=4, right=6, mid=5
- nums[mid]=1 ≠ target (0)
- Is left half sorted? nums[4]=0 <= nums[5]=1 → Yes!
- Is target in [0,1]? Yes (0 is in range)
- Search left half: right = 4

**Iteration 3:**
- left=4, right=4, mid=4
- nums[mid]=0 == target → **Found!**
- Return 4

## Visual Example

Array: `[4,5,6,7,0,1,2]`, searching for 0

**Iteration 1:** Check mid=7
- Left half `[4,5,6,7]` is sorted ✓
- Target 0 not in [4,7] → go right

**Iteration 2:** Check mid=1
- Left half `[0,1]` is sorted ✓
- Target 0 in [0,1] → go left

**Iteration 3:** Check mid=0
- Found! Return index 4

## Example: Target Not Found

Array: `[4,5,6,7,0,1,2]`, searching for 3

**Iteration 1:** mid=3 (value 7)
- Left sorted [4,7], target 3 not in range → go right

**Iteration 2:** mid=5 (value 1)
- Left sorted [0,1], target 3 not in range → go right

**Iteration 3:** mid=6 (value 2)
- left=6, right=6, value=2 ≠ 3

**Iteration 4:** left=7, right=6
- left > right → Return -1 (not found)

## Edge Cases

1. **Single element:**
   - `nums = [1]`, target = 1 → return 0
   - `nums = [1]`, target = 0 → return -1

2. **No rotation (already sorted):**
   - `nums = [1,2,3,4,5]`, target = 3 → standard binary search

3. **Target is at inflection point:**
   - `nums = [4,5,6,7,0,1,2]`, target = 0 → return 4
   - `nums = [4,5,6,7,0,1,2]`, target = 7 → return 3

4. **Target at boundaries:**
   - First element: `nums = [4,5,6,7,0,1,2]`, target = 4 → return 0
   - Last element: `nums = [4,5,6,7,0,1,2]`, target = 2 → return 6

5. **Two elements:**
   - `nums = [3,1]`, target = 1 → return 1
   - `nums = [1,3]`, target = 3 → return 1

## Common Mistakes

1. **Not checking if nums[mid] equals target first:**
   - ❌ Always check this before deciding which half to search
   - ✓ Return immediately when found

2. **Wrong comparison to identify sorted half:**
   - ❌ Using nums[mid] vs nums[right]
   - ✓ Use nums[left] vs nums[mid]

3. **Incorrect range checking:**
   - ❌ `target > nums[left] && target < nums[mid]` (missing equals)
   - ✓ `target >= nums[left] && target <= nums[mid]`

4. **Using `left < right` instead of `left <= right`:**
   - ❌ Might miss the target at the last position
   - ✓ Use `left <= right` for searching a target

5. **Not handling the case when both halves seem sorted:**
   - When nums[left] == nums[mid], use `<=` to handle this
   - Left half is considered sorted in this case

## Comparison with "Find Minimum in Rotated Sorted Array"

| Aspect | Find Minimum (153) | Search Target (33) |
|--------|-------------------|-------------------|
| Goal | Find minimum element | Find target value |
| Return | Value or index | Index or -1 |
| Loop | `left < right` | `left <= right` |
| Compare | nums[mid] vs nums[right] | nums[left] vs nums[mid] |
| Strategy | Find inflection | Identify sorted half |

## Time and Space Complexity

**Time Complexity:** O(log n)
- Binary search halves the search space each iteration
- Maximum log₂(n) iterations

**Space Complexity:** O(1)
- Only using constant extra space
- No additional data structures

## Pattern Recognition

This is a **Modified Binary Search** problem with these characteristics:

1. ✅ Array has partial order (two sorted subarrays)
2. ✅ Need O(log n) time complexity
3. ✅ Can eliminate half of search space each step
4. ✅ Searching for a specific target value

**Similar Problems:**
- Find Minimum in Rotated Sorted Array (153)
- Search in Rotated Sorted Array II (81) - with duplicates
- Find Peak Element (162)

## Key Takeaways

1. **Rotated array = two sorted subarrays** separated by inflection point
2. **At least one half is always sorted** - identify it first
3. **Check if target is in sorted half** - if yes, search there; if no, search other half
4. **Use `left <= right`** for searching a target value
5. **Always check nums[mid] == target first** before deciding direction
6. **Compare nums[left] with nums[mid]** to determine which half is sorted

This problem combines the concepts of binary search with rotated arrays, requiring you to identify the sorted portion before deciding which direction to search!
