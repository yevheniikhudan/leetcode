# 235. Lowest Common Ancestor of a Binary Search Tree

**Difficulty:** Medium

## Problem Description

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): "The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**)."

## Examples

### Example 1:
```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```
Visual representation:
```
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

p = 2 (left subtree)
q = 8 (right subtree)
LCA = 6 (the split point)
```

### Example 2:
```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
```
Visual representation:
```
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

p = 2
q = 4 (in right subtree of 2)
LCA = 2 (node can be ancestor of itself)
```

### Example 3:
```
Input: root = [2,1], p = 2, q = 1
Output: 2
```
Visual representation:
```
    2
   /
  1

p = 2 (root)
q = 1 (left child)
LCA = 2
```

## Constraints

- The number of nodes in the tree is in the range `[2, 10^5]`.
- `-10^9 <= Node.val <= 10^9`
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the BST.

## Topics

- Tree
- Depth-First Search
- Binary Search Tree
- Binary Tree

## Related Problems

- Lowest Common Ancestor of a Binary Tree (Medium) - **Important variant without BST property**
- Smallest Common Region (Medium)
- Lowest Common Ancestor of a Binary Tree II (Medium)
- Lowest Common Ancestor of a Binary Tree III (Medium)
- Lowest Common Ancestor of a Binary Tree IV (Medium)

## Key Insights

1. **BST Property**: In a BST, left subtree values < node value < right subtree values
2. **Split Point**: The LCA is the node where p and q "split" (one goes left, one goes right)
3. **Both on Same Side**: If both p and q are smaller than current node, LCA is in left subtree
4. **Both on Same Side**: If both p and q are greater than current node, LCA is in right subtree
5. **Split or Match**: If one is on each side (or current node equals p or q), current node is the LCA

## Acceptance Rate

69.7%
