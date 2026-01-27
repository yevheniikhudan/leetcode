# Minimum Cost Path with Edge Reversals - Tutorial

## Understanding the Problem

We have a directed graph where we can reverse incoming edges at nodes (at most once per node) to find the minimum cost path from 0 to n-1. Reversing an edge costs 2x the original weight and allows immediate traversal.

Key points:
- Directed graph with weights
- Each node can reverse at most one incoming edge
- Reversal costs 2 * w and allows traversal to the original source
- Need shortest path considering these reversals

## Approach: Dijkstra with Augmented Graph

### Strategy
Model the graph with additional "reversed" edges:
- For each original edge u → v with weight w, add a reversed edge v → u with weight 2 * w
- This represents using the reversal at node v to go back to u
- Run Dijkstra from 0 to n-1 on this augmented graph
- The minimum cost found is the answer

### Why This Works
- The reversal is only used once per node (since each reversed edge is unique per original edge)
- Immediate traversal is handled by the edge weight
- Dijkstra finds the shortest path in the augmented graph

### Time Complexity: O((V + E) log V)
- Building graph: O(E)
- Dijkstra with heap: O((V + E) log V)

### Space Complexity: O(V + E)

### Visual Example
For edges [[0,1,3],[3,1,1]]:
- Original: 0→1:3, 3→1:1
- Augmented: add 1→3:2 (reversed from 3→1)
- Path 0→1→3 costs 3 + 2 = 5

## Edge Cases

- No path possible: return -1
- Direct path without reversals
- Multiple reversals needed (but each node at most one)
- Cycles or disconnected components

## Common Pitfalls

- Forgetting that reversal is per node, not per edge
- Incorrect weight for reversed edges (must be 2*w)
- Not handling immediate traversal (it's built into the edge)
- Graph may have multiple components

## Optimization Notes

- Use priority queue for Dijkstra
- Since n <= 5e4, E <= 1e5, time is acceptable
- Augmented graph has 2E edges, still fine
