# Minimum Window Substring - Tutorial

## Problem Understanding

Given a string `s` and a pattern string `t`, find the **smallest substring** in `s` that contains **all characters** from `t` (including duplicates).

**Key Requirements:**
- Must include **all characters** from `t`
- Must include **duplicates** (if `t = "AA"`, need at least 2 A's)
- Want the **minimum length** substring
- If no such substring exists, return `""`

**Example:**
```
s = "ADOBECODEBANC"
t = "ABC"

Possible windows that contain A, B, C:
- "ADOBEC" (length 6)
- "ADOBECODE" (length 9)
- "ADOBECODEBA" (length 11)
- "ODEBANC" (length 7)
- "BANC" (length 4) ← Minimum!

Output: "BANC"
```

## Strategy: Variable-Length Sliding Window

This is a **hard** problem because the window size is **variable** (unlike Permutation in String where it was fixed).

### Core Algorithm: Expand and Contract

1. **Expand** the window (move right pointer) until we have all characters from `t`
2. **Contract** the window (move left pointer) while we still have all characters
3. Track the minimum window found
4. Repeat until we've processed the entire string

### Two Key Components

**1. Frequency Maps:**
- `t_count`: Character frequencies needed from `t`
- `window_count`: Character frequencies in current window

**2. Match Tracking:**
- Track how many **unique characters** have the required frequency
- When `matched == required_chars`, we have a valid window

## Detailed Algorithm

### Step-by-Step Process

```
1. Build frequency map for t
   Example: t = "ABC" → {A:1, B:1, C:1}

2. Initialize:
   - left = 0, right = 0
   - window_count = {}
   - matched = 0 (how many chars meet the requirement)
   - required = len(t_count) (how many unique chars we need)
   - min_len = infinity
   - result = ""

3. Expand window (move right):
   - Add s[right] to window_count
   - If s[right] count now matches t_count, increment matched
   
4. Contract window (move left) while valid:
   - While matched == required:
     - Update result if current window is smaller
     - Remove s[left] from window_count
     - If s[left] count drops below required, decrement matched
     - Move left++
   
5. Return result
```

### Example Walkthrough

```
s = "ADOBECODEBANC"
t = "ABC"
t_count = {A:1, B:1, C:1}
required = 3

Initial: left=0, right=0, matched=0

right=0, s[right]='A':
  window_count = {A:1}
  A matches! matched=1
  Window: "A", not valid yet

right=1, s[right]='D':
  window_count = {A:1, D:1}
  matched=1, Window: "AD"

right=2, s[right]='O':
  window_count = {A:1, D:1, O:1}
  matched=1, Window: "ADO"

right=3, s[right]='B':
  window_count = {A:1, D:1, O:1, B:1}
  B matches! matched=2
  Window: "ADOB"

right=4, s[right]='E':
  window_count = {A:1, D:1, O:1, B:1, E:1}
  matched=2, Window: "ADOBE"

right=5, s[right]='C':
  window_count = {A:1, D:1, O:1, B:1, E:1, C:1}
  C matches! matched=3 ✅ VALID WINDOW!
  
  Contract:
    Window: "ADOBEC" (length 6), update result
    Remove 'A': matched=2, not valid
    left=1
  
right=6, s[right]='O':
  window_count = {D:1, O:2, B:1, E:1, C:1}
  matched=2, expand...

... continue until right=12, s[right]='C':
  After expansion, window contains: "BANC"
  All chars matched, contract to minimum
  Window: "BANC" (length 4), update result!

Final result: "BANC"
```

## Implementation Details

### Method 1: Hash Map with Match Counter

```
Track:
- t_count: {char: count} for t
- window_count: {char: count} for current window
- matched: number of chars with sufficient count
- required: number of unique chars in t

Expand:
  Add char to window
  If window[char] == t_count[char]:
    matched++

Contract:
  If matched == required:
    Update minimum
    Remove left char
    If window[left] < t_count[left]:
      matched--
    left++
```

### Method 2: Using Arrays (Faster for ASCII)

```
Use two arrays of size 128 (ASCII):
- t_count[128]
- window_count[128]

Same logic, just with arrays instead of hash maps
```

## Algorithm Complexity

**Time Complexity:** O(m + n)
- Build `t_count`: O(n)
- Expand `right` through entire string: O(m)
- Contract `left` through entire string: O(m) total (not per iteration!)
- Total: O(m + n)

**Space Complexity:** O(k)
- k = number of unique characters in `t`
- At most O(52) for English letters (upper + lower)
- Effectively O(1)

## Key Insights

### 1. Why is `left` pointer O(m) total, not O(m²)?

Each character is visited **at most twice**:
- Once when `right` adds it
- Once when `left` removes it

So total operations = 2m = O(m)

### 2. When to Contract vs. Expand

```
while right < len(s):
    # Always expand
    Add s[right] to window
    
    # Contract only when valid
    while window is valid:
        Update minimum
        Remove s[left]
        left++
    
    right++
```

### 3. Handling Duplicates

If `t = "AAB"`, we need:
- At least 2 A's
- At least 1 B

Use frequency counts, not just presence!

## Common Mistakes to Avoid

1. **Forgetting to handle duplicates:**
   - Use counts, not just set membership

2. **Not tracking matched characters correctly:**
   - Only increment `matched` when count **exactly matches**
   - Decrement when count **drops below** requirement

3. **Updating result incorrectly:**
   - Update when window is valid **and** smaller than previous minimum
   - Store both indices, not just length

4. **Off-by-one errors:**
   - Window is `[left, right]` inclusive
   - Length is `right - left + 1`

5. **Not handling "no valid window":**
   - Return `""` if no valid window found

## Edge Cases

1. **t longer than s:** Return `""`
2. **t has characters not in s:** Return `""`
3. **s == t:** Return s
4. **t has all duplicates:** e.g., `t = "AAA"`, need at least 3 A's
5. **Single character:** s="a", t="a" → "a"
6. **Multiple valid windows:** Return the smallest

## Alternative Approaches

### Brute Force (TLE)
```
For each substring in s:
  Check if it contains all chars from t
  Track minimum
  
Time: O(m² × n) - Too slow!
```

### Optimized Brute Force
```
For each starting position:
  Expand until valid
  Check if minimum
  
Time: O(m²) - Still too slow!
```

### Optimal: Sliding Window (This approach)
```
Expand and contract dynamically
Time: O(m + n) ✅
```

## Summary

**Pattern:** Variable-length sliding window with frequency matching
- **Expand** to find valid window
- **Contract** to minimize window
- Track minimum throughout
- O(m + n) time, O(1) space

This is the **classic hard sliding window problem** - master this pattern and you can solve many similar problems!
