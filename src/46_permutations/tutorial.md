# Permutations - Tutorial

## Understanding the Problem

Given an array of distinct integers, generate all possible permutations (orderings) of the array.

## Approaches

### Approach 1: Backtracking (DFS)
- **Strategy:**
  - Use recursion to build permutations.
  - At each step, choose an unused element and add it to the current permutation.
  - Mark elements as used (e.g., with a boolean array or by removing from a list).
  - When the permutation reaches the length of the input, add it to the result.
- **Key Concepts:**
  - Backtracking: undo the last choice before trying the next.
  - Each recursive call represents a decision for the next position.
- **Time Complexity:** O(n!)
- **Space Complexity:** O(n) for recursion stack and current permutation.

### Approach 2: Iterative (Heap's Algorithm)
- Can be used for generating permutations, but backtracking is preferred for interviews.

## Edge Cases
- Single element: only one permutation.
- Empty array: (not allowed by constraints).

## Common Pitfalls
- Not marking elements as used/un-used correctly.
- Not copying the current permutation before adding to results.
- Generating duplicate permutations (not an issue with distinct elements).
