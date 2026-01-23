# Tutorial: Minimum Pair Removal to Sort Array I

This problem is related to finding the minimum number of removals to make the array non-decreasing. The optimal solution is to find the length of the Longest Non-Decreasing Subsequence (LNDS), and the answer is `n - LNDS`.

**Approach:**
- Use dynamic programming to find the length of the LNDS.
- The minimum number of pairs to remove is `n - LNDS`.

*No code is provided in this tutorial, only the algorithmic idea.*
