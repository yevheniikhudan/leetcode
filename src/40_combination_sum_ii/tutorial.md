# Combination Sum II - Tutorial

## Understanding the Problem

Given a list of candidate numbers (may contain duplicates) and a target, find all unique combinations that sum to the target. Each number can be used **at most once** per combination.

## Approaches

### Approach 1: Backtracking with Duplicate Skipping
- **Strategy:**
  - Sort candidates to group duplicates together.
  - Use recursion to build combinations.
  - At each step, skip candidates that are the same as the previous (to avoid duplicate combinations).
  - Only use each candidate once per combination (move to next index in recursion).
- **Key Concepts:**
  - Sorting allows easy duplicate skipping.
  - Track current index to ensure each candidate is used at most once.
  - Prune search when sum exceeds target.
- **Time Complexity:** Exponential in the worst case.
- **Space Complexity:** O(target) for recursion stack.

### Approach 2: Iterative (Not common for this problem)
- Backtracking is preferred for handling duplicates and single-use constraint.

## Edge Cases
- No solution: return an empty list.
- Candidates with duplicates: skip duplicates in the same recursive level.
- Candidates with only one number: only possible if target matches that number.

## Common Pitfalls
- Not skipping duplicates correctly (leads to duplicate combinations).
- Using the same candidate more than once per combination.
- Not backtracking correctly (forgetting to remove the last element).
