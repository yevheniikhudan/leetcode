# 297. Serialize and Deserialize Binary Tree

**Difficulty:** Hard

## Problem Description

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as [how LeetCode serializes a binary tree](https://support.leetcode.com/hc/en-us/articles/32442719377939-How-to-create-test-cases-on-LeetCode#h_01J5EGREAW3NAEJ14XC07GRW1A). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

## Examples

### Example 1:
```
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

    1
   / \
  2   3
     / \
    4   5
```

### Example 2:
```
Input: root = []
Output: []
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-1000 <= Node.val <= 1000`

## Topics
- String
- Tree
- Depth-First Search
- Breadth-First Search
- Design
- Binary Tree

## Companies
Amazon, Google, Facebook, Microsoft, Bloomberg

## Similar Problems
- Encode and Decode Strings (Medium)
- Serialize and Deserialize BST (Medium)
- Find Duplicate Subtrees (Medium)
- Serialize and Deserialize N-ary Tree (Hard)

## Hints
1. Your serialized format can be anything, but it must be reversible.
2. Consider using preorder traversal with null markers, or level-order with nulls.
3. For deserialization, use a queue or index to reconstruct the tree.
4. Be careful with empty trees and null children.
