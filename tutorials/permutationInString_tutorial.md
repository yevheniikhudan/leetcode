# Permutation in String - Tutorial

## Problem Understanding

Given two strings `s1` and `s2`, determine if `s2` contains any permutation of `s1` as a substring.

**Key Insight:** A permutation has the **same character frequencies** as the original string, just in a different order.

**Examples:**
- `s1 = "ab"` has permutations: `"ab"`, `"ba"`
- If `s2 = "eidbaooo"`, it contains `"ba"` → return `true`
- If `s2 = "eidboaoo"`, it doesn't contain any permutation → return `false`

## Strategy: Sliding Window with Character Frequency

### Core Idea

Two strings are permutations of each other if and only if they have **identical character frequency counts**.

Instead of generating all permutations of `s1` (which would be `n!` permutations), we:
1. Count the frequency of characters in `s1`
2. Use a sliding window of size `len(s1)` on `s2`
3. Check if the window has the same character frequencies as `s1`

### Algorithm Steps

**Method 1: Fixed-size Sliding Window**

1. **Build frequency map for `s1`:**
   ```
   s1_count = frequency_map(s1)
   ```

2. **Initialize sliding window on `s2`:**
   - Window size = `len(s1)`
   - Build frequency map for first window

3. **Slide the window:**
   - Compare current window frequencies with `s1_count`
   - If match → return `true`
   - Slide window: remove leftmost char, add new rightmost char
   - Update frequency map incrementally

4. **Return `false`** if no match found

### Example Walkthrough

```
s1 = "ab", s2 = "eidbaooo"
s1_count = {a:1, b:1}
window_size = 2

Window at indices [0,1]: "ei"
  count = {e:1, i:1} ≠ s1_count

Window at indices [1,2]: "id"
  count = {i:1, d:1} ≠ s1_count

Window at indices [2,3]: "db"
  count = {d:1, b:1} ≠ s1_count

Window at indices [3,4]: "ba"
  count = {b:1, a:1} = s1_count ✅
  Return true!
```

### Optimization: Single Pass with Match Counter

Instead of comparing entire frequency maps each time, track **how many characters match**.

**Enhanced Algorithm:**

1. Build frequency maps for `s1` and first window of `s2`
2. Initialize `matches = 0` (count of characters with matching frequencies)
3. For initial window, count how many characters have matching frequencies
4. Slide window:
   - Update frequency for outgoing character (left), check if match status changes
   - Update frequency for incoming character (right), check if match status changes
5. If `matches == 26` (all lowercase letters match) → return `true`

**Why 26?** We track all 26 lowercase letters. If all have the same frequency (including 0), it's a permutation.

### Detailed Algorithm (Optimized)

```
Initialize:
  s1_count = [0] * 26
  s2_count = [0] * 26
  
  # Count s1 frequencies
  for c in s1:
    s1_count[c - 'a']++
  
  # Build first window
  for i in range(len(s1)):
    s2_count[s2[i] - 'a']++
  
  # Count initial matches
  matches = 0
  for i in range(26):
    if s1_count[i] == s2_count[i]:
      matches++
  
  # Check first window
  if matches == 26:
    return true
  
  # Slide window
  for right in range(len(s1), len(s2)):
    # Add right character
    index = s2[right] - 'a'
    s2_count[index]++
    if s2_count[index] == s1_count[index]:
      matches++
    elif s2_count[index] == s1_count[index] + 1:
      matches--
    
    # Remove left character
    left = right - len(s1)
    index = s2[left] - 'a'
    s2_count[index]--
    if s2_count[index] == s1_count[index]:
      matches++
    elif s2_count[index] == s1_count[index] - 1:
      matches--
    
    if matches == 26:
      return true
  
  return false
```

### Why Track Matches?

**Without optimization:**
- Compare all 26 frequencies each window → O(26) per window
- Total: O(n × 26) = O(n)

**With match counter:**
- Only update affected characters → O(1) per window update
- Total: O(n)

Both are O(n), but the optimized version has a better constant factor.

## Algorithm Complexity

**Time Complexity:** O(n + m)
- O(m) to build `s1` frequency map (m = length of s1)
- O(n) to slide window through `s2` (n = length of s2)
- Each window update is O(1) with match counter

**Space Complexity:** O(1)
- Two arrays of size 26 (constant space)
- Or two hash maps with at most 26 entries

## Alternative Approaches

### Method 1: Sorting (Simpler but Slower)
```
For each substring of s2 with length len(s1):
  If sorted(substring) == sorted(s1):
    return true
```
**Time:** O(n × m log m) - Too slow for large inputs

### Method 2: Hash Map Comparison
```
Build frequency map for s1
For each window in s2:
  Build frequency map for window
  If maps are equal:
    return true
```
**Time:** O(n × m) or O(n × 26) - Workable but not optimal

### Method 3: Sliding Window with Match Counter (Optimal)
- Described above
- **Best approach** for this problem

## Key Edge Cases

1. **s1 longer than s2:** Impossible to have permutation → return `false`
2. **s1 and s2 same length:** Only one window to check
3. **s1 length = 1:** Check if character exists in s2
4. **All same characters:** e.g., s1="aa", s2="aaa" → true
5. **No overlap:** s1="ab", s2="cde" → false

## Common Mistakes to Avoid

1. **Forgetting to handle window initialization:** First window needs special handling
2. **Off-by-one errors:** Window indices can be tricky
3. **Not updating match counter correctly:** Need to handle both increase and decrease
4. **Comparing hash maps inefficiently:** Use match counter optimization
5. **Edge case when s1 > s2:** Should return false immediately

## Summary

**Best Solution:** Fixed-size sliding window with character frequency matching
- Use arrays of size 26 for lowercase letters
- Track number of matching frequencies (optimization)
- Slide window one character at a time
- O(n) time, O(1) space
