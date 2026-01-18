# Tutorial: Graph Valid Tree

A valid tree is an undirected graph that is connected and acyclic.

**Approach:**
- The graph must have exactly n-1 edges for n nodes.
- Use BFS or DFS to check if the graph is connected (all nodes are reachable from node 0).
- During traversal, check for cycles (a visited node that is not the parent).
- If all nodes are visited and no cycles are found, the graph is a valid tree.

*No code is provided in this tutorial, only the algorithmic idea.*
