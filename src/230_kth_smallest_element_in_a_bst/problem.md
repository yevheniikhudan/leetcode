# 230. Kth Smallest Element in a BST

**Difficulty**: Medium

**Topics**: Tree, Depth-First Search, Binary Search Tree, Binary Tree

## Problem Description

Given the `root` of a binary search tree, and an integer `k`, return the `kth` smallest value (**1-indexed**) of all the values of the nodes in the tree.

## Examples

### Example 1:

```
Input: root = [3,1,4,null,2], k = 1
Output: 1
```

Visual representation:
```
    3
   / \
  1   4
   \
    2
```
Inorder traversal: [1, 2, 3, 4]  
1st smallest = 1

### Example 2:

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
```

Visual representation:
```
      5
     / \
    3   6
   / \
  2   4
 /
1
```
Inorder traversal: [1, 2, 3, 4, 5, 6]  
3rd smallest = 3

## Constraints

- The number of nodes in the tree is `n`
- `1 <= k <= n <= 10^4`
- `0 <= Node.val <= 10^4`

## Follow-up

If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

**Hint**: Consider augmenting the tree structure to store subtree sizes.

## Related Problems

- 94. Binary Tree Inorder Traversal
- 671. Second Minimum Node In a Binary Tree
- 285. Inorder Successor in BST
