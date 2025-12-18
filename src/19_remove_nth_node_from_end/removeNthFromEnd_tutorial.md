# Remove Nth Node From End of List - Tutorial

## Problem Understanding

Given a linked list, remove the nth node from the end of the list and return the head.

**Key Points:**
- Remove from END, not from beginning
- n is always valid (1 ≤ n ≤ list length)
- Must do this efficiently in one pass
- Original: `1 → 2 → 3 → 4 → 5`, n = 2
- Result: `1 → 2 → 3 → 5` (removed 4)

## Intuition

**Challenge:** How to find the nth node from the END without knowing the list length?

**Naive Approach:**
1. Count total nodes (first pass)
2. Calculate position from start
3. Remove that node (second pass)
- Time: O(n), but requires two passes

**Better Approach: Two Pointers**
Use two pointers separated by n nodes. When the fast pointer reaches the end, the slow pointer will be exactly n nodes behind (at the node before the target).

## Approach: Two-Pointer Technique

### Key Insight

Maintain a gap of n nodes between two pointers:
- When `fast` reaches the end
- `slow` is at the node BEFORE the one to remove

**Why n+1 gap?**
We need slow to point to the node BEFORE the target so we can bypass the target node.

### Algorithm Steps

1. **Create dummy node** - handles edge case of removing head
2. **Position fast pointer** - move it n+1 steps ahead
3. **Move both pointers** - until fast reaches end
4. **Remove node** - bypass the target by updating slow's next pointer
5. **Return** - return dummy's next (handles case where head was removed)

## Visual Walkthrough

**Input:** `head = [1,2,3,4,5], n = 2`

### Step 1: Create Dummy and Position Pointers

```
dummy → 1 → 2 → 3 → 4 → 5
↑
slow/fast
```

### Step 2: Move Fast Pointer n+1 Steps (3 steps for n=2)

```
After 1 step:
dummy → 1 → 2 → 3 → 4 → 5
↑       ↑
slow   fast

After 2 steps:
dummy → 1 → 2 → 3 → 4 → 5
↑           ↑
slow       fast

After 3 steps:
dummy → 1 → 2 → 3 → 4 → 5
↑               ↑
slow           fast
```

### Step 3: Move Both Until Fast Reaches End

```
Iteration 1:
dummy → 1 → 2 → 3 → 4 → 5
        ↑           ↑
       slow        fast

Iteration 2:
dummy → 1 → 2 → 3 → 4 → 5
            ↑           ↑
           slow        fast

Iteration 3:
dummy → 1 → 2 → 3 → 4 → 5 → None
                ↑               ↑
               slow            fast
```

### Step 4: Remove Node

```
slow.next = slow.next.next

Before:
dummy → 1 → 2 → 3 → 4 → 5
                ↑   
               slow

After:
dummy → 1 → 2 → 3 → 5
                ↑   
               slow
              (4 is bypassed)

Result: 1 → 2 → 3 → 5
```

## Drawing Template

Use this template to visualize the two-pointer technique:

### Initial State
```
Draw the list with dummy node:
dummy → [  ] → [  ] → [  ] → [  ] → [  ]
         __    __    __    __    __

n = ___
```

### Position Fast Pointer (n+1 steps ahead)
```
dummy → [  ] → [  ] → [  ] → [  ] → [  ]
 ↑
slow/fast

After moving fast n+1 steps:
dummy → [  ] → [  ] → [  ] → [  ] → [  ]
 ↑                      ↑
slow                   fast

Gap between pointers: ___ nodes
```

### Move Both Pointers
```
Track iterations until fast reaches None:

Iteration ___:
dummy → [  ] → [  ] → [  ] → [  ] → [  ]
         ↑
        slow/fast position

When fast = None, slow is at: ____
```

### Remove Node
```
Before removal:
[  ] → [  ] → [  ]
 ↑      ↑
slow  target

After removal:
[  ] → [  ]
 ↑
slow
```

## Edge Cases

1. **Remove only node:** `[1], n=1` → `[]`
2. **Remove head:** `[1,2], n=2` → `[2]`
3. **Remove last node:** `[1,2,3], n=1` → `[1,2]`
4. **Two nodes, remove first:** `[1,2], n=1` → `[1]`
5. **Long list, remove middle:** Works same as main algorithm

## Why Dummy Node?

Without dummy node, removing the head requires special handling:

**With dummy:**
- dummy → 1 → 2 → 3
- slow is at dummy, can bypass node 1

**Without dummy:**
- 1 → 2 → 3
- If removing 1, need special case to return the new head

Dummy node unifies all cases!

## Complexity Analysis

- **Time Complexity:** O(L)
  - Single pass through the list
  - Moving fast pointer: O(n)
  - Moving both pointers: O(L-n)
  - Total: O(L) where L is list length

- **Space Complexity:** O(1)
  - Only using pointers
  - Dummy node is just one extra node

## Common Pitfalls

1. **Off-by-one error:** Moving fast n steps instead of n+1
   - Need slow to be BEFORE target node
2. **Forgetting dummy node:** Makes removing head complicated
3. **Not handling single node:** Check edge cases
4. **Memory leaks (C++):** Remember to delete the removed node
5. **Wrong gap size:** Fast should be n+1 ahead, not n ahead

## Key Takeaways

- **Two-pointer technique** solves "from end" problems elegantly
- **Dummy node** simplifies edge case handling
- **One-pass solution** is possible with careful pointer management
- **Gap of n+1** ensures slow is at the right position to remove target
- This pattern applies to many "nth from end" problems

## Practice Tips

1. Draw the list and trace through with small examples
2. Practice with different values of n (1, 2, middle, last)
3. Try removing head (n = length)
4. Verify the n+1 gap makes slow stop at the right position
5. Test with single node and two node cases
