# Tutorial: House Robber

## Understanding the Problem
Rob houses in a line, can't rob adjacent ones. Maximize money.

## Key Concepts
- **DP State:** Max money up to house i.
- **Transition:** Rob i: nums[i] + dp[i-2], Skip i: dp[i-1]
- **Base:** dp[0] = nums[0], dp[1] = max(nums[0], nums[1])

## Approaches

### 1. Bottom-Up DP
- dp[i] = max(dp[i-1], dp[i-2] + nums[i])
- Answer: dp[n-1]

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

### 2. Optimized DP (Constant Space)
- Track prev2, prev1, update iteratively.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

### 3. Recursion with Memoization
- Recur from 0, choose rob or skip, memoize.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

## Visual Example
nums = [1,2,3,1]

Rob 0 and 2: 1+3=4  
Rob 1 and 3: 2+1=3  
Rob 0 and 3: 1+1=2  
Rob 1: 2  
Rob 2: 3  
Max: 4

## Edge Cases
- n=1: nums[0]
- n=2: max(nums[0], nums[1])
- All zeros: 0

## Common Pitfalls
- Can't rob adjacent, so skip every other.
- Max of rob current + prev prev, or prev.
- Handle small n explicitly.
