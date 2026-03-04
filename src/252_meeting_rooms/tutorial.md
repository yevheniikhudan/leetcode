# Tutorial: Meeting Rooms

## Understanding the Problem
You are given multiple time intervals, where each interval represents a meeting start and end time. The goal is to check whether one person can attend every meeting.

This is possible only when no pair of meetings overlaps.

A key detail: if one meeting ends exactly when another starts, this is valid and not considered overlap.

## Visual Intuition
Consider these meetings:
- `[0, 30]`
- `[5, 10]`
- `[15, 20]`

Timeline view:
- The long meeting `[0,30]` covers the time range where the other two also occur.
- Since time ranges intersect, overlap exists.
- Result is `false`.

Now consider:
- `[2, 4]`
- `[7, 10]`

These ranges are separated on the timeline, so no overlap exists.

## Approach 1 (Most Efficient): Sort by Start Time + Adjacent Check
### Strategy
1. Sort intervals by start time.
2. Walk through sorted intervals once.
3. Compare each current start with previous end:
   - If `current_start < previous_end`, overlap exists.
   - Otherwise continue.

### Why It Works
After sorting by start time, any overlap must happen between neighboring intervals in that order. If every adjacent pair is non-overlapping, the whole schedule is valid.

### Complexity
- Time: `O(n log n)` due to sorting
- Space: `O(1)` extra space (ignoring sort implementation details)

## Approach 2: Separate Starts and Ends (Two-Array Sweep)
### Strategy
1. Put all start times into one array, end times into another.
2. Sort both arrays.
3. Scan with pointers to detect whether a next meeting starts before the earliest currently ending meeting.

### Notes
This pattern is very useful for room-counting variants and timeline collision analysis.

### Complexity
- Time: `O(n log n)`
- Space: `O(n)`

## Approach 3: Brute Force Pair Comparison
### Strategy
Check every pair of meetings for intersection.

### Complexity
- Time: `O(n^2)`
- Space: `O(1)`

This is simple but inefficient for large input sizes.

## Key Patterns and Concepts
- Interval overlap detection
- Sorting to reduce pairwise checks
- Greedy local validation (adjacent comparisons after sorting)

## Edge Cases
- Single meeting: always `true`
- Meetings that only touch (`end == next_start`): still `true`
- Already sorted input: still use same logic safely
- Very large list of meetings: prefer sorting approach over brute force

## Common Pitfalls
- Using `<=` instead of `<` for overlap check, which incorrectly treats boundary-touching meetings as overlapping
- Forgetting to sort first before adjacent comparisons
- Mutating test input unexpectedly across repeated tests

## Optimization Notes
For this decision problem (yes/no overlap), sorting + one pass is typically the cleanest and fastest practical approach.
