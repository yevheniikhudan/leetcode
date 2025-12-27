# Tutorial: Count Good Nodes in Binary Tree

## Understanding the Problem

A **good node** is defined as a node where its value is greater than or equal to all values of nodes in the path from the root to that node.

### Key Insights

1. **Root is always good**: The root has no ancestors, so it's always considered a good node
2. **Path-dependent**: Whether a node is "good" depends on the path taken from root, not the entire tree
3. **Track maximum**: We need to track the maximum value encountered along each path
4. **Comparison rule**: A node X is good if `X.val >= max_value_in_path_to_X`

### Visual Example

```
        3 (good: no ancestors)
       / \
      /   \
     1     4 (good: 4 >= 3)
    /     / \
   3     1   5 (good: 5 >= 4)
(good: 3>=3)  (not good: 1 < 4)

Path to each node:
- Root 3: [] → always good
- Node 1 (left): [3] → 1 < 3, not good
- Node 4 (right): [3] → 4 >= 3, good
- Node 3 (left-left): [3, 1] → 3 >= max(3,1)=3, good
- Node 1 (right-left): [3, 4] → 1 < 4, not good
- Node 5 (right-right): [3, 4] → 5 >= 4, good

Total: 4 good nodes (3, 4, 3, 5)
```

## Approach 1: Recursive DFS with Path Maximum

### Strategy

Use depth-first search to traverse the tree while maintaining the maximum value seen in the current path.

### Steps

1. Start at the root with the maximum value being the root's value
2. For each node visited:
   - Check if current node's value >= maximum value in path
   - If yes, increment the good node counter
   - Update the maximum value for subsequent nodes in this path
   - Recursively visit left and right children with the updated maximum
3. Return the total count

### Time & Space Complexity

- **Time Complexity**: O(n) - visit each node exactly once
- **Space Complexity**: O(h) - recursion call stack depth, where h is tree height
  - Best case (balanced tree): O(log n)
  - Worst case (skewed tree): O(n)

### Why This Works

Each path from root to any node is independent. By passing the maximum value down through recursive calls, we maintain path-specific information without needing to store entire paths.

## Approach 2: Iterative DFS with Stack

### Strategy

Use an explicit stack to simulate the recursive DFS, storing both the node and the maximum value in the path to that node.

### Steps

1. Initialize a stack with the root node and its value as the initial maximum
2. While the stack is not empty:
   - Pop a (node, max_so_far) pair
   - Check if node.val >= max_so_far, increment count if true
   - Calculate new_max = max(max_so_far, node.val)
   - Push right child with new_max (if exists)
   - Push left child with new_max (if exists)
3. Return the total count

### Time & Space Complexity

- **Time Complexity**: O(n) - visit each node once
- **Space Complexity**: O(h) - stack size in worst case
  - Average case: O(log n) for balanced trees
  - Worst case: O(n) for skewed trees

### Advantages

- No recursion depth limitations
- Explicit control over traversal order
- Can be easier to debug and visualize

## Approach 3: BFS with Queue

### Strategy

Use breadth-first search (level-order traversal) to process nodes, maintaining the maximum value for each path.

### Steps

1. Initialize a queue with the root node and its value
2. While the queue is not empty:
   - Dequeue a (node, max_so_far) pair
   - Check if node.val >= max_so_far, increment count if true
   - Calculate new_max = max(max_so_far, node.val)
   - Enqueue left child with new_max (if exists)
   - Enqueue right child with new_max (if exists)
3. Return the total count

### Time & Space Complexity

- **Time Complexity**: O(n) - visit each node once
- **Space Complexity**: O(w) - where w is the maximum width of the tree
  - Can be larger than DFS in wide, shallow trees
  - For complete binary tree: O(n/2) = O(n)

### When to Use

BFS can be useful when you want to process nodes level by level, but for this specific problem, DFS is more natural since we're tracking path information.

## Comparison of Approaches

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Recursive DFS | O(n) | O(h) | Clean, intuitive | Recursion limit |
| Iterative DFS | O(n) | O(h) | No recursion limit | More code |
| BFS | O(n) | O(w) | Level-by-level | Higher space for wide trees |

**Recommendation**: Use **Recursive DFS** for its simplicity and clarity.

## Common Pitfalls

1. **Using > instead of >=**: Remember that equal values are also considered "good"
   - Wrong: `if node.val > max_so_far`
   - Correct: `if node.val >= max_so_far`

2. **Not updating maximum correctly**: Always pass the maximum of current path
   - Wrong: Pass `node.val` to children
   - Correct: Pass `max(max_so_far, node.val)` to children

3. **Forgetting root is always good**: The root has no ancestors to compare against

4. **Comparing with parent only**: Must compare with maximum of entire path, not just parent

## Edge Cases to Consider

1. **Single node tree**: Should return 1 (root is always good)
2. **All nodes have same value**: All nodes should be good (use >= not >)
3. **Strictly increasing path**: All nodes in that path are good
4. **Strictly decreasing path**: Only root is good
5. **Negative values**: Algorithm works the same with negative numbers
6. **Very deep tree**: Consider stack depth for recursive solution

## Optimization Tips

1. **Pass values, not paths**: Instead of storing entire paths, just track the maximum
2. **Early termination**: Not applicable here (must visit all nodes)
3. **Choose DFS over BFS**: Better space complexity for most tree structures
4. **Use inline comparisons**: No need for separate max variable storage

## Testing Strategy

Test cases should cover:
- Standard binary tree with mixed values
- Single node
- All equal values
- Monotonically increasing values (all good)
- Monotonically decreasing values (only root good)
- Trees with negative values
- Skewed trees (left-only or right-only)
- Complete/balanced trees
- Trees with multiple levels

## Pattern Recognition

This problem exemplifies:
- **DFS with state tracking**: Passing information down through recursion/stack
- **Path-dependent calculations**: Decision at each node depends on ancestors
- **Tree traversal patterns**: Any traversal order works (pre/in/post-order DFS, or BFS)
