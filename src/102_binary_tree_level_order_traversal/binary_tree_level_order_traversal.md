# 102. Binary Tree Level Order Traversal

**Difficulty:** Medium

## Problem Description

Given the `root` of a binary tree, return the **level order traversal** of its nodes' values. (i.e., from left to right, level by level).

## Examples

### Example 1:
```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```
Visual representation:
```
      3
     / \
    9  20
      /  \
     15   7

Level 0: [3]
Level 1: [9, 20]
Level 2: [15, 7]
```

### Example 2:
```
Input: root = [1]
Output: [[1]]
```
Visual representation:
```
    1

Level 0: [1]
```

### Example 3:
```
Input: root = []
Output: []
```
Empty tree returns empty list.

## Constraints

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-1000 <= Node.val <= 1000`

## Topics

- Tree
- Breadth-First Search
- Binary Tree

## Related Problems

- Binary Tree Zigzag Level Order Traversal (Medium)
- Binary Tree Level Order Traversal II (Medium) - Bottom-up traversal
- Minimum Depth of Binary Tree (Easy)
- Binary Tree Vertical Order Traversal (Medium)
- Average of Levels in Binary Tree (Easy)
- N-ary Tree Level Order Traversal (Medium)
- Cousins in Binary Tree (Easy)
- Minimum Number of Operations to Sort a Binary Tree by Level (Medium)

## Hints

1. Use a queue to perform BFS (Breadth-First Search).

## Key Concepts

- **Level Order Traversal**: Visit all nodes at depth d before visiting nodes at depth d+1
- **BFS (Breadth-First Search)**: Use a queue to process nodes level by level
- **Queue**: FIFO data structure perfect for level-by-level processing

## Acceptance Rate

71.8%
