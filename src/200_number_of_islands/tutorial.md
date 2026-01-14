# 200. Number of Islands - Tutorial

This problem is a classic application of Depth-First Search (DFS) or Breadth-First Search (BFS) for grid traversal.

## Key Concepts
- **DFS/BFS:** Used to explore and mark all land cells connected to a starting cell.
- **Visited Marking:** Mark visited land cells to avoid recounting the same island.

## Approach Outline
1. Iterate through each cell in the grid.
2. When a '1' (land) is found, increment the island count and start a DFS/BFS to mark all connected land as visited (e.g., change to '0').
3. Continue until all cells are processed.

No code is provided here; see the solution files for language-specific skeletons.
