# Same Tree - Tutorial

## Problem Understanding

We need to determine if two binary trees are **exactly the same** in both structure and node values. Two trees are considered the same if:
1. They have the same structure (same shape)
2. Corresponding nodes have the same values

## Intuition

The key insight is that two trees are identical if:
- Both roots are null (empty trees), OR
- Both roots exist AND have the same value AND their left subtrees are identical AND their right subtrees are identical

This is a natural recursive problem - to check if two trees are the same, we check if their roots match and then recursively check their subtrees.

## Approaches

### Approach 1: Recursive DFS (Depth-First Search)

**Concept:**
- Base cases:
  - If both trees are null → they are the same (return true)
  - If one tree is null and the other isn't → they are different (return false)
  - If both exist but have different values → they are different (return false)
- Recursive case:
  - Recursively check if left subtrees are the same
  - Recursively check if right subtrees are the same
  - Both must be true for the trees to be identical

**Visual Example:**
```
Comparing:
    p:          q:
    1           1
   / \         / \
  2   3       2   3

Step 1: Compare roots (1 == 1) ✓
Step 2: Compare left subtrees (2 == 2, both leaves) ✓
Step 3: Compare right subtrees (3 == 3, both leaves) ✓
Result: true
```

**Another Example (Different):**
```
Comparing:
    p:          q:
    1           1
   /             \
  2               2

Step 1: Compare roots (1 == 1) ✓
Step 2: Compare left subtrees:
  - p has left child (2)
  - q has null left child
  - One is null, other isn't → false
Result: false
```

**Time Complexity:** O(min(n, m)) where n and m are the number of nodes in p and q
- We visit each node at most once
- We stop as soon as we find a mismatch

**Space Complexity:** O(min(h1, h2)) where h1 and h2 are the heights of the two trees
- Recursive call stack depth
- In worst case (skewed tree), this is O(n)
- In best case (balanced tree), this is O(log n)

### Approach 2: Iterative BFS (Breadth-First Search)

**Concept:**
- Use two queues (one for each tree)
- Traverse both trees level by level simultaneously
- At each step, dequeue a node from each queue and compare:
  - If both are null → continue
  - If one is null → return false
  - If values differ → return false
  - Otherwise, enqueue their children

**Visual Example:**
```
Comparing:
    p:          q:
    1           1
   / \         / \
  2   3       2   3

Queue states:
Initial: queueP = [1], queueQ = [1]
After dequeuing roots: queueP = [2, 3], queueQ = [2, 3]
After dequeuing 2's: queueP = [3], queueQ = [3]
After dequeuing 3's: queueP = [], queueQ = []
All matched → true
```

**Time Complexity:** O(min(n, m))
- We visit each node at most once

**Space Complexity:** O(min(w1, w2)) where w1 and w2 are the maximum widths of the two trees
- Queue size is proportional to the maximum width of the tree
- For a complete binary tree, this is O(n/2) = O(n)

### Approach 3: Iterative DFS with Stack

**Concept:**
- Similar to BFS but uses a stack instead of a queue
- Push pairs of corresponding nodes onto the stack
- Pop and compare nodes until stack is empty

**Time Complexity:** O(min(n, m))
**Space Complexity:** O(min(h1, h2))

## Edge Cases to Consider

1. **Both trees are empty (null)**: Should return `true`
2. **One tree is empty, the other is not**: Should return `false`
3. **Single node trees**: Compare values directly
4. **Trees with same structure but different values**: Should return `false`
5. **Trees with different structures**: Should return `false` as soon as structural difference is found
6. **Mirror trees**: Should return `false` (they are different)
7. **Complete identical trees**: Should return `true`

## Common Pitfalls

1. **Not handling null cases properly**: Must check if both are null, one is null, or both exist
2. **Forgetting to check both subtrees**: Must verify both left AND right subtrees match
3. **Not short-circuiting early**: Can return false as soon as a mismatch is found
4. **Comparing only values without structure**: Trees must have identical structure

## Key Takeaways

- This is a fundamental tree comparison problem
- The recursive approach is the most natural and elegant
- The problem tests understanding of:
  - Tree traversal (DFS/BFS)
  - Recursive thinking
  - Handling base cases (null trees)
- The same logic applies to comparing any two recursive data structures
- This problem is a building block for more complex tree problems (e.g., Symmetric Tree, Subtree of Another Tree)

## Comparison of Approaches

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Recursive DFS | O(min(n,m)) | O(min(h1,h2)) | Clean, intuitive, easy to understand | Uses call stack (could overflow for very deep trees) |
| Iterative BFS | O(min(n,m)) | O(min(w1,w2)) | No recursion, explicit queue | More verbose, requires manual queue management |
| Iterative DFS | O(min(n,m)) | O(min(h1,h2)) | No recursion | More verbose than recursive version |

**Recommended Approach:** Recursive DFS for its simplicity and elegance.
