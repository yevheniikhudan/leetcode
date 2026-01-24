# Tutorial: Swim in Rising Water

## Understanding the Problem
Grid with elevations, water rises to level t. Can move to adjacent cells if both <= t. Find min t to reach bottom-right from top-left.

## Key Concepts
- **Binary Search on Time:** Search for min t where path exists.
- **Connectivity Check:** Use DFS/BFS/Union-Find to check if (0,0) and (n-1,n-1) connected at time t.
- **Dijkstra's Alternative:** Priority queue to find min max elevation path.

## Approaches

### 1. Binary Search + BFS/DFS (Optimal)
- Binary search on t (0 to max elevation).
- For each mid, check if path exists using BFS/DFS.
- Cells with elevation <= mid are traversable.

**Time Complexity:** O(n² log n) (binary search * BFS)  
**Space Complexity:** O(n²)

### 2. Dijkstra's Algorithm
- Treat as graph, edge weight is max elevation of two cells.
- Find shortest path where "distance" is max elevation.

**Time Complexity:** O(n² log n)  
**Space Complexity:** O(n²)

### 3. Union-Find with Sorting
- Sort cells by elevation.
- Add cells in order, union adjacent.
- Check when (0,0) and (n-1,n-1) connected.

**Time Complexity:** O(n² log n)  
**Space Complexity:** O(n²)

## Visual Example
Grid: [[0,2],[1,3]]

At t=3, all cells <=3, connected.

## Edge Cases
- n=1: return grid[0][0]
- All elevations same: return that value
- Path blocked until high t

## Common Pitfalls
- Forgetting unique elevations (no ties).
- Binary search bounds: 0 to max(grid).
- In BFS, only visit cells <= t.

## Optimization Notes
- Binary search is efficient for n<=50.
- Dijkstra's gives exact min max, but binary search simpler.
