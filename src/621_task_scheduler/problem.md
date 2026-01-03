# 621. Task Scheduler

**Difficulty:** Medium

## Topics
- Array
- Hash Table
- Greedy
- Sorting
- Heap (Priority Queue)

## Problem Description
Given a characters array `tasks`, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU can complete either one task or be idle.

However, there is a non-negative integer `n` that represents the cooldown period between two same tasks (the same task must be separated by at least `n` units of time).

Return the least number of units of times that the CPU will take to finish all the given tasks.

### Example 1:
```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B
```

### Example 2:
```
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: A -> A -> A -> B -> B -> B
```

### Example 3:
```
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
```

## Constraints
- 1 <= tasks.length <= 10^4
- tasks[i] is an uppercase English letter.
- 0 <= n <= 100

## Related Problems
- 358. Rearrange String k Distance Apart
- 767. Reorganize String
