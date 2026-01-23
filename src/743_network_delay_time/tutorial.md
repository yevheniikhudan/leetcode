# Tutorial: Network Delay Time

## Understanding the Problem
This problem involves finding the minimum time required for a signal to propagate from a starting node `k` to all other nodes in a directed graph. The graph has `n` nodes and directed edges with travel times. If any node is unreachable, return -1.

The key insight is that we need the shortest path from `k` to every node, and then take the maximum of those shortest times. This represents the time when the last node receives the signal.

## Visual Example
Consider Example 1:
- Nodes: 1,2,3,4
- Edges: 2->1 (1), 2->3 (1), 3->4 (1)
- Start: 2

Signal from 2 reaches:
- 1 at time 1 (direct)
- 3 at time 1 (direct)
- 4 at time 2 (via 3)

Maximum time: 2

## Approaches

### 1. Dijkstra's Algorithm (Most Efficient)
**Concept:** Use a priority queue to always process the node with the smallest current shortest time. Maintain a distance array tracking minimum time to reach each node.

**Steps:**
1. Build adjacency list from times
2. Initialize distance array with infinity, except start node at 0
3. Use min-heap (priority queue) with (time, node) pairs
4. While queue not empty:
   - Extract node with smallest time
   - For each neighbor, calculate new time = current_time + edge_weight
   - If new time < neighbor's current distance, update and push to queue
5. Find maximum in distance array (excluding infinity)
6. If any distance is infinity, return -1

**Time Complexity:** O((V + E) log V) where V=nodes, E=edges
**Space Complexity:** O(V + E)

**Why efficient:** Guarantees shortest paths in graphs with non-negative weights.

### 2. Breadth-First Search (BFS) with Relaxation
**Concept:** Similar to Dijkstra but uses queue instead of priority queue. May visit nodes multiple times.

**Steps:**
1. Build graph
2. Initialize distances
3. Use queue for BFS
4. For each node, relax neighbors
5. May need multiple passes

**Time Complexity:** O(V * E) in worst case
**Space Complexity:** O(V + E)

**When to use:** For unweighted graphs or when simplicity is preferred.

### 3. Depth-First Search (DFS)
**Concept:** Explore paths recursively, but not optimal for shortest paths.

**Time Complexity:** O(V + E) but doesn't guarantee shortest paths
**Space Complexity:** O(V) for recursion stack

**Limitation:** DFS doesn't naturally find shortest paths in weighted graphs.

## Key Concepts and Patterns
- **Shortest Path in Weighted Graph:** Dijkstra's algorithm
- **Graph Representation:** Adjacency list for efficiency
- **Priority Queue Usage:** Min-heap for selecting next node
- **Distance Tracking:** Array to store minimum times
- **Unreachability Check:** Any node with infinite distance means impossible

## Edge Cases and Common Pitfalls
- **Disconnected Graph:** Some nodes unreachable → return -1
- **Single Node:** n=1, should return 0 if k=1
- **No Edges:** Only start node reachable, others -1
- **Cycles:** Dijkstra handles cycles correctly
- **Zero Weights:** Allowed, but doesn't affect since non-negative
- **Node Numbering:** Nodes from 1 to n, not 0-based

## Optimization Notes
- Use adjacency list for O(1) neighbor access
- Priority queue ensures we process smallest times first
- Early termination possible if all nodes visited before queue empty
- For dense graphs, Fibonacci heap could optimize further, but not needed here

## Related Patterns
- Single source shortest path problems
- Network flow problems
- Minimum spanning tree (similar but different goal)
