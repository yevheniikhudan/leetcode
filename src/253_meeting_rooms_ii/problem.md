# 253. Meeting Rooms II

- Difficulty: Medium
- Topics: Array, Sorting, Heap (Priority Queue), Two Pointers

## Problem Description
Given an array of meeting intervals where `intervals[i] = [start_i, end_i]`, return the minimum number of conference rooms required so that all meetings can be held.

If one meeting ends at time `t` and another starts at time `t`, the same room can be reused.

## Examples

### Example 1
Input: `intervals = [[0,30],[5,10],[15,20]]`

Output: `2`

Explanation: One room handles `[0,30]`, and another handles `[5,10]` then `[15,20]`.

### Example 2
Input: `intervals = [[7,10],[2,4]]`

Output: `1`

Explanation: Meetings do not overlap, so one room is enough.

### Example 3
Input: `intervals = [[1,5],[2,3],[3,6]]`

Output: `2`

Explanation: During time `2..3`, two meetings are active at once.

## Constraints
- `1 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= start_i < end_i <= 10^6`

## Related Problems
- 252. Meeting Rooms
- 56. Merge Intervals
- 435. Non-overlapping Intervals
