# Tutorial: Course Schedule (Topological Sort)

This problem is a classic application of topological sorting in a directed graph. Each course is a node, and each prerequisite pair [a, b] is a directed edge from b to a. The task is to determine if the graph has a cycle (impossible to finish all courses) or is acyclic (possible to finish all courses).

**Approach:**
- Build the graph using adjacency lists.
- Use either Kahn's algorithm (BFS) or DFS to detect cycles.
- If all nodes can be visited in topological order, return True. If a cycle is detected, return False.

**Key Points:**
- Kahn's algorithm uses in-degree counting and a queue.
- DFS approach marks nodes as visiting/visited to detect cycles.
- Both approaches are efficient for the given constraints.

*No code is provided in this tutorial, only the algorithmic idea.*
