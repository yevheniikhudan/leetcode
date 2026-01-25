# Decode Ways - Tutorial

## Understanding the Problem

We need to count the number of ways to decode a string of digits into letters using the standard mapping (1=A, 2=B, ..., 26=Z). The string can have leading zeros, and some groupings may be invalid (e.g., "06" is invalid).

Key points:
- Single digit: 1-9 valid, 0 invalid alone
- Two digits: 10-26 valid, others invalid
- Overlapping possibilities (e.g., "12" can be 1+2 or 12)
- If any prefix can't be decoded, the whole string is invalid

## Approach: Dynamic Programming

### Strategy
Use DP where dp[i] represents the number of ways to decode the first i characters.

- dp[0] = 1 (empty string has 1 way: do nothing)
- For each position i from 1 to n:
  - If s[i-1] != '0', dp[i] += dp[i-1] (single digit decode)
  - If i >= 2 and the two-digit s[i-2:i] is valid (10-26), dp[i] += dp[i-2] (two-digit decode)

Return dp[n]. If dp[n] == 0, no valid decodings.

### Time Complexity: O(n)
### Space Complexity: O(n) (can optimize to O(1))

### Visual Example
For "226":
- dp[0] = 1
- i=1, s[0]='2' !=0, dp[1] = dp[0] = 1
- i=2, s[1]='2' !=0, dp[2] += dp[1] = 1; s[0:2]="22" valid, dp[2] += dp[0] = 2
- i=3, s[2]='6' !=0, dp[3] += dp[2] = 2; s[1:3]="26" valid, dp[3] += dp[1] = 3

## Edge Cases

- Single digit: "1" → 1, "0" → 0
- Leading zero: "01" → 0, "10" → 1
- All zeros: "00" → 0
- Invalid two-digit: "27" → 1 (only 2+7)
- Empty string: 1 (but constraints say 1 <= n)

## Common Pitfalls

- Forgetting that '0' can't be decoded alone
- Incorrect two-digit validation (only 10-26)
- Not handling i=1 separately for two-digit checks
- Off-by-one in indexing

## Optimization Notes

- Space can be reduced to O(1) by using two variables for dp[i-1] and dp[i-2]
- The DP approach is efficient and handles all constraints
