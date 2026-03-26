# Spiral Matrix - Tutorial

## Understanding the Problem

You have an m×n matrix and must extract all elements in spiral (clockwise) order, starting from the top-left corner and spiraling inward.

The challenge is tracking boundaries as you move: when you reach an edge, you must turn inward and continue until all elements are visited.

## Best Approach: Layer-by-Layer Boundary Traversal

### Strategy

Imagine the matrix as concentric rectangular layers. Process each layer from outside to inside:

1. Traverse the **top row** left-to-right
2. Traverse the **right column** top-to-bottom (excluding top corner already visited)
3. Traverse the **bottom row** right-to-left (excluding right corner already visited)
4. Traverse the **left column** bottom-to-top (excluding both corners already visited)
5. Move inward by shrinking boundaries and repeat

### Why It Works

By managing four boundaries (top, bottom, left, right), you can traverse each element exactly once in spiral order.

After each direction, shrink the relevant boundary to prevent revisiting elements.

### Visual Walkthrough

Start:
```
1 2 3
4 5 6
7 8 9
```

**Step 1:** Top row (left-to-right): 1, 2, 3
```
→ → →
4 5 6
7 8 9
```

**Step 2:** Right column (top-to-bottom, excluding top-right): 6, 9
```
1 2 3
4 5 ↓
7 8 ↓
```

**Step 3:** Bottom row (right-to-left, excluding bottom-right): 8, 7
```
1 2 3
4 5 6
← ← 9
```

**Step 4:** Left column (bottom-to-top, excluding both corners): 4
```
1 2 3
↑ 5 6
7 8 9
```

**Step 5:** Move inward, remaining: 5

Result: `[1, 2, 3, 6, 9, 8, 7, 4, 5]`

### Complexity

- **Time:** `O(m × n)` — visit each element exactly once
- **Space:** `O(1)` — not counting the output array

## Alternative Approach: Direction Vector with Turn

### Strategy

Use four direction vectors: right, down, left, up. Traverse in each direction until hitting a visited element or boundary, then turn.

### When It Helps

More compact code with less explicit boundary tracking; relies on marking visited cells.

### Tradeoffs

- Requires marking visited cells (extra space)
- Less intuitive boundary logic
- Easier to make direction-turning mistakes

## Key Concepts and Patterns

- Boundary management
- Layer-by-layer traversal
- State tracking (boundaries shrink after each pass)
- Directional iteration

## Edge Cases

- **Single row:** `[[1,2,3,4]]` — just traverse left-to-right
- **Single column:** `[[1],[2],[3],[4]]` — just traverse top-to-bottom
- **1×1 matrix:** `[[1]]` — return immediately
- **Rectangular (non-square):** Different dimensions require careful boundary handling
- **Negative values:** No special handling needed

## Common Pitfalls

- Forgetting to shrink boundaries after each direction
- Revisiting elements because boundaries overlap
- Incorrect boundary conditions (e.g., `<=` vs `<`)
- Not handling single-row or single-column edge cases
- Processing the same element twice at corners

## Optimization Notes

- The boundary-tracking approach is already optimal
- Avoid using a visited matrix; instead, shrink boundaries
- Since matrix is small (max 10×10), clarity matters more than micro-optimizations
- Use descriptive variable names for the four boundaries
