# Is Subsequence - Tutorial

## Understanding the Problem

A subsequence is formed by **deleting some characters** from a string **without changing the order** of remaining characters.

For example:
- "abc" is a subsequence of "ahbgdc" because we can trace a path: **a**h**b**g**c**
- "axc" is NOT a subsequence of "ahbgdc" because there's no 'x' after the 'a'

The key insight: we need to check if we can **match all characters** of `s` in `t` **in order**.

## Visual Example

```
s = "abc"
t = "ahbgdc"

Match process:
Position: 0 1 2 3 4 5
String:   a h b g d c
Match:    ✓   ✓     ✓  (Found 'a' at 0, 'b' at 2, 'c' at 5)

Result: true
```

## Approach 1: Two Pointers (Optimal)

**Idea:** Use two pointers, one for `s` and one for `t`. 
- Move through `t` and whenever we find a character matching current position in `s`, advance `s` pointer
- If we reach the end of `s`, it's a subsequence

**Why it's optimal:**
- Single pass through `t`
- Time: O(n) where n = length of `t`
- Space: O(1)

## Approach 2: Dynamic Programming

**Idea:** Create a DP table where `dp[i][j]` represents whether `s[0...i-1]` is a subsequence of `t[0...j-1]`

**Recurrence:**
```
dp[0][j] = true (empty string is subsequence of any string)
dp[i][0] = false (non-empty string can't be subsequence of empty string)
dp[i][j] = dp[i-1][j-1] if s[i-1] == t[j-1]
         = dp[i][j-1] if s[i-1] != t[j-1]
```

**Time:** O(m × n) where m = len(s), n = len(t)
**Space:** O(m × n)

## Approach 3: Built-in Methods (Not Recommended for Interview)

Some languages have built-in subsequence checking, but demonstrating algorithmic thinking is preferred.

## Complexity Analysis

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Two Pointers | O(n) | O(1) | Optimal, single pass |
| DP | O(m×n) | O(m×n) | More space, but easier to extend |

## Key Concepts

1. **Two Pointers Technique:** Efficiently track progress in both strings simultaneously
2. **Greedy Approach:** Always take the first matching character (works because order is preserved)
3. **Dynamic Programming:** Build up solutions for subproblems

## Edge Cases

1. `s` is empty → always `true`
2. `t` is empty but `s` is not → always `false`
3. `s` and `t` are identical → `true`
4. `s` is longer than `t` → always `false`
5. Single character matching

## Common Pitfalls

- Confusing subsequence with substring (subsequence doesn't need to be consecutive)
- Not handling empty strings correctly
- Overcomplicating with DP when two pointers suffice
