# Copilot Instructions

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


## Coding Standards

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
