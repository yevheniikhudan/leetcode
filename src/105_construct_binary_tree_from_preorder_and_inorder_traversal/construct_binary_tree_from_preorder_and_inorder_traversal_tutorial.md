# Tutorial: Construct Binary Tree from Preorder and Inorder Traversal

## Understanding the Problem

We need to reconstruct a binary tree given its preorder and inorder traversals.

**Key Observations:**
1. **Preorder traversal**: Root → Left → Right
2. **Inorder traversal**: Left → Root → Right
3. The first element in preorder is always the root
4. Once we know the root, we can find it in inorder to determine left and right subtrees

## Approach: Recursive Divide and Conquer

### Algorithm

1. **Base case**: If arrays are empty, return `null`

2. **Find root**: First element of preorder is the root

3. **Split inorder array**:
   - Find root's position in inorder
   - Everything to the left belongs to left subtree
   - Everything to the right belongs to right subtree

4. **Split preorder array**:
   - Skip the root (first element)
   - Next `leftSize` elements belong to left subtree
   - Remaining elements belong to right subtree

5. **Recursively build subtrees**:
   - Build left subtree from left portions
   - Build right subtree from right portions

### Example Walkthrough

```
preorder = [3,9,20,15,7]
inorder  = [9,3,15,20,7]
```

**Step 1:** Root is 3 (first in preorder)
```
Find 3 in inorder: [9, | 3 |, 15,20,7]
Left subtree inorder: [9]
Right subtree inorder: [15,20,7]
```

**Step 2:** Split preorder accordingly
```
preorder without root: [9,20,15,7]
Left subtree preorder: [9] (size 1)
Right subtree preorder: [20,15,7] (remaining)
```

**Step 3:** Recursively build left subtree
```
preorder = [9]
inorder = [9]
Root = 9 (leaf node)
```

**Step 4:** Recursively build right subtree
```
preorder = [20,15,7]
inorder = [15,20,7]
Root = 20
Left subtree: [15]
Right subtree: [7]
```

Final tree:
```
      3
     / \
    9  20
      /  \
     15   7
```

## Optimization: HashMap for O(1) Lookups

Instead of searching for root in inorder array every time (O(n)), use a hashmap to store index of each value in inorder (O(1) lookup).

## Complexity Analysis

### Time Complexity: O(n)
- We visit each node exactly once
- With hashmap, finding root position is O(1)
- Total: O(n)

### Space Complexity: O(n)
- Hashmap stores n elements: O(n)
- Recursion stack in worst case (skewed tree): O(n)
- Total: O(n)

## Common Pitfalls

1. **Off-by-one errors** when splitting arrays
2. **Not handling edge cases** (empty tree, single node)
3. **Inefficient search** without hashmap (O(n²) total time)
4. **Incorrect index calculations** for preorder splits

## Implementation Tips

1. Use a hashmap to store inorder indices
2. Pass indices instead of creating new arrays (more efficient)
3. Keep track of preorder index as you build the tree
4. Handle base cases carefully (empty ranges)
