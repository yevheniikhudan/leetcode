# 104. Maximum Depth of Binary Tree

**Difficulty:** Easy  
**Topics:** Tree, Depth-First Search, Breadth-First Search, Binary Tree

## Problem Statement

Given the `root` of a binary tree, return its maximum depth.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

## Examples

### Example 1:
```
Input: root = [3,9,20,null,null,15,7]
Output: 3

Visual:
    3
   / \
  9  20
    /  \
   15   7

Explanation: The longest path is 3 -> 20 -> 15 (or 3 -> 20 -> 7), which has 3 nodes.
```

### Example 2:
```
Input: root = [1,null,2]
Output: 2

Visual:
  1
   \
    2

Explanation: The longest path is 1 -> 2, which has 2 nodes.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-100 <= Node.val <= 100`

## Related Problems

- [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) (Easy)
- [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/) (Easy)
- [Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/) (Easy)
- [Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees/) (Medium)
- [Amount of Time for Binary Tree to Be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/) (Medium)
- [Height of Binary Tree After Subtree Removal Queries](https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/) (Hard)
