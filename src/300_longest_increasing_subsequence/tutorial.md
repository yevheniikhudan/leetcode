# Tutorial: Longest Increasing Subsequence

## Understanding the Problem
The Longest Increasing Subsequence (LIS) problem asks to find the length of the longest subsequence in an array that is strictly increasing. A subsequence is derived from the array by deleting some or no elements without changing the order of the remaining elements. It's not necessarily contiguous.

This is a classic DP problem with an O(n log n) optimization using binary search.

## Visual Examples
- **Example 1:** nums = [10,9,2,5,3,7,101,18]
  - Possible LIS: [2,3,7,101] (length 4), [2,5,7,101] (length 4), etc.
  - Not [10,9] (decreasing).

- **Example 2:** nums = [0,1,0,3,2,3]
  - LIS: [0,1,2,3] or [0,1,3] (length 4)

- **Example 3:** nums = [7,7,7,7,7,7,7]
  - LIS: [7] (length 1), since all equal, not strictly increasing.

## Multiple Approaches

### 1. Dynamic Programming (O(n^2)) - Straightforward
Use a DP array where dp[i] is the LIS ending at index i.
- For each i, check all j < i, if nums[j] < nums[i], dp[i] = max(dp[i], dp[j] + 1)
- Track global max.
- Time: O(n^2), Space: O(n)

### 2. Patience Sorting (O(n log n)) - Optimal
Maintain a list of the smallest tail for each length.
- Use binary search to find insertion point in the list.
- Replace or append to keep the list increasing.
- Time: O(n log n), Space: O(n)

### 3. Brute Force (Exponential)
Generate all subsequences and check increasing ones.
- Time: O(2^n), Space: O(n) - too slow for n=2500

## Time/Space Complexity Analysis
- **DP:** O(n^2) time, O(n) space - good for small n
- **Patience Sorting:** O(n log n) time, O(n) space - best for large n
- Patience sorting is preferred for interviews due to efficiency

## Key Concepts and Patterns
- **Subsequence vs Subarray:** Subsequence doesn't need to be contiguous
- **Strictly Increasing:** nums[i] < nums[j] for i < j in subsequence
- **DP State:** LIS ending at each position
- **Binary Search Optimization:** Maintain active lists for tails
- **Greedy Choice:** Always try to extend with smallest possible tail

## Edge Cases and Common Pitfalls
- **All Equal:** LIS = 1
- **Strictly Increasing:** LIS = n
- **Strictly Decreasing:** LIS = 1
- **Single Element:** LIS = 1
- **Empty Array:** Not possible per constraints
- **Duplicates:** Can't use equal elements in strictly increasing
- **Pitfall:** Confusing with longest increasing subarray (contiguous)

## Optimization Notes
- For O(n log n), use patience sorting with binary search
- DP is simpler to understand but slower
- In code, use bisect in Python for binary search
- For very large n, O(n log n) is necessary
