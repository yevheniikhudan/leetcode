# 543. Diameter of Binary Tree

**Difficulty:** Easy  
**Topics:** Tree, Depth-First Search, Binary Tree

## Problem Statement

Given the `root` of a binary tree, return the **length** of the **diameter** of the tree.

The **diameter** of a binary tree is the **length** of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The **length** of a path between two nodes is represented by the **number of edges** between them.

## Examples

### Example 1:
```
Input: root = [1,2,3,4,5]
Output: 3

Visual:
      1
     / \
    2   3
   / \
  4   5

Explanation: The diameter is 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
The path has 3 edges: 4->2, 2->1, 1->3 (or 5->2, 2->1, 1->3).
```

### Example 2:
```
Input: root = [1,2]
Output: 1

Visual:
  1
 /
2

Explanation: The diameter is 1, which is the length of the path [2,1].
The path has 1 edge: 2->1.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-100 <= Node.val <= 100`

## Related Problems

- [Diameter of N-Ary Tree](https://leetcode.com/problems/diameter-of-n-ary-tree/) (Medium)
- [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-characters/) (Hard)
