# Tutorial: Invert Binary Tree

## Understanding the Problem

Inverting a binary tree means swapping the left and right children of every node in the tree. Think of it as creating a mirror image of the tree.

## Visual Example

Starting with this tree:
```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```

After inversion (mirror image):
```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

Notice that:
- Node 4's children: 2 and 7 are swapped
- Node 2's children: 1 and 3 are swapped
- Node 7's children: 6 and 9 are swapped

## Key Insight

Every node performs the same operation: **swap its left and right children**. This naturally suggests a recursive solution where we:
1. Swap current node's children
2. Recursively invert the left subtree
3. Recursively invert the right subtree

## Approach 1: Recursive (DFS)

### Strategy
- **Base case:** If node is null, return null
- **Recursive case:** 
  - Swap left and right children
  - Recursively invert left subtree
  - Recursively invert right subtree
  - Return the node

### Step-by-Step Example

For tree `[4,2,7,1,3,6,9]`:

**Step 1:** Start at root (4)
```
Process node 4:
- Save left child (2)
- Save right child (7)
- Swap: left = 7, right = 2
- Recursively process left (now 7)
- Recursively process right (now 2)
```

**Step 2:** Process node 7 (now on left)
```
Process node 7:
- Save left child (6)
- Save right child (9)
- Swap: left = 9, right = 6
- Recursively process children
```

**Step 3:** Process node 2 (now on right)
```
Process node 2:
- Save left child (1)
- Save right child (3)
- Swap: left = 3, right = 1
- Recursively process children
```

**Step 4:** Leaf nodes (1, 3, 6, 9) return themselves

### Complexity
- **Time:** O(n) - Visit each node exactly once
- **Space:** O(h) - Recursion stack depth, where h is tree height
  - Best case (balanced tree): O(log n)
  - Worst case (skewed tree): O(n)

### Why This Works
The recursive nature ensures we process every node from bottom to top, and each swap is independent, making the solution elegant and correct.

---

## Approach 2: Iterative (BFS with Queue)

### Strategy
Use a queue to process nodes level by level:
- Add root to queue
- While queue is not empty:
  - Remove node from queue
  - Swap its left and right children
  - Add children to queue for processing

### Step-by-Step Example

For tree `[4,2,7,1,3,6,9]`:

**Initial:** Queue = [4]

**Iteration 1:**
```
Process node 4:
- Swap children: left=7, right=2
- Add 7 and 2 to queue
Queue = [7, 2]
```

**Iteration 2:**
```
Process node 7:
- Swap children: left=9, right=6
- Add 9 and 6 to queue
Queue = [2, 9, 6]
```

**Iteration 3:**
```
Process node 2:
- Swap children: left=3, right=1
- Add 3 and 1 to queue
Queue = [9, 6, 3, 1]
```

**Iterations 4-7:** Process leaf nodes (no children to swap)

### Complexity
- **Time:** O(n) - Visit each node exactly once
- **Space:** O(w) - Queue size, where w is maximum width of tree
  - Perfect binary tree: O(n/2) = O(n) at last level
  - Skewed tree: O(1)

---

## Approach 3: Iterative (DFS with Stack)

### Strategy
Use a stack instead of queue for depth-first traversal:
- Push root to stack
- While stack is not empty:
  - Pop node from stack
  - Swap its left and right children
  - Push children to stack for processing

### Comparison with BFS
- **BFS (Queue):** Processes level by level (FIFO)
- **DFS (Stack):** Processes depth-first (LIFO)
- Both work correctly because order doesn't matter - every node needs the same swap operation

### Complexity
- **Time:** O(n) - Visit each node exactly once
- **Space:** O(h) - Stack size, where h is tree height
  - Similar to recursive approach
  - Best case: O(log n), Worst case: O(n)

---

## Comparing All Approaches

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| **Recursive** | O(n) | O(h) | Most elegant, easy to understand | Uses recursion stack |
| **BFS (Queue)** | O(n) | O(w) | Level-by-level processing | Slightly more code |
| **DFS (Stack)** | O(n) | O(h) | Similar to recursive but explicit | More verbose than recursive |

**Recommendation:** Use the **recursive approach** for interviews - it's the most elegant and natural solution.

---

## Edge Cases to Consider

1. **Empty tree:** Return null
2. **Single node:** Return the node itself (no children to swap)
3. **Only left children:** Still works, swaps with null
4. **Only right children:** Still works, swaps with null
5. **Perfect binary tree:** All approaches work equally well
6. **Skewed tree:** Recursive and DFS stack use O(n) space

---

## Common Mistakes

1. **Forgetting to return the root:** Remember to return the modified tree's root
2. **Swapping in wrong order:** Save both children before swapping to avoid losing references
3. **Not handling null nodes:** Always check for null before processing
4. **Modifying only one level:** Make sure to recursively process all levels

---

## Pattern Recognition

This problem teaches an important pattern: **applying the same operation to every node in a tree**. This pattern appears in many tree problems:
- Flipping/inverting trees
- Doubling all values
- Checking properties at every node
- Transforming tree structures

The key is recognizing that the operation is **independent at each node** and can be applied recursively or iteratively.

---

## Optimization Notes

- All approaches already have optimal O(n) time complexity
- Space complexity varies by approach but all are acceptable
- Recursive solution is typically preferred for clarity
- For extremely deep trees where stack overflow is a concern, use iterative BFS
