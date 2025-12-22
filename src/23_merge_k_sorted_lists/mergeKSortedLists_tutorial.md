# Merge k Sorted Lists - Tutorial

## Problem Understanding

Given `k` sorted linked lists, merge them into **one** sorted linked list.

**Key Points:**
- Each individual list is already sorted
- Need to maintain sorted order in final result
- Can have up to 10,000 lists (k can be very large!)
- Total nodes across all lists ≤ 10,000

## Approaches

### Approach 1: Min-Heap (Priority Queue) ⭐⭐⭐ (Best for Large k)

**Key Insight:** At any moment, the next smallest element must be at the front of one of the k lists.

**Strategy:**
1. Use a min-heap to track the smallest node from each list
2. Initially add the head of each list to the heap
3. Repeatedly:
   - Pop the smallest node from heap (this is next in result)
   - If that node has a next node, push it to heap
4. Continue until heap is empty

**Why This Works:**
- Heap maintains the k smallest candidates efficiently
- Always have O(log k) access to the minimum
- Each node is added/removed from heap exactly once

**Visualization:**
```
Lists:
  1 → 4 → 5
  1 → 3 → 4
  2 → 6

Heap: [1, 1, 2]  (minimum of each list)

Step 1: Pop 1 (from list 1), add to result, push 4
  Result: 1
  Heap: [1, 2, 4]

Step 2: Pop 1 (from list 2), add to result, push 3
  Result: 1 → 1
  Heap: [2, 3, 4]

Step 3: Pop 2 (from list 3), add to result, push 6
  Result: 1 → 1 → 2
  Heap: [3, 4, 6]

... continue until heap empty
```

**Time Complexity:** O(N log k)
- N = total number of nodes
- Each node: O(log k) to add/remove from heap
- Total: N operations × O(log k) each

**Space Complexity:** O(k)
- Heap stores at most k nodes

---

### Approach 2: Divide and Conquer (Merge Sort Style) ⭐⭐

**Key Insight:** Merging k lists is like merge sort - pair them up and merge recursively.

**Strategy:**
1. Pair up lists and merge each pair
2. This reduces k lists to k/2 lists
3. Repeat until only 1 list remains

**Visualization:**
```
Round 1: Merge pairs
  [1→4→5] + [1→3→4] = [1→1→3→4→4→5]
  [2→6]   (alone)

Round 2: Merge pairs
  [1→1→3→4→4→5] + [2→6] = [1→1→2→3→4→4→5→6]

Done!
```

**Time Complexity:** O(N log k)
- log k levels of merging
- Each level processes all N nodes
- Total: N × log k

**Space Complexity:** O(1) or O(log k)
- O(1) if iterative
- O(log k) if recursive (call stack)

---

### Approach 3: Merge One by One ⚠️ (Inefficient)

**Strategy:** Merge list 1 with list 2, then result with list 3, etc.

**Why It's Slow:**
- First merge: merge 2 lists
- Second merge: merge result with third list (now longer)
- Third merge: merge result with fourth list (even longer)
- Each merge gets progressively slower

**Time Complexity:** O(k × N)
- Much worse than O(N log k)!

**Not Recommended** for large k!

---

### Approach 4: Brute Force (Not Recommended)

**Strategy:**
1. Collect all nodes into an array
2. Sort the array
3. Rebuild linked list

**Time Complexity:** O(N log N)
**Space Complexity:** O(N)

**Why Not Great:**
- Doesn't use fact that lists are already sorted
- Extra space for array
- More code to rebuild list

---

## Detailed: Min-Heap Approach

### Why Min-Heap is Optimal:

1. **Always know the minimum:** Heap top is always smallest
2. **Efficient updates:** O(log k) to add/remove
3. **Minimal comparisons:** Only compare k elements at a time
4. **Scalable:** Works great even with k = 10,000

### Implementation Considerations:

**Heap Elements:**
- Store nodes, not values
- Need to compare by node values

**Python:** Use `heapq` with tuples `(value, index, node)`
**Java:** Use `PriorityQueue` with custom comparator
**C++:** Use `priority_queue` with custom comparator

**Handling Ties:**
- When values are equal, need tiebreaker (like list index)
- Prevents comparison errors

---

## Detailed: Divide and Conquer Approach

### Pairing Strategy:

```
k=8 lists: [0, 1, 2, 3, 4, 5, 6, 7]

Round 1: Merge adjacent pairs
  0+1, 2+3, 4+5, 6+7
  Result: [01, 23, 45, 67]

Round 2: Merge adjacent pairs
  01+23, 45+67
  Result: [0123, 4567]

Round 3: Merge final pair
  0123+4567
  Result: [01234567]

Total rounds: log₂(8) = 3
```

**Optimization:** Can reuse merge-two-lists function!

---

## Visual Template (Use Excalidraw)

Draw these scenarios:

### 1. Min-Heap Approach:
- Draw k lists as rows
- Draw heap as triangle structure
- Show pointers advancing through lists
- Animate building result list

### 2. Divide and Conquer:
- Draw merge tree (like merge sort tree)
- Show pairs merging at each level
- Count the levels (log k)

### 3. Step-by-step Example:
- Lists: [1→4→5], [1→3→4], [2→6]
- Show heap state after each pop/push
- Show result list growing

---

## Complexity Comparison

| Approach | Time | Space | Best For |
|----------|------|-------|----------|
| **Min-Heap** | O(N log k) | O(k) | Large k, need constant updates |
| **Divide & Conquer** | O(N log k) | O(1) or O(log k) | Memory constrained |
| **One by One** | O(k × N) | O(1) | Small k only |
| **Brute Force** | O(N log N) | O(N) | Not recommended |

**Winner:** Min-Heap or Divide & Conquer (both O(N log k))

---

## Edge Cases

1. **Empty input:** `lists = []` → return `None`
2. **All empty lists:** `lists = [[], [], []]` → return `None`
3. **Single list:** `lists = [[1,2,3]]` → return that list
4. **Lists of different lengths:** Handle gracefully
5. **Negative values:** Works the same
6. **Duplicate values across lists:** All should appear in result

---

## Common Mistakes

1. ❌ **Comparing nodes instead of values** in heap
2. ❌ **Forgetting to add next node** when popping from heap
3. ❌ **Not handling empty lists** in input array
4. ❌ **Wrong heap comparison** (max heap instead of min heap)
5. ❌ **Memory leak** in C++ (forgetting to handle ownership)
6. ❌ **Not using dummy node** to simplify result list building

---

## Key Insights

1. **Heap is Perfect for This:**
   - k-way merging is exactly what heaps are designed for
   - Priority queue gives us O(log k) operations

2. **Already Sorted Advantage:**
   - Don't need to look at all nodes at once
   - Only need to compare k nodes (one from each list)

3. **Divide and Conquer Alternative:**
   - Reuses merge-two-lists logic
   - Same time complexity as heap
   - Better space complexity (no heap storage)

4. **Scalability:**
   - O(N log k) works even when k = 10,000
   - O(k × N) would be too slow

---

## Practice Steps

1. Start with merge-two-lists problem (easier)
2. Draw k=3 lists and simulate heap approach
3. Track heap contents after each step
4. Try divide-and-conquer approach
5. Compare approaches on paper
6. Implement your chosen approach

---

## Related Concepts

- **Priority Queue / Heap:** Min-heap operations
- **K-way Merge:** General pattern for merging k sorted sequences
- **Divide and Conquer:** Recursive problem decomposition
- **Merge Sort:** Similar merging technique
- **Linked List Manipulation:** Building result list
