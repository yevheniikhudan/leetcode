# Tutorial: Balanced Binary Tree

## Understanding the Problem

A **height-balanced** (or **balanced**) binary tree is one where for every node, the heights of its left and right subtrees differ by at most 1.

### Key Points:
- Must check EVERY node in the tree
- Height difference at any node must be ≤ 1
- Empty tree is considered balanced
- Single node is considered balanced

## Visual Examples

### Example 1: Balanced Tree ✓
```
    3           Heights:
   / \          Node 9: height 1
  9  20         Node 20: height 2
    /  \        Node 3: |1-2| = 1 ✓
   15   7
```
**Result: Balanced** - All nodes have height difference ≤ 1

### Example 2: Not Balanced ✗
```
       1        Heights:
      / \       Node 3: height 2
     2   2      Node 2 (left): |2-0| = 2 ✗
    / \         
   3   3        
  / \
 4   4
```
**Result: Not Balanced** - Node 2 has left height 2 and right height 0 (diff > 1)

### Example 3: Skewed Tree ✗
```
  1             Heights:
 /              Node 1: |2-0| = 2 ✗
2
 \
  3
```
**Result: Not Balanced** - Height difference at root is 2

### Example 4: Balanced Complete Tree ✓
```
       1        All nodes have:
      / \       Height difference ≤ 1
     2   3
    / \
   4   5
```
**Result: Balanced**

## Key Insight

To check if a tree is balanced:
1. **For each node:** Compute heights of left and right subtrees
2. **Check condition:** `|left_height - right_height| <= 1`
3. **Recursive check:** Both left and right subtrees must also be balanced

This requires:
- Computing height of subtrees
- Checking balance condition at every node
- Early termination if any node is unbalanced

---

## Approach 1: Top-Down (Naive)

### Strategy
For each node, compute the height of left and right subtrees and check the balance condition.

### Pseudocode
```
function isBalanced(node):
    if node is null:
        return true
    
    left_height = height(node.left)
    right_height = height(node.right)
    
    if |left_height - right_height| > 1:
        return false
    
    return isBalanced(node.left) and isBalanced(node.right)

function height(node):
    if node is null:
        return 0
    return 1 + max(height(node.left), height(node.right))
```

### Problem
**Inefficient!** For each node, we compute heights from scratch.

### Complexity
- **Time:** O(n²) - For each of n nodes, we traverse subtrees to compute height
- **Space:** O(h) - Recursion stack
- **Not optimal!**

---

## Approach 2: Bottom-Up (Optimized) ⭐

### Strategy
Compute height and check balance simultaneously in a single DFS traversal.

**Key idea:** Return height if balanced, or a special value (like -1) if unbalanced.

### Algorithm
```
function height(node):
    if node is null:
        return 0
    
    left_height = height(node.left)
    if left_height == -1:  // Left subtree is unbalanced
        return -1
    
    right_height = height(node.right)
    if right_height == -1:  // Right subtree is unbalanced
        return -1
    
    if |left_height - right_height| > 1:  // Current node is unbalanced
        return -1
    
    return 1 + max(left_height, right_height)

function isBalanced(root):
    return height(root) != -1
```

### Why This Works
- **Single traversal:** Each node visited once
- **Early termination:** Returns -1 immediately when unbalanced found
- **Height as return value:** No separate height function needed
- **Bottom-up:** Checks from leaves to root

### Step-by-Step Example

For tree `[1,2,2,3,3,null,null,4,4]`:

```
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
```

**Process node 4 (left leaf):**
```
left_height = 0, right_height = 0
diff = 0, balanced ✓
return 1
```

**Process node 4 (right leaf):**
```
left_height = 0, right_height = 0
diff = 0, balanced ✓
return 1
```

**Process node 3 (left):**
```
left_height = 1, right_height = 1
diff = 0, balanced ✓
return 2
```

**Process node 3 (right):**
```
left_height = 1, right_height = 1
diff = 0, balanced ✓
return 2
```

**Process node 2 (left):**
```
left_height = 2, right_height = 2
diff = 0, balanced ✓
return 3
```

**Process node 2 (right):**
```
left_height = 0, right_height = 0
diff = 0, balanced ✓
return 1
```

**Process node 1 (root):**
```
left_height = 3, right_height = 1
diff = |3 - 1| = 2 > 1 ✗
return -1
```

**Result:** `height(root) == -1` → **Not Balanced**

### Complexity
- **Time:** O(n) - Visit each node exactly once ✓
- **Space:** O(h) - Recursion stack
- **Optimal!** ⭐

---

## Comparing Approaches

| Approach | Time | Space | Visits per Node | Early Exit |
|----------|------|-------|-----------------|------------|
| **Top-Down (Naive)** | O(n²) | O(h) | Multiple | No |
| **Bottom-Up (Optimal)** | O(n) | O(h) | Once | Yes ✓ |

**Recommendation:** Use the **bottom-up approach** - it's optimal and elegant!

---

## Edge Cases to Consider

1. **Empty tree:** Considered balanced (return true)
2. **Single node:** Balanced (height 1, no children to compare)
3. **Two nodes:** Check if height difference ≤ 1
4. **Left-skewed tree:** Usually not balanced
5. **Right-skewed tree:** Usually not balanced
6. **Perfect binary tree:** Always balanced
7. **Complete binary tree:** Always balanced

---

## Common Mistakes

1. **Only checking the root:**
   - Must check EVERY node, not just root
   - Balance must hold for all nodes

2. **Computing height separately:**
   - Leads to O(n²) solution
   - Can be combined with balance check

3. **Not using early termination:**
   - Once unbalanced found, can return immediately
   - No need to check remaining nodes

4. **Confusing height and depth:**
   - Use height (distance from node to deepest leaf)
   - Not depth (distance from root to node)

5. **Off-by-one in height calculation:**
   - Remember: null node has height 0
   - Leaf node has height 1

---

## Pattern Recognition

This problem demonstrates the **bottom-up tree validation** pattern:

```
function validate(node):
    if not node:
        return base_case
    
    left_result = validate(node.left)
    if left_result is invalid:
        return invalid
    
    right_result = validate(node.right)
    if right_result is invalid:
        return invalid
    
    if current_node_violates_condition:
        return invalid
    
    return valid_result
```

This pattern appears in:
- Validating BST
- Checking tree properties
- Computing tree metrics with constraints
- Path sum problems with conditions

---

## Relationship to Other Problems

- **Maximum Depth:** Uses same height computation, but simpler (no balance check)
- **Diameter of Binary Tree:** Also combines two subtree metrics (sum instead of diff)
- **Validate Binary Search Tree:** Similar bottom-up validation pattern
- **Lowest Common Ancestor:** Also uses bottom-up traversal

---

## Optimization Notes

- Bottom-up approach is already optimal O(n)
- Early termination saves unnecessary computation
- Using -1 as sentinel avoids need for separate boolean flag
- Single DFS pass is most efficient
- No way to improve on O(n) - must visit all nodes in worst case

---

## Implementation Tips

### Using Sentinel Value (-1)
```
if left_height == -1 or right_height == -1:
    return -1
```
Avoids need for tuple/pair returns

### Alternative: Using Tuple
```
return (is_balanced, height)
```
More explicit but more verbose

### Alternative: Using Class Variable
```
self.is_balanced = True
# Check and update in DFS
```
Works but less elegant than sentinel value

**Recommendation:** Use -1 sentinel for clean, efficient code!
