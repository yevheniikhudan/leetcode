# Tutorial: Insert Interval (LeetCode 57)

## Understanding the problem
You are given a sorted list of non-overlapping intervals. Insert a new interval into the list and merge any overlapping intervals. The list remains sorted by start time.

## Key Observations
- Because intervals are sorted and non-overlapping, you can find where the new interval fits by comparing starts.
- Overlaps occur when an interval's start is <= newInterval's end and the interval's end is >= newInterval's start.

## Approaches (conceptual)

1. One-pass merging (O(n) time, O(n) space)
- Iterate over intervals:
  - Append all intervals that end before the new interval starts (no overlap).
  - Merge all intervals that overlap with the new interval by expanding new interval's start/end.
  - Append the merged new interval.
  - Append remaining intervals.

2. Binary search to find insertion index (O(log n) + O(n) for merging)
- Use binary search to find the first interval that could overlap with newInterval.
- Then merge forward from that point.

3. Build result using stack-like merging (O(n) time)
- Push intervals into result, merging with the last interval when overlaps occur.

## Time/Space Complexity
- One-pass: O(n) time, O(n) space for result list.
- Binary search + merge: O(n) worst-case time, O(n) space.

## Edge Cases and Pitfalls
- Empty intervals list: return [newInterval].
- New interval entirely before or after all intervals.
- New interval fully contained within an existing interval.
- Adjacent intervals where one ends exactly when the next starts — treat as non-overlapping unless problem states otherwise.

## Optimization Notes
- Use one-pass merging for clarity and optimal time.
- Binary search is useful when you must optimize constant factors for very large n.
