# Set Matrix Zeroes - Tutorial

## Understanding the Problem

You are given a matrix. Whenever a cell contains `0`, its whole row and whole column must become `0`.

The key challenge is that once you start writing zeros, you can destroy information needed for later decisions. So you must separate:

- Discovering which rows/columns should become zero
  - Applying zero updates

## Most Efficient Approach First: First Row/Column as Markers

### Core Idea

Use the first row and first column as marker storage:

- If `matrix[r][c] == 0`, mark:
  - `matrix[r][0] = 0` (row `r` should be zeroed)
  - `matrix[0][c] = 0` (column `c` should be zeroed)

Also track two booleans:

- Whether original first row must be zeroed
- Whether original first column must be zeroed

Because first row and first column are reused for markers, these booleans preserve their original state.

### Step-by-Step Strategy

1. Scan first row and first column to capture their original zero-state.
2. Scan the inner submatrix (excluding first row and first column) and write markers.
3. Zero inner cells based on row/column markers.
4. Zero first row if needed.
5. Zero first column if needed.

### Why It Works

- Marker writes avoid extra arrays.
- Inner cells are updated only after all markers are established.
- First row/column are handled last using saved boolean flags.

### Complexity

- **Time:** `O(m * n)`
- **Space:** `O(1)` extra

## Alternative Approach: Extra Row/Column Sets

### Idea

- First pass: collect row indices and column indices containing a zero.
- Second pass: zero any cell whose row or column is marked.

### Complexity

- **Time:** `O(m * n)`
- **Space:** `O(m + n)`

This is easier to reason about, but not constant-space.

## Visual Intuition

For matrix:

```text
1 1 1
1 0 1
1 1 1
```

The zero at center marks row 1 and column 1.
Result:

```text
1 0 1
0 0 0
1 0 1
```

## Edge Cases

- Single cell matrix
- One row matrix
- One column matrix
- Zeros already in first row
- Zeros already in first column
- All values already zero

## Common Pitfalls

- Zeroing immediately during scan (causes chain-reaction corruption)
- Forgetting separate handling for first row and first column
- Mixing marker writes and marker reads in the same phase
- Incorrect traversal boundaries when excluding first row/column

## Optimization Notes

- Marker strategy already reaches optimal extra-space target.
- Keep update phases clearly separated to avoid logical bugs.
- First row/column handling at the end is the most error-prone part; treat it explicitly.
