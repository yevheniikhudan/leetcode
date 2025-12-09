# Two Sum II - Input Array Is Sorted - Tutorial

## Problem Understanding

Find two numbers in a **sorted** array that add up to a target. Return their **1-indexed** positions (not 0-indexed).

**Key differences from Two Sum I:**
- Array is **sorted** - can use two pointers!
- Return **1-indexed** positions (add 1 to indices)
- Must use **O(1) extra space** (no hash map)

## Key Insights

1. **Array is sorted** - can use two-pointer technique
2. **One solution exists** - can return as soon as found
3. **Two pointers move smartly**: 
   - If sum is too small, move left pointer right (increase sum)
   - If sum is too large, move right pointer left (decrease sum)
4. **O(1) space** - no need for hash map

## Approach: Two Pointers (Optimal)

### Algorithm:
1. Initialize `left = 0`, `right = len(numbers) - 1`
2. While `left < right`:
   - Calculate `sum = numbers[left] + numbers[right]`
   - If `sum == target`: return `[left + 1, right + 1]` (1-indexed)
   - If `sum < target`: move `left++` (need larger sum)
   - If `sum > target`: move `right--` (need smaller sum)
3. Return result (guaranteed to exist)

### Example Walkthrough

```
numbers = [2, 7, 11, 15], target = 9

Step 1:
left = 0 (2), right = 3 (15)
sum = 2 + 15 = 17 > 9
→ Move right left

Step 2:
left = 0 (2), right = 2 (11)
sum = 2 + 11 = 13 > 9
→ Move right left

Step 3:
left = 0 (2), right = 1 (7)
sum = 2 + 7 = 9 == 9
→ Found! Return [1, 2] (1-indexed)
```

### Why This Works

**Sorted array property:**
- If current sum is too small, we need a larger number → move left pointer right
- If current sum is too large, we need a smaller number → move right pointer left
- We'll never skip the solution because we're exploring all valid pairs

### Time Complexity
- O(n) - each pointer moves at most n times

### Space Complexity
- O(1) - only using two pointers

## Alternative Approach: Binary Search

For each element, binary search for `target - element`:

### Algorithm:
1. For each index i:
   - Calculate `complement = target - numbers[i]`
   - Binary search for complement in `numbers[i+1:]`
   - If found, return indices

### Time Complexity
- O(n log n) - n iterations × log n binary search

### Space Complexity
- O(1)

**Note:** Two pointers is better (O(n) vs O(n log n))

## Edge Cases

1. **Minimum array (2 elements)**: Always a solution
2. **Negative numbers**: Works the same way
3. **Duplicate values**: Still works correctly
4. **Target is negative**: No special handling needed

## Common Mistakes

1. **Forgetting 1-indexed**: Must return `[left + 1, right + 1]`, not `[left, right]`
2. **Using hash map**: Violates O(1) space requirement
3. **Not leveraging sorted property**: Using brute force O(n²)
4. **Wrong pointer movement**: Moving wrong pointer for sum comparison

## Comparison with Two Sum I

| Aspect | Two Sum I | Two Sum II |
|--------|-----------|------------|
| Array | Unsorted | Sorted |
| Approach | Hash Map | Two Pointers |
| Time | O(n) | O(n) |
| Space | O(n) | O(1) |
| Index | 0-based | 1-based |

## Optimization Tips

1. **Use sorted property**: Two pointers is perfect for sorted arrays
2. **Early termination**: Return as soon as found (one solution guaranteed)
3. **No extra space**: Don't use hash map or create new arrays
