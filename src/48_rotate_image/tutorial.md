# Rotate Image - Tutorial

## Understanding the Problem

We need to rotate an `n x n` matrix by 90 degrees clockwise without creating a second matrix.

That constraint is the key challenge. A direct copy-based rotation is easy to imagine, but it is not allowed here. The goal is to rearrange values inside the same matrix.

For a clockwise rotation:

- The first row becomes the last column
- The second row becomes the second-to-last column
- The last row becomes the first column

For example:

```text
1 2 3      7 4 1
4 5 6  ->  8 5 2
7 8 9      9 6 3
```

## Best Approach: Transpose Then Reverse Each Row

### Strategy

The cleanest in-place approach is to break the rotation into two transformations:

1. **Transpose the matrix**
   - Swap across the main diagonal
   - Row `r`, column `c` swaps with row `c`, column `r`

2. **Reverse each row**
   - After transposition, reversing every row completes the clockwise rotation

### Why It Works

Transposition flips the matrix over its main diagonal. That converts rows into columns, but not yet in the final clockwise order.

Reversing each row then moves every value into the exact position it needs after a 90-degree clockwise turn.

### Visual Walkthrough

Start:

```text
1 2 3
4 5 6
7 8 9
```

After transpose:

```text
1 4 7
2 5 8
3 6 9
```

After reversing each row:

```text
7 4 1
8 5 2
9 6 3
```

### Complexity

- **Time:** `O(n^2)`
- **Space:** `O(1)`

This is optimal because every cell must be touched at least once.

## Alternative Approach: Layer-by-Layer Four-Way Swaps

### Strategy

Another in-place method rotates the matrix one square layer at a time:

- Process the outer ring first
- Then move inward
- For each position, rotate four corresponding cells in a cycle

Each move sends:

- top -> right
- right -> bottom
- bottom -> left
- left -> top

### When It Helps

This approach is also `O(n^2)` time and `O(1)` space. It is useful when you want to think directly in terms of the final rotated positions rather than matrix transformations.

### Tradeoffs

- More index bookkeeping
- Easier to make off-by-one mistakes
- Harder to explain quickly than transpose + reverse

## Key Concepts and Patterns

- Matrix transformation
- In-place modification
- Symmetry across the main diagonal
- Layered traversal

## Edge Cases

- `1 x 1` matrix: rotation changes nothing
- `2 x 2` matrix: smallest non-trivial rotation
- Negative values: no special handling needed
- Repeated values: positions matter, not uniqueness

## Common Pitfalls

- Using an extra matrix even though the problem requires in-place rotation
- Reversing columns instead of rows for clockwise rotation
- Swapping every pair twice during transpose
- Mixing up clockwise and counterclockwise transformations

## Optimization Notes

- The transpose + reverse method is already optimal for this problem's constraints
- Use the diagonal boundary carefully during transpose so each pair is swapped exactly once
- Since the matrix is small (`n <= 20`), clarity matters more than micro-optimizations
