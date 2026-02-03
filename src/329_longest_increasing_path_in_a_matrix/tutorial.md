# Tutorial: Longest Increasing Path in a Matrix

## Understanding the Problem

The problem requires finding the longest path in a matrix where each step moves to a neighboring cell (up, down, left, right) with a strictly increasing value. No diagonals or boundary wrapping. The path length is the number of cells in the sequence.

This is a graph problem where each cell is a node, and edges exist to neighbors with higher values. We need the longest path in this DAG (directed acyclic graph, since values increase).

## Visual Examples

For matrix = [[9,9,4],[6,6,8],[2,1,1]]:

- Path: (2,2)=1 -> (1,2)=2 -> (0,2)=6 -> (0,1)=9, length 4.
- Other paths are shorter.

For [[3,4,5],[3,2,6],[2,2,1]]:

- Path: (0,0)=3 -> (0,1)=4 -> (0,2)=5 -> (1,2)=6, length 4.

## Approaches

### 1. DFS with Memoization (Top-Down DP)
- Perform DFS from each cell, exploring neighbors with higher values.
- Memoize the longest path length from each cell to avoid recomputation.
- For each cell, recurse to neighbors if matrix[ni][nj] > matrix[i][j], add 1 to the max from neighbors.
- Track global max length.

### 2. Bottom-Up DP
- Create a DP table dp[i][j] = longest path starting from (i,j).
- Iterate through all cells, for each, check neighbors with lower values (since path increases, so from end backwards).
- Actually, since it's increasing, process in order of increasing values, but DFS is simpler.

### 3. Topological Sort + DP
- Model as graph, use topological sort to process cells in order.
- But DFS with memo is most straightforward.

## Time and Space Complexity

- DFS with Memo: O(m*n) time (each cell visited once, 4 directions), O(m*n) space for memo and stack.
- Bottom-Up: O(m*n), same space.

Since m,n <= 200, 40,000 cells, fine.

## Key Concepts and Patterns

- Graph Traversal: DFS/BFS on grid.
- Memoization: Cache results for subproblems.
- Increasing Constraint: Only move to strictly higher values.
- Boundary Checks: Ensure moves are within bounds.

## Edge Cases and Common Pitfalls

- Single cell: Length 1.
- All equal: Length 1 (can't move if not increasing).
- All increasing in one direction: Full row/column length.
- Large matrix: Ensure no TLE, use memo.
- Zero or negative values: Values >=0, but increasing means > current.

## Optimization Notes

- Use memo to avoid exponential time without it.
- In DFS, return 1 + max from valid neighbors, or 1 if none.
- Global max updated during DFS calls.
