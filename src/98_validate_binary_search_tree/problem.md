# 98. Validate Binary Search Tree

**Difficulty**: Medium

**Topics**: Tree, Depth-First Search, Binary Search Tree, Binary Tree

## Problem Description

Given the `root` of a binary tree, return `true` if it is a valid binary search tree, otherwise return `false`.

A valid binary search tree satisfies the following constraints:

- The left subtree of every node contains only nodes with keys **less than** the node's key.
- The right subtree of every node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees are also binary search trees.

## Examples

### Example 1:

```
Input: root = [2,1,3]
Output: true
```

Visual representation:
```
    2
   / \
  1   3
```

### Example 2:

```
Input: root = [1,2,3]
Output: false
```

Visual representation:
```
    1
   / \
  2   3
```
Explanation: The root node's value is 1 but its left child's value is 2 which is greater than 1.

### Example 3:

```
Input: root = [5,1,4,null,null,3,6]
Output: false
```

Visual representation:
```
      5
     / \
    1   4
       / \
      3   6
```
Explanation: The root node's value is 5. However, its right child's value is 4, and the right subtree contains 3 which is less than 5.

## Constraints

- `1 <= The number of nodes in the tree <= 1000`
- `-1000 <= Node.val <= 1000`

## Related Problems

- 94. Binary Tree Inorder Traversal
- 501. Find Mode in Binary Search Tree
- 530. Minimum Absolute Difference in BST
- 700. Search in a Binary Search Tree
