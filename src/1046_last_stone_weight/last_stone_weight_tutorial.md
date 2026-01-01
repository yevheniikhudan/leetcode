# 1046. Last Stone Weight — Tutorial

## Understanding the Problem
- You are given a list of stone weights.
- Each turn, smash the two heaviest stones.
- If they are equal, both are destroyed. If not, the heavier is reduced by the lighter's weight.
- Repeat until at most one stone remains.

## Visual Example
Suppose stones = [2,7,4,1,8,1]
- Smash 8 and 7 → 1 (stones: [2,4,1,1,1])
- Smash 4 and 2 → 2 (stones: [2,1,1,1])
- Smash 2 and 1 → 1 (stones: [1,1,1])
- Smash 1 and 1 → 0 (stones: [1])

## Approaches
- **Max-Heap (Priority Queue):**
  - Insert all stones into a max-heap.
  - While more than one stone remains, pop the two largest, smash, and push the result if nonzero.
  - Return the last stone or 0 if none remain.

## Complexity
- Time: O(n log n) for heap operations
- Space: O(n)

## Edge Cases
- All stones destroyed (return 0)
- Only one stone (return its weight)
- All stones same weight

## Optimization Notes
- Heap is the most efficient and direct approach for this problem.
