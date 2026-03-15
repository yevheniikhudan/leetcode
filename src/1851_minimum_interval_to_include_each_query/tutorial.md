# Tutorial: Minimum Interval to Include Each Query

## Understanding the Problem
For each query value, you need the size of the smallest interval that contains it.

The direct approach would check every interval for every query, but that would be too slow because both arrays can have up to `10^5` elements.

The key observation is that queries can be processed in sorted order. As queries increase, more intervals become relevant, and some intervals stop being useful.

## Visual Intuition
Suppose:
- Intervals: `[1,4]`, `[2,4]`, `[3,6]`, `[4,4]`
- Queries: `2`, `3`, `4`, `5`

As you move from smaller queries to larger ones:
- Add intervals whose left boundary is now reachable
- Remove intervals whose right boundary is already behind the current query
- Among the remaining intervals, choose the one with the smallest size

This suggests a sweep-line process combined with a min-heap.

## Approach 1 (Most Efficient): Offline Queries with Min-Heap
### Strategy
1. Sort `intervals` by their left endpoint.
2. Sort `queries`, but keep each query's original index.
3. Sweep through the queries from smallest to largest.
4. For each query:
   - Add every interval with `left <= query` into a min-heap
   - Store both interval size and interval right endpoint in the heap
   - Remove heap entries whose `right < query` because they no longer cover the query
5. The top of the heap is the smallest interval that still contains the query.
6. Write that size into the result array at the query's original index.

### Why It Works
When queries are processed in increasing order, intervals only need to be added once.

The heap always holds intervals that have started. After removing intervals that already ended, every remaining interval covers the current query. Since the heap is ordered by interval size, the smallest valid interval is immediately available.

### Complexity
- Time: `O((n + m) log n)`
- Space: `O(n)`

Here, `n` is the number of intervals and `m` is the number of queries.

## Approach 2: Balanced Search Structure by Active Interval Size
### Strategy
Maintain active intervals in a structure that supports insertion, deletion, and retrieving the minimum size while sweeping queries.

### Tradeoff
This has the same high-level idea as the heap solution, but the implementation is usually more complex than necessary for this problem.

## Approach 3: Brute Force Search
### Strategy
For every query, scan all intervals and keep the minimum interval size that contains it.

### Complexity
- Time: `O(n * m)`
- Space: `O(1)` extra

This is too slow for the problem constraints.

## Key Concepts and Patterns
- Offline query processing
- Sorting with original index recovery
- Sweep line
- Min-heap of candidate intervals
- Lazy removal of expired intervals

## Edge Cases
- A query that is not inside any interval should return `-1`
- Multiple intervals may contain the same query; choose the smallest size
- Duplicate queries should each get the correct answer in their original positions
- Single-point intervals like `[4,4]` are valid and may be the best answer

## Common Pitfalls
- Forgetting to preserve original query indices after sorting
- Using interval length incorrectly instead of `right - left + 1`
- Not removing intervals whose right endpoint is smaller than the current query
- Returning answers in sorted-query order instead of original order

## Optimization Notes
The offline heap approach is the standard solution because it scales to the full constraints and keeps the logic focused: add intervals as they become available, discard expired ones, and read the smallest valid interval from the heap.