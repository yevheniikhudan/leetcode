# Tutorial: Maximum Depth of Binary Tree

## Understanding the Problem

The **maximum depth** (also called **height**) of a binary tree is the number of nodes along the longest path from the root to any leaf node.

Key points:
- Count includes both the root and the leaf
- An empty tree has depth 0
- A single-node tree has depth 1
- The depth is measured in **number of nodes**, not edges

## Visual Examples

### Example 1: Balanced Tree
```
    3           Depth = 3
   / \
  9  20         Level 1: node 3
    /  \        Level 2: nodes 9, 20
   15   7       Level 3: nodes 15, 7
```
The longest paths are:
- 3 → 20 → 15 (3 nodes)
- 3 → 20 → 7 (3 nodes)

Maximum depth = **3**

### Example 2: Right-Skewed Tree
```
  1             Depth = 2
   \
    2           Level 1: node 1
                Level 2: node 2
```
Maximum depth = **2**

### Example 3: More Complex Tree
```
      1         Depth = 4
     / \
    2   3       Level 1: node 1
   / \          Level 2: nodes 2, 3
  4   5         Level 3: nodes 4, 5
 /              Level 4: node 6
6
```
Longest path: 1 → 2 → 4 → 6 (4 nodes)

Maximum depth = **4**

## Key Insight

The maximum depth of a tree can be defined recursively:
- **Base case:** Empty tree has depth 0
- **Recursive case:** For any node, its depth = 1 + max(depth of left subtree, depth of right subtree)

This naturally leads to a recursive solution!

---

## Approach 1: Recursive DFS (Top-Down)

### Strategy
Use recursion to explore each subtree and find the maximum depth:
1. If the node is null, return 0
2. Recursively find the depth of the left subtree
3. Recursively find the depth of the right subtree
4. Return 1 + max(left depth, right depth)

### Step-by-Step Example

For tree `[3,9,20,null,null,15,7]`:

**Call 1:** `maxDepth(3)`
```
leftDepth = maxDepth(9)
rightDepth = maxDepth(20)
return 1 + max(leftDepth, rightDepth)
```

**Call 2:** `maxDepth(9)` (leaf node)
```
leftDepth = maxDepth(null) = 0
rightDepth = maxDepth(null) = 0
return 1 + max(0, 0) = 1
```

**Call 3:** `maxDepth(20)`
```
leftDepth = maxDepth(15) = 1
rightDepth = maxDepth(7) = 1
return 1 + max(1, 1) = 2
```

**Back to Call 1:**
```
return 1 + max(1, 2) = 3
```

**Result:** Maximum depth = **3**

### Why This Works
The recursive definition perfectly matches the problem:
- Each node contributes 1 to the depth
- We take the maximum of left and right paths
- Base case handles empty subtrees

### Complexity
- **Time:** O(n) - Visit each node exactly once
- **Space:** O(h) - Recursion stack depth
  - Best case (balanced): O(log n)
  - Worst case (skewed): O(n)

---

## Approach 2: Iterative BFS (Level-Order Traversal)

### Strategy
Use a queue to traverse the tree level by level:
1. Start with root in the queue
2. For each level:
   - Process all nodes at that level
   - Add their children to the queue
   - Increment depth counter
3. Return the depth counter

### Step-by-Step Example

For tree `[3,9,20,null,null,15,7]`:

**Initial:** Queue = [3], depth = 0

**Level 1:**
```
Process: 3
Add to queue: 9, 20
Queue = [9, 20]
depth = 1
```

**Level 2:**
```
Process: 9, 20
Add to queue: 15, 7
Queue = [15, 7]
depth = 2
```

**Level 3:**
```
Process: 15, 7
Add to queue: (none - leaf nodes)
Queue = []
depth = 3
```

**Result:** Maximum depth = **3**

### Why This Works
- Each iteration processes one complete level
- Depth counter tracks the number of levels
- BFS guarantees we explore all levels

### Complexity
- **Time:** O(n) - Visit each node exactly once
- **Space:** O(w) - Queue size, where w is maximum width
  - Worst case: O(n) for a complete binary tree at the last level

---

## Approach 3: Iterative DFS (with Stack)

### Strategy
Use a stack to simulate recursive DFS, tracking depth at each node:
1. Push (root, depth=1) onto stack
2. While stack is not empty:
   - Pop (node, depth)
   - Update maximum depth
   - Push children with depth+1
3. Return maximum depth

### Complexity
- **Time:** O(n) - Visit each node exactly once
- **Space:** O(h) - Stack size
  - Similar to recursive approach

---

## Comparing All Approaches

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| **Recursive DFS** | O(n) | O(h) | Most elegant, easiest to code | Uses recursion stack |
| **Iterative BFS** | O(n) | O(w) | Good for wide trees, explicit level tracking | More code, uses queue |
| **Iterative DFS** | O(n) | O(h) | Avoids recursion | More complex to track depth |

**Recommendation:** Use the **recursive DFS approach** - it's the most elegant and natural solution.

---

## Edge Cases to Consider

1. **Empty tree (null root):** Return 0
2. **Single node:** Return 1
3. **Left-skewed tree:** Depth = number of left children + 1
4. **Right-skewed tree:** Depth = number of right children + 1
5. **Balanced tree:** Depth ≈ log₂(n) + 1
6. **Complete binary tree:** All levels filled except possibly the last

---

## Common Mistakes

1. **Forgetting the base case:** Always check for null first
2. **Off-by-one error:** Remember to include the current node (+1)
3. **Using min instead of max:** We want the maximum depth, not minimum
4. **Counting edges instead of nodes:** The problem asks for number of nodes

---

## Pattern Recognition

This problem teaches the classic **tree recursion pattern**:
```
function solve(node):
    if not node: return base_value
    left_result = solve(node.left)
    right_result = solve(node.right)
    return combine(current, left_result, right_result)
```

This pattern appears in many tree problems:
- Finding tree height/depth
- Checking if tree is balanced
- Finding diameter of tree
- Computing path sums
- Validating binary search trees

---

## Relationship to Other Problems

- **Minimum Depth:** Similar but use min instead of max, and requires reaching a leaf
- **Balanced Binary Tree:** Uses depth to check if left and right differ by ≤1
- **Diameter of Binary Tree:** Uses depth to find longest path through any node
- **Binary Tree Level Order Traversal:** BFS approach is the same

---

## Optimization Notes

- All approaches are already optimal O(n) time
- Can't avoid visiting all nodes - must explore entire tree
- Recursive solution is typically preferred for its simplicity
- For extremely deep trees, iterative approach avoids stack overflow
