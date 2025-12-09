# Longest Substring Without Repeating Characters - Tutorial

## Problem Understanding

Find the length of the longest substring in a string where all characters are unique (no duplicates).

**Key Points:**
- **Substring** = contiguous sequence of characters (not subsequence)
- **No repeating characters** = all characters in the substring must be unique
- Return the **length**, not the substring itself
- String can contain letters, digits, symbols, and spaces

**Example:**
- `"abcabcbb"` → longest unique substring is `"abc"` (length 3)
- `"bbbbb"` → longest unique substring is `"b"` (length 1)
- `"pwwkew"` → longest unique substring is `"wke"` (length 3)

## Approach: Sliding Window with Hash Set/Map

### Key Insight

Use the **sliding window technique** with a hash set or hash map to track characters in the current window:

1. **Expand** the window by moving the right pointer
2. **Contract** the window by moving the left pointer when we find a duplicate
3. Track the maximum window size seen

### Why Sliding Window?

- We need a **contiguous substring** → natural fit for sliding window
- When we find a duplicate, we don't need to restart from scratch
- We can efficiently track which characters are in the current window

## Algorithm Steps

### Approach 1: Sliding Window with Hash Set

1. Initialize `left = 0`, `right = 0`, `max_length = 0`
2. Create an empty hash set to track characters in current window
3. While `right < len(s)`:
   - If `s[right]` is NOT in the set:
     - Add `s[right]` to the set
     - Update `max_length = max(max_length, right - left + 1)`
     - Move `right` forward
   - If `s[right]` IS in the set (duplicate found):
     - Remove `s[left]` from the set
     - Move `left` forward
4. Return `max_length`

### Example Walkthrough

```
s = "abcabcbb"

Step-by-step:

Initial: left=0, right=0, set={}, max_length=0

right=0, char='a':
  'a' not in set → add 'a'
  set={'a'}, max_length=1
  
right=1, char='b':
  'b' not in set → add 'b'
  set={'a','b'}, max_length=2
  
right=2, char='c':
  'c' not in set → add 'c'
  set={'a','b','c'}, max_length=3
  
right=3, char='a':
  'a' in set (duplicate!) → remove s[left]='a'
  left=1, set={'b','c'}
  'a' not in set → add 'a'
  set={'b','c','a'}, max_length=3
  
right=4, char='b':
  'b' in set (duplicate!) → remove s[left]='b'
  left=2, set={'c','a'}
  'b' not in set → add 'b'
  set={'c','a','b'}, max_length=3

... continue ...

Final answer: max_length=3
```

### Approach 2: Sliding Window with Hash Map (Optimized)

Instead of removing characters one by one from the left, we can **jump** the left pointer directly:

1. Use a hash map to store `{character: index}`
2. When we find a duplicate at position `right`:
   - Jump `left` to `max(left, map[s[right]] + 1)`
   - This skips all characters up to and including the previous occurrence
3. Update the map with the current character's index
4. Track the maximum window size

**Advantage**: Each character is visited at most twice (once by right, once by left)

### Example Walkthrough (Optimized)

```
s = "abcabcbb"

left=0, right=0, map={}, max_length=0

right=0, char='a':
  map={'a': 0}, max_length=1

right=1, char='b':
  map={'a': 0, 'b': 1}, max_length=2

right=2, char='c':
  map={'a': 0, 'b': 1, 'c': 2}, max_length=3

right=3, char='a':
  'a' at index 0 → jump left to 1
  map={'a': 3, 'b': 1, 'c': 2}, max_length=3

right=4, char='b':
  'b' at index 1 → jump left to 2
  map={'a': 3, 'b': 4, 'c': 2}, max_length=3

right=5, char='c':
  'c' at index 2 → jump left to 3
  map={'a': 3, 'b': 4, 'c': 5}, max_length=3

right=6, char='b':
  'b' at index 4 → jump left to 5
  map={'a': 3, 'b': 6, 'c': 5}, max_length=3

right=7, char='b':
  'b' at index 6 → jump left to 7
  map={'a': 3, 'b': 7, 'c': 5}, max_length=3

Final answer: max_length=3
```

## Complexity Analysis

### Hash Set Approach
- **Time**: O(2n) = O(n) - each character visited at most twice
- **Space**: O(min(n, m)) where m is the charset size (at most 128 ASCII or 256 extended ASCII)

### Hash Map Approach (Optimized)
- **Time**: O(n) - each character visited once by right pointer
- **Space**: O(min(n, m)) where m is the charset size

## Edge Cases

1. **Empty string**: `s = ""` → return 0
2. **All unique characters**: `s = "abcdef"` → return 6 (length of string)
3. **All same character**: `s = "aaaa"` → return 1
4. **Single character**: `s = "a"` → return 1
5. **Special characters and spaces**: `s = "a b!c"` → all count as unique characters

## Common Mistakes

1. **Confusing substring with subsequence**: Must be contiguous!
2. **Not handling the empty string case**: Check for `len(s) == 0`
3. **Off-by-one errors**: Window size is `right - left + 1`
4. **Not updating max_length**: Need to check after every successful addition
5. **Forgetting to update the map**: In hash map approach, always update current character's index

## Key Takeaways

- **Sliding window** is the optimal pattern for substring problems
- **Hash set** tracks existence, **hash map** tracks positions
- **Two pointers** (left and right) define the window boundaries
- **Expand** when valid, **contract** when invalid (duplicate found)
- Always track the maximum window size seen so far
