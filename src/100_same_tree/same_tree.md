# 100. Same Tree

**Difficulty:** Easy

## Problem Description

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

## Examples

### Example 1:
```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```
Visual representation:
```
    p:          q:
    1           1
   / \         / \
  2   3       2   3
```

### Example 2:
```
Input: p = [1,2], q = [1,null,2]
Output: false
```
Visual representation:
```
    p:          q:
    1           1
   /             \
  2               2
```

### Example 3:
```
Input: p = [1,2,1], q = [1,1,2]
Output: false
```
Visual representation:
```
    p:          q:
    1           1
   / \         / \
  2   1       1   2
```

## Constraints

- The number of nodes in both trees is in the range `[0, 100]`.
- `-10^4 <= Node.val <= 10^4`

## Topics

- Tree
- Depth-First Search
- Breadth-First Search
- Binary Tree

## Related Problems

- Symmetric Tree (Easy)
- Subtree of Another Tree (Easy)
- Invert Binary Tree (Easy)

## Acceptance Rate

66.3%
