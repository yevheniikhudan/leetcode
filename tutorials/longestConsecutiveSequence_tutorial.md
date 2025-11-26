# Longest Consecutive Sequence - Tutorial

## Problem Understanding

Find the length of the longest sequence of consecutive integers in an unsorted array. For example, `[1, 2, 3, 4]` is a consecutive sequence of length 4.

**Important:** Must be O(n) time complexity - cannot sort the array first (sorting is O(n log n)).

## Key Insights

1. **Use a Hash Set**: For O(1) lookups to check if a number exists.
2. **Find Sequence Starts**: Only start counting from numbers that are the beginning of a sequence.
3. **A number is a sequence start** if `num - 1` is NOT in the set.
4. **Avoid redundant work**: Don't count sequences from the middle.

## Approach: Hash Set (Optimal)

### Algorithm:
1. Put all numbers in a hash set for O(1) lookup.
2. For each number in the set:
   - Check if it's the start of a sequence (i.e., `num - 1` not in set)
   - If yes, count how long the sequence is by checking `num + 1`, `num + 2`, etc.
   - Track the maximum sequence length.
3. Return the maximum length.

### Example Walkthrough

```
nums = [100, 4, 200, 1, 3, 2]
set = {100, 4, 200, 1, 3, 2}

For 100:
  - Is 99 in set? No → Start of sequence
  - Count: 100 → length 1

For 4:
  - Is 3 in set? Yes → Not a start, skip

For 200:
  - Is 199 in set? No → Start of sequence
  - Count: 200 → length 1

For 1:
  - Is 0 in set? No → Start of sequence
  - Count: 1 → 2 → 3 → 4 → length 4 ✓

For 3:
  - Is 2 in set? Yes → Not a start, skip

For 2:
  - Is 1 in set? Yes → Not a start, skip

Maximum length = 4
```

## Why This is O(n)

**Key insight:** Each number is visited at most twice:
1. Once when checking if it's a sequence start
2. Once when counting as part of a sequence

Even though there's a nested loop, the inner loop only runs for sequence starts, and each number is counted only once across all sequences.

## Edge Cases

1. **Empty array**: Return 0
2. **Single element**: Return 1
3. **All duplicates**: Return 1
4. **No consecutive numbers**: Return 1
5. **Negative numbers**: Works the same way
6. **Multiple sequences**: Find the longest one

## Common Mistakes

1. **Sorting first**: O(n log n) - violates time requirement
2. **Not checking for sequence start**: Counts every number, leading to redundant work
3. **Not using a set**: Using a list leads to O(n) lookups, making total O(n²)
4. **Not handling duplicates**: Add all numbers to set (duplicates automatically handled)

## Alternative Approaches

### Approach 1: Sorting (O(n log n) - Not Optimal)
```
1. Sort the array
2. Iterate and count consecutive numbers
3. Track max length
```
**Problem:** O(n log n) time complexity

### Approach 2: Union Find (O(n) but more complex)
```
1. Use Union Find data structure
2. Union consecutive numbers
3. Find largest component
```
**Problem:** More complex, same time complexity

## Optimization Tips

1. **Early exit**: If remaining elements < current max, can stop early
2. **Use set for deduplication**: Automatically handles duplicates
3. **Only count from sequence starts**: Avoids redundant work

## Time Complexity
- O(n) for creating the set
- O(n) for iterating (each element visited at most twice)
- **Total: O(n)**

## Space Complexity
- O(n) for the hash set
