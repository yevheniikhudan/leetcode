# Sentence Similarity - Tutorial

## Understanding the Problem

**Core Concept**: Determine whether two sentences are similar based on word relationships.

Two sentences are similar if:
1. They have the **same length**
2. Each word at the same position is **similar** to the word at that position in the other sentence

Two words are similar if:
1. They are **identical**, OR
2. They appear as a pair in the `similarPairs` list, OR
3. They are **transitively connected** through similar pairs (e.g., if "great" ~ "good" and "good" ~ "fine", then "great" ~ "fine")

**Example**:
```
sentence1 = ["great", "acting", "skills"]
sentence2 = ["fine", "drama", "talent"]
similarPairs = [["great", "good"], ["fine", "good"], ["acting", "drama"], ["skills", "talent"]]
```

Position 0: "great" and "fine" are both connected to "good" (transitive similarity)
Position 1: "acting" and "drama" are directly similar
Position 2: "skills" and "talent" are directly similar

Result: `true`

---

## Visual Examples and Diagrams

### Graph Representation of Similarity Pairs

Think of similarity as a graph where words are nodes and similar pairs are edges:

```
Example 1:
similarPairs = [["great", "good"], ["fine", "good"]]

    great ─── good ─── fine
    
All three words are in the same connected component.
So "great" ~ "fine" (transitive)
```

```
Example 2:
similarPairs = [["a", "b"], ["c", "d"]]

    a ─── b        c ─── d
    
Two separate components. "a" is NOT similar to "c"
```

### Position Matching

```
sentence1: ["great",  "acting", "skills"]
sentence2: ["fine",   "drama",  "talent"]
           [   ✓   ,    ✓    ,    ✓    ]  (all positions similar)
           
Result: True
```

---

## Approaches (Strategies)

### Approach 1: Union-Find (Most Efficient)
**Strategy**: Build a Union-Find (Disjoint Set Union) data structure.

**Key Steps**:
1. For each similar pair, **union** the two words together
2. For each position in the sentences, check if the two words are in the **same set**
3. Two words in the same set are transitively similar

**Why This Works**:
- Union-Find efficiently handles transitive relationships
- When we union "great" and "good", and then union "fine" and "good", all three end up in the same set automatically
- Path compression and union by rank optimize operations

**Advantages**:
- Very efficient for large numbers of pairs
- Natural fit for the transitive similarity problem
- Handles all edge cases elegantly

**Time Complexity**: O(N + M × α(K)) where N = sentence length, M = number of pairs, K = unique words, α = inverse Ackermann (nearly constant)
**Space Complexity**: O(K) for the union-find structure

---

### Approach 2: Graph DFS/BFS with Adjacency List
**Strategy**: Build an adjacency list and traverse with DFS or BFS.

**Key Steps**:
1. Build an **undirected graph** where each word is a node
2. For each similar pair, add edges in both directions
3. For each position, check if both words are **reachable from each other** via DFS/BFS
4. If reachable, they're in the same connected component (transitively similar)

**Why This Works**:
- Connected components naturally represent transitive similarity
- If you can reach one word from another via edges, they're transitively similar

**Advantages**:
- Intuitive graph-based approach
- Clear visualization of connected components

**Time Complexity**: O(N × (K + M)) where we might need to traverse the entire graph for each position check
**Space Complexity**: O(K + M) for the adjacency list

---

### Approach 3: Direct Pair Lookup (Least Efficient)
**Strategy**: Store similar pairs in a set and check directly.

**Key Steps**:
1. Store all similar pairs in a **set** (including both directions)
2. For each position, check:
   - Are the words identical? OR
   - Is the pair in the set?
3. If direct checks fail, recursively check if there's an intermediate word that connects them

**Limitations**:
- Checking transitive relationships requires recursive exploration
- Can be slow for long chains of similarity
- Multiple redundant checks for the same relationships

**Time Complexity**: Potentially exponential in worst case for transitive checks
**Space Complexity**: O(M) for storing pairs

---

## Time & Space Complexity Analysis

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Union-Find | O(N + M·α(K)) | O(K) | **Best for most cases** |
| Graph DFS/BFS | O(N·(K+M)) | O(K+M) | Can be slower with repeated traversals |
| Direct Pair Lookup | O(N·K²) or worse | O(M) | Inefficient for transitive checks |

where:
- N = sentence length
- M = number of similar pairs
- K = number of unique words

---

## Key Concepts and Patterns

### 1. **Transitivity**
The most critical insight: if A~B and B~C, then A~C.
- This is automatically handled by union-find and connected components
- Direct pair lookup requires explicit checking

### 2. **Connected Components**
Words that are transitively similar form a connected component in the graph.
- All words in the same component are similar to each other
- Two words at the same position need to be in the same component

### 3. **Bidirectional Relationships**
Similarity is **symmetric**: if "great" ~ "fine", then "fine" ~ "great".
- Must handle both directions in pairs
- Union-find and graphs handle this naturally

### 4. **Identity as Built-in Similarity**
A word is always similar to itself.
- This is free in union-find (every node is in its own set initially)
- In DFS/BFS, a word can reach itself
- In pair lookup, this must be checked explicitly

---

## Edge Cases and Common Pitfalls

### Edge Case 1: Empty Similarity Pairs
```
sentence1 = ["a", "b"]
sentence2 = ["b", "a"]
similarPairs = []
```
Only identical words are similar. Result: `false` (positions don't match exactly)

### Edge Case 2: Same Sentence
```
sentence1 = ["great", "acting", "skills"]
sentence2 = ["great", "acting", "skills"]
similarPairs = []
```
Every position matches identically. Result: `true`

### Edge Case 3: Long Transitive Chains
```
similarPairs = [["a","b"], ["b","c"], ["c","d"], ["d","e"]]
```
All words end up in the same component. "a" ~ "e" through the chain.

### Common Pitfall 1: Forgetting Symmetry
Pairs should work both ways. If you store [a → b], remember to handle [b → a].

### Common Pitfall 2: Forgetting Identity
Words are always similar to themselves. Position matching like ["a"] vs ["a"] should return `true`.

### Common Pitfall 3: Not Handling Transitive Relationships
Thinking only about direct pairs and missing transitive connections.

### Common Pitfall 4: Different Sentence Lengths
If sentences have different lengths, immediately return `false`.

---

## Optimization Notes

### Optimization 1: Union-Find with Path Compression
When finding the root of a node, compress the path so future finds are faster.

### Optimization 2: Union by Rank
Always attach smaller trees under larger ones to keep the tree shallow.

### Optimization 3: Early Termination
If you find any position where words aren't similar, return `false` immediately. Don't check all positions.

### Optimization 4: Lazy Building
Only add pairs to your data structure if they appear in `similarPairs`. Don't preprocess words.

### Optimization 5: Set for O(1) Pair Lookup
When storing pairs directly, use a set for O(1) lookup instead of a list.

---

## Summary

The **Union-Find approach** is the most elegant and efficient:
1. Words form transitive groups through similar pairs
2. Union-Find naturally handles this with disjoint sets
3. Check if words at each position are in the same set
4. Time complexity is nearly linear, space is linear in unique words

The **Graph approach** is intuitive and also efficient:
1. Treat similarity as an undirected graph
2. Connected components represent transitive groups
3. Check if words at each position are in the same component
4. Slightly less efficient than union-find due to repeated traversals

Choose **Union-Find** for optimal performance.