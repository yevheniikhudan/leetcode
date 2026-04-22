# Minimize Hamming Distance After Swap Operations - Tutorial

## Understanding the Problem

**Core Concept**: We want to transform a source array into a target array by swapping elements, where only certain index pairs can be swapped directly. We want to minimize the Hamming distance (number of mismatched positions).

**Key Insights**:
1. If indices i and j can be swapped directly, they're connected
2. If i connects to j, and j connects to k, then through a series of swaps, i and k can exchange values (transitively connected)
3. All indices in the same connected component can freely rearrange their values among themselves
4. For each connected component, we should optimally match source values with target values to maximize matches

**Example**:
```
source = [1, 2, 3, 4]
target = [2, 1, 4, 3]
allowedSwaps = [[0,1], [2,3]]
```

Position pairs: (0,1) connected, (2,3) connected. Two separate components.
- Component 1: positions {0,1} with values {1,2}. Target needs {2,1}. Perfect match! 2 positions correct.
- Component 2: positions {2,3} with values {3,4}. Target needs {4,3}. Perfect match! 2 positions correct.
- Result: Hamming distance = 0

---

## Visual Examples and Diagrams

### Connected Components Through Swaps

```
Example 1:
allowedSwaps = [[0,1], [1,2]]

Positions: 0 -- 1 -- 2
           
All three positions are in the same component.
Values at these positions can be freely rearranged.
```

```
Example 2:
allowedSwaps = [[0,1], [3,4]]

Positions: 0 -- 1    3 -- 4    2 (isolated)
           
Three components: {0,1}, {3,4}, {2}
Position 2 cannot be changed - must already match target[2]
```

### Optimal Value Matching

```
Component {0, 1, 2} with source values {5, 3, 7}
Target needs at these positions {5, 7, 3}

Mapping:
- position 0 needs 5, has 5 ✓
- position 1 needs 7, has 3 ✗
- position 2 needs 3, has 7 ✗

By rearranging: source becomes [5, 7, 3]
Result: Only position 0 matches originally, but with rearrangement all 3 match!
```

---

## Approaches (Strategies)

### Approach 1: Union-Find (Disjoint Set Union) - Most Efficient

**Strategy**: 
1. Use Union-Find to group all indices that can transitively swap with each other
2. For each connected component, collect all source values and target values
3. Count how many values from source exist in the target for that component
4. Each matched value reduces Hamming distance by 1

**Why This Works**:
- Union-Find naturally handles transitive connectivity
- When we union(0,1) and union(1,2), all three become connected
- For each component, we count overlapping values between source and target
- Positions with matching values after optimal rearrangement don't contribute to Hamming distance

**Time Complexity**: O(N + M·α(N))
- N = length of arrays
- M = number of allowed swaps
- α(N) = inverse Ackermann (nearly constant)

**Space Complexity**: O(N + M)
- Union-Find structure: O(N)
- Hash sets for values: O(N)

**Advantages**:
- Most efficient for large inputs
- Elegant and clean implementation
- Near-linear time complexity

---

### Approach 2: Graph DFS/BFS with Adjacency List

**Strategy**:
1. Build an undirected graph where indices are nodes and allowed swaps are edges
2. Use DFS or BFS to find all connected components
3. For each component, count overlapping values as in Approach 1

**Time Complexity**: O(N + M + sum of component sizes) = O(N + M)

**Space Complexity**: O(N + M)
- Adjacency list: O(N + M)
- Visited array: O(N)
- Hash sets: O(N)

**Advantages**:
- Intuitive graph representation
- Easy to visualize and debug
- Still very efficient

**Disadvantages**:
- Slightly more code than Union-Find
- DFS can use recursion stack space

---

### Approach 3: Brute Force (Not Recommended)

**Strategy**: Try all possible swap sequences and find the one with minimum Hamming distance.

**Limitations**:
- Exponential time complexity
- Only practical for very small inputs
- Inefficient for any reasonably sized problem

---

## Time & Space Complexity Analysis

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Union-Find | O(N + M·α(N)) | O(N+M) | **Best - nearly linear** |
| Graph DFS/BFS | O(N + M) | O(N+M) | Competitive, more intuitive |
| Brute Force | Exponential | Varies | Impractical |

where N = array length, M = number of allowed swaps

---

## Key Concepts and Patterns

### 1. **Connected Components**
The most critical insight: indices that can transitively swap are in the same connected component. All values in these positions can be rearranged freely.

### 2. **Value Frequency Matching**
For each component:
- Collect all source values in that component
- Collect all target values in that component
- Count how many source values exist as target values
- These are the positions that can be made correct

**Example**:
```
Component positions: {0, 2, 4}
Source values: {5, 7, 3}
Target values: {7, 3, 5}

Overlapping values: {5, 7, 3} (all three!)
Matches possible: 3
Hamming contribution: 0
```

### 3. **Isolation**
An index that cannot swap with anything (no edges) is isolated. Its source value must equal target value, or it contributes to Hamming distance.

### 4. **Transitivity Through Swaps**
If swap(0,1) and swap(1,2) are allowed, then effectively we can rearrange values at {0,1,2} in any way through a sequence of swaps.

---

## Edge Cases and Common Pitfalls

### Edge Case 1: No Swaps Allowed
```
allowedSwaps = []
source = [1, 2, 3]
target = [3, 2, 1]
```
Each position is isolated. Only matches at identical positions count (position 1). Hamming distance = 2.

### Edge Case 2: All Positions Connected
```
allowedSwaps = [[0,1], [1,2], [2,3]]
source = [4, 3, 2, 1]
target = [1, 2, 3, 4]
```
Single component with all 4 positions. Values {1,2,3,4} can match {1,2,3,4} perfectly. Hamming distance = 0.

### Edge Case 3: Duplicate Values
```
source = [1, 1, 2]
target = [2, 1, 1]
Component {0,1,2}: source has {1,1,2}, target needs {2,1,1}
All values match! Hamming distance = 0.
```

### Common Pitfall 1: Not Recognizing Transitivity
Thinking only about direct swaps instead of recognizing that connected indices can achieve any permutation.

### Common Pitfall 2: Not Counting Duplicates Correctly
When counting overlapping values, use a frequency map to handle duplicates properly.
```
source = [1, 1, 3]
target = [1, 2, 3]
Can match: at most 2 ones and 1 three = all three if they're in same component!
```

### Common Pitfall 3: Ignoring Isolated Positions
Single elements (not in any swap) cannot be rearranged and must match exactly.

---

## Optimization Notes

### Optimization 1: Early Termination
If current Hamming distance is 0, we can return immediately.

### Optimization 2: Efficient Union-Find
Use both path compression and union by rank for optimal α(N) amortization:
```
Path compression: Flatten the tree on find()
Union by rank: Attach smaller tree under larger tree
```

### Optimization 3: Frequency Counting
Use Counter/HashMap instead of nested loops:
```
For each component:
  count = min(freq_source[value], freq_target[value])
  hamming -= count
```
This correctly handles duplicates in O(n) per component.

### Optimization 4: Single Pass Union
Process all allowed swaps once to build the Union-Find structure, then analyze once. No re-processing.

---

## Algorithm Summary

**Union-Find Approach** (Recommended):

1. Initialize Union-Find with N nodes
2. For each allowed swap (a, b), union(a, b)
3. Group indices by their root (connected component)
4. For each component:
   - Collect source values and target values
   - Count how many source values exist in target values (considering frequency)
   - Subtract this count from total Hamming distance
5. Return final Hamming distance

**Key Formula**:
```
Initial Hamming = count of positions where source[i] != target[i]
For each component:
  matches = count of values that appear in both source[component] and target[component]
  Hamming -= matches
Return Hamming
```

---

## Why This Approach is Optimal

Union-Find elegantly captures the problem's structure:
- **Transitive relationships**: Automatically handled through path compression
- **Component analysis**: Union-Find roots group indices naturally
- **No redundant work**: Single pass through swaps and indices
- **Provably correct**: Each value in a component can be positioned optimally

For this problem, Union-Find is not just efficient—it's the **natural fit** for representing connected components of swappable indices.