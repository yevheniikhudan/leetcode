# 252. Meeting Rooms

- Difficulty: Easy
- Topics: Array, Sorting

## Problem Description
Given an array of meeting time intervals where `intervals[i] = [start_i, end_i]`, determine whether a person can attend all meetings.

A person can attend all meetings only if no two meetings overlap in time.

## Examples

### Example 1
Input: `intervals = [[0,30],[5,10],[15,20]]`

Output: `false`

Explanation: The meeting `[0,30]` overlaps with both `[5,10]` and `[15,20]`.

### Example 2
Input: `intervals = [[7,10],[2,4]]`

Output: `true`

Explanation: These two meetings do not overlap.

### Example 3
Input: `intervals = [[1,2],[2,3],[3,4]]`

Output: `true`

Explanation: Meetings that touch at boundaries (end equals next start) are not overlapping.

## Constraints
- `1 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= start_i < end_i <= 10^6`

## Related Problems
- 253. Meeting Rooms II
- 56. Merge Intervals
- 435. Non-overlapping Intervals
