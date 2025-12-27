# 199. Binary Tree Right Side View

**Difficulty:** Medium

## Problem Description

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return the values of the nodes you can see ordered from top to bottom.

## Examples

### Example 1:
```
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```
Visual representation:
```
      1      ← visible (rightmost at level 0)
     / \
    2   3    ← visible (rightmost at level 1)
     \   \
      5   4  ← visible (rightmost at level 2)

Standing on the right side, you see: 1, 3, 4
```

### Example 2:
```
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]
```
Visual representation:
```
        1        ← visible (level 0)
       / \
      2   3      ← visible (level 1)
     /
    4            ← visible (level 2)
   /
  5              ← visible (level 3)

Standing on the right side, you see: 1, 3, 4, 5
Note: Even though 4 and 5 are on the left side of the tree,
they are the rightmost nodes at their respective levels.
```

### Example 3:
```
Input: root = [1,null,3]
Output: [1,3]
```
Visual representation:
```
    1    ← visible
     \
      3  ← visible
```

### Example 4:
```
Input: root = []
Output: []
```
Empty tree returns empty list.

## Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## Topics

- Tree
- Depth-First Search
- Breadth-First Search
- Binary Tree

## Related Problems

- Populating Next Right Pointers in Each Node (Medium)
- Boundary of Binary Tree (Medium)

## Key Insights

1. **Right side view** = The **rightmost node** at each level
2. **Not always the right child**: If right child doesn't exist at a level, the left child is visible
3. **Level-by-level processing**: Natural fit for BFS (level order traversal)
4. **Alternative: DFS with right-first traversal**: Visit right subtree before left

## Acceptance Rate

69.0%
