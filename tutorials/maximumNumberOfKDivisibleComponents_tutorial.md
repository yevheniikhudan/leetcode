# Maximum Number of K-Divisible Components - Tutorial

## Problem Understanding

Given an undirected tree with `n` nodes, where each node has a value, we need to:
1. Split the tree into components by removing edges
2. Each component's sum of values must be divisible by `k`
3. Maximize the number of components

**Key Insight**: The total sum of all values is guaranteed to be divisible by `k`.

## Approach: DFS with Subtree Sum

### Strategy

The key insight is to use **DFS (post-order traversal)** to calculate subtree sums:

1. **Root the tree** at any node (e.g., node 0)
2. For each subtree, calculate the sum of all node values in that subtree
3. If a subtree's sum is divisible by `k`, we can **cut it off** as a separate component
4. When we cut off a subtree, we increment the component count and return `0` to the parent (since this component is separate)
5. Otherwise, return the subtree sum modulo `k` to the parent

### Why This Works

**Post-order DFS** processes children before parents, allowing us to:
- Make greedy decisions: Cut off subtrees as soon as their sum is divisible by `k`
- This is optimal because cutting earlier creates more components
- Each valid cut reduces the remaining tree size

**Modulo Arithmetic**: 
- We only care if sums are divisible by `k`, so we can work with `sum % k`
- This prevents overflow for large values

### Algorithm Steps

1. Build an adjacency list from the edges to represent the tree
2. Perform DFS starting from any root node (typically node 0)
3. In the DFS function:
   - Start with the current node's value modulo k
   - Recursively visit all children (neighbors except parent)
   - Add each child's returned sum to the current subtree sum (using modulo)
   - If the subtree sum is divisible by k, increment the component count and return 0
   - Otherwise, return the subtree sum modulo k to the parent
4. Return the total component count

### Example Walkthrough

**Example 1**: n=5, edges=[[0,2],[1,2],[1,3],[2,4]], values=[1,8,1,4,4], k=6

**Tree structure** (rooted at 0):
- Node 0 (value=1) connects to node 2
- Node 2 (value=1) connects to nodes 1 and 4
- Node 1 (value=8) connects to node 3
- Node 3 (value=4) is a leaf
- Node 4 (value=4) is a leaf

**DFS traversal** (post-order - children before parents):

1. **Visit node 3**: sum = 4 mod 6 = 4, not divisible, return 4 to parent
2. **Visit node 4**: sum = 4 mod 6 = 4, not divisible, return 4 to parent
3. **Visit node 1**: 
   - Start with value 8 mod 6 = 2
   - Add child(3) = 4, subtree_sum = (2+4) mod 6 = 0
   - Divisible by 6! Increment count to 1, return 0
4. **Visit node 2**:
   - Start with value 1 mod 6 = 1
   - Add child(1) = 0, subtree_sum = (1+0) mod 6 = 1
   - Add child(4) = 4, subtree_sum = (1+4) mod 6 = 5
   - Not divisible, return 5 to parent
5. **Visit node 0**:
   - Start with value 1 mod 6 = 1
   - Add child(2) = 5, subtree_sum = (1+5) mod 6 = 0
   - Divisible by 6! Increment count to 2, return 0

**Result**: 2 components
- Component 1: nodes {1, 3} with sum = 12
- Component 2: nodes {0, 2, 4} with sum = 6

### Time & Space Complexity

- **Time**: O(n) - Visit each node once in DFS
- **Space**: O(n) - Adjacency list + recursion stack

## Key Insights

1. **Greedy Approach Works**: Cut subtrees as soon as possible to maximize components
2. **Post-Order DFS**: Process children before parents to make decisions bottom-up
3. **Modulo Arithmetic**: Work with `sum % k` to avoid overflow and simplify logic
4. **Guaranteed Valid**: Since total sum is divisible by `k`, at least the root component will be valid

## Common Mistakes

1. **Using Pre-Order DFS**: Won't work because we need child information first
2. **Forgetting to Return 0**: When cutting a subtree, must return 0 to parent
3. **Integer Overflow**: Values can be up to 10⁹, need to use `long` in some languages
4. **Not Handling Bidirectional Edges**: Tree is undirected, need to track parent to avoid revisiting

## Edge Cases

1. **Single node** (n=1): Always 1 component
2. **All values = 0**: Every node can be a separate component (n components)
3. **k = 1**: All sums divisible by 1, maximize cuts (n components)
4. **Large k**: May result in only 1 component (entire tree)

## Optimization Tips

1. **Use Modulo Early**: Apply `% k` as soon as values are added
2. **Avoid Visited Array**: Use parent tracking in tree traversal
3. **Use Long**: For subtree sums to avoid overflow during calculation

## Related Concepts

- **Tree DP**: Computing values bottom-up in a tree
- **Post-Order Traversal**: Processing children before parents
- **Greedy on Trees**: Making optimal local decisions
- **Modular Arithmetic**: Using modulo to simplify calculations
