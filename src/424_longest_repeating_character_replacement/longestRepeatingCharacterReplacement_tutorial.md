# Longest Repeating Character Replacement - Tutorial

## Problem Understanding

Given a string of uppercase letters and an integer `k` (number of allowed replacements), find the longest substring where all characters can be made the same by replacing at most `k` characters.

**Key Insights:**
- We can replace any character with any other character
- We want to maximize the window where we can make all characters the same
- We have at most `k` replacements available

**Example:**
```
s = "AABABBA", k = 1

We can replace the 'A' in the middle:
AABABBA → AABBBBA
Substring "BBBB" has length 4
```

## Strategy: Sliding Window

### Core Idea

For a window `[left, right]` to be valid:
- We pick the **most frequent character** in the window
- Replace all other characters with this most frequent one
- Number of replacements needed = `window_size - max_frequency`
- This must be ≤ `k`

**Formula:**
```
window_size - max_frequency ≤ k
(right - left + 1) - max_frequency ≤ k
```

If this condition is violated, shrink the window from the left.

### Algorithm Steps

1. **Initialize:**
   - `left = 0` (left pointer)
   - `max_freq = 0` (max frequency of any character in current window)
   - `count = {}` (frequency map of characters)
   - `max_len = 0` (result)

2. **Expand window (move right pointer):**
   - Add `s[right]` to window
   - Update its frequency in `count`
   - Update `max_freq` if this character has highest frequency

3. **Shrink window if needed:**
   - While `(right - left + 1) - max_freq > k`:
     - Remove `s[left]` from window
     - Decrease its frequency
     - Move `left++`

4. **Update result:**
   - `max_len = max(max_len, right - left + 1)`

5. **Repeat** until `right` reaches end

### Example Walkthrough

```
s = "AABABBA", k = 1

left=0, right=0: "A"
  count = {A:1}, max_freq=1, window=1, replacements=0
  max_len = 1

left=0, right=1: "AA"
  count = {A:2}, max_freq=2, window=2, replacements=0
  max_len = 2

left=0, right=2: "AAB"
  count = {A:2, B:1}, max_freq=2, window=3, replacements=1 ✅
  max_len = 3

left=0, right=3: "AABA"
  count = {A:3, B:1}, max_freq=3, window=4, replacements=1 ✅
  max_len = 4

left=0, right=4: "AABAB"
  count = {A:3, B:2}, max_freq=3, window=5, replacements=2 ❌
  Shrink: left=1, count = {A:2, B:2}
  window=4, replacements=2 ❌
  Shrink: left=2, count = {A:1, B:2}
  window=3, replacements=1 ✅

left=2, right=5: "BABB"
  count = {A:1, B:3}, max_freq=3, window=4, replacements=1 ✅
  max_len = 4

left=2, right=6: "BABBA"
  count = {A:2, B:3}, max_freq=3, window=5, replacements=2 ❌
  Shrink: left=3, count = {A:2, B:2}
  window=4, replacements=2 ❌
  Shrink: left=4, count = {A:1, B:2}
  window=3, replacements=1 ✅

Result: max_len = 4
```

### Why We Don't Need to Update max_freq When Shrinking

**Optimization:** We can skip updating `max_freq` when the window shrinks!

**Why?** Because we only care about finding a **longer** window than what we've seen. If the current `max_freq` isn't the true max anymore, it means we're looking at a smaller or equal-sized window, which won't improve our answer.

**Simplified condition:**
```python
# Instead of checking: (right - left + 1) - max_freq > k
# We can check: (right - left + 1) > max_freq + k

if (right - left + 1) > max_freq + k:
    count[s[left]] -= 1
    left += 1
```

This way, we never shrink `max_freq`, and the window only grows or slides.

## Algorithm Complexity

**Time Complexity:** O(n)
- Single pass through the string
- Each character is visited at most twice (once by right, once by left)

**Space Complexity:** O(1) or O(26)
- Hash map stores at most 26 uppercase letters
- Constant space

## Key Edge Cases

1. **k = 0:** Can only find longest substring of same characters
2. **k ≥ length:** Can replace entire string → return `len(s)`
3. **All same characters:** Return `len(s)`
4. **Single character:** Return `1`
5. **Alternating characters:** e.g., "ABABAB" with k=2 → 5

## Common Mistakes to Avoid

1. **Forgetting to track max frequency:** Need to know the most frequent character
2. **Recalculating max_freq from scratch:** Use the optimization mentioned above
3. **Off-by-one errors:** Window size is `right - left + 1`, not `right - left`
4. **Not handling k=0:** Special case where no replacements allowed
5. **Shrinking too aggressively:** Only shrink when window becomes invalid

## Alternative Approaches

### Brute Force (TLE)
- Try all possible substrings: O(n²)
- For each substring, count replacements needed: O(n)
- Total: O(n³) - Too slow for n = 10⁵

### Binary Search + Sliding Window
- Binary search on answer length
- For each length, check if valid window exists
- More complex, same time complexity

The **standard sliding window** approach is optimal and most intuitive for this problem.
