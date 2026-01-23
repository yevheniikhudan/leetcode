# Tutorial: Reconstruct Itinerary

## Understanding the Problem
Given flight tickets as [departure, arrival], reconstruct the travel path starting from JFK, using each ticket exactly once, choosing the lexicographically smallest path.

## Key Concepts
- **Graph Representation:** Model airports as nodes, tickets as directed edges.
- **Eulerian Path:** Find a path that visits each edge exactly once.
- **Lexical Order:** Choose smallest airport names at each step.

## Approaches

### 1. DFS with Backtracking (Optimal)
- Build adjacency list, sort destinations lexicographically.
- DFS from JFK, remove used edges, backtrack if stuck.
- Collect path in reverse order.

**Time Complexity:** O(E log E) (sorting edges)  
**Space Complexity:** O(E + V)

### 2. Hierholzer's Algorithm
- Similar to DFS, but more efficient for Eulerian paths.
- Traverse until stuck, then backtrack.

**Time Complexity:** O(E log E)  
**Space Complexity:** O(E + V)

## Visual Example
Tickets: [["JFK","MUC"],["MUC","LHR"],["LHR","SFO"],["SFO","SJC"]]

Graph: JFK -> MUC -> LHR -> SFO -> SJC

Path: JFK, MUC, LHR, SFO, SJC

## Edge Cases
- Single ticket: ["JFK", "ABC"] -> ["JFK", "ABC"]
- Multiple from same airport: Choose smallest first.
- Cycles: Ensure all tickets used.

## Common Pitfalls
- Not sorting destinations: Wrong lexical order.
- Not removing used tickets: Reuse edges.
- Starting from wrong airport.

## Optimization Notes
- Sort adjacency lists for lexical order.
- Use stack for DFS to avoid recursion depth issues.
