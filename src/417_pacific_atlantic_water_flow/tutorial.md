# Tutorial: Pacific Atlantic Water Flow

## Understanding the Problem
Given a grid of heights, find all coordinates where water can flow to both the Pacific (top/left) and Atlantic (bottom/right) oceans. Water can only flow from a cell to neighboring cells with height less than or equal to the current cell.

## Visual Example
- See problem statement for a sample grid and output.

## Approaches
### 1. Reverse DFS/BFS from Ocean Borders (Most Efficient)
- Start DFS/BFS from all Pacific-bordering cells and mark reachable cells.
- Repeat for Atlantic-bordering cells.
- The intersection of reachable cells for both oceans gives the answer.
- Time: O(m*n), Space: O(m*n)

### 2. Brute Force DFS from Each Cell
- For each cell, check if it can reach both oceans by DFS.
- Time: O((m*n)^2), Space: O(m*n)

## Complexity
- Reverse DFS/BFS: O(m*n) time and space.
- Brute force: O((m*n)^2) time, O(m*n) space.

## Edge Cases
- Empty grid.
- Single row or column.

## Optimization Notes
- The reverse DFS/BFS approach is optimal and preferred for this problem.
