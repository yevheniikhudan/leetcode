# 1851. Minimum Interval to Include Each Query

- Difficulty: Hard
- Topics: Array, Binary Search, Sweep Line, Sorting, Heap (Priority Queue)

## Problem Description
You are given a 2D integer array `intervals`, where `intervals[i] = [left_i, right_i]` describes the `i`th interval starting at `left_i` and ending at `right_i` inclusive.

The size of an interval is the number of integers it contains, which is `right_i - left_i + 1`.

You are also given an integer array `queries`. The answer to the `j`th query is the size of the smallest interval `i` such that `left_i <= queries[j] <= right_i`.

If no interval contains the query, the answer is `-1`.

Return an array containing the answers to the queries.

## Examples

### Example 1
Input: `intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]`

Output: `[3,3,1,4]`

Explanation:
- Query `2` is covered by `[2,4]`, whose size is `3`
- Query `3` is covered by `[2,4]`, whose size is `3`
- Query `4` is covered by `[4,4]`, whose size is `1`
- Query `5` is covered by `[3,6]`, whose size is `4`

### Example 2
Input: `intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]`

Output: `[2,-1,4,6]`

Explanation:
- Query `2` is covered by `[2,3]`, whose size is `2`
- Query `19` is not covered by any interval
- Query `5` is covered by `[2,5]`, whose size is `4`
- Query `22` is covered by `[20,25]`, whose size is `6`

## Constraints
- `1 <= intervals.length <= 10^5`
- `1 <= queries.length <= 10^5`
- `intervals[i].length == 2`
- `1 <= left_i <= right_i <= 10^7`
- `1 <= queries[j] <= 10^7`

## Related Problems
- 57. Insert Interval
- 253. Meeting Rooms II
- 2251. Number of Flowers in Full Bloom