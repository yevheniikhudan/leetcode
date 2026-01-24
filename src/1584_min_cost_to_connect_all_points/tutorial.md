# Tutorial: Min Cost to Connect All Points

## Understanding the Problem
Given points on a 2D plane, connect all points with minimum total cost using Manhattan distance. Ensure all points are connected (no cycles in final graph).

## Key Concepts
- **Minimum Spanning Tree (MST):** Connect all nodes with minimum total edge weight, no cycles.
- **Manhattan Distance:** |x1-x2| + |y1-y2|
- **Union-Find:** Efficiently check and merge connected components.

## Approaches

### 1. Kruskal's Algorithm (Optimal)
- Generate all possible edges with weights.
- Sort edges by weight.
- Use Union-Find to add edges without forming cycles.

**Time Complexity:** O(E log E) (sorting edges)  
**Space Complexity:** O(E + V)

### 2. Prim's Algorithm
- Start from any node, grow MST by adding closest unconnected node.
- Use priority queue for minimum distance.

**Time Complexity:** O(E log V) with heap  
**Space Complexity:** O(V + E)

## Visual Example
Points: [[0,0],[2,2],[3,10],[5,2],[7,0]]

Edges sorted by distance, add until connected.

## Edge Cases
- 1 point: cost 0
- 2 points: distance between them
- All collinear: still MST

## Common Pitfalls
- Forgetting to sort edges in Kruskal's.
- Not handling large coordinates (use long for distances).
- Incorrect Union-Find implementation.

## Optimization Notes
- Kruskal's is simpler for dense graphs (n=1000, E~500k).
- Use path compression and union by rank in Union-Find.
