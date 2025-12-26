# Subtree of Another Tree - Tutorial

## Problem Understanding

We need to determine if `subRoot` is a subtree of `root`. A subtree means:
1. There exists a node in `root` where if we start from that node
2. The entire tree structure below it (including the node itself) is **identical** to `subRoot`
3. "Identical" means same structure AND same node values

**Key insight:** This problem combines two concepts:
- **Tree traversal** - to find potential matching nodes in `root`
- **Tree comparison** - to check if a subtree is identical to `subRoot` (Same Tree problem!)

## Intuition

Think of it as a two-step process:
1. Traverse through every node in `root`
2. At each node, check if the tree rooted at that node is identical to `subRoot`
3. If any node matches, return `true`
4. If we've checked all nodes and none match, return `false`

This is essentially asking: "Does `root` contain an exact copy of `subRoot` somewhere?"

## Approaches

### Approach 1: Recursive DFS with Tree Comparison

**Concept:**
- Use a helper function `isSameTree(p, q)` to check if two trees are identical
- For the main function:
  - Base case: if `root` is null, no subtree exists → return `false`
  - Check if tree rooted at current `root` is identical to `subRoot`
  - If yes, return `true`
  - If no, recursively check left and right subtrees

**Step-by-Step Logic:**

```
isSubtree(root, subRoot):
    1. If root is null → return false (can't find subRoot in empty tree)
    2. If isSameTree(root, subRoot) → return true (found exact match!)
    3. Otherwise, check left: isSubtree(root.left, subRoot)
    4. Or check right: isSubtree(root.right, subRoot)
    5. Return true if either left OR right contains subRoot

isSameTree(p, q):
    1. If both null → return true
    2. If one null → return false
    3. If values differ → return false
    4. Recursively check left and right subtrees
```

**Visual Example 1 (true):**
```
root = [3,4,5,1,2]    subRoot = [4,1,2]

       3
      / \
     4   5          Check if tree at 3 matches? NO (3 ≠ 4)
    / \             Check left subtree (4)...
   1   2                 4
                        / \
                       1   2    ← This matches subRoot exactly! ✓
```

**Visual Example 2 (false):**
```
root = [3,4,5,1,2,null,null,null,null,0]    subRoot = [4,1,2]

       3
      / \
     4   5          Check if tree at 3 matches? NO
    / \             Check left subtree (4)...
   1   2                 4
      /                 / \
     0                 1   2    Structure different!
                          /     subRoot has no child at 2
                         0      root has child 0 at 2
                                
    isSameTree(root, subRoot) returns false
    Continue checking... no other matches found
```

**Time Complexity:** O(m × n) where m = nodes in root, n = nodes in subRoot
- For each node in root (m nodes), we might call isSameTree
- isSameTree takes O(n) time to compare
- In worst case: O(m × n)

**Space Complexity:** O(h₁ + h₂) where h₁ = height of root, h₂ = height of subRoot
- Recursive call stack for both functions
- In worst case (skewed tree): O(m + n)
- In best case (balanced): O(log m + log n)

### Approach 2: Serialization (String Matching)

**Concept:**
- Serialize both trees into strings (e.g., preorder traversal with null markers)
- Check if subRoot's serialization is a substring of root's serialization
- Use markers to avoid false positives (e.g., left null as "#L", right null as "#R")

**Example:**
```
root = [3,4,5,1,2]
Serialize: "^3 ^4 ^1 #L #R ^2 #L #R ^5 #L #R"

subRoot = [4,1,2]
Serialize: "^4 ^1 #L #R ^2 #L #R"

Check if subRoot string is in root string → YES! ✓
```

**Why markers matter:**
```
root = [12]           serialized: "12"
subRoot = [2]         serialized: "2"

"2" is substring of "12" but 2 is NOT a subtree of 12!
Solution: Add delimiters like "^12" and "^2" → "2" not in "^12"
```

**Time Complexity:** O(m + n)
- Serialization: O(m) for root, O(n) for subRoot
- String matching (KMP algorithm): O(m + n)

**Space Complexity:** O(m + n)
- String storage for both serializations

### Approach 3: Tree Hashing

**Concept:**
- Compute a hash for each subtree
- Check if any subtree's hash matches subRoot's hash
- Use a hash function like: `hash(node) = (node.val * prime1 + hash(left) * prime2 + hash(right) * prime3) % MOD`

**Time Complexity:** O(m + n)
**Space Complexity:** O(m)

**Caution:** Hash collisions possible (though rare with good hash functions)

## Edge Cases to Consider

1. **subRoot is null**: Typically considered `true` (null is subtree of any tree)
2. **root is null, subRoot is not**: Should return `false`
3. **Both null**: Should return `true`
4. **subRoot equals entire root**: Should return `true` (tree is subtree of itself)
5. **subRoot is larger than root**: Should return `false`
6. **Multiple potential matches**: Only need one to match
7. **Similar values but different structure**: Must check exact structure
8. **Leaf nodes vs internal nodes**: A leaf in subRoot must be a leaf in root's subtree

## Common Pitfalls

1. **Forgetting to check current node before recursing**: Must try `isSameTree` at current node first
2. **Not handling null cases in isSameTree**: Both functions need proper null checks
3. **Using simple string matching without delimiters**: Can cause false positives (e.g., "12" contains "2")
4. **Confusing "subtree" with "path"**: Subtree must include ALL descendants, not just a path
5. **Not checking structure**: Values matching isn't enough, structure must match too

## Key Takeaways

- This problem **reuses the Same Tree problem** as a helper function
- It demonstrates **problem decomposition** - break complex problem into simpler subproblems
- Multiple approaches exist with different trade-offs:
  - **Recursive DFS**: Most intuitive, O(m × n) time
  - **Serialization**: Faster O(m + n), but requires more space
  - **Hashing**: Fast but has collision risk
- The recursive approach is typically preferred in interviews for its clarity

## Comparison of Approaches

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Recursive DFS | O(m × n) | O(h₁ + h₂) | Clear, intuitive, no extra data structures | Slower for large trees |
| Serialization | O(m + n) | O(m + n) | Faster, elegant string matching | More memory, need careful delimiters |
| Tree Hashing | O(m + n) | O(m) | Very fast | Hash collisions possible, complex implementation |

**Recommended Approach:** Recursive DFS for clarity and correctness. For large inputs, consider serialization.

## Implementation Tips

1. **Reuse Same Tree logic**: Don't duplicate code, write a clean `isSameTree` helper
2. **Think recursively**: "Is subRoot in left subtree OR right subtree?"
3. **Short-circuit evaluation**: Use `||` (OR) operator to stop as soon as match is found
4. **Test edge cases**: Empty trees, single nodes, identical trees

## Connection to Same Tree Problem

This problem is a direct extension of "100. Same Tree":
- **Same Tree**: Are these two trees identical?
- **Subtree**: Does root contain an identical copy of subRoot somewhere?

If you can solve Same Tree, you can solve Subtree by wrapping it with tree traversal logic!
