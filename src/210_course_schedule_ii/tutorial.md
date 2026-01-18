# Tutorial: Course Schedule II (Topological Sort)

This problem is a direct extension of Course Schedule I. Instead of just checking if all courses can be finished, you must return a valid order to take the courses (topological order of the graph).

**Approach:**
- Build the graph using adjacency lists.
- Use Kahn's algorithm (BFS) or DFS to generate a topological order.
- If a cycle is detected (not all nodes are included in the order), return an empty list.

**Key Points:**
- Kahn's algorithm uses in-degree counting and a queue to build the order.
- DFS approach can also be used to build the order in reverse postorder.
- Both approaches are efficient for the given constraints.

*No code is provided in this tutorial, only the algorithmic idea.*
