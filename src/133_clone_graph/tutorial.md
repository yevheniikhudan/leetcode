# 133. Clone Graph - Tutorial

This problem is a classic application of graph traversal (DFS or BFS) and hash mapping for deep copying structures.

## Key Concepts
- **DFS/BFS:** Used to traverse all nodes and edges.
- **Hash Map:** Used to map original nodes to their clones to avoid cycles and repeated work.

## Approach Outline
1. Use a hash map to store the mapping from original nodes to their clones.
2. Traverse the graph using DFS or BFS.
3. For each node, clone it if it hasn't been cloned yet, and recursively/iteratively clone its neighbors.

No code is provided here; see the solution files for language-specific skeletons.
