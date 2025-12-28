# Tutorial: Binary Tree Maximum Path Sum

## Understanding the Problem

This is a **hard** problem that requires understanding what constitutes a valid path and how to maximize its sum.

**Key Concepts:**
1. A path can start and end at **any nodes** (doesn't need to go through root)
2. A path connects nodes via parent-child edges
3. Each node appears **at most once** in a path
4. We need to find the **maximum sum** among all possible paths

## Problem Analysis

### What paths are valid?

Valid paths include:
- Single node: `[5]`
- Parent-child chain: `[2, 1, 3]`
- Inverted V shape: `[left child, parent, right child]`
- Any combination going up then down (or just up, or just down)

### What paths are NOT valid?
- Paths that require visiting a node twice
- Paths that "go up" after "going down"

## Approach: Post-Order DFS with Global Maximum

### Key Insight

At each node, we have **two different values to track**:

1. **Local maximum path** (for updating global answer):
   - Can include both left and right subtrees (forming "∧" shape)
   - `node.val + max_left_gain + max_right_gain`
   - This is checked against the global maximum

2. **Return value** (for parent node to use):
   - Can only include ONE subtree (left OR right)
   - `node.val + max(max_left_gain, max_right_gain)`
   - This ensures paths don't branch (no visiting same node twice)

### Algorithm Steps

```
1. Initialize global variable: max_sum = -infinity

2. For each node (post-order DFS):
   a. Base case: if node is null, return 0
   
   b. Recursively get max gain from left subtree
      - max_left = max(0, dfs(node.left))
      - Use max(0, ...) to ignore negative paths
   
   c. Recursively get max gain from right subtree
      - max_right = max(0, dfs(node.right))
   
   d. Calculate path sum through current node (both sides):
      - current_path_sum = node.val + max_left + max_right
      - Update global max_sum if this is better
   
   e. Return max gain going through current node (one side):
      - return node.val + max(max_left, max_right)

3. Return max_sum
```

### Example Walkthrough

```
Tree: [-10, 9, 20, null, null, 15, 7]

       -10
       / \
      9  20
        /  \
       15   7
```

**Step-by-step execution:**

1. **Node 9** (leaf):
   - max_left = 0, max_right = 0
   - current_path = 9 + 0 + 0 = 9
   - max_sum = 9
   - returns 9

2. **Node 15** (leaf):
   - current_path = 15
   - max_sum = 15
   - returns 15

3. **Node 7** (leaf):
   - current_path = 7
   - max_sum = 15 (no change)
   - returns 7

4. **Node 20**:
   - max_left = 15, max_right = 7
   - current_path = 20 + 15 + 7 = 42 ✨
   - max_sum = 42
   - returns 20 + max(15, 7) = 35 (can only take one path up)

5. **Node -10** (root):
   - max_left = max(0, 9) = 9
   - max_right = max(0, 35) = 35
   - current_path = -10 + 9 + 35 = 34
   - max_sum = 42 (no change)
   - returns -10 + 35 = 25

**Answer: 42** (path 15 → 20 → 7)

## Why Use max(0, child_gain)?

If a subtree has negative sum, we're better off **not including it** in our path. Using `max(0, gain)` ensures we only add positive contributions.

Example:
```
      5
     /
   -3
```
Without max(0, ...): path sum = 5 + (-3) = 2
With max(0, ...): path sum = 5 + 0 = 5 ✓

## Complexity Analysis

### Time Complexity: O(n)
- Visit each node exactly once in DFS
- O(1) work at each node

### Space Complexity: O(h)
- Recursion stack depth = tree height
- Best case (balanced): O(log n)
- Worst case (skewed): O(n)

## Common Pitfalls

1. **Returning the wrong value**: Remember to return `node.val + max(left, right)`, not the full path sum
2. **Forgetting max(0, ...)**: Negative paths should be excluded
3. **Not initializing max_sum correctly**: Use `-infinity` or smallest possible value, not 0
4. **Confusing local vs global maximum**: The path through a node (local) vs the answer (global)

## Implementation Tips

1. Use a class variable or nonlocal variable for `max_sum`
2. Handle null nodes at the start of the recursive function
3. Calculate both the local maximum (for update) and return value (for parent) separately
4. Remember: local uses both children, return uses only one
