# Lowest Common Ancestor of a Binary Search Tree - Tutorial

## Problem Understanding

We need to find the **Lowest Common Ancestor (LCA)** of two nodes in a **Binary Search Tree (BST)**.

**Key Definitions:**
- **Ancestor**: A node is an ancestor of another if it's on the path from root to that node
- **Common Ancestor**: A node that is an ancestor of both p and q
- **Lowest Common Ancestor**: The deepest (lowest) node that is an ancestor of both p and q
- **Important**: A node can be an ancestor of itself!

**Critical Insight:** This problem is specifically for a **BST**, not just any binary tree. The BST property makes this problem much simpler!

## BST Property Review

In a Binary Search Tree:
- All values in the **left subtree** are **less than** the node's value
- All values in the **right subtree** are **greater than** the node's value
- This property holds for **every node** in the tree

## Intuition

The key insight is finding the **split point** - the first node where p and q diverge into different subtrees (or where one of them matches the current node).

**Three scenarios at any node:**

1. **Both p and q are smaller than current node**
   - Both must be in the left subtree
   - LCA is also in the left subtree
   - Go left!

2. **Both p and q are greater than current node**
   - Both must be in the right subtree
   - LCA is also in the right subtree
   - Go right!

3. **p and q are on different sides (or current node equals p or q)**
   - Current node is the split point
   - This is the LCA!
   - Return current node

## Visual Example

```
Tree:      6
          / \
         2   8
        / \ / \
       0  4 7  9
         / \
        3   5

Finding LCA(2, 8):
Start at 6:
  - 2 < 6 (left)
  - 8 > 6 (right)
  - Split point! Return 6 ✓

Finding LCA(2, 4):
Start at 6:
  - 2 < 6 (left)
  - 4 < 6 (left)
  - Both left, go left to node 2
At node 2:
  - 2 == 2 (current node is p!)
  - Split point! Return 2 ✓

Finding LCA(3, 5):
Start at 6:
  - 3 < 6 (left)
  - 5 < 6 (left)
  - Both left, go left to node 2
At node 2:
  - 3 > 2 (right)
  - 5 > 2 (right)
  - Both right, go right to node 4
At node 4:
  - 3 < 4 (left)
  - 5 > 4 (right)
  - Split point! Return 4 ✓
```

## Approaches

### Approach 1: Recursive Solution

**Concept:**
- Base case: Current node is the split point → return it
- If both values are smaller → recurse left
- If both values are greater → recurse right

**Pseudocode:**
```
lowestCommonAncestor(root, p, q):
    if p.val < root.val AND q.val < root.val:
        return lowestCommonAncestor(root.left, p, q)
    
    if p.val > root.val AND q.val > root.val:
        return lowestCommonAncestor(root.right, p, q)
    
    return root  # Split point found!
```

**Why it works:**
- We use the BST property to guide our search
- We only recurse in one direction (never both)
- We stop as soon as we find the split point

**Time Complexity:** O(h) where h is the height of the tree
- Best case (balanced BST): O(log n)
- Worst case (skewed tree): O(n)
- We visit at most one node per level

**Space Complexity:** O(h) due to recursion stack
- Best case: O(log n)
- Worst case: O(n)

### Approach 2: Iterative Solution

**Concept:**
- Same logic as recursive, but using a while loop
- No recursion stack needed
- Often preferred for its simplicity

**Pseudocode:**
```
lowestCommonAncestor(root, p, q):
    current = root
    
    while current:
        if p.val < current.val AND q.val < current.val:
            current = current.left
        elif p.val > current.val AND q.val > current.val:
            current = current.right
        else:
            return current  # Split point!
```

**Time Complexity:** O(h)
**Space Complexity:** O(1) - **Better than recursive!**

### Approach 3: Generic Binary Tree Approach (Not Recommended Here)

For a **regular binary tree** (without BST property), you'd need to:
- Search both subtrees for p and q
- Track where each node is found
- Time: O(n), Space: O(h)

**But we don't need this!** The BST property gives us a much more efficient solution.

## Edge Cases to Consider

1. **One node is ancestor of the other**: Return the ancestor node itself
   - Example: LCA(2, 4) = 2 (where 4 is descendant of 2)

2. **Both nodes at same level**: Find their split point
   - Example: LCA(7, 9) = 8

3. **Nodes at different depths**: Standard case
   - Example: LCA(0, 9) = 6

4. **Root is one of the nodes**: Root can be LCA
   - Example: LCA(6, 8) = 6

5. **Adjacent nodes**: Parent is LCA
   - Example: LCA(2, 8) = 6

## Common Pitfalls

1. **Not using BST property**: Don't search both subtrees - use the ordering!
2. **Forgetting node can be its own ancestor**: Check for equality with current node
3. **Using node objects instead of values**: Compare `p.val` and `q.val`, not node references
4. **Overcomplicating**: This problem is simpler than it looks due to BST property

## Key Takeaways

1. **BST property simplifies the problem significantly**
   - Regular binary tree: O(n) time
   - BST: O(h) time (much better for balanced trees)

2. **Only traverse one path** - never need to search both subtrees

3. **Iterative solution is preferable** - cleaner and O(1) space

4. **Split point concept** - where paths to p and q diverge

5. **Compare values, not nodes** - use the BST ordering property

## Comparison of Approaches

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Recursive | O(h) | O(h) | Natural, easy to understand | Uses recursion stack |
| Iterative | O(h) | O(1) | No recursion, constant space | Slightly less intuitive |
| Generic Tree | O(n) | O(h) | Works for any binary tree | Ignores BST property, slower |

**Recommended Approach:** Iterative for optimal space complexity and clarity.

## Step-by-Step Example

```
Finding LCA(0, 5) in tree:
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

Step 1: At node 6
  - 0 < 6? YES
  - 5 < 6? YES
  - Both smaller → Go LEFT

Step 2: At node 2
  - 0 < 2? YES
  - 5 < 2? NO (5 > 2)
  - Different sides → SPLIT POINT!
  - Return 2 ✓

Why? Because:
  - 0 is in left subtree of 2
  - 5 is in right subtree of 2
  - 2 is the lowest node containing both
```

## Connection to Other Problems

This problem teaches:
- **Using BST properties** for efficient search
- **Split point concept** - finding where paths diverge
- **Comparison-based navigation** - using values to guide traversal

These concepts apply to many other BST problems!

## Implementation Tips

1. **Use value comparisons**: `p.val < root.val`, not `p < root`
2. **Handle all three cases**: both left, both right, or split
3. **Iterative is cleaner**: Less code, better space complexity
4. **Don't overthink**: The BST property makes this straightforward
