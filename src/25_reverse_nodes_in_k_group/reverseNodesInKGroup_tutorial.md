# Reverse Nodes in k-Group - Tutorial

## Problem Understanding

Given a linked list, reverse every `k` consecutive nodes. If there are fewer than `k` nodes left at the end, leave them as-is.

**Key Requirements:**
- Reverse in groups of exactly `k` nodes
- If fewer than `k` nodes remain, don't reverse them
- Cannot modify node values, only rearrange pointers
- Follow-up: O(1) space (no recursion or extra data structures)

**Example Visualization:**
```
Input:  1 → 2 → 3 → 4 → 5, k = 2
        [1 → 2] [3 → 4] [5]
        
Output: 2 → 1 → 4 → 3 → 5
        [2 → 1] [4 → 3] [5]
```

---

## Approaches

### Approach 1: Iterative with Pointer Manipulation ⭐⭐⭐ (Best - O(1) Space)

**Key Insight:** Process the list in chunks of k nodes, reversing each complete chunk.

**High-Level Strategy:**
1. Check if there are at least k nodes ahead
2. If yes: reverse the next k nodes
3. Connect the reversed segment to the previous segment
4. Move to the next group
5. Repeat until fewer than k nodes remain

**Visual Breakdown:**

**Initial State:**
```
dummy → 1 → 2 → 3 → 4 → 5
prev    |
        groupStart
```

**After reversing first k=2 nodes:**
```
dummy → 2 → 1 → 3 → 4 → 5
        ↑   ↑
       new  old
      head  head
```

**Key Variables Needed:**
- `prev`: Node before current group
- `groupStart`: First node of current group (becomes last after reverse)
- `groupEnd`: Last node of current group (becomes first after reverse)
- `nextGroup`: First node of next group

**Steps to Reverse a k-Group:**
1. **Identify the group:**
   - Start from `prev.next`
   - Count k nodes forward
   - If can't count k nodes → done!

2. **Reverse the k nodes:**
   - Use standard reverse logic
   - Keep track of what comes after

3. **Reconnect:**
   - `prev.next` = new head of reversed group
   - Old head of group → next group's head
   - Move `prev` to old head of group

4. **Continue to next group**

**Time Complexity:** O(n) - each node visited once  
**Space Complexity:** O(1) - only pointers used ✅

---

### Approach 2: Recursive Solution ⭐⭐ (Clean but uses stack)

**Key Insight:** Recursively reverse each group and connect them.

**Strategy:**
1. Check if there are at least k nodes
2. If yes:
   - Reverse first k nodes
   - Recursively process remaining list
   - Connect reversed group to recursive result
3. If no: return head as-is

**Visual Flow:**
```
reverseKGroup([1,2,3,4,5], k=2)
  ↓
  Reverse [1,2] → [2,1]
  ↓
  Recursively process [3,4,5]
    ↓
    Reverse [3,4] → [4,3]
    ↓
    Recursively process [5]
      ↓
      Return [5] as-is (< k nodes)
    ↓
    Connect: [4,3] → [5]
  ↓
  Connect: [2,1] → [4,3,5]
  ↓
  Return: [2,1,4,3,5]
```

**Time Complexity:** O(n)  
**Space Complexity:** O(n/k) - recursion stack ⚠️

---

### Approach 3: Helper Function Pattern ⭐⭐⭐

**Key Insight:** Separate concerns - counting, reversing, and connecting.

**Helper Functions:**
1. **countNodes(head, k)**: Check if k nodes exist
2. **reverseK(head, k)**: Reverse exactly k nodes, return new head
3. **Main function**: Use helpers to process groups

**Advantages:**
- Cleaner code organization
- Each function has single responsibility
- Easier to test and debug

---

## Detailed: Iterative Approach

### The Reverse Operation

**Standard Reverse for k Nodes:**
```
Input:  1 → 2 → 3 (k=3)
        ↓
        curr

Step 1: Save next, reverse pointer
  prev = None
  curr = 1, next = 2
  1.next = None
  prev = 1, curr = 2

Step 2: 
  next = 3
  2.next = 1
  prev = 2, curr = 3

Step 3:
  next = None
  3.next = 2
  prev = 3, curr = None

Result: 3 → 2 → 1
        ↑
       prev (new head)
```

### The Connection Logic

**Before Reverse:**
```
prev → [1 → 2 → 3] → 4 → 5
       groupStart   nextGroup
```

**After Reverse:**
```
Want: prev → [3 → 2 → 1] → 4 → 5
              ↑       ↑
           newHead  oldHead
```

**Key Connections:**
1. `prev.next = newHead` (3)
2. `oldHead.next = nextGroup` (1 → 4)
3. `prev = oldHead` (move to 1 for next iteration)

---

## Edge Cases

### 1. **Fewer than k nodes remaining**
```
Input: [1,2,3,4,5], k=3
After first group: [3,2,1,4,5]
Remaining: [4,5] (only 2 nodes, < 3)
Output: [3,2,1,4,5] (don't reverse)
```

### 2. **Exact multiple of k**
```
Input: [1,2,3,4], k=2
Output: [2,1,4,3]
All groups reversed!
```

### 3. **k = 1**
```
Input: [1,2,3], k=1
Output: [1,2,3]
Reverse each single node = no change
```

### 4. **k = n (length)**
```
Input: [1,2,3], k=3
Output: [3,2,1]
Reverse entire list
```

### 5. **Single node**
```
Input: [1], k=1 or any k
Output: [1]
```

---

## Visual Template (Use Excalidraw)

Draw these scenarios:

### 1. Step-by-Step Reversal:
- Original list: `1 → 2 → 3 → 4 → 5`, k=2
- Show pointer positions during first group reverse
- Show connections being updated
- Show final state

### 2. Pointer Tracking:
- Draw `prev`, `curr`, `next` pointers
- Show how they move during reversal
- Highlight the reconnection step

### 3. Edge Case:
- Show list with incomplete group at end
- Demonstrate why those nodes aren't reversed

---

## Common Mistakes

1. ❌ **Not checking if k nodes exist** before reversing
2. ❌ **Losing connection** to the rest of the list
3. ❌ **Forgetting dummy node** to handle new head
4. ❌ **Off-by-one errors** in counting k nodes
5. ❌ **Not updating prev** pointer after each group
6. ❌ **Modifying node values** instead of rearranging pointers
7. ❌ **Reversing incomplete groups** at the end

---

## Step-by-Step Algorithm (Iterative)

```
1. Create dummy node pointing to head
2. Set prev = dummy

3. While true:
   a. Check if k nodes exist from prev.next
   b. If not: break (we're done)
   
   c. Save groupStart = prev.next
   d. Save groupEnd by moving k nodes forward
   e. Save nextGroup = groupEnd.next
   
   f. Reverse k nodes from groupStart to groupEnd
      - Standard reverse algorithm
      - Returns new head of reversed group
   
   g. Reconnect:
      - prev.next = new head of reversed group
      - groupStart.next = nextGroup (groupStart is now tail)
      - prev = groupStart (move prev for next iteration)

4. Return dummy.next
```

---

## Complexity Analysis

### Iterative Approach:
- **Time:** O(n) - each node processed once
- **Space:** O(1) - only pointers ✅

### Recursive Approach:
- **Time:** O(n) - each node processed once
- **Space:** O(n/k) - recursion depth

---

## Key Insights

1. **Dummy Node is Essential:**
   - Simplifies handling new head
   - Provides anchor point for reconnection

2. **Three-Phase Pattern:**
   - Check (do we have k nodes?)
   - Reverse (reverse the k nodes)
   - Connect (link to previous and next)

3. **Pointer Juggling:**
   - Need to track: prev, curr, next, groupStart, groupEnd
   - Careful not to lose any connections!

4. **The "prev" Pointer:**
   - Always points to node BEFORE current group
   - Gets updated to old head of group after reversal
   - Critical for connecting groups together

5. **Boundary Conditions:**
   - Must count nodes before reversing
   - Last incomplete group stays as-is

---

## Comparison with "Reverse Linked List"

| Aspect | Reverse Entire List | Reverse in k-Groups |
|--------|-------------------|-------------------|
| **Groups** | One group (entire list) | Multiple groups of k |
| **Counting** | Not needed | Must count k nodes |
| **Incomplete** | N/A | Leave incomplete group as-is |
| **Reconnection** | Return new head | Connect each reversed group |
| **Complexity** | Simpler | More bookkeeping |

---

## Practice Steps

1. First master reversing entire linked list
2. Practice reversing first k nodes only
3. Add logic to check if k nodes exist
4. Implement reconnection logic
5. Handle the iteration through all groups
6. Test with edge cases

---

## Related Concepts

- **Linked List Reversal:** Core operation
- **Pointer Manipulation:** Critical skill
- **Group Processing:** Chunking pattern
- **Dummy Node Pattern:** Simplifies head changes
- **Iterative vs Recursive:** Space trade-offs
