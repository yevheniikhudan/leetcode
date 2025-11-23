# Greatest Sum Divisible by Three - Tutorial

## Key Insights
- Use dynamic programming to track maximum sums for each remainder (0, 1, 2) when divided by 3
- For each number, we can either include it or skip it
- Track the best sum for each possible remainder modulo 3

## Approach: Dynamic Programming

### State Definition
`dp[i]` = maximum sum with remainder `i` when divided by 3
- `dp[0]` = max sum divisible by 3
- `dp[1]` = max sum with remainder 1
- `dp[2]` = max sum with remainder 2

### Transition
For each number `num` with remainder `r = num % 3`:
- If we add `num` to a sum with remainder `i`, new remainder is `(i + r) % 3`
- Update `dp[(i + r) % 3]` with `dp[i] + num` if it's larger

### Steps
1. Initialize `dp = [0, -infinity, -infinity]` (only remainder 0 is valid initially)
2. For each number in nums:
   - Calculate `r = num % 3`
   - Create temporary array to avoid updating same iteration
   - For each remainder i in [0, 1, 2]:
     - Update `temp[(i + r) % 3] = max(temp[(i + r) % 3], dp[i] + num)`
   - Copy temp back to dp
3. Return `dp[0]`

## Example
For nums = [3,6,5,1,8]:
- Initial: dp = [0, -inf, -inf]
- After 3: dp = [3, -inf, -inf] (3 % 3 = 0)
- After 6: dp = [9, -inf, -inf] (6 % 3 = 0)
- After 5: dp = [9, -inf, 14] (5 % 3 = 2)
- After 1: dp = [9, 10, 15] (1 % 3 = 1)
- After 8: dp = [18, 17, 15] (8 % 3 = 2)
- Result: dp[0] = 18

## Implementation
- Time complexity: O(n)
- Space complexity: O(1) - only 3 states

## Alternative: Greedy Approach
1. Sum all numbers
2. If sum % 3 == 0, return sum
3. If sum % 3 == 1, remove smallest element with remainder 1, or two smallest with remainder 2
4. If sum % 3 == 2, remove smallest element with remainder 2, or two smallest with remainder 1

## Edge Cases
- No valid subset: return 0
- All numbers divisible by 3: return sum of all
- Single element not divisible by 3: return 0
