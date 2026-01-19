# Tutorial: Largest Divisible Subset

This problem is a variation of the Longest Increasing Subsequence (LIS) problem, but with a divisibility condition.

**Approach:**
- Sort the input array.
- Use dynamic programming: for each number, find the largest subset ending at that number where all previous numbers divide it.
- Track the previous index for reconstruction.
- At the end, reconstruct the subset from the DP table.

*No code is provided in this tutorial, only the algorithmic idea.*
