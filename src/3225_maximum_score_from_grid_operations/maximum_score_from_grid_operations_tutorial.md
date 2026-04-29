# Maximum Score From Grid Operations Tutorial

## Understanding the Problem

Each operation affects one entire column prefix. After all operations, every column has a black prefix at the top and a white suffix below it.

A cell contributes to the score only when:

- It remains white.
- Its left or right neighbor is black.

The task is to choose how far to color each column so the final white cells next to black cells have the largest total value.

## Key Observations

- Operations on the same column can be represented by a single final cutoff row.
- A column with no operation has zero black cells.
- A column colored through the last row has no white cells in that column.
- Contributions are local between neighboring columns, but each column choice can affect both the left and right side.
- Since `grid[i][j]` can be up to `10^9`, the final score may exceed 32-bit integer limits.

## Solving Checklist

- Define what state represents the final color pattern of a column.
- Decide how to score cells that become white next to a neighboring black prefix.
- Use column prefix sums to query vertical ranges quickly.
- Handle boundaries: the first and last columns have only one horizontal neighbor.
- Validate against both sample grids and small custom grids.

## Edge Cases

- `n = 1`: there are no horizontal neighbors, so the answer should be `0`.
- All values are `0`.
- A column is left fully white.
- A column is colored fully black.
- Large values require `long long` in C++ and `long` in Java.

## Complexity Targets

The constraints allow polynomial dynamic programming over columns and possible cutoff rows. Aim for an approach that avoids enumerating every combination of column states.
