# 994. Rotting Oranges - Tutorial

This problem is a classic application of Breadth-First Search (BFS) for grid traversal and multi-source propagation.

## Key Concepts
- **BFS:** Used to simulate the spread of rot from all rotten oranges simultaneously.
- **Queue:** Store the positions of all rotten oranges to process them level by level (minute by minute).
- **Visited/Marking:** Mark oranges as rotten as they are processed to avoid revisiting.

## Approach Outline
1. Add all initial rotten oranges to a queue.
2. For each minute, process all oranges in the queue and rot their fresh neighbors.
3. Continue until no more fresh oranges can be rotted.
4. Return the number of minutes elapsed, or -1 if some fresh oranges remain.

No code is provided here; see the solution files for language-specific skeletons.
