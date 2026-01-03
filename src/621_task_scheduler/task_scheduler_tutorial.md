# Task Scheduler - Tutorial

## Understanding the Problem
You are given a list of tasks (characters) and a cooldown period `n`. You must schedule the tasks so that the same task is separated by at least `n` units of time. The goal is to minimize the total time (including idle slots).

## Visual Example
Example: tasks = [A, A, A, B, B, B], n = 2
- Schedule: A B idle A B idle A B
- Total time: 8

## Approaches
### 1. Greedy (Count & Math)
- Count the frequency of each task.
- The most frequent task determines the minimum schedule length.
- Formula: `(max_count - 1) * (n + 1) + num_max_count_tasks`
- Take the maximum of this value and the total number of tasks.

### 2. Simulation (Heap)
- Use a max-heap to always pick the most frequent available task.
- Use a queue to track cooldowns.
- Simulate each time unit, scheduling tasks or idling as needed.

## Time/Space Complexity
- Greedy: O(N) time, O(1) space (since only 26 task types)
- Heap: O(N log N) time, O(N) space

## Key Concepts
- Task frequency
- Idle slots
- Greedy scheduling

## Edge Cases
- n = 0 (no cooldown)
- All tasks are unique
- Multiple tasks with max frequency

## Optimization Notes
- Greedy formula is optimal for this problem
- Heap simulation is useful for interview demonstration

*No code in this tutorial section.*
