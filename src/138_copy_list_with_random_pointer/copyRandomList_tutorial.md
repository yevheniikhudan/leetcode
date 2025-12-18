# Copy List with Random Pointer - Tutorial

## Problem Understanding

Given a linked list where each node has:
- A `val` (integer value)
- A `next` pointer (points to next node)
- A `random` pointer (points to ANY node in the list or null)

**Task:** Create a **deep copy** where:
- All nodes are brand new (no shared nodes with original)
- Structure is preserved (same next/random relationships)
- Pointers in copy point to nodes in copy, not original

**Example:**
```
Original: 1 → 2 → 3
Random pointers: 1→3, 2→1, 3→2

Copy:     1'→ 2'→ 3'
Random pointers: 1'→3', 2'→1', 3'→2'
(All pointers stay within their own list)
```

## Key Challenge

**Problem:** How to handle random pointers during copying?

When copying node A that has `random → B`:
- We need to set `A'.random → B'`
- But B' might not exist yet!
- Or we don't know where B' is

**We need a way to track: Original Node → Copied Node**

## Approach 1: Hash Map (Two-Pass)

### Intuition

Use a hash map to remember which nodes we've created:
- **Key:** Original node
- **Value:** Corresponding new node

This way, when we need to set a random pointer, we can look up the copied node in O(1) time.

### Algorithm Steps

**Pass 1: Create all nodes and build the map**
1. Traverse the original list
2. For each node, create a new node with same value
3. Store mapping: `map[original_node] = new_node`

**Pass 2: Set next and random pointers**
1. Traverse the original list again
2. For each node, set its copy's pointers:
   - `copy.next = map[original.next]`
   - `copy.random = map[original.random]`

### Visual Walkthrough

**Input:** `[[7,null],[13,0],[11,4],[10,2],[1,0]]`

**Pass 1: Create nodes and map**
```
Original:  7 → 13 → 11 → 10 → 1
           ↓    ↓    ↓    ↓   ↓
Map:      7'   13'  11'  10'  1'

Hash Map:
  7  → 7'
  13 → 13'
  11 → 11'
  10 → 10'
  1  → 1'
```

**Pass 2: Set pointers**
```
For node 7 (random = null):
  7'.next = map[13] = 13'
  7'.random = null

For node 13 (random = node 0):
  13'.next = map[11] = 11'
  13'.random = map[7] = 7'

For node 11 (random = node 4):
  11'.next = map[10] = 10'
  11'.random = map[1] = 1'

... and so on
```

**Final Result:**
```
Copied: 7' → 13' → 11' → 10' → 1'
Random: 7'→null, 13'→7', 11'→1', 10'→11', 1'→7'
```

## Approach 2: Interweaving (Three-Pass, O(1) Space)

### Intuition

Instead of using extra space for a hash map, **interweave** the copied nodes into the original list:

```
Original:    A → B → C
Interweaved: A → A' → B → B' → C → C'
```

Now, for any node N, its copy N' is at `N.next`!

### Algorithm Steps

**Pass 1: Create and interweave**
```
For each node N:
  1. Create copy N'
  2. Insert N' between N and N.next
  Result: N → N' → (N.next) → ...
```

**Pass 2: Set random pointers**
```
For each original node N:
  If N.random exists:
    N'.random = N.random.next (which is the copy of N.random)
```

**Pass 3: Separate the lists**
```
Restore original list structure
Extract the copied list
```

### Visual Walkthrough

**Input:** `[[1,1],[2,1]]`

**Pass 1: Interweave**
```
Original: 1 → 2

After inserting copies:
1 → 1' → 2 → 2' → null
```

**Pass 2: Set random pointers**
```
Node 1: random = node at index 1 (which is 2)
  1' is at 1.next
  2' is at 2.next
  1'.random = 1.random.next = 2.next = 2'

Node 2: random = node at index 1 (which is 2)
  2'.random = 2.random.next = 2.next = 2'
```

**Pass 3: Separate**
```
Extract copied list: 1' → 2'
Restore original: 1 → 2
```

## Drawing Template

Use this template to trace through the algorithm:

### Hash Map Approach

**Step 1: Create Map**
```
Original List:
[  ] → [  ] → [  ] → [  ]
 __    __    __    __

Hash Map:
Original → Copy
________   ________
________   ________
________   ________
________   ________
```

**Step 2: Set Pointers**
```
For each node:
Original node: ____, random index: ____
  Copy.next = map[original.next] = ____
  Copy.random = map[original.random] = ____
```

### Interweaving Approach

**Step 1: Interweave**
```
Original:
[  ] → [  ] → [  ]

After interweaving:
[  ] → [ '] → [  ] → [ '] → [  ] → [ ']
```

**Step 2: Set Random Pointers**
```
For each original node at position i:
  Node value: ____
  Random points to position: ____
  Copy's random = original.random.next
```

**Step 3: Separate**
```
Original: [  ] → [  ] → [  ]
Copied:   [ '] → [ '] → [ ']
```

## Edge Cases

1. **Empty list:** `null` → return `null`
2. **Single node with null random:** `[[1,null]]` → `[[1,null]]`
3. **Self-referencing random:** Node's random points to itself
4. **All nulls:** No random pointers set
5. **Circular randoms:** A→B, B→A
6. **Random to last node:** Ensure we handle boundary correctly

## Complexity Analysis

### Hash Map Approach
- **Time Complexity:** O(n)
  - Pass 1: O(n) to create nodes and map
  - Pass 2: O(n) to set pointers
  - Total: O(n)
- **Space Complexity:** O(n)
  - Hash map stores n entries

### Interweaving Approach
- **Time Complexity:** O(n)
  - Pass 1: O(n) to interweave
  - Pass 2: O(n) to set random pointers
  - Pass 3: O(n) to separate
  - Total: O(n)
- **Space Complexity:** O(1)
  - Only using pointers, no extra data structures
  - (Not counting the space for the new list itself)

## Common Pitfalls

1. **Shallow copy:** Creating new nodes but pointing to old nodes
2. **Not handling null random:** Forgetting to check if random is null
3. **Wrong map lookup:** Using value instead of node reference as key
4. **Not restoring original list:** In interweaving approach, must restore
5. **Off-by-one in interweaving:** Incorrect pointer manipulation
6. **Memory leaks:** In languages with manual memory management

## Key Takeaways

- **Hash map approach:** Simple and intuitive, uses O(n) space
- **Interweaving approach:** Clever space optimization to O(1)
- **Deep copy means:** New nodes with same structure, no shared references
- **Two main challenges:** Tracking copied nodes & handling random pointers
- **Hash map is a common pattern** for "need to remember previous mappings"

## Practice Tips

1. Start with hash map approach (easier to understand)
2. Draw out small examples by hand
3. Test with null random pointers
4. Test with self-referencing nodes
5. For interweaving: carefully trace pointer changes
6. Verify deep copy: check no nodes are shared
7. Try both approaches to understand trade-offs
