# Tutorial: Cheapest Flights Within K Stops

## Understanding the Problem
Graph with cities as nodes, flights as directed edges with costs. Find cheapest path from src to dst with at most k stops (edges). Stops mean intermediate cities, so k stops allow k+1 edges.

## Key Concepts
- **Shortest Path with Constraints:** Standard Dijkstra fails due to stop limit; need to track stops.
- **State Representation:** Use (cost, stops) per node.
- **Graph Modeling:** Adjacency list from flights.

## Approaches

### 1. BFS with Priority Queue (Modified Dijkstra)
- Priority queue: (cost, city, stops)
- Track min cost to each city with <= k stops.
- Stop when stops > k.

**Time Complexity:** O((V + E) log V)  
**Space Complexity:** O(V + E)

### 2. Dynamic Programming
- DP[state][city] = min cost to city with exactly 'state' stops.
- Or 2D DP: dp[stops][city]

**Time Complexity:** O(k * E)  
**Space Complexity:** O(k * V)

### 3. Bellman-Ford Variation
- Relax edges up to k+1 times.
- Track min cost after each iteration.

**Time Complexity:** O(k * E)  
**Space Complexity:** O(V)

## Visual Example
n=3, flights=[[0,1,100],[1,2,100],[0,2,500]], src=0, dst=2, k=1

Path 0->1->2: cost 200, stops=1  
Path 0->2: cost 500, stops=0

Cheapest with <=1 stop: 200

## Edge Cases
- No path: return -1
- k=0: direct flight only
- Multiple paths, choose min cost

## Common Pitfalls
- Stops vs edges: k stops = k+1 edges
- Negative costs? No, all positive
- Cycle handling: priority queue prevents revisits with higher cost
