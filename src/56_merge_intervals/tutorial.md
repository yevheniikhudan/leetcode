Understanding the problem

Given a list of intervals (each a pair of start and end times), merge any overlapping intervals into single intervals. The output should be a list of non-overlapping intervals that cover the same total range as the input.

An interval [a, b] overlaps with [c, d] if max(a, c) <= min(b, d). Specifically, they overlap if a <= d and c <= b. Touching intervals (e.g., [1,3] and [3,5]) are considered overlapping since they share the point 3.

The goal is to produce the minimal set of intervals that cover all input intervals without overlaps.

Visual example

Input: [[1,3],[2,6],[8,10],[15,18]]

- [1,3] and [2,6] overlap (2 <= 3), merge to [1,6]
- [8,10] and [15,18] are separate
- Output: [[1,6],[8,10],[15,18]]

Another: [[1,4],[4,5]] -> merge to [1,5] since 4 == 4 (touching/overlapping)

Multiple approaches (from most efficient)

1) Sort and merge (optimal)
- Sort intervals by start time (O(n log n) sort).
- Iterate through sorted list, maintaining current merged interval.
- If next interval overlaps current (next.start <= current.end), extend current.end = max(current.end, next.end).
- Else, add current to result and start new current.
- Time complexity: O(n log n) due to sort, O(n) merge.
- Space complexity: O(n) for sort and result.

2) Interval graph and union-find
- Model intervals as nodes, connect if overlapping.
- Use union-find to group overlapping intervals, then find min start and max end per group.
- Time complexity: O(n^2) in worst case (dense overlaps), better with optimizations but generally slower than sort.
- Space complexity: O(n).

3) Brute-force check all pairs (not recommended)
- For each pair, check overlap and merge repeatedly until no changes.
- Time complexity: O(n^2), inefficient for n=10^4.

Time and space complexity summary

- Optimal sort-and-merge: Time O(n log n), Space O(n).
- Union-find: Time O(n^2) worst-case, Space O(n).

Key concepts and patterns

- Sorting intervals: Common for interval problems to sort by start or end.
- Greedy merging: Extend current interval when overlapping, start new when not.
- Overlap condition: Two intervals [a,b] and [c,d] overlap if a <= d and c <= b.
- Edge cases: Single interval, all disjoint, all overlapping, touching intervals.

Edge cases and pitfalls

- Empty input: Return empty list.
- Single interval: Return as is.
- All intervals disjoint: Return all unchanged.
- All intervals overlap: Merge into one big interval.
- Touching intervals (e.g., [1,3],[3,5]): Must merge since they overlap at endpoint.
- Unsorted input: Must sort first.
- Negative numbers: Constraints allow 0 to 10^4, but logic works for negatives too.
- Large n (10^4): O(n log n) is fine, O(n^2) would TLE.

Optimization notes

- In-place sorting if allowed, but usually not necessary.
- Use lambda for sort in languages that support it.
- Result list can be built incrementally without extra space beyond output.

Common implementation checklist

- Sort intervals by start time.
- Initialize result list and current interval.
- Loop through intervals, merge if overlap, else add to result.
- Add final current interval.
- Return result.
