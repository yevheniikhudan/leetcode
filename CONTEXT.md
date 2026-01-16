# LeetCode Practice - Context File

## 📋 Instructions for AI Assistant

### When Given a LeetCode Link:

Create the complete setup with the following structure:

#### Directory Structure:
```
src/{ProblemNumber}_{problem_title}/
├── problem.md
├── tutorial.md
├── {problem_title}.py
├── {problem_title}.cpp
└── {ProblemTitle}.java
```

#### Naming Conventions:
- **Directory:** `{ProblemNumber}_{problem_title}` (snake_case with number prefix)
  - Example: `226_invert_binary_tree`
- **Files:**
  - `problem.md` - Problem description
  - `tutorial.md` - Tutorial (NO code implementations)
  - `{problem_title}.py` - Python skeleton (snake_case)
  - `{problem_title}.cpp` - C++ skeleton (snake_case)
  - `{ProblemTitle}.java` - Java skeleton (PascalCase)

#### What to Create:

1. **problem.md**
   - Problem title and difficulty
   - Topics/tags
   - Full problem description
   - Examples with clear input/output
   - Constraints
   - Related problems (if any)

2. **tutorial.md**
   - Understanding the problem (conceptual explanation)
   - Visual examples and diagrams
   - Multiple approaches (explain strategies, NO code), started from the most efficient
   - Time/Space complexity analysis
   - Key concepts and patterns
   - Edge cases and common pitfalls
   - Optimization notes

3. **{problem_title}.py** (Python Skeleton)
   - Class and method signatures ONLY
   - Method returns `pass` (no implementation)
   - Helper functions for testing
   - Test scaffolding with 5+ test cases
   - All tests ready to run

4. **{ProblemTitle}.java** (Java Skeleton)
   - Class and method signatures ONLY
   - Method returns `null` or appropriate default (no implementation)
   - Helper methods for testing
   - Test scaffolding with 5+ test cases
   - All tests ready to run
   - Class named Solution with method signatures (no implementation)
   - Separate class named {ProblemTitle} for main and test helpers

5. **{problem_title}.cpp** (C++ Skeleton)
   - Class and method signatures ONLY
   - Method returns `nullptr` or appropriate default (no implementation)
   - Helper functions for testing (including memory cleanup)
   - Test scaffolding with 5+ test cases
   - All tests ready to run

### Important Notes:
- ✅ Create ONLY these 5 files per problem
- ✅ Tutorial must be CODE-FREE (concepts and strategies only)
- ✅ Skeleton files contain ONLY signatures and test scaffolding
- ✅ NO implementations in skeleton files
- ❌ Do NOT create Excalidraw files (we will extend this later)

---

## 🗂️ Project Structure

```
leetcode/
├── CONTEXT.md (this file)
├── c++/
├── java/
├── python/
└── src/
    ├── 2_add_two_numbers/
    ├── 19_remove_nth_node_from_end/
    ├── 21_merge_two_sorted_lists/
    ├── 23_merge_k_sorted_lists/
    ├── 25_reverse_nodes_in_k_group/
    ├── 138_copy_list_with_random_pointer/
    ├── 141_linked_list_cycle/
    ├── 143_reorder_list/
    ├── 146_lru_cache/
    ├── 206_reverse_linked_list/
    ├── 226_invert_binary_tree/
    └── 287_find_the_duplicate_number/
```

---

## 🎯 Problems Completed

### Linked List Problems

#### 1. **206 - Reverse Linked List** (Easy)
- **Status:** ✅ Reviewed
- **Approaches:** Iterative, Recursive
- **Key Pattern:** Two-pointer traversal, pointer reversal

#### 2. **21 - Merge Two Sorted Lists** (Easy)
- **Status:** ✅ Reviewed
- **Approaches:** Iterative, Recursive
- **Key Pattern:** Two-pointer merge

#### 3. **141 - Linked List Cycle** (Easy)
- **Status:** ✅ Reviewed
- **Approaches:** Floyd's Cycle Detection (slow/fast pointers)
- **Key Pattern:** Two-pointer with different speeds

#### 4. **143 - Reorder List** (Medium)
- **Status:** ✅ Reviewed
- **Approaches:** Find middle + Reverse + Merge
- **Key Pattern:** Multiple linked list operations combined

#### 5. **19 - Remove Nth Node from End** (Medium)
- **Status:** ✅ Reviewed
- **Approaches:** Two-pass, One-pass with two pointers
- **Key Pattern:** Dummy node, two-pointer with gap

#### 6. **138 - Copy List with Random Pointer** (Medium)
- **Status:** ✅ Reviewed
- **Approaches:** HashMap, Interweaving nodes
- **Key Pattern:** Deep copy with extra pointers

#### 7. **2 - Add Two Numbers** (Medium)
- **Status:** ✅ Reviewed
- **Approaches:** Iterative with carry
- **Key Pattern:** Digit-by-digit addition with linked lists

#### 8. **25 - Reverse Nodes in k-Group** (Hard)
- **Status:** ✅ Reviewed (Python, Java, C++)
- **Approaches:** Iterative with dummy node
- **Key Pattern:** Group reversal, pointer management
- **Key Learning:** 
  - Dummy node simplifies head handling
  - Save `groupFirst` before reversal, reuse after
  - Connection to `groupNext` happens in first reversal iteration
  - Java version fixed redundancy from C++ version

### Array/Cycle Detection Problems

#### 9. **287 - Find the Duplicate Number** (Medium)
- **Status:** ✅ Reviewed
- **Approaches:** Floyd's Cycle Detection, Binary Search, Bit Manipulation
- **Key Pattern:** Treat array as linked list for cycle detection

### Design Problems

#### 10. **146 - LRU Cache** (Medium)
- **Status:** ✅ Reviewed
- **Approaches:** HashMap + Doubly Linked List
- **Key Pattern:** O(1) operations with combined data structures

#### 11. **23 - Merge k Sorted Lists** (Hard)
- **Status:** ✅ Reviewed (all approaches in all languages)
- **Approaches:** 
  - Min-Heap: O(N log k) time, O(k) space
  - Divide and Conquer: O(N log k) time, O(log k) space
  - Sequential merging: O(kN) time, O(1) space
- **Key Pattern:** K-way merge optimization

### Tree Problems

#### 12. **226 - Invert Binary Tree** (Easy)
- **Status:** 🔄 Ready to implement
- **Approaches:** Recursive DFS, Iterative BFS, Iterative DFS
- **Key Pattern:** Tree traversal and recursion

### Stone Smashing Problems

#### 13. **1046 - Last Stone Weight** (Easy)
- **Status:** ✅ Implemented (Python, Java, C++)
- **Approaches:** Max-Heap (priority queue)
- **Key Pattern:** Repeatedly combine two largest elements
- **C++ Note:** Now uses `class Solution` template as per LeetCode standard
- **Java Note:** Handles empty queue case to avoid `NullPointerException`

---

## 🔑 Key Patterns & Templates

### 1. **Dummy Node Pattern** (Linked Lists)
```
dummy = new Node(0)
dummy.next = head
// Work with dummy to simplify head modifications
return dummy.next
```
**Use when:** Head might change, need unified handling

### 2. **Two Pointers (Fast/Slow)**
```
slow = head
fast = head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
```
**Use when:** Finding middle, detecting cycles

### 3. **Floyd's Cycle Detection**
- Phase 1: Detect cycle (fast/slow meet)
- Phase 2: Find cycle start (reset one pointer to head)

### 4. **Linked List Reversal**
```
prev = null
curr = head
while curr:
    tmp = curr.next
    curr.next = prev
    prev = curr
    curr = tmp
return prev
```

### 5. **Tree Recursion Template**
```
function traverse(node):
    if not node: return base_case
    // Process current node
    left_result = traverse(node.left)
    right_result = traverse(node.right)
    // Combine results
    return combined_result
```

---

## 💡 Language-Specific Best Practices

### Python
- Use `Optional[TreeNode]` for nullable types
- Use `heapq` for min-heap (note: it's a min-heap by default)
- Use `pass` for unimplemented methods
- Helper functions outside class for testing

### Java
- Use `PascalCase` for class names
- Use proper access modifiers (`private` for helpers, `public` for API)
- Use `null` for unimplemented returns
- `PriorityQueue` is min-heap by default
- No manual memory management (GC handles it)
- **Java Solution Structure Convention**
  - Each LeetCode Java solution should use:
    - `Solution` class for the main algorithm/logic (e.g., `public ListNode middleNode(ListNode head)`)
    - A separate class (e.g., `MiddleOfTheLinkedList`) for `main` and test helpers
    - `ListNode` (or similar) as its own class (not public)
  - This structure matches LeetCode conventions and keeps logic/test separation clear.
  - All new Java solutions should follow this pattern.

### C++
- Use `nullptr` (not `NULL` or `0`)
- Use `->` for pointer member access
- Always delete dynamically allocated memory
- `priority_queue` is **max-heap by default** (use custom comparator for min-heap)
- Public members/methods should come before private
- Include destructor for classes with dynamic memory

---

## 🎯 Common Mistakes to Avoid

1. **C++ Priority Queue:** It's a max-heap by default!
2. **Incomplete Types:** Define structs before use in C++
3. **Memory Leaks:** Always delete allocated memory in C++
4. **Off-by-One:** Carefully count nodes in linked list problems
5. **Null Checks:** Always check for null/nullptr before dereferencing
6. **Pointer Cycles:** Be careful when modifying next pointers

---

## 📚 Next Steps

- Continue implementing more problems
- Focus on different categories (Trees, Graphs, DP, etc.)
- Practice pattern recognition
- Optimize solutions after initial implementation

---

## 🧪 Test Output Format Update

All test cases in main functions should print results in the following format:

```
actual | expected
```

For example:
```
1 | 2
1 | 1
[1,2,3] | [1,2,3]
```

This format applies to all languages (Python, Java, C++). Do not update code files automatically—update only when implementing or refactoring test scaffolding.

---

**Last Updated:** December 24, 2025
