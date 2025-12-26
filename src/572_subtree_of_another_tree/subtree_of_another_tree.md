# 572. Subtree of Another Tree

**Difficulty:** Easy

## Problem Description

Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of `subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

## Examples

### Example 1:
```
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
```
Visual representation:
```
    root:           subRoot:
       3               4
      / \             / \
     4   5           1   2
    / \
   1   2
   
The subtree rooted at node 4 in root matches subRoot exactly.
```

### Example 2:
```
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
```
Visual representation:
```
    root:           subRoot:
       3               4
      / \             / \
     4   5           1   2
    / \
   1   2
      /
     0
     
The subtree rooted at node 4 in root has an extra node (0),
so it does NOT match subRoot.
```

## Constraints

- The number of nodes in the `root` tree is in the range `[1, 2000]`.
- The number of nodes in the `subRoot` tree is in the range `[1, 1000]`.
- `-10^4 <= root.val <= 10^4`
- `-10^4 <= subRoot.val <= 10^4`

## Topics

- Tree
- Depth-First Search
- String Matching
- Binary Tree
- Hash Function

## Related Problems

- Same Tree (Easy)
- Count Univalue Subtrees (Medium)
- Most Frequent Subtree Sum (Medium)

## Hints

1. Which approach is better here - recursive or iterative?
2. If recursive approach is better, can you write recursive function with its parameters?
3. Two trees s and t are said to be identical if their root values are same and their left and right subtrees are identical. Can you write this in form of recursive formulae?
4. Recursive formulae can be: `isIdentical(s,t) = s.val == t.val AND isIdentical(s.left, t.left) AND isIdentical(s.right, t.right)`

## Acceptance Rate

50.9%
