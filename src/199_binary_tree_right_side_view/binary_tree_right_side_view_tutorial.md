# Binary Tree Right Side View - Tutorial

## Problem Understanding

We need to find the **rightmost visible node** at each level of a binary tree, as if we're standing on the right side looking at the tree.

**Key Point:** The "right side view" doesn't mean just following right children! It means the **rightmost node at each depth level**.

**Visual Example:**
```
Tree:     1           Right side view: [1, 3, 4, 5]
         / \
        2   3         Level 0: see 1 (rightmost)
       /             Level 1: see 3 (rightmost)
      4              Level 2: see 4 (rightmost, even though left!)
     /               Level 3: see 5 (rightmost, even though left!)
    5

If we only followed right children: 1 → 3 → ✗ (would miss 4 and 5)
```

## Intuition

This is essentially a variation of **level order traversal** where we only care about the **last node** at each level.

**Two main approaches:**
1. **BFS (Level Order)**: Process level by level, take the last node
2. **DFS (Right-First)**: Visit right subtree first, track the first node seen at each depth

## Approaches

### Approach 1: BFS with Level Order Traversal (Most Intuitive)

**Concept:**
- Use a queue to perform level order traversal
- For each level, the **last node processed** is the rightmost node
- Add that node's value to the result

**Algorithm:**

```
1. If root is null, return []
2. Initialize: result = [], queue = [root]
3. While queue is not empty:
   a. Get level size: levelSize = queue.size()
   b. For i from 0 to levelSize:
      - Dequeue node
      - If this is the last node (i == levelSize - 1):
        → Add node.val to result
      - Enqueue left and right children
4. Return result
```

**Visual Walkthrough:**

```
Tree:     1
         / \
        2   3
         \   \
          5   4

Level 0: queue = [1]
  Process 1 (last at level) → result = [1]
  Enqueue 2, 3 → queue = [2, 3]

Level 1: queue = [2, 3]
  Process 2 → skip
  Process 3 (last at level) → result = [1, 3]
  Enqueue 5, 4 → queue = [5, 4]

Level 2: queue = [5, 4]
  Process 5 → skip
  Process 4 (last at level) → result = [1, 3, 4]

Return [1, 3, 4]
```

**Time Complexity:** O(n) where n is the number of nodes
- Visit each node exactly once

**Space Complexity:** O(w) where w is the maximum width of the tree
- Queue holds at most one level at a time

### Approach 2: BFS - Alternative (Take Last at Each Level)

**Concept:**
- Process level by level
- Keep track of the last node value seen at each level
- Add it to result after processing the entire level

**Algorithm:**

```
1. If root is null, return []
2. Initialize: result = [], queue = [root]
3. While queue is not empty:
   a. Get level size: levelSize = queue.size()
   b. rightmostValue = null
   c. For i from 0 to levelSize:
      - Dequeue node
      - rightmostValue = node.val  (continuously update)
      - Enqueue left and right children
   d. Add rightmostValue to result
4. Return result
```

**Time Complexity:** O(n)
**Space Complexity:** O(w)

### Approach 3: DFS with Right-First Traversal

**Concept:**
- Use DFS, but visit **right subtree before left**
- Track the current depth
- For each depth, record the **first node** we encounter (which will be the rightmost)

**Algorithm:**

```
def rightSideView(root):
    result = []
    
    def dfs(node, depth):
        if not node:
            return
        
        # If this is the first time we've seen this depth
        if depth == len(result):
            result.append(node.val)
        
        # Visit RIGHT first, then left
        dfs(node.right, depth + 1)
        dfs(node.left, depth + 1)
    
    dfs(root, 0)
    return result
```

**Why right-first?**
- By visiting right subtree first, the rightmost node at each depth is encountered first
- We only add to result if `depth == len(result)`, meaning this is the first node at this depth
- Since we go right-first, the first node is the rightmost!

**Visual Trace:**

```
Tree:     1
         / \
        2   3
         \   \
          5   4

DFS trace (right-first):
dfs(1, 0) → result = [1] (first at depth 0)
  dfs(3, 1) → result = [1, 3] (first at depth 1)
    dfs(4, 2) → result = [1, 3, 4] (first at depth 2)
    dfs(null, 2) → skip
  dfs(2, 1) → skip (depth 1 already seen)
    dfs(null, 2) → skip
    dfs(5, 2) → skip (depth 2 already seen)

Return [1, 3, 4]
```

**Time Complexity:** O(n)
**Space Complexity:** O(h) where h is height (recursion stack)

## Edge Cases to Consider

1. **Empty tree**: Return `[]`
2. **Single node**: Return `[root.val]`
3. **Only left children**: Left nodes are visible (they're the rightmost at their level)
4. **Only right children**: Simple case, all right nodes visible
5. **Balanced tree**: Rightmost nodes are all right children
6. **Zigzag pattern**: Some levels have right visible, some have left visible

## Common Pitfalls

1. **Thinking only right children are visible**: The rightmost node might be a left child if no right child exists at that level
2. **Not processing entire level**: In BFS, must process all nodes at current level before moving to next
3. **Wrong DFS order**: Must visit right before left for DFS approach to work
4. **Not tracking depth correctly**: Each level must be tracked separately

## Key Takeaways

1. **Right side view = Rightmost node per level**
2. **BFS approach is more intuitive**: Natural fit for level processing
3. **DFS can work too**: Visit right-first and track first node at each depth
4. **This is a level order traversal variant**: Uses same BFS pattern as problem 102
5. **Not just about right children**: Position in tree doesn't matter, only position at level

## Comparison of Approaches

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| BFS - Take Last | O(n) | O(w) | Intuitive, clear logic | Need to track level size |
| BFS - Update Rightmost | O(n) | O(w) | Simpler loop | Continuously updates (slight overhead) |
| DFS Right-First | O(n) | O(h) | Less space (usually), elegant | Less intuitive, must remember right-first order |

**Recommended Approach:** BFS (take last at each level) - most intuitive and standard.

## Connection to Other Problems

This problem teaches:
- **Level-by-level processing with selection** - not all nodes, just specific ones
- **Rightmost node concept** - appears in many tree problems
- **BFS pattern variations** - same structure, different selection criteria

Similar patterns:
- **Left Side View**: Same problem, take first node at each level
- **Bottom View**: Rightmost node when looking from bottom
- **Top View**: First node at each horizontal distance

## Implementation Pattern

**BFS Template:**
```
// 1. Edge case
if (!root) return []

// 2. Initialize
queue = [root]
result = []

// 3. Process each level
while queue not empty:
    levelSize = queue.size()
    
    // 4. Process all nodes at this level
    for i from 0 to levelSize:
        node = queue.dequeue()
        
        // 5. Check if this is the rightmost node
        if i == levelSize - 1:
            result.append(node.val)
        
        // 6. Add children
        if node.left: queue.enqueue(node.left)
        if node.right: queue.enqueue(node.right)

// 7. Return result
return result
```

**DFS Template:**
```
result = []

function dfs(node, depth):
    if !node: return
    
    // First time seeing this depth
    if depth == result.length:
        result.append(node.val)
    
    // RIGHT FIRST!
    dfs(node.right, depth + 1)
    dfs(node.left, depth + 1)

dfs(root, 0)
return result
```

Master both patterns - BFS for intuition, DFS for elegance!
