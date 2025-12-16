# Linked List Cycle - Tutorial

## Problem Understanding

You need to detect if a linked list contains a cycle - meaning that by following the `next` pointers, you can reach a node you've already visited.

**Key Points:**
- A cycle exists when a node's `next` pointer points back to a previous node
- You need to detect if ANY cycle exists (not find where it starts)
- `pos` parameter is just for explanation - you don't receive it as input
- Must return `true` if cycle exists, `false` otherwise

**Visual Example:**
```
Cycle exists:
3 → 2 → 0 → -4
    ↑_________↓

No cycle:
1 → 2 → 3 → null
```

## Approach 1: Hash Set (Space O(n))

### Key Idea

Keep track of all visited nodes in a hash set. If you encounter a node you've already visited, there's a cycle.

### Algorithm Steps

1. Create an empty hash set to store visited nodes
2. Start from the head
3. While current node is not null:
   - If current node is in the set → cycle found, return `true`
   - Add current node to the set
   - Move to next node
4. If you reach null → no cycle, return `false`

### Visual Walkthrough

**Input:** `head = [3,2,0,-4]` with cycle (tail connects to node 2)

```
Step 1: visited = {}, curr = 3
        Add 3 to visited
        visited = {3}

Step 2: curr = 2
        2 not in visited, add it
        visited = {3, 2}

Step 3: curr = 0
        0 not in visited, add it
        visited = {3, 2, 0}

Step 4: curr = -4
        -4 not in visited, add it
        visited = {3, 2, 0, -4}

Step 5: curr = 2 (cycle!)
        2 IS in visited → return true ✅
```

### Complexity Analysis

- **Time Complexity:** O(n) - visit each node at most once
- **Space Complexity:** O(n) - store all nodes in hash set

### Pros and Cons

✅ **Pros:**
- Simple and intuitive
- Easy to implement
- Works for all cases

❌ **Cons:**
- Uses O(n) extra space
- Not optimal for the follow-up question

---

## Approach 2: Floyd's Cycle Detection (Tortoise and Hare) ⭐

### Key Idea

Use **two pointers** moving at different speeds:
- **Slow pointer:** moves 1 step at a time
- **Fast pointer:** moves 2 steps at a time

If there's a cycle, the fast pointer will eventually catch up to the slow pointer (they'll meet). If there's no cycle, the fast pointer will reach the end (null).

**Why it works:** Think of it like running on a circular track. If one runner is twice as fast, they'll eventually lap the slower runner.

### Algorithm Steps

1. Initialize two pointers: `slow = head`, `fast = head`
2. While `fast` and `fast.next` are not null:
   - Move `slow` one step: `slow = slow.next`
   - Move `fast` two steps: `fast = fast.next.next`
   - If `slow == fast` → cycle found, return `true`
3. If loop exits → no cycle, return `false`

### Visual Walkthrough

**Input:** `head = [3,2,0,-4]` with cycle at node 2

```
Initial:
slow = 3, fast = 3

Step 1:
slow = 2 (moved 1 step)
fast = 0 (moved 2 steps)
slow ≠ fast

Step 2:
slow = 0 (moved 1 step)
fast = 2 (moved 2 steps, wrapped around due to cycle)
slow ≠ fast

Step 3:
slow = -4 (moved 1 step)
fast = -4 (moved 2 steps: 2 → 0 → -4)
slow == fast → Cycle detected! ✅
```

**Input:** `head = [1,2,3]` with no cycle

```
Initial:
slow = 1, fast = 1

Step 1:
slow = 2
fast = 3
slow ≠ fast

Step 2:
slow = 3
fast = null (went past the end)
Loop exits → No cycle ✅
```

### Why Does This Work?

**Mathematical Proof:**

If there's a cycle:
1. Both pointers will eventually enter the cycle
2. Once inside, the distance between them decreases by 1 each step
3. Since the cycle is finite, they must eventually meet

Think of it as the "gap closing" problem:
- Gap between pointers decreases by 1 per iteration
- Gap must eventually become 0 → they meet!

### Complexity Analysis

- **Time Complexity:** O(n) 
  - No cycle: Fast pointer reaches end in n/2 steps
  - With cycle: They meet after at most n steps
- **Space Complexity:** O(1) - only two pointers! ⭐

### Edge Cases

1. **Empty list** (`head = null`): Fast pointer is null immediately → no cycle
2. **Single node, no cycle** (`[1]`): Fast.next is null → no cycle
3. **Single node with cycle** (self-loop): Slow and fast both stay at same node → cycle detected
4. **Two nodes with cycle**: Works correctly

---

## Comparison: Hash Set vs Two Pointers

| Aspect | Hash Set | Two Pointers (Floyd's) |
|--------|----------|------------------------|
| Time | O(n) | O(n) |
| Space | O(n) | O(1) ⭐ |
| Intuitive? | ✅ Very | ⚠️ Requires understanding |
| Interview preferred | For quick solution | ✅ For follow-up |
| Edge cases | Easy | Must be careful |

---

## Common Pitfalls

1. **Forgetting null checks:** Always check `fast != null && fast.next != null`

2. **Wrong initialization:** Start both at head, not slow at head and fast at head.next

3. **Off-by-one errors:** Make sure fast moves TWO steps

4. **Comparing values instead of nodes:** Compare `slow == fast`, not `slow.val == fast.val`

5. **Modifying the list:** Don't change node values or structure (unlike some approaches that mark visited nodes)

---

## Key Takeaways

- **Hash set approach** is straightforward but uses O(n) space
- **Floyd's algorithm** (two pointers) is the optimal solution with O(1) space
- Fast pointer moves 2x speed of slow pointer
- If cycle exists, they MUST meet inside the cycle
- Always check `fast != null && fast.next != null` to avoid null pointer errors
- This is a **classic interview problem** - you should know both solutions!

---

## Practice Tips

1. Draw the linked list and trace through both pointers step by step
2. Test with: no cycle, single node, two nodes, cycle at different positions
3. Understand WHY Floyd's algorithm works (gap closing logic)
4. Practice implementing both solutions
5. In interviews, mention both approaches and explain trade-offs
