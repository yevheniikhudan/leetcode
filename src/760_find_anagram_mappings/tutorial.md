# Tutorial: Find Anagram Mappings

## Understanding the Problem

We need to create a mapping that tells us: for each element in `nums1`, at what index does it appear in `nums2`?

Since `nums2` is an anagram of `nums1` with all unique elements, every element in `nums1` appears exactly once in `nums2`. Our task is to find where each element is located.

**Key insight:** Instead of searching for each element repeatedly, we can pre-build a lookup structure that tells us instantly where to find any value.

---

## Approach 1: Hash Map Lookup (OPTIMAL ✅)

### Concept

1. **Build a map** from `nums2`: Create a dictionary/hash map where the key is each value and the value is its index
2. **Iterate through `nums1`**: For each element, look up its index in the map
3. **Store results**: Record the index in the mapping array

### Why This Works

- Hash map lookups are O(1) on average
- We traverse `nums2` once to build the map: O(n)
- We traverse `nums1` once to look up indices: O(n)
- Total: O(n) time, very efficient

### Visual Example

```
nums1 = [12, 28, 46, 32, 50]
nums2 = [50, 12, 32, 46, 28]

Step 1: Build map from nums2
  Map = {50: 0, 12: 1, 32: 2, 46: 3, 28: 4}

Step 2: Iterate nums1 and look up in map
  nums1[0] = 12 → map[12] = 1 → mapping[0] = 1
  nums1[1] = 28 → map[28] = 4 → mapping[1] = 4
  nums1[2] = 46 → map[46] = 3 → mapping[2] = 3
  nums1[3] = 32 → map[32] = 2 → mapping[3] = 2
  nums1[4] = 50 → map[50] = 0 → mapping[4] = 0

Result: [1, 4, 3, 2, 0]
```

### Complexity Analysis

**Time Complexity: O(n)**
- Building the hash map: O(n) where n = len(nums2)
- Iterating through nums1 and doing lookups: O(n) where n = len(nums1)
- Total: O(n + n) = O(n)

**Space Complexity: O(n)**
- Hash map stores up to n key-value pairs
- Output mapping array: O(n)
- Total: O(n) additional space

---

## Approach 2: Nested Loop Search (Brute Force ❌)

### Concept

For each element in `nums1`, iterate through `nums2` and find where it matches, then record that index.

### How It Works

```
For each element in nums1:
  For each index in nums2:
    If nums1[i] == nums2[j]:
      mapping[i] = j
      Break
```

### Why It's Inefficient

- For each of n elements in nums1, we potentially search through all n elements in nums2
- Worst case: O(n²) comparisons
- Not practical for larger arrays, even though constraints are small (n ≤ 100)

### Complexity Analysis

**Time Complexity: O(n²)**
- Outer loop: n iterations
- Inner loop: up to n iterations
- Total: n × n = O(n²)

**Space Complexity: O(1)**
- Only the output array, which doesn't count as auxiliary space
- No extra data structures needed

---

## Key Concepts and Patterns

### 1. Hash Map for Fast Lookup
Use a hash map when you need to repeatedly look up values or indices. Building the map is O(n), but each subsequent lookup is O(1).

### 2. One-to-One Mapping
Since all elements are unique in both arrays, each element in nums1 maps to exactly one index in nums2, and vice versa. This is called a **bijection**.

### 3. Anagram Properties
- Same elements, same frequencies
- Different order (usually)
- All elements here are unique (simplifies the problem)

### 4. Building vs. Searching Trade-off
- Brute force: No preprocessing, but slow searches
- Hash map: O(n) preprocessing, but O(1) lookups

---

## Edge Cases and Common Pitfalls

### Edge Case 1: Single Element
```
nums1 = [5]
nums2 = [5]
Result: [0]
```
Both arrays have one element, and it's at index 0 in nums2.

### Edge Case 2: Already in Order
```
nums1 = [1, 2, 3]
nums2 = [1, 2, 3]
Result: [0, 1, 2]
```
When elements are in the same order, the mapping is the identity mapping.

### Edge Case 3: Completely Reversed
```
nums1 = [1, 2, 3]
nums2 = [3, 2, 1]
Result: [2, 1, 0]
```
Elements are in reverse order, so indices are reversed.

### Edge Case 4: Mixed Order
```
nums1 = [2, 1, 3, 1]  ← Wait, problem says all elements are unique!
```
According to constraints, all elements in nums1 and nums2 are unique, so we don't need to handle duplicates.

### Common Pitfall 1: Confusing Direction
❌ **Wrong:** Looking up where to find nums2[i] in nums1
✅ **Right:** Looking up where to find nums1[i] in nums2

### Common Pitfall 2: Wrong Index Storage
❌ **Wrong:** Storing the value instead of the index
✅ **Right:** Storing `mapping[i] = j` where j is the **index** in nums2

### Common Pitfall 3: Inefficient Repeated Searches
❌ **Wrong:** Searching through nums2 for each element in nums1
✅ **Right:** Build a hash map once, then do O(1) lookups

### Common Pitfall 4: Assuming Specific Order
❌ **Wrong:** Assuming nums1 and nums2 are in a particular order
✅ **Right:** Handle any order; they're only related by being anagrams

---

## Optimization Notes

### Optimization 1: Use Hash Map
The single most important optimization is using a hash map instead of nested loops. This reduces time complexity from O(n²) to O(n).

### Optimization 2: Single Pass for Building
Build the map in one pass through nums2, not multiple passes. Don't rebuild it for each lookup.

### Optimization 3: Language-Specific Optimizations
- **Python:** Use a dictionary comprehension for conciseness
- **Java:** Use HashMap for flexibility; TreeMap if you need ordering
- **C++:** Use `unordered_map` for O(1) average lookups (better than `map`)

### Optimization 4: Early Exit Not Applicable
Since each element appears exactly once, there's no opportunity for early termination. We must process all elements.

---

## Complexity Summary

| Approach | Time | Space | Practical |
|----------|------|-------|-----------|
| Hash Map | O(n) | O(n) | ✅ Best |
| Nested Loop | O(n²) | O(1) | ❌ Avoid |

---

## Problem-Solving Pattern

This problem demonstrates the **Index Mapping Pattern**:
1. When you need to find where elements are located, build a lookup structure
2. Hash maps are ideal for value-to-index or index-to-value mappings
3. This pattern appears in many problems: Isomorphic Strings, Valid Sudoku, Group Anagrams, etc.

---

## Summary

**Best Approach:** Use a hash map to build a value→index mapping from `nums2`, then iterate `nums1` and look up each element's index.

**Time Complexity:** O(n) - optimal
**Space Complexity:** O(n) - necessary for the output

This is a straightforward problem that emphasizes the importance of choosing the right data structure for the job.