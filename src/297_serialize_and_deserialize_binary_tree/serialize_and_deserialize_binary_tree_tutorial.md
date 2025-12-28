# Tutorial: Serialize and Deserialize Binary Tree

## Understanding the Problem

We need to design an algorithm to convert a binary tree to a string (serialize) and back (deserialize), with no restrictions on the format as long as it is reversible.

## Common Approaches

### 1. Preorder Traversal with Null Markers
- Traverse the tree in preorder (root, left, right)
- Use a special marker (e.g., "#" or "null") for null children
- Serialize as a comma-separated string
- Example: [1,2,3,null,null,4,5] → "1,2,#,#,3,4,#,#,5,#,#"

### 2. Level-Order Traversal (BFS) with Nulls
- Traverse the tree level by level
- Use "null" for missing children
- Serialize as a comma-separated string
- Example: [1,2,3,null,null,4,5] → "1,2,3,null,null,4,5,null,null,null,null"

## Implementation Details

### Serialization
- For preorder: recursively append value or null marker
- For level-order: use a queue, append value or null marker

### Deserialization
- For preorder: use an index or iterator to reconstruct tree recursively
- For level-order: use a queue to reconstruct children

## Example Walkthrough

Given tree:
```
    1
   / \
  2   3
     / \
    4   5
```
Preorder serialization: "1,2,#,#,3,4,#,#,5,#,#"

## Complexity Analysis
- Time: O(n) for both serialization and deserialization
- Space: O(n) for the output string and recursion/queue

## Pitfalls
- Forgetting to handle null children
- Not handling empty trees
- Not using a reversible format

## Tips
- Use split/join for string manipulation
- Use a queue or index for deserialization
- Test with empty and single-node trees
