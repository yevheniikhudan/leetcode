# Tutorial: Meeting Rooms II

## Understanding the Problem
You need the minimum number of rooms required so that no overlapping meetings are assigned to the same room.

This is equivalent to finding the maximum number of meetings happening at the same time.

## Visual Intuition
Intervals:
- `[0, 30]`
- `[5, 10]`
- `[15, 20]`

Timeline intuition:
- At time `5..10`, `[0,30]` and `[5,10]` overlap → at least 2 rooms.
- After `10`, one room frees, so `[15,20]` can reuse it.
- Maximum simultaneous meetings is 2.

## Approach 1 (Most Efficient in Practice): Min-Heap by End Time
### Strategy
1. Sort meetings by start time.
2. Maintain a min-heap of current room end times.
3. For each meeting:
   - If the smallest end time `<= current_start`, reuse that room (pop once).
   - Push current end time into heap.
4. Heap size tracks active rooms; maximum size is the answer.

### Why It Works
The earliest room to become free is always the best candidate for reuse. A min-heap gives that room in `O(log n)` updates.

### Complexity
- Time: `O(n log n)`
- Space: `O(n)`

## Approach 2: Sweep Line with Separate Start/End Arrays
### Strategy
1. Extract all starts and all ends.
2. Sort both arrays.
3. Use two pointers:
   - If `starts[i] < ends[j]`, a new meeting starts before the earliest end, so rooms in use increase.
   - Else, one meeting ended, so move end pointer and reuse room.
4. Track the maximum rooms in use.

### Complexity
- Time: `O(n log n)`
- Space: `O(n)`

## Approach 3: Brute Force Timeline Mapping (Conceptual)
### Strategy
Model each time point and count active meetings.

### Complexity
Potentially large and inefficient when time values are big, so this is usually not practical for constraints.

## Key Concepts and Patterns
- Interval overlap counting
- Resource allocation under overlap
- Greedy reuse of earliest-finished resource
- Priority queue / sweep line patterns

## Edge Cases
- Single meeting → answer is `1`
- Fully non-overlapping meetings → answer is `1`
- All meetings overlap at some point → answer equals number of meetings
- Boundary touching (`end == next_start`) should reuse room

## Common Pitfalls
- Treating `end == start` as overlap (it is not)
- Forgetting to sort meetings before heap processing
- Confusing “count overlaps” with “max simultaneous meetings”

## Optimization Notes
For interview and production-style readability, heap and two-array sweep are both strong `O(n log n)` choices. The sweep-line variant can be slightly simpler to reason about for this exact count-only problem.
