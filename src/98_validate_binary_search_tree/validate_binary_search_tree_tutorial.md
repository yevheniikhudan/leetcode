# Tutorial: Validate Binary Search Tree

## Understanding the Problem

A **Binary Search Tree (BST)** has a strict ordering property:
- **Every** node in the left subtree must be **less than** the node
- **Every** node in the right subtree must be **greater than** the node
- This property must hold for **all** nodes in the tree

### Common Misconception

❌ **WRONG**: Just checking if `left.val < node.val < right.val` is NOT enough!

Example of why this fails:
```
      5
     / \
    1   4
       / \
      3   6
```
- Node 5: 1 < 5 < 4? No, but that's not even the issue
- Node 4: 3 < 4 < 6? Yes, looks valid locally
- **BUT**: Node 3 is in the right subtree of 5, so it must be > 5, but 3 < 5
- **Result**: Invalid BST!

### Key Insight

Each node has a **valid range** of values it can take:
- Root can be any value: `(-∞, +∞)`
- Left child must be in range: `(-∞, parent.val)`
- Right child must be in range: `(parent.val, +∞)`

As we traverse down, we narrow the valid range for each subtree.

## Approach 1: DFS with Range Validation (Recommended)

### Strategy

Pass down the valid range `(min, max)` for each node. A node is valid if its value is within this range, and both subtrees are valid with updated ranges.

### Steps

1. Start at root with range `(-∞, +∞)`
2. For each node:
   - Check if `min < node.val < max`
   - Recursively validate left subtree with range `(min, node.val)`
   - Recursively validate right subtree with range `(node.val, max)`
3. Return true only if all nodes are valid

### Example Walkthrough

```
Tree: [2,1,3]
      2
     / \
    1   3

Node 2: min=-∞, max=+∞ → -∞ < 2 < +∞ ✓
  Node 1 (left): min=-∞, max=2 → -∞ < 1 < 2 ✓
  Node 3 (right): min=2, max=+∞ → 2 < 3 < +∞ ✓
Result: Valid BST
```

```
Tree: [5,1,4,null,null,3,6]
        5
       / \
      1   4
         / \
        3   6

Node 5: min=-∞, max=+∞ → -∞ < 5 < +∞ ✓
  Node 1 (left): min=-∞, max=5 → -∞ < 1 < 5 ✓
  Node 4 (right): min=5, max=+∞ → 5 < 4 < +∞? NO! 4 < 5 ✗
Result: Invalid BST
```

### Time & Space Complexity

- **Time Complexity**: O(n) - visit each node once
- **Space Complexity**: O(h) - recursion stack depth
  - Best case (balanced): O(log n)
  - Worst case (skewed): O(n)

## Approach 2: Inorder Traversal

### Strategy

A valid BST has an **inorder traversal that is strictly increasing**. Perform inorder traversal and check if values are strictly ascending.

### Steps

1. Perform inorder traversal (left → node → right)
2. Keep track of the previous value visited
3. For each node, check if `current.val > previous.val`
4. If any value is not greater than the previous, return false

### Why This Works

Inorder traversal of a BST visits nodes in ascending order:
```
BST:     3          Inorder: 1, 2, 3, 4, 5
        / \
       2   4
      /     \
     1       5
```

### Implementation Variations

**Variation 1**: Store all values in array, then check
- Space: O(n) - stores all values
- Simple but uses extra space

**Variation 2**: Track previous value during traversal
- Space: O(h) - only recursion stack
- More efficient

### Time & Space Complexity

- **Time Complexity**: O(n) - visit each node once
- **Space Complexity**: 
  - With array: O(n)
  - With previous tracking: O(h)

## Approach 3: Iterative with Stack

### Strategy

Use an explicit stack to perform iterative DFS with range validation, avoiding recursion depth limits.

### Steps

1. Initialize stack with `(root, -∞, +∞)`
2. While stack is not empty:
   - Pop `(node, min, max)`
   - Check if `min < node.val < max`
   - Push right child with `(node.val, max)`
   - Push left child with `(min, node.val)`
3. Return true if all checks pass

### Time & Space Complexity

- **Time Complexity**: O(n)
- **Space Complexity**: O(h) for stack

## Comparison of Approaches

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| DFS with Range | O(n) | O(h) | Clear logic, efficient | Need to handle infinity |
| Inorder Array | O(n) | O(n) | Simple to understand | Extra space |
| Inorder Previous | O(n) | O(h) | Space efficient | Slightly complex |
| Iterative Stack | O(n) | O(h) | No recursion limit | More code |

**Recommendation**: Use **DFS with Range** (Approach 1) for clarity and efficiency.

## Common Pitfalls

1. **Only comparing with parent**: Must check entire subtree constraints
   ```
   Wrong: node.left.val < node.val < node.right.val
   Right: ALL left subtree values < node.val < ALL right subtree values
   ```

2. **Not handling duplicates**: BST requires strict ordering (< and >, not <=)
   ```
   Tree: [5,5,6] → Invalid (left child equals parent)
   ```

3. **Integer overflow with infinity**: 
   - Using `float('inf')` and `float('-inf')` in Python ✓
   - Using `Integer.MIN_VALUE` and `Integer.MAX_VALUE` in Java might fail if tree has these values
   - Use `Long` or `null` to represent infinity

4. **Not checking null nodes**: Always check if node is null before accessing

## Edge Cases to Consider

1. **Single node**: Always a valid BST
2. **Two nodes**: Check left < parent or parent < right
3. **Tree with boundary values**: -1000 and 1000
4. **Skewed tree**: All nodes on one side
5. **Complete BST**: All levels filled
6. **Nearly valid BST**: One node violates the property

## Handling Infinity Values

### Python
```
Use float('-inf') and float('inf')
```

### Java
```
Use Long.MIN_VALUE and Long.MAX_VALUE
Or use null to represent no bound
```

### C++
```
Use LLONG_MIN and LLONG_MAX from <climits>
Or use nullptr with optional<long long>
```

## Optimization Tips

1. **Early termination**: Return false as soon as invalid node is found
2. **Pass by value for primitives**: Ranges are small, no need for references
3. **Iterative for very deep trees**: Avoid stack overflow
4. **Inorder for sorted output**: If you need the sorted values anyway

## Pattern Recognition

This problem demonstrates:
- **Valid range propagation**: Passing constraints down through recursion
- **BST property validation**: Understanding tree invariants
- **Inorder traversal**: Leveraging BST sorting property
- **Recursive tree validation**: Checking global properties with local checks

## Testing Strategy

Test with:
1. Single node tree
2. Valid BST (balanced)
3. Invalid BST (root violates property)
4. Invalid BST (deeper node violates property)
5. Left-skewed BST
6. Right-skewed BST
7. Tree with negative values
8. Tree with boundary values (-1000, 1000)
9. Tree where only comparing with parent would fail
