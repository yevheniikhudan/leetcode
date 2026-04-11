# Valid Word Square - Tutorial

## Understanding the Problem

A valid word square means that if you arrange words in a grid, the grid reads the same way both horizontally (rows) and vertically (columns). Specifically:
- The 1st row equals the 1st column
- The 2nd row equals the 2nd column
- And so on...

This is similar to the concept of a symmetric matrix, where element at position `(i, j)` equals the element at position `(j, i)`.

---

## Visual Examples

### Valid Word Square
```
Grid representation:
  a b c d   (row 0)
  b n r t   (row 1)
  c r m y   (row 2)
  d t y e   (row 3)

Column 0: a, b, c, d (reads as "abcd" = row 0 ✓)
Column 1: b, n, r, t (reads as "bnrt" = row 1 ✓)
Column 2: c, r, m, y (reads as "crmy" = row 2 ✓)
Column 3: d, t, y, e (reads as "dtye" = row 3 ✓)
```

### Invalid Word Square
```
Grid representation:
  b a l l   (row 0)
  a r e a   (row 1)
  r e a d   (row 2)
  l a d y   (row 3)

Column 0: b, a, r, l (reads as "barl" = row 0? No, row 0 is "ball" ✗)
Column 2: l, e, a, d (reads as "lead" ≠ row 2 "read" ✗)
```

---

## Multiple Approaches

### Approach 1: Direct Element Comparison (Most Efficient)
**Concept:**
- For every position `(i, j)` in the grid, check if `words[i][j]` equals `words[j][i]`.
- Handle out-of-bounds cases: if row `i` doesn't have character at index `j`, or row `j` doesn't have character at index `i`, they must both be out of bounds (or one exists while the other doesn't means invalid).

**Strategy:**
1. Iterate through all positions `(i, j)` where `i <= j` (to avoid redundant checks).
2. For each position, verify that both `words[i][j]` and `words[j][i]` either:
   - Both exist and are equal, OR
   - Both don't exist (out of bounds).
3. Return `false` if any mismatch is found, `true` if all positions pass.

**Pros:**
- Single pass through relevant positions
- O(m*n) time complexity (m = number of strings, n = max length)
- Space efficient

**Cons:**
- Need careful boundary checking

### Approach 2: Build Column Strings
**Concept:**
- Explicitly build each column as a string
- Compare each column string with the corresponding row string

**Strategy:**
1. For each column index `j` from `0` to max word length:
   - Extract the character at index `j` from each word
   - Form a column string
   - Compare with the corresponding row (word at index `j`)
2. Return `false` if any mismatch, `true` otherwise.

**Pros:**
- Straightforward logic
- Easy to understand

**Cons:**
- Extra space for building column strings
- Slightly less efficient

---

## Time and Space Complexity

### Approach 1 (Direct Comparison):
- **Time Complexity:** O(n × m) where n is the number of words and m is the maximum word length. We check each position once.
- **Space Complexity:** O(1) - only using constant extra space for iteration variables.

### Approach 2 (Column Building):
- **Time Complexity:** O(n × m) - same as Approach 1.
- **Space Complexity:** O(m) - for storing the column strings.

---

## Key Concepts and Patterns

1. **Symmetry Check:** The problem is fundamentally checking for symmetry across the diagonal.
2. **Boundary Handling:** Critical to handle cases where words have different lengths.
3. **Index Mapping:** Understanding how to map from grid coordinates `(i, j)` to string indices is essential.

---

## Edge Cases and Common Pitfalls

1. **Different Word Lengths:**
   - Words don't need to be the same length
   - Example: `["ab", "ba", "c"]` is valid because row 0 = "ab" and column 0 = "ab", row 1 = "ba" and column 1 = "ba", row 2 = "c" and column 2 would be out of bounds for words[0] and words[1], which is acceptable.

2. **Single Word:**
   - A single word always forms a valid word square

3. **Out of Bounds Handling:**
   - If `words[i]` doesn't have a character at index `j`, but `words[j]` does have a character at index `i`, it's invalid.
   - Both must be out of bounds for the square to be valid.

4. **Empty Words:**
   - According to constraints, minimum word length is 1, so this isn't an issue.

---

## Optimization Notes

- **Early Exit:** Return `false` as soon as a mismatch is found—no need to check all positions.
- **Pruning:** Only check positions where `i <= j` to avoid redundant comparisons (checking `(0,1)` is enough, no need to check `(1,0)` separately if they must be equal).
- **String Length Optimization:** Build a map of word lengths or find the maximum length upfront to avoid redundant length calculations.
