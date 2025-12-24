# 226. Invert Binary Tree

**Difficulty:** Easy  
**Topics:** Tree, Depth-First Search, Breadth-First Search, Binary Tree

## Problem Statement

Given the `root` of a binary tree, invert the tree, and return its root.

## Examples

### Example 1:
```
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Visual:
     4                    4
   /   \                /   \
  2     7      =>      7     2
 / \   / \            / \   / \
1   3 6   9          9   6 3   1
```

### Example 2:
```
Input: root = [2,1,3]
Output: [2,3,1]

Visual:
   2                2
  / \      =>      / \
 1   3            3   1
```

### Example 3:
```
Input: root = []
Output: []
```

## Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## Note

This problem became famous when Max Howell (creator of Homebrew) tweeted:
> "Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so f*** off."

## Related Problems

- [Reverse Odd Levels of Binary Tree](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/) (Medium)
