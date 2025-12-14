# Merge Two Sorted Lists - Tutorial

## Problem Understanding

You're given two sorted linked lists, and you need to merge them into a single sorted linked list by connecting the nodes from both lists.

**Key Points:**
- Both input lists are already sorted in ascending order
- You need to maintain the sorted order in the merged list
- You should reuse the existing nodes (don't create new nodes)
- The result should contain all nodes from both lists

## Intuition

Think of merging like organizing two stacks of sorted cards into one sorted stack. At each step, you compare the top cards from both stacks and take the smaller one.

**Visual Example:**
```
list1: 1 → 2 → 4
list2: 1 → 3 → 4

Step-by-step:
Compare 1 vs 1 → take 1 from list1 → Result: 1
Compare 2 vs 1 → take 1 from list2 → Result: 1 → 1
Compare 2 vs 3 → take 2 from list1 → Result: 1 → 1 → 2
Compare 4 vs 3 → take 3 from list2 → Result: 1 → 1 → 2 → 3
Compare 4 vs 4 → take 4 from list1 → Result: 1 → 1 → 2 → 3 → 4
Only list2 left → take 4           → Result: 1 → 1 → 2 → 3 → 4 → 4
```

## Approach 1: Iterative Solution (Dummy Node)

### Key Idea

Use a **dummy node** to simplify the logic:
1. Create a dummy node to serve as the starting point
2. Use a `tail` pointer to track where to attach the next node
3. Compare nodes from both lists and attach the smaller one
4. Move the pointer in the list we took from
5. When one list is exhausted, attach the remainder of the other list
6. Return `dummy.next` (the actual head)

### Algorithm Steps

1. Create a dummy node: `dummy = new ListNode()`
2. Initialize tail pointer: `tail = dummy`
3. While both lists have nodes:
   - Compare `list1.val` vs `list2.val`
   - Attach the smaller node to `tail.next`
   - Move the pointer in the list we took from
   - Move `tail` forward
4. Attach the remaining nodes (if any) from either list
5. Return `dummy.next`

### Visual Walkthrough

**Input:** `list1 = [1,2,4]`, `list2 = [1,3,4]`

```
Initial:
dummy → (empty)
tail = dummy
list1 = 1 → 2 → 4
list2 = 1 → 3 → 4
```

**Step 1:** Compare 1 vs 1, take list1
```
dummy → 1
        ↑tail
list1 = 2 → 4
list2 = 1 → 3 → 4
```

**Step 2:** Compare 2 vs 1, take list2
```
dummy → 1 → 1
            ↑tail
list1 = 2 → 4
list2 = 3 → 4
```

**Step 3:** Compare 2 vs 3, take list1
```
dummy → 1 → 1 → 2
                ↑tail
list1 = 4
list2 = 3 → 4
```

**Step 4:** Compare 4 vs 3, take list2
```
dummy → 1 → 1 → 2 → 3
                    ↑tail
list1 = 4
list2 = 4
```

**Step 5:** Compare 4 vs 4, take list1
```
dummy → 1 → 1 → 2 → 3 → 4
                        ↑tail
list1 = null
list2 = 4
```

**Step 6:** list1 is null, attach remaining list2
```
dummy → 1 → 1 → 2 → 3 → 4 → 4
                            ↑tail
Final result: dummy.next = 1 → 1 → 2 → 3 → 4 → 4
```

### Complexity Analysis

- **Time Complexity:** O(n + m) - visit each node once, where n and m are lengths of the two lists
- **Space Complexity:** O(1) - only using a few pointers

### Why Use a Dummy Node?

Without a dummy node, you'd need special logic to handle the first node:
```
❌ Without dummy: Need to check if result is empty and set head
✅ With dummy: Always attach to tail.next, return dummy.next at end
```

The dummy node eliminates edge case handling for the head!

## Approach 2: Recursive Solution

### Key Idea

Use recursion to naturally handle the merging:
1. **Base cases:** If one list is empty, return the other
2. **Recursive case:** 
   - Compare the first nodes
   - The smaller one becomes the head
   - Its `next` points to the result of merging the remaining nodes

### Algorithm Steps

1. **Base cases:**
   - If `list1` is null, return `list2`
   - If `list2` is null, return `list1`

2. **Recursive case:**
   - If `list1.val <= list2.val`:
     - `list1.next = mergeTwoLists(list1.next, list2)`
     - Return `list1`
   - Else:
     - `list2.next = mergeTwoLists(list1, list2.next)`
     - Return `list2`

### Visual Walkthrough

**Input:** `list1 = [1,2]`, `list2 = [1,3]`

```
Call: merge([1,2], [1,3])
  1 <= 1, take list1[1]
  1.next = merge([2], [1,3])
  
    Call: merge([2], [1,3])
      2 > 1, take list2[1]
      1.next = merge([2], [3])
      
        Call: merge([2], [3])
          2 <= 3, take list1[2]
          2.next = merge([], [3])
          
            Call: merge([], [3])
              Base case: return list2[3]
              
          Return: 2 → 3
          
      Return: 1 → 2 → 3
      
  Return: 1 → 1 → 2 → 3
```

### Complexity Analysis

- **Time Complexity:** O(n + m) - visit each node once
- **Space Complexity:** O(n + m) - recursive call stack

## Comparison: Iterative vs Recursive

| Aspect | Iterative | Recursive |
|--------|-----------|-----------|
| Space | O(1) - better | O(n+m) - call stack |
| Code length | Slightly longer | Very concise |
| Readability | Clear step-by-step | Elegant |
| Stack overflow risk | None | Possible for very long lists |
| Interview preference | Either is fine | Shows good recursion understanding |

## Edge Cases to Consider

1. **Both lists empty:** Return null
2. **One list empty:** Return the other list
3. **Lists of different lengths:** Handle remaining nodes correctly
4. **Duplicate values:** Both lists can have same values
5. **Single node lists:** Should work correctly

## Common Pitfalls

1. **Forgetting the dummy node:** Makes the code more complex with special cases
2. **Not moving both pointers:** Remember to move the pointer of the list you took from
3. **Forgetting remaining nodes:** After the loop, one list may still have nodes
4. **Creating new nodes:** You should reuse existing nodes, not create new ones
5. **Wrong return value:** Return `dummy.next`, not `dummy`

## Key Takeaways

- **Dummy node pattern** simplifies linked list problems by eliminating head edge cases
- **Two-pointer technique** is common for comparing elements from two sources
- **Recursive solution** is elegant but uses more space
- Both input lists are already sorted - leverage this property!
- Always handle the remaining nodes when one list is exhausted

## Practice Tips

1. Draw the linked lists and pointers step by step
2. Test with equal-length and different-length lists
3. Test with edge cases: [], [1], [1,1,1]
4. Practice both iterative and recursive versions
5. Think about when dummy nodes are useful
