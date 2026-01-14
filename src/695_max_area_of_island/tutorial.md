# 695. Max Area of Island - Tutorial

This problem is a variation of the classic DFS/BFS grid traversal, focusing on finding the largest connected component (island).

## Key Concepts
- **DFS/BFS:** Used to explore and count the area of each island.
- **Visited Marking:** Mark visited land cells to avoid recounting.
- **Area Calculation:** Count the number of cells in each island during traversal.

## Approach Outline
1. Iterate through each cell in the grid.
2. When a '1' (land) is found, start a DFS/BFS to count the area and mark all connected land as visited (e.g., change to '0').
3. Track and return the maximum area found.

No code is provided here; see the solution files for language-specific skeletons.
