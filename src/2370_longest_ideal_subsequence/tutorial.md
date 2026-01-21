# Tutorial: Longest Ideal Subsequence

This problem is solved using dynamic programming with a frequency array.

**Approach:**
- Use a DP array of size 26, where `dp[c]` is the length of the longest ideal subsequence ending with character `chr(c + ord('a'))`.
- For each character in `s`, check all characters within distance `k` and take the maximum previous length.
- Update `dp` for the current character by adding 1 to the best previous length.
- Return the maximum value in `dp`.

*No code is provided in this tutorial, only the algorithmic idea.*
