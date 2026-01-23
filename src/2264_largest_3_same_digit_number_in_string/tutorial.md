# Tutorial: Largest 3-Same-Digit Number in String

## Understanding the Problem
We need to find the largest substring of exactly 3 identical digits in the given string `num`. If multiple exist, return the one with the highest digit value. If none, return empty string.

## Key Concepts
- **Substring Search:** Check every 3-consecutive characters.
- **Digit Comparison:** Since digits are '0'-'9', higher digit means larger number.
- **Efficiency:** With N<=1000, O(N) is fine.

## Approaches

### 1. Brute Force Check (Optimal)
- Iterate from i=0 to i<N-2.
- For each i, check if num[i]==num[i+1]==num[i+2].
- Track the maximum such substring (lexicographically largest).
- Return the max or "".

**Time Complexity:** O(N)  
**Space Complexity:** O(1)

### 2. Predefined Check (From Hints)
- Check for "999", "888", ..., "000" in order.
- Return the first found.

**Time Complexity:** O(N * 10) = O(N)  
**Space Complexity:** O(1)

## Visual Example
For "6777133339":
- Positions: 677, 777, 771, 713, 133, 333, 333, 339
- Good: "777", "333"
- Max: "777"

## Edge Cases
- No good substring: Return ""
- Multiple same: Return the largest digit one.
- Leading zeros: "000" is valid.
- All same digits: Return the 3-char substring.

## Common Pitfalls
- Forgetting length 3 exactly.
- Not handling no match.
- Comparing strings vs digits.

## Optimization Notes
- Brute force is simplest and efficient.
- No need for advanced data structures.
