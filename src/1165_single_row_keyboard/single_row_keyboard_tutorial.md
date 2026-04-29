# Single-Row Keyboard - Tutorial

## Understanding the Problem

We need to simulate typing on a keyboard where all keys are in a single row. The time to type a character is the **distance** (absolute difference in indices) from the current finger position to the target character.

### Key Insight

The keyboard layout is custom, not the standard QWERTY. We must:
1. Map each character to its position in the custom keyboard
2. Track the current finger position (starts at 0)
3. For each character to type, calculate distance and update position

## Approach 1: Hash Map + Linear Iteration

### Concept

1. **Create a mapping** from each character to its index in the keyboard string
2. **Initialize** finger position at index 0 and total time to 0
3. **For each character** in the word:
   - Calculate distance = |current_position - target_position|
   - Add distance to total time
   - Update current position to target position

### Step-by-Step Example

```
keyboard = "abcdefghijklmnopqrstuvwxyz"
word = "cba"

Step 1: Create character-to-index mapping
{a:0, b:1, c:2, d:3, ..., z:25}

Step 2: Process each character
- Start: position = 0, time = 0
- 'c' (index 2): distance = |0 - 2| = 2, position = 2, time = 2
- 'b' (index 1): distance = |2 - 1| = 1, position = 1, time = 3
- 'a' (index 0): distance = |1 - 0| = 1, position = 0, time = 4

Output: 4
```

### Complexity

- **Time:** O(n + m) where n = keyboard length (26) and m = word length
  - O(n) to create the hash map
  - O(m) to process each character
- **Space:** O(n) for the hash map (at most 26 characters)

## Approach 2: Dictionary Lookup During Iteration

### Concept

Instead of pre-creating the mapping, we can use `keyboard.find()` or `keyboard.index()` for each character. This saves space but uses O(n) time per lookup.

```python
def calculateTime(keyboard, word):
    pos = 0
    total = 0
    for char in word:
        new_pos = keyboard.index(char)  # O(n) lookup
        total += abs(pos - new_pos)
        pos = new_pos
    return total
```

- **Time:** O(m × n) - less efficient
- **Space:** O(1) - no extra hash map

## Edge Cases & Pitfalls

1. **Single character word:** `word = "a"` → Return distance from index 0 to position of 'a'
2. **Repeated characters:** `word = "aaa"` → Distance should be 0 after first 'a'
3. **Non-standard keyboard:** Characters in different order than QWERTY
4. **Large position differences:** Keyboard can be any permutation of lowercase letters
5. **Start position:** Always start at index 0

## Complexity Analysis

**Time Complexity:** O(n + m)
- O(n) to build character-to-index mapping (n = 26)
- O(m) to iterate through word (m = word.length)
- Total: O(26 + m) = O(m)

**Space Complexity:** O(n)
- Hash map stores 26 characters
- O(26) = O(1) effectively

## Summary

The optimal solution uses a hash map to store character positions, then iterates through the word once, accumulating distances. This is efficient and straightforward.
