# Reorder List - Tutorial

## Problem Understanding

You need to reorder a linked list so that it alternates between nodes from the beginning and the end:
- Take first node, then last node
- Take second node, then second-to-last node
- Continue until all nodes are used

**Key Points:**
- Must reorder in-place (O(1) extra space, not counting recursion stack)
- Cannot change node values, only rearrange pointers
- Original: `1 → 2 → 3 → 4 → 5`
- Result: `1 → 5 → 2 → 4 → 3`

**Pattern:**
```
Original: L0 → L1 → L2 → L3 → L4 → L5
Result:   L0 → L5 → L1 → L4 → L2 → L3
          ↑___↑____↑____↑____↑____↑
          Start  End  2nd  2ndEnd  ...
```

## Drawing Template

Use this template to visualize the reorder list process:

### Initial List
```
Draw your input list:

Node:  [  ] → [  ] → [  ] → [  ] → [  ] → [  ]
Value:  __    __    __    __    __    __
Index:  0     1     2     3     4     5
```

### Step 1: Find Middle (Slow/Fast Pointers)
```
Track pointer positions as they move:

Iteration 0:
slow = [  ], fast = [  ]
[  ] → [  ] → [  ] → [  ] → [  ] → [  ]
 ↑                                 
slow/fast

Iteration 1:
slow = [  ], fast = [  ]
[  ] → [  ] → [  ] → [  ] → [  ] → [  ]
       ↑             ↑
      slow          fast

Iteration 2:
slow = [  ], fast = [  ]
[  ] → [  ] → [  ] → [  ] → [  ] → [  ]
             ↑                     ↑
            slow                  fast

Middle found at: _____
```

### Step 2: Split and Reverse Second Half
```
After splitting:

First Half:
[  ] → [  ] → [  ] → None
 __    __    __

Second Half (before reverse):
[  ] → [  ] → [  ] → None
 __    __    __

Second Half (after reverse):
[  ] ← [  ] ← [  ]
 __    __    __
 ↑
head

Redraw:
[  ] → [  ] → [  ] → None
 __    __    __
```

### Step 3: Merge Two Halves
```
Show each merge iteration:

Before merge:
First:  [  ] → [  ] → [  ]
         __    __    __

Second: [  ] → [  ] → [  ]
         __    __    __

Iteration 1:
first=____, second=____
[  ] → [  ] → [  ] → [  ] → [  ] → [  ]
 __    __    __    __    __    __
 ↑     ↑
conn  conn

Iteration 2:
first=____, second=____
[  ] → [  ] → [  ] → [  ] → [  ] → [  ]
 __    __    __    __    __    __
             ↑     ↑
            conn  conn

Iteration 3:
first=____, second=____
[  ] → [  ] → [  ] → [  ] → [  ] → [  ]
 __    __    __    __    __    __
                         ↑     ↑
                        conn  conn

Final Result:
[  ] → [  ] → [  ] → [  ] → [  ] → [  ]
 __    __    __    __    __    __
```

### Edge Case Template
```
Test your understanding with edge cases:

Single Node:
[  ]
 __
Result: [  ]
        __

Two Nodes:
[  ] → [  ]
 __    __
Result: [  ] → [  ]
        __    __

Three Nodes:
[  ] → [  ] → [  ]
 __    __    __
Middle: ____
After split & reverse:
  First: [  ] → [  ]    Second: [  ]
          __    __               __
Result: [  ] → [  ] → [  ]
        __    __    __
```

## Intuition

To interleave nodes from start and end, we need easy access to both ends. But singly linked lists only allow forward traversal!

**Solution Approach:**
1. Find the middle of the list
2. Reverse the second half
3. Merge the two halves alternately

## Approach: Three-Step Process

### Step 1: Find the Middle

Use **slow and fast pointers** (tortoise and hare):
- Slow moves 1 step at a time
- Fast moves 2 steps at a time
- When fast reaches the end, slow is at the middle

```
Original: 1 → 2 → 3 → 4 → 5
                ↑
              middle

Original: 1 → 2 → 3 → 4
             ↑
           middle
```

### Step 2: Reverse the Second Half

Starting from the middle, reverse the second half of the list:

```
Before:  1 → 2 → 3 → 4 → 5
         First half: 1 → 2 → 3
         Second half: 4 → 5

After reversing second half:
         First half: 1 → 2 → 3
         Second half: 5 → 4
```

### Step 3: Merge Two Halves

Alternately take nodes from first and second halves:

```
First:  1 → 2 → 3
Second: 5 → 4

Merge: 1 → 5 → 2 → 4 → 3
```

## Detailed Algorithm

### Step 1: Find Middle

```
slow = head
fast = head

while fast.next and fast.next.next:
    slow = slow.next
    fast = fast.next.next

# slow is now at the end of first half
```

**Why `fast.next.next`?**
- Ensures we split correctly for both odd and even lengths
- For odd length: middle belongs to first half
- For even length: split evenly

### Step 2: Reverse Second Half

```
# Split into two halves
second = slow.next
slow.next = None  # End first half

# Reverse second half
prev = None
while second:
    next = second.next
    second.next = prev
    prev = second
    second = next

second = prev  # New head of second half
```

### Step 3: Merge

```
first = head
while second:
    # Save next nodes
    tmp1 = first.next
    tmp2 = second.next
    
    # Relink
    first.next = second
    second.next = tmp1
    
    # Move forward
    first = tmp1
    second = tmp2
```

## Visual Walkthrough

**Input:** `head = [1,2,3,4,5]`

### Step 1: Find Middle

```
Initial:
slow = 1, fast = 1
1 → 2 → 3 → 4 → 5

After loop:
slow = 3, fast = 5
1 → 2 → 3 → 4 → 5
        ↑       ↑
      slow    fast
```

### Step 2: Split and Reverse

```
Split:
First:  1 → 2 → 3 → None
Second: 4 → 5

Reverse second:
First:  1 → 2 → 3
Second: 5 → 4 → None
```

### Step 3: Merge

```
Iteration 1:
first = 1, second = 5
1 → 5 → 2 → 3
    ↓
    4

Iteration 2:
first = 2, second = 4
1 → 5 → 2 → 4 → 3

Iteration 3:
first = 3, second = None
Done!

Result: 1 → 5 → 2 → 4 → 3
```

## Edge Cases

1. **Single node:** `[1]` → `[1]` (no change needed)
2. **Two nodes:** `[1,2]` → `[1,2]` (no change needed)
3. **Three nodes:** `[1,2,3]` → `[1,3,2]`
4. **Even length:** `[1,2,3,4]` → `[1,4,2,3]`
5. **Odd length:** `[1,2,3,4,5]` → `[1,5,2,4,3]`

## Complexity Analysis

- **Time Complexity:** O(n)
  - Find middle: O(n)
  - Reverse second half: O(n/2)
  - Merge: O(n/2)
  - Total: O(n)

- **Space Complexity:** O(1)
  - Only using pointers
  - In-place modification

## Common Pitfalls

1. **Wrong middle finding:** Not handling odd/even lengths correctly
2. **Forgetting to split:** Must set `slow.next = None` to separate the halves
3. **Merging logic errors:** Not saving next pointers before relinking
4. **Off-by-one errors:** Checking wrong conditions in merge loop
5. **Not handling edge cases:** Single node or two nodes need special attention

## Key Takeaways

- **Three-step approach:** Find middle → Reverse → Merge
- **Slow/fast pointers** are perfect for finding the middle
- **In-place reversal** reuses the reverseList pattern
- **Merge pattern:** Save next pointers, relink, move forward
- This problem **combines multiple linked list techniques**
- Must modify structure, not values

## Practice Tips

1. Draw the list and trace through each step
2. Practice each sub-problem separately:
   - Find middle
   - Reverse list
   - Merge two lists
3. Test with both odd and even lengths
4. Verify edge cases: 1, 2, 3 nodes
5. Make sure to break the list in the middle (set `slow.next = None`)
