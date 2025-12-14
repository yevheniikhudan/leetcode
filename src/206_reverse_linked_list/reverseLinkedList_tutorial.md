# Reverse Linked List - Tutorial

## Problem Understanding

You're given the head of a singly linked list. Your task is to reverse the direction of all the pointers, so the list flows in the opposite direction, and return the new head.

**Key Points:**
- Each node has a `val` and a `next` pointer
- We need to reverse the direction of all `next` pointers
- The original tail becomes the new head
- The original head becomes the new tail (pointing to null)

## Intuition

Think of a linked list like a chain of people holding hands:
```
1 → 2 → 3 → 4 → 5 → null
```

To reverse it, we need each person to turn around and hold the hand of the person behind them:
```
null ← 1 ← 2 ← 3 ← 4 ← 5
```

## Approach 1: Iterative Solution

### Key Idea

Use **three pointers** to reverse the links one by one:
1. `prev` - tracks the previous node (starts as null)
2. `curr` - tracks the current node we're processing
3. `next` - temporarily stores the next node before we change the link

### Algorithm Steps

1. Initialize `prev = null` and `curr = head`
2. While `curr` is not null:
   - Save the next node: `next = curr.next`
   - Reverse the current link: `curr.next = prev`
   - Move forward: `prev = curr`, `curr = next`
3. Return `prev` (the new head)

### Visual Walkthrough

**Initial:** `head = [1,2,3,4,5]`

```
prev = null, curr = 1
null   1 → 2 → 3 → 4 → 5
```

**Step 1:**
```
Save next = 2
Reverse: 1.next = null
Move: prev = 1, curr = 2

null ← 1   2 → 3 → 4 → 5
      prev curr
```

**Step 2:**
```
Save next = 3
Reverse: 2.next = 1
Move: prev = 2, curr = 3

null ← 1 ← 2   3 → 4 → 5
           prev curr
```

**Step 3-5:** Continue until all nodes are reversed

**Final:**
```
null ← 1 ← 2 ← 3 ← 4 ← 5
                        prev (new head)
```

### Complexity Analysis

- **Time Complexity:** O(n) - we visit each node exactly once
- **Space Complexity:** O(1) - only using three pointers

## Approach 2: Recursive Solution

### Key Idea

Use the call stack to process nodes from the end backwards:
1. Recursively reach the last node (the new head)
2. On the way back up the call stack, reverse each link
3. Return the new head (which was the last node)

### Algorithm Steps

1. **Base case:** If head is null or head.next is null, return head
2. **Recursive case:**
   - Recursively reverse the rest: `newHead = reverseList(head.next)`
   - Reverse the current link: `head.next.next = head`
   - Break the old link: `head.next = null`
   - Return `newHead`

### Visual Walkthrough

**Input:** `head = [1,2,3]`

```
Call stack going down:
reverseList(1)
  reverseList(2)
    reverseList(3)
      return 3 (base case)
```

```
Coming back up:
At node 2:
  newHead = 3
  2.next.next = 2  →  3.next = 2
  2.next = null
  
  Result: 3 → 2 → null

At node 1:
  newHead = 3 (unchanged)
  1.next.next = 1  →  2.next = 1
  1.next = null
  
  Result: 3 → 2 → 1 → null
```

### Complexity Analysis

- **Time Complexity:** O(n) - visit each node once
- **Space Complexity:** O(n) - recursive call stack uses n frames

## Comparison: Iterative vs Recursive

| Aspect | Iterative | Recursive |
|--------|-----------|-----------|
| Space | O(1) - better | O(n) - call stack |
| Readability | More code, clearer logic | Less code, elegant |
| Performance | Faster (no function calls) | Slower (function overhead) |
| Stack overflow risk | None | Possible for very long lists |

## Common Pitfalls

1. **Forgetting to save `next`:** If you change `curr.next` before saving it, you lose the rest of the list!

2. **Wrong return value:** Return `prev`, not `curr` (curr will be null at the end)

3. **Not breaking the old head's link (recursive):** Forgetting `head.next = null` creates a cycle

4. **Empty list edge case:** Handle null input correctly

## Key Takeaways

- **Iterative approach** is generally preferred for linked list reversal (O(1) space)
- **Three pointers** (prev, curr, next) is the standard pattern for in-place linked list operations
- **Recursive approach** is elegant but uses more space
- Always think about edge cases: empty list, single node, two nodes

## Practice Tips

1. Draw the linked list and pointers step by step
2. Trace through with a small example (2-3 nodes)
3. Practice both iterative and recursive versions
4. Test with edge cases: [], [1], [1,2]
