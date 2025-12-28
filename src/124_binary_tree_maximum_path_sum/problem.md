# 124. Binary Tree Maximum Path Sum

**Difficulty:** Hard

## Problem Description

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path **does not need to pass through the root**.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return the **maximum path sum** of any **non-empty** path.

## Examples

### Example 1:
```
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

      1
     / \
    2   3
```

### Example 2:
```
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

       -10
       / \
      9  20
        /  \
       15   7
```

## Constraints

- The number of nodes in the tree is in the range `[1, 3 * 10^4]`
- `-1000 <= Node.val <= 1000`

## Topics

- Dynamic Programming
- Tree
- Depth-First Search
- Binary Tree

## Companies

Amazon, Facebook, Microsoft, Google, Apple

## Similar Problems

- Path Sum (Easy)
- Sum Root to Leaf Numbers (Medium)
- Longest Univalue Path (Medium)
- Time Needed to Inform All Employees (Medium)

## Hints

1. A path can start and end at any node in the tree
2. For each node, consider:
   - The node itself
   - The node + its left subtree path
   - The node + its right subtree path
   - The node + both left and right subtree paths (forming an "inverted V")
3. The key insight: At each node, you need to decide whether to include negative paths or not
4. Use a global variable to track the maximum path sum seen so far
5. The recursive function should return the maximum path sum starting from the current node going down (not forming a "V")
