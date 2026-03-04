## Understanding the Problem

The goal is to remove the minimum number of intervals such that the remaining intervals are non-overlapping. Two intervals `[a, b]` and `[c, d]` are overlapping if `a < d` and `c < b`.

### Key Idea

To minimize the number of intervals removed, we can use a greedy strategy:
- Always keep the interval with the smallest end time that does not overlap with the previous interval.
- Remove all other intervals that overlap with the current interval.

This works because keeping the interval with the smallest end time leaves the most room for subsequent intervals.

### Visual Example

Input: `[[1,2],[2,3],[3,4],[1,3]]`

1. Sort intervals by end time: `[[1,2],[2,3],[1,3],[3,4]]`
2. Start with the first interval `[1,2]`.
3. Keep `[2,3]` because it does not overlap with `[1,2]`.
4. Skip `[1,3]` because it overlaps with `[2,3]`.
5. Keep `[3,4]` because it does not overlap with `[2,3]`.
6. Removed intervals: 1 (`[1,3]`).

Output: `1`.

### Multiple Approaches

#### 1. Greedy with Sorting (Optimal)
- **Steps**:
  1. Sort intervals by their end times.
  2. Iterate through the intervals, keeping track of the end time of the last non-overlapping interval.
  3. If the current interval starts before the last end time, remove it.
- **Time Complexity**: O(n log n) (due to sorting).
- **Space Complexity**: O(1) (in-place sorting).

#### 2. Dynamic Programming (Suboptimal)
- **Steps**:
  1. Sort intervals by start time.
  2. Use DP to find the maximum number of non-overlapping intervals.
  3. Subtract this number from the total number of intervals to get the result.
- **Time Complexity**: O(n^2).
- **Space Complexity**: O(n).

#### 3. Brute Force (Inefficient)
- **Steps**:
  1. Generate all subsets of intervals.
  2. Check which subsets are non-overlapping.
  3. Find the subset with the maximum size.
- **Time Complexity**: O(2^n).
- **Space Complexity**: O(n).

### Edge Cases

1. Single interval: No intervals to remove.
2. All intervals are disjoint: No intervals to remove.
3. All intervals overlap: Remove all but one interval.
4. Intervals with the same start or end time: Handle ties correctly during sorting.

### Optimization Notes

- Sorting by end time ensures that we always consider the interval that leaves the most room for subsequent intervals.
- Avoid unnecessary comparisons by skipping intervals that are guaranteed to overlap.

### Common Pitfalls

1. Forgetting to sort intervals by end time.
2. Removing intervals unnecessarily due to incorrect overlap checks.
3. Not handling edge cases like empty input or intervals with the same start/end time.

### Complexity Summary

- **Greedy**: O(n log n) time, O(1) space.
- **DP**: O(n^2) time, O(n) space.
- **Brute Force**: O(2^n) time, O(n) space.

### Further Reading

- [Greedy Algorithms](https://en.wikipedia.org/wiki/Greedy_algorithm)
- Related Problems:
  - 56 Merge Intervals
  - 57 Insert Interval
  - 452 Minimum Number of Arrows to Burst Balloons
