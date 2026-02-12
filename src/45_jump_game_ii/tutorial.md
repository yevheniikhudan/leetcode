# Tutorial: Jump Game II

## Understanding the Problem

We need the minimum number of jumps to reach the last index. A greedy approach works well: keep track of the current range reachable with the current number of jumps, and the farthest index reachable within that range. When we exhaust the current range, we make another jump and extend the range to the farthest.

## Approaches

### 1. Greedy (O(n) time, O(1) space)
- Maintain `jumps`, `end` (current range end), and `farthest` (farthest reach within current range).
- Iterate i from 0 to n-2:
  - Update `farthest = max(farthest, i + nums[i])`.
  - If i == end: jumps++, end = farthest.

### 2. BFS / Level order on indices
- Each level represents one jump. Enqueue reachable indices, etc. O(n^2) worst-case.

### 3. Dynamic Programming
- DP[i] = min jumps to reach i. O(n^2) time.

Greedy is the preferred solution for constraints.

## Edge Cases
- Single element: 0 jumps.
- Large jumps early: early termination.

## Complexity
- Greedy: O(n) time, O(1) extra space.
- BFS/DP: O(n^2) time, O(n) space.
