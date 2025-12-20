# Find the Duplicate Number - Tutorial

## Problem Understanding

You have an array of `n + 1` integers where each integer is in the range `[1, n]`. By the **Pigeonhole Principle**, at least one number must be duplicated. Your task is to find that duplicate.

**Key Constraints**:
- Cannot modify the array
- Must use O(1) extra space
- Must find the duplicate efficiently

## Approaches

### Approach 1: Floyd's Cycle Detection (Tortoise and Hare) ⭐

**Key Insight**: Treat the array as a linked list where `nums[i]` points to index `nums[i]`.

**Why This Works**:
1. Since there's a duplicate, multiple indices point to the same value
2. This creates a cycle in the "linked list"
3. The duplicate number is the entry point to the cycle
4. Use Floyd's algorithm (same as detecting cycle in linked list!)

**Visualization**:
```
Array: [1, 3, 4, 2, 2]
Index:  0  1  2  3  4

Treat as linked list:
- Start at index 0 (value 1)
- Go to index 1 (value 3)
- Go to index 3 (value 2)
- Go to index 2 (value 4)
- Go to index 4 (value 2)
- Go to index 2 (cycle detected!)

The cycle entry point is index 2, which has value 2 (the duplicate!)
```

**Phase 1: Detect Cycle**
- Use slow pointer (moves 1 step) and fast pointer (moves 2 steps)
- They will meet inside the cycle

**Phase 2: Find Entry Point**
- Reset one pointer to start
- Move both pointers 1 step at a time
- They meet at the cycle entry point (the duplicate!)

**Time Complexity**: O(n)
**Space Complexity**: O(1) ✅

---

### Approach 2: Binary Search

**Key Insight**: Use binary search on the value range `[1, n]`, not on indices!

**Strategy**:
1. For a midpoint value `mid`, count how many numbers are ≤ `mid`
2. If count > `mid`, the duplicate is in the left half `[1, mid]`
3. If count ≤ `mid`, the duplicate is in the right half `[mid+1, n]`

**Why This Works**:
- Without duplicates: exactly `mid` numbers would be ≤ `mid`
- With a duplicate in range `[1, mid]`: more than `mid` numbers are ≤ `mid`

**Visualization**:
```
Array: [1, 3, 4, 2, 2]
Range: [1, 4]

Check mid = 2:
- Count numbers ≤ 2: [1, 2, 2] = 3 numbers
- Expected: 2 numbers
- Since 3 > 2, duplicate is in [1, 2]

Check mid = 1:
- Count numbers ≤ 1: [1] = 1 number
- Expected: 1 number
- Since 1 ≤ 1, duplicate is in [2, 2]

Answer: 2
```

**Time Complexity**: O(n log n)
**Space Complexity**: O(1) ✅

---

### Approach 3: Bit Manipulation (Advanced)

**Key Insight**: Use XOR properties and bit counting.

**Strategy**:
1. For each bit position (0 to 31)
2. Count how many numbers have that bit set
3. Compare with expected count
4. Build the duplicate number bit by bit

**Time Complexity**: O(n log n)
**Space Complexity**: O(1) ✅

---

## Visual Template (Use Excalidraw)

Draw these scenarios:

### Floyd's Cycle Detection:
1. Array as indices: `[0, 1, 2, 3, 4]`
2. Array values: `[1, 3, 4, 2, 2]`
3. Draw arrows showing the "linked list":
   - 0 → 1 → 3 → 2 → 4 → 2 (cycle!)
4. Mark where slow/fast pointers meet
5. Show cycle entry point (the duplicate)

### Binary Search:
1. Draw the value range `[1, n]`
2. Show how you narrow down the range
3. Mark count of numbers ≤ mid at each step
4. Show converging to the duplicate

---

## Key Insights

1. **Pigeonhole Principle**: With `n + 1` items in `n` slots, at least one slot must have 2+ items

2. **Array as Graph**: The array can be viewed as a functional graph where index `i` has an edge to index `nums[i]`

3. **Cycle Detection**: The duplicate creates a cycle in this graph, and the duplicate value is the entry point

4. **Binary Search on Values**: You can binary search on the value space, not just indices!

---

## Common Mistakes

1. ❌ Modifying the array (violates constraints)
2. ❌ Using extra space like HashSet (violates O(1) space requirement)
3. ❌ Sorting the array (violates "don't modify" constraint)
4. ❌ Using mathematical formulas (doesn't work when duplicate appears > 2 times)

---

## Practice Steps

1. Start with Floyd's Cycle Detection (most elegant!)
2. Draw the array as a graph with arrows
3. Simulate slow/fast pointer movement
4. Find where they meet, then find cycle entry
5. Try Binary Search approach for variety
6. Compare time/space trade-offs

---

## Related Concepts

- **Floyd's Cycle Detection**: Same algorithm used in "Linked List Cycle II"
- **Binary Search**: Creative use on value range instead of indices
- **Pigeonhole Principle**: Mathematical guarantee of duplicate existence
- **Functional Graphs**: Array indices forming a graph structure
