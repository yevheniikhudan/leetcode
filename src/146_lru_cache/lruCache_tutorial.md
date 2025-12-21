# LRU Cache - Tutorial

## Problem Understanding

An **LRU (Least Recently Used) Cache** is a data structure that:
1. Stores key-value pairs with a fixed capacity
2. When at capacity, removes the **least recently used** item
3. Supports O(1) time for both `get` and `put` operations

**"Recently Used"** means:
- Accessed via `get(key)`
- Added or updated via `put(key, value)`

## Key Challenge

**How do we achieve O(1) time for both operations?**

We need:
- **Fast lookup** by key → Hash Table
- **Fast removal** of least recently used → Doubly Linked List
- **Fast update** of usage order → Move nodes in linked list

## Data Structure Design

### Why Hash Table + Doubly Linked List?

**Hash Table (HashMap/Dictionary):**
- Maps `key` → `node in linked list`
- Provides O(1) lookup

**Doubly Linked List:**
- Maintains order of usage (most recent to least recent)
- Provides O(1) insertion and deletion when you have the node reference
- **Head** = Most recently used
- **Tail** = Least recently used

### Visual Structure

```
Hash Table:
key1 → Node1 ──┐
key2 → Node2 ──┼─→ Doubly Linked List:
key3 → Node3 ──┘    Head ←→ Node1 ←→ Node2 ←→ Node3 ←→ Tail
                    (MRU)                            (LRU)
```

## Core Operations

### 1. get(key)

**Goal:** Return value and mark as recently used

**Steps:**
1. Check if key exists in hash table
   - If NO: return -1
   - If YES: proceed to step 2
2. Get the node from hash table
3. **Move node to front** (most recently used position)
4. Return node's value

**Why move to front?** Accessing a key makes it "recently used"!

---

### 2. put(key, value)

**Goal:** Add/update key-value pair, evict LRU if needed

**Case 1: Key already exists**
1. Get the node from hash table
2. Update node's value
3. **Move node to front** (mark as recently used)

**Case 2: Key doesn't exist**
1. Check if cache is at capacity
   - If YES: **Remove tail node** (least recently used)
   - Also remove from hash table
2. Create new node with key-value
3. Add node to front
4. Add to hash table

---

### 3. Helper Operations

**Move to Front (Make Most Recently Used):**
1. Remove node from current position
2. Insert node at head

**Remove Node:**
1. Update previous node's next pointer
2. Update next node's previous pointer

**Add to Front:**
1. Insert after dummy head
2. Update pointers

---

## Implementation Strategy

### Doubly Linked List Node Structure

Each node needs:
- `key` (to remove from hash table when evicting)
- `value` (the cached data)
- `prev` pointer (to previous node)
- `next` pointer (to next node)

### Dummy Nodes (Sentinel Nodes)

Use **dummy head** and **dummy tail** to simplify edge cases:
```
DummyHead ←→ Node1 ←→ Node2 ←→ DummyTail
```

**Benefits:**
- No null checks for insertion/deletion
- Head/tail operations become uniform
- Cleaner code

---

## Visualization Example

**Capacity = 2**

### Initial State
```
Hash: {}
List: DummyHead ←→ DummyTail
```

### After put(1, 1)
```
Hash: {1 → Node1}
List: DummyHead ←→ Node1(1,1) ←→ DummyTail
```

### After put(2, 2)
```
Hash: {1 → Node1, 2 → Node2}
List: DummyHead ←→ Node2(2,2) ←→ Node1(1,1) ←→ DummyTail
      (MRU)                                    (LRU)
```

### After get(1)
```
Hash: {1 → Node1, 2 → Node2}
List: DummyHead ←→ Node1(1,1) ←→ Node2(2,2) ←→ DummyTail
      (MRU - just accessed)              (LRU)
```

### After put(3, 3) - Capacity reached!
```
Evict Node2 (LRU):
Hash: {1 → Node1, 3 → Node3}
List: DummyHead ←→ Node3(3,3) ←→ Node1(1,1) ←→ DummyTail
      (MRU - just added)                 (LRU)
```

---

## Visual Template (Use Excalidraw)

Draw these scenarios:

### 1. Data Structure Diagram
- Hash table with arrows pointing to nodes
- Doubly linked list with bidirectional arrows
- Label head (MRU) and tail (LRU)

### 2. Operation Sequences
- Show state after each operation
- Highlight which node is moved/evicted
- Show hash table updates

### 3. Edge Cases
- Single element cache
- Full cache eviction
- Updating existing key

---

## Time & Space Complexity

### Time Complexity:
- **get(key)**: O(1) - hash lookup + linked list pointer update
- **put(key, value)**: O(1) - hash lookup + linked list insertion/deletion

### Space Complexity:
- O(capacity) - hash table + linked list nodes

---

## Common Mistakes

1. ❌ **Forgetting to update hash table** when evicting LRU node
2. ❌ **Not moving node on get()** - accessing should mark as recently used!
3. ❌ **Wrong eviction** - must remove TAIL (least recent), not head
4. ❌ **Forgetting to update value** when key already exists in put()
5. ❌ **Null pointer errors** - use dummy head/tail to avoid
6. ❌ **Not storing key in node** - need it to remove from hash table

---

## Key Insights

1. **Combination of Data Structures**: Neither hash table nor linked list alone can achieve O(1) for both operations

2. **Doubly Linked vs Singly Linked**: Need doubly linked to remove nodes in O(1) (need access to previous node)

3. **Dummy Nodes**: Simplify edge cases dramatically

4. **Order Maintenance**: Linked list order = usage order (MRU to LRU)

5. **Two-Way Mapping**: Hash table stores key→node, node stores key (for reverse lookup)

---

## Practice Steps

1. Draw the data structure on paper
2. Simulate get/put operations step by step
3. Track both hash table and linked list state
4. Pay attention to pointer updates
5. Test edge cases: capacity 1, repeated keys, eviction

---

## Alternative Approaches

### ❌ Why NOT use array/list?
- O(n) to find LRU element
- O(n) to remove from middle

### ❌ Why NOT use hash table only?
- Can't track usage order efficiently
- O(n) to find LRU key

### ❌ Why NOT use priority queue?
- O(log n) operations
- Updating priority is expensive

### ✅ Why Hash Table + Doubly Linked List?
- **Perfect combination**: O(1) lookup + O(1) insertion/deletion
- Natural order maintenance with linked list
- Fast access with hash table

---

## Related Concepts

- **Cache Replacement Policies**: LRU, LFU, FIFO
- **Doubly Linked List Operations**: Insert, delete, move
- **Hash Table Design**: Key-value mapping
- **Sentinel Nodes**: Simplifying boundary conditions
