# 110. Balanced Binary Tree

**Difficulty:** Easy  
**Topics:** Tree, Depth-First Search, Binary Tree

## Problem Statement

Given a binary tree, determine if it is **height-balanced**.

A **height-balanced** binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

## Examples

### Example 1:
```
Input: root = [3,9,20,null,null,15,7]
Output: true

Visual:
    3
   / \
  9  20
    /  \
   15   7

Explanation: 
- Node 3: left height = 1, right height = 2, diff = 1 ✓
- Node 9: left height = 0, right height = 0, diff = 0 ✓
- Node 20: left height = 1, right height = 1, diff = 0 ✓
All nodes satisfy the balanced condition.
```

### Example 2:
```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Visual:
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4

Explanation:
- Node 2: left height = 2, right height = 0, diff = 2 ✗
The left subtree of node 2 is not balanced (height difference > 1).
```

### Example 3:
```
Input: root = []
Output: true

Explanation: An empty tree is considered balanced.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-10^4 <= Node.val <= 10^4`

## Related Problems

- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) (Easy)
- [K-th Largest Perfect Subtree Size in Binary Tree](https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/) (Medium)
- [Check Balanced String](https://leetcode.com/problems/check-balanced-string/) (Easy)
