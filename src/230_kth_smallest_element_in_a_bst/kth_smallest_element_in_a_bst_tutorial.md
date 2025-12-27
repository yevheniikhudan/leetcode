# Tutorial: Kth Smallest Element in a BST

## Understanding the Problem

Given a BST and an integer `k`, find the kth smallest element. The key insight is that **inorder traversal of a BST visits nodes in ascending order**.

### Key Property of BST

For any BST:
```
Inorder traversal (left → root → right) = sorted ascending order
```

Example:
```
BST:      3          Inorder: [1, 2, 3, 4]
         / \         
        1   4        1st smallest = 1
         \           2nd smallest = 2
          2          3rd smallest = 3
                     4th smallest = 4
```

## Approach 1: Inorder Traversal with Array (Simple)

### Strategy

Perform complete inorder traversal, store all values in an array, then return the kth element.

### Steps

1. Perform inorder traversal recursively
2. Store all values in a list/array
3. Return `array[k-1]` (k is 1-indexed)

### Time & Space Complexity

- **Time Complexity**: O(n) - must visit all n nodes
- **Space Complexity**: O(n) - store all values in array + O(h) recursion stack

### Pros & Cons

✅ Simple to implement  
✅ Easy to understand  
❌ Uses O(n) extra space  
❌ Visits all nodes even if k is small  

## Approach 2: Inorder Traversal with Early Stop (Optimal)

### Strategy

Perform inorder traversal but stop as soon as we've visited k nodes. No need to visit the entire tree!

### Steps

1. Perform inorder traversal
2. Keep a counter of nodes visited
3. When counter reaches k, save the value and stop
4. Return the kth value

### Implementation Pattern

**Using counter and result variable:**
```
counter = 0
result = None

function inorder(node):
    if not node or counter >= k:
        return
    
    inorder(node.left)
    
    counter += 1
    if counter == k:
        result = node.val
        return
    
    inorder(node.right)
```

**Using decrementing k:**
```
function inorder(node):
    if not node:
        return None
    
    left_result = inorder(node.left)
    if left_result is not None:
        return left_result
    
    k -= 1
    if k == 0:
        return node.val
    
    return inorder(node.right)
```

### Time & Space Complexity

- **Time Complexity**: O(h + k) - where h is height
  - Must traverse down to leftmost node: O(h)
  - Then visit k nodes: O(k)
  - Best case (k=1): O(h)
  - Worst case (k=n): O(n)
- **Space Complexity**: O(h) - only recursion stack

### Pros & Cons

✅ Space efficient: O(h) instead of O(n)  
✅ Time efficient for small k  
✅ Early termination  
✅ Still straightforward  

## Approach 3: Iterative with Stack

### Strategy

Use explicit stack to perform iterative inorder traversal with early stopping.

### Steps

1. Initialize empty stack
2. Go to leftmost node, pushing all nodes to stack
3. Pop from stack, decrement k
4. When k becomes 0, return current node's value
5. Move to right child and repeat

### Pseudocode

```
stack = []
current = root

while current or stack:
    # Go to leftmost node
    while current:
        stack.push(current)
        current = current.left
    
    # Process node
    current = stack.pop()
    k -= 1
    if k == 0:
        return current.val
    
    # Move to right subtree
    current = current.right
```

### Time & Space Complexity

- **Time Complexity**: O(h + k)
- **Space Complexity**: O(h) - explicit stack

### Pros & Cons

✅ No recursion (good for very deep trees)  
✅ Space efficient  
✅ Early termination  
❌ More code than recursive  

## Approach 4: Augmented Tree (Follow-up Solution)

### Strategy

If the tree is modified frequently and we query kth smallest often, augment each node with the size of its left subtree.

### Data Structure

```
class TreeNode:
    val: int
    left: TreeNode
    right: TreeNode
    left_size: int  # Number of nodes in left subtree
```

### Algorithm

```
function kthSmallest(node, k):
    left_size = node.left_size
    
    if k <= left_size:
        # kth smallest is in left subtree
        return kthSmallest(node.left, k)
    elif k == left_size + 1:
        # Current node is the kth smallest
        return node.val
    else:
        # kth smallest is in right subtree
        return kthSmallest(node.right, k - left_size - 1)
```

### Time & Space Complexity

- **Query Time**: O(h) - at most one path from root to leaf
- **Update Time**: O(h) - update left_size along path
- **Space**: O(1) extra per node

### Pros & Cons

✅ Optimal query time: O(h)  
✅ Great for frequent queries  
❌ Requires modifying tree structure  
❌ Must maintain left_size during inserts/deletes  

## Comparison of Approaches

| Approach | Time | Space | Best For |
|----------|------|-------|----------|
| Array Storage | O(n) | O(n) | One-time query, small trees |
| Early Stop Recursive | O(h+k) | O(h) | General case (recommended) |
| Iterative Stack | O(h+k) | O(h) | Avoiding recursion |
| Augmented Tree | O(h) | O(1) | Frequent queries + modifications |

**Recommendation**: Use **Approach 2 (Early Stop Recursive)** for the standard problem. Use **Approach 4** for the follow-up.

## Common Pitfalls

1. **Forgetting k is 1-indexed**: k=1 means first smallest, not k=0
2. **Visiting entire tree**: Don't forget to stop early when k is reached
3. **Not leveraging BST property**: Random tree needs O(n) sorting; BST gives sorted order naturally
4. **Off-by-one errors**: Be careful with counter incrementing vs decrementing

## Edge Cases to Consider

1. **k = 1**: Leftmost node (minimum element)
2. **k = n**: Rightmost node (maximum element)
3. **Single node tree**: k must be 1
4. **Left-skewed tree**: All nodes on left
5. **Right-skewed tree**: Must traverse all left nodes first
6. **Balanced tree**: Efficient traversal
7. **k at boundary**: k = 1 or k = n

## Optimization Tips

1. **Early termination**: Stop as soon as kth element is found
2. **Iterative for very deep trees**: Avoid stack overflow
3. **Augmented tree for frequent queries**: Best query time O(h)
4. **Use instance variables**: Avoid passing counters through all recursive calls

## Pattern Recognition

This problem demonstrates:
- **BST inorder property**: Inorder traversal gives sorted order
- **Early stopping optimization**: Don't process more than needed
- **Counter tracking**: Maintaining state during traversal
- **Data structure augmentation**: Trading space for query time

## Testing Strategy

Test with:
1. Minimum element (k=1)
2. Maximum element (k=n)
3. Middle element
4. Single node tree
5. Left-skewed tree
6. Right-skewed tree
7. Balanced tree
8. Small k value
9. Large k value (close to n)
