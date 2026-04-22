# Largest Unique Number - Tutorial

## Understanding the Problem

We need to find the **largest number** in an array that appears **exactly once**. If no such number exists, return -1.

### Key Insight

We need two things:
1. **Count frequencies** - How many times does each number appear?
2. **Filter and find max** - Among numbers appearing once, which is largest?

## Approach 1: Hash Map / Dictionary

### Concept

1. **Count occurrences** of each number using a hash map/dictionary
2. **Iterate through the map** and find numbers with count = 1
3. **Return the maximum** or -1 if none exist

### Step-by-Step

```
Input: [5,7,3,9,4,9,8,3,1]

Step 1: Count frequencies
{5:1, 7:1, 3:2, 9:2, 4:1, 8:1, 1:1}

Step 2: Filter numbers with count = 1
[5, 7, 4, 8, 1]

Step 3: Find maximum
8
```

### Complexity

- **Time:** O(n) - one pass to count, one pass to find max
- **Space:** O(n) - hash map stores up to n unique numbers

## Approach 2: Counter (Python Built-in)

### Concept

Use Python's `Counter` class for cleaner, more Pythonic code:

```python
from collections import Counter

def largestUniqueNumber(nums):
    counts = Counter(nums)
    # Get all numbers with count = 1
    unique_nums = [num for num, count in counts.items() if count == 1]
    # Return max or -1
    return max(unique_nums) if unique_nums else -1
```

Or even more concisely with a generator:
```python
return max((num for num, count in Counter(nums).items() if count == 1), default=-1)
```

## Approach 3: Sorting (Less Efficient)

### Concept

Sort in descending order, then find first number with count = 1:
- **Time:** O(n log n) - slower than counting approach
- **Space:** O(n) - for sorting

## Edge Cases & Pitfalls

1. **All duplicates:** `[1,1,2,2,3,3]` → Return -1
2. **Single element:** `[5]` → Return 5 ✓
3. **One unique:** `[7,7,8,8,9]` → Return 9
4. **Empty after filtering:** `[0,0,1,1]` → Return -1
5. **Zero in array:** `[0,1,0,2]` → 0 appears twice (not unique)

## Complexity Analysis

**Time Complexity:** O(n)
- Counting: O(n) for one pass through array
- Filtering: O(k) where k ≤ n unique elements
- Total: O(n)

**Space Complexity:** O(n)
- Hash map stores up to n unique elements

## Summary

The most efficient approach is to count frequencies using a hash map, then find the maximum among numbers appearing exactly once. This is a straightforward O(n) time, O(n) space solution.
