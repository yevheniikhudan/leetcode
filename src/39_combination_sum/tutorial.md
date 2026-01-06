# Combination Sum - Tutorial

## Understanding the Problem

Given a set of distinct positive integers (candidates) and a target, find all unique combinations where the chosen numbers sum to the target. Each number can be used unlimited times.

## Approaches

### Approach 1: Backtracking (DFS)
- **Strategy:**
  - Use recursion to build combinations.
  - At each step, try each candidate (including the same one again).
  - If the sum exceeds the target, backtrack.
  - If the sum equals the target, add the current combination to the result.
- **Key Concepts:**
  - Candidates can be reused (recurse with the same index).
  - Avoid duplicates by always moving forward in the candidate list.
- **Time Complexity:** Exponential in the worst case (O(2^target) for small candidates).
- **Space Complexity:** O(target) for recursion stack.

### Approach 2: Iterative (Not common for this problem)
- Usually, backtracking is preferred for clarity and flexibility.

### Approach 3: Dynamic Programming (for counting, not listing)
- Can be used to count the number of combinations, but not to list them efficiently.

## Edge Cases
- No solution: return an empty list.
- Candidates larger than target: skip them.
- Candidates with only one number: only possible if target is divisible by that number.

## Common Pitfalls
- Including duplicate combinations (avoid by always moving forward in the candidate list).
- Not handling unlimited use of each candidate.
- Not backtracking correctly (forgetting to remove the last element).
