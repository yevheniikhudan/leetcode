# Tutorial: Diameter of Binary Tree

## Understanding the Problem

The **diameter** of a binary tree is the longest path between any two nodes, measured in **number of edges** (not nodes).

### Key Points:
- The path can go through any node (not necessarily the root)
- The path must connect two nodes (can't just be a single node)
- We count **edges**, not nodes
- The longest path will always be between two leaf nodes (or near-leaf nodes)

## Visual Examples

### Example 1: Diameter Through Root
```
      1          Diameter = 3
     / \
    2   3        Path: 4 -> 2 -> 1 -> 3
   / \           Edges: 4-2, 2-1, 1-3 = 3 edges
  4   5

Alternative path: 5 -> 2 -> 1 -> 3 (also 3 edges)
```

### Example 2: Diameter NOT Through Root
```
        1        Diameter = 4
       /
      2          Path: 4 -> 2 -> 5 -> 6 -> 7
     / \         Edges: 4-2, 2-5, 5-6, 6-7 = 4 edges
    4   5       
       / \      (Notice: path doesn't go through root node 1!)
      6   7
```

### Example 3: Single Edge
```
  1              Diameter = 1
 /
2                Path: 2 -> 1
                 Edges: 2-1 = 1 edge
```

## Key Insight

For any node, the diameter passing through that node is:
```
left_height + right_height
```

Where:
- `left_height` = height of left subtree (number of edges to deepest leaf)
- `right_height` = height of right subtree (number of edges to deepest leaf)

**The diameter of the entire tree** is the maximum diameter at any node!

## Critical Understanding: Edges vs Nodes

**Important:** The problem asks for **edges**, not nodes!

```
      1
     / \
    2   3

Path from 2 to 3: [2, 1, 3]
- Number of nodes: 3
- Number of edges: 2 (edge 2-1 and edge 1-3) ← This is the answer!
```

So if left subtree has height h₁ (edges) and right subtree has height h₂ (edges), the diameter through this node is h₁ + h₂.

---

## Approach: DFS with Height Tracking

### Strategy
Use DFS to compute the height of each subtree while tracking the maximum diameter:

1. For each node, recursively compute:
   - Height of left subtree (in edges)
   - Height of right subtree (in edges)
2. Calculate diameter at this node: `left_height + right_height`
3. Update global maximum diameter
4. Return height of current node: `1 + max(left_height, right_height)`

### Step-by-Step Example

For tree `[1,2,3,4,5]`:

```
      1
     / \
    2   3
   / \
  4   5
```

**Process node 4 (leaf):**
```
left_height = 0 (no left child)
right_height = 0 (no right child)
diameter at 4 = 0 + 0 = 0
height of 4 = 1 + max(0, 0) = 1
```

**Process node 5 (leaf):**
```
left_height = 0
right_height = 0
diameter at 5 = 0 + 0 = 0
height of 5 = 1 + max(0, 0) = 1
```

**Process node 2:**
```
left_height = 1 (from node 4)
right_height = 1 (from node 5)
diameter at 2 = 1 + 1 = 2
height of 2 = 1 + max(1, 1) = 2
```

**Process node 3 (leaf):**
```
left_height = 0
right_height = 0
diameter at 3 = 0 + 0 = 0
height of 3 = 1 + max(0, 0) = 1
```

**Process node 1 (root):**
```
left_height = 2 (from node 2)
right_height = 1 (from node 3)
diameter at 1 = 2 + 1 = 3 ← Maximum diameter!
height of 1 = 1 + max(2, 1) = 3
```

**Result:** Maximum diameter = **3**

---

## Algorithm Details

### Recursive Height Function

We need a helper function that:
1. Computes the height of a subtree (in edges)
2. Updates the global maximum diameter

```
function height(node):
    if node is null:
        return 0  // height of empty tree is 0
    
    left_height = height(node.left)
    right_height = height(node.right)
    
    // Update diameter (this could be the longest path)
    diameter = max(diameter, left_height + right_height)
    
    // Return height of this subtree
    return 1 + max(left_height, right_height)
```

### Why This Works

1. **Every path is considered:** We check diameter at every node
2. **Height is edges:** We return 1 + max(left, right), counting edges
3. **Diameter through node:** left_height + right_height gives path length through that node
4. **Global maximum:** We track the best diameter seen so far

---

## Complexity Analysis

### Time Complexity: O(n)
- Visit each node exactly once
- Constant work at each node (max comparison, addition)
- **Optimal** - can't avoid visiting all nodes

### Space Complexity: O(h)
- Where h is the height of the tree
- Space used by recursion call stack
- **Best case (balanced tree):** O(log n)
- **Worst case (skewed tree):** O(n)

---

## Edge Cases to Consider

1. **Single node tree:** Diameter = 0 (no edges)
2. **Two nodes:** Diameter = 1 (one edge)
3. **Left-skewed tree:** Diameter = left height
4. **Right-skewed tree:** Diameter = right height
5. **Balanced tree:** Diameter likely passes through root
6. **Unbalanced tree:** Diameter may not pass through root

---

## Common Mistakes

1. **Counting nodes instead of edges:** 
   - If path is [4, 2, 1, 3], that's 4 nodes but 3 edges!
   - Solution: Return 0 for null, not -1

2. **Forgetting to update diameter at each node:**
   - Must check diameter at EVERY node, not just root
   - Longest path might not go through root

3. **Not using a global/class variable:**
   - Need to track maximum across all recursive calls
   - Can't just return from one function call

4. **Confusing height and depth:**
   - Height = distance from node to deepest leaf
   - For this problem, we need height (edges to leaf)

---

## Pattern Recognition

This problem teaches an important pattern: **Computing something globally while calculating something locally**.

**Local:** Height of each subtree (returned from recursion)  
**Global:** Maximum diameter (tracked across all calls)

This pattern appears in many tree problems:
- Finding maximum path sum
- Checking if tree is balanced
- Finding largest BST subtree
- Computing tree properties that depend on subtree properties

---

## Relationship to Other Problems

- **Maximum Depth:** Similar DFS, but only returns depth
- **Balanced Binary Tree:** Uses height to check balance condition
- **Binary Tree Maximum Path Sum:** Similar pattern but sums node values
- **Longest Univalue Path:** Similar but adds constraints on values

---

## Optimization Notes

- The solution is already optimal O(n) time
- Can't improve on visiting all nodes
- Space is optimal for recursive approach
- Could use iterative approach for very deep trees (avoid stack overflow)
- No need for multiple passes - single DFS is sufficient
