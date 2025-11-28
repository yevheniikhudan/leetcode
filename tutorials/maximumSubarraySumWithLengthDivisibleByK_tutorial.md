# 2872 Maximum Subarray Sum With Length Divisible by K - Tutorial

## Problem Understanding

Find the maximum sum of a subarray where the subarray's length is divisible by `k`.

**Key Requirements:**
- The subarray must be contiguous
- The length of the subarray must be divisible by `k` (length % k == 0)
- We want the maximum possible sum

**Key Insight:** 
For a subarray from index `i` to `j` to have length divisible by `k`, we need:
- `(j - i + 1) % k == 0`
- Which means: `(j + 1) % k == (i) % k`
- Or in terms of prefix indices: `j % k == (i - 1) % k`

## Approach: Prefix Sum with Hash Table

### Strategy

Use **prefix sums** combined with **modular arithmetic**:

1. Calculate prefix sums as we iterate through the array
2. For each position, track the **minimum prefix sum** seen so far for each remainder when divided by `k`
3. For position `i` with remainder `r = i % k`, if we've seen a previous position with the same remainder, the subarray between them has length divisible by `k`
4. To maximize the sum, subtract the **minimum** prefix sum with the same remainder

### Why This Works

**Subarray sum from index i to j:**
- `sum[i:j] = prefix[j] - prefix[i-1]`

**For length divisible by k:**
- We need `(j - (i-1)) % k == 0`
- This means `j % k == (i-1) % k`

**To maximize the sum:**
- For each position `j`, we want to find the smallest `prefix[i-1]` where `(i-1) % k == j % k`
- Then `sum = prefix[j] - min_prefix[j % k]`

### Algorithm

```
1. Initialize:
   - min_prefix = {0: 0, 1: INF, 2: INF, ..., k-1: INF}
   - max_sum = -infinity
   - current_prefix = 0

2. For each index i from 0 to n-1:
   a. current_prefix += nums[i]
   b. remainder = (i + 1) % k
   c. max_sum = max(max_sum, current_prefix - min_prefix[remainder])
   d. min_prefix[remainder] = min(min_prefix[remainder], current_prefix)

3. Return max_sum
```

### Example Walkthrough

```
nums = [-5, 1, 2, -3, 4], k = 2

Initial: min_prefix = {0: 0, 1: INF}
         max_sum = -infinity

i=0, nums[0]=-5:
  current_prefix = -5
  remainder = 1 % 2 = 1
  max_sum = max(-inf, -5 - INF) = -inf (skip since INF)
  min_prefix[1] = -5

i=1, nums[1]=1:
  current_prefix = -4
  remainder = 2 % 2 = 0
  max_sum = max(-inf, -4 - 0) = -4
  min_prefix[0] = min(0, -4) = -4

i=2, nums[2]=2:
  current_prefix = -2
  remainder = 3 % 2 = 1
  max_sum = max(-4, -2 - (-5)) = max(-4, 3) = 3
  min_prefix[1] = min(-5, -2) = -5

i=3, nums[3]=-3:
  current_prefix = -5
  remainder = 4 % 2 = 0
  max_sum = max(3, -5 - (-4)) = max(3, -1) = 3
  min_prefix[0] = min(-4, -5) = -5

i=4, nums[4]=4:
  current_prefix = -1
  remainder = 5 % 2 = 1
  max_sum = max(3, -1 - (-5)) = max(3, 4) = 4
  min_prefix[1] = min(-5, -1) = -5

Answer: 4 (subarray [1, 2, -3, 4] with length 4)
```

### Time & Space Complexity

- **Time**: O(n) - Single pass through the array
- **Space**: O(k) - Hash table with k entries for remainders

## Key Insights

1. **Prefix Sum Pattern**: Convert subarray sum problem to prefix sum difference
2. **Modular Arithmetic**: Use `index % k` to track positions with same remainder
3. **Minimize Previous Sum**: To maximize subarray sum, subtract the minimum prefix sum with the same remainder
4. **Initialize Carefully**: `min_prefix[0] = 0` allows subarrays starting from index 0

## Common Mistakes

1. **Wrong Initialization**: Forgetting to initialize `min_prefix[0] = 0`
2. **Off-by-One Error**: Using `i % k` instead of `(i + 1) % k` for the remainder
3. **Not Handling Negatives**: Assuming all sums are positive (problem allows negative numbers)
4. **Missing Edge Cases**: Not considering subarrays of length exactly k

## Edge Cases

1. **k = 1**: All subarrays are valid (divisible by 1), return maximum subarray sum
2. **All negative numbers**: Must still pick a subarray (can't skip all elements)
3. **Array length equals k**: Only one valid subarray (the entire array)
4. **Single element with k = 1**: Return that element

## Variations & Related Problems

- **Kadane's Algorithm**: Maximum subarray sum (no length constraint)
- **Subarray Sums Divisible by K**: Count subarrays with sum divisible by k
- **Maximum Sum Subarray of Size K**: Fixed size k (simpler sliding window)

## Optimization Tips

1. **Use Array Instead of Hash Table**: Since k is bounded, use array of size k
2. **Early Termination**: If k = 1, just use Kadane's algorithm
3. **Avoid Infinity**: Use the first actual value instead of infinity for initialization
