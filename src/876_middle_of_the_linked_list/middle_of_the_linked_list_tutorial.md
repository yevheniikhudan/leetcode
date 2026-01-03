# Middle of the Linked List - Tutorial

## Understanding the Problem
Given a singly linked list, return the middle node. If there are two middle nodes, return the second one.

## Approaches
### 1. Two-Pointer (Fast/Slow)
- Use two pointers: slow and fast.
- Move slow by 1 step, fast by 2 steps.
- When fast reaches the end, slow is at the middle.
- If the list has even length, slow will be at the second middle node.

### 2. Array/List
- Traverse the list and store nodes in an array.
- Return the node at index n//2.

## Time/Space Complexity
- Two-Pointer: O(N) time, O(1) space
- Array: O(N) time, O(N) space

## Key Concepts
- Linked list traversal
- Two-pointer technique

## Edge Cases
- Single node
- Even number of nodes

*No code in this tutorial section.*
