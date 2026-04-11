# Tutorial: Length of Last Word

## Understanding the Problem

We need to find the length of the **last word** in a string that may contain multiple words separated by spaces, and there may be leading or trailing spaces.

Key observations:
- Words are consecutive non-space characters
- We only care about the **length**, not the word itself
- The string is guaranteed to have at least one word
- Spaces can appear anywhere: leading, trailing, or between words

### Visual Example

```
Input: "   fly me   to   the moon  "

[Space][Space][Space]fly[Space]me[Space][Space][Space]to[Space][Space][Space]the[Space]moon[Space][Space]
                                                                                    ^^^^
                                                                        Last word = "moon" (length 4)
```

## Approaches

### Approach 1: Two Pointers from Right (Most Efficient) ⭐

**Strategy:**
1. Start from the end of the string (rightmost position)
2. Skip all trailing spaces
3. Once you encounter a non-space character, start counting
4. Stop counting when you hit a space or reach the beginning of the string

**Why this works:**
- We don't need to process the entire string or split it
- We go directly to where the last word is
- We minimize unnecessary operations

**Visualization:**

```
Original: "   fly me   to   the moon  "
           0   1  2   3  4  5  6   7 8 9
Position:  →→→→→→→→→→→→→→→→→→→→→→[m][o][o][n]←←← (scanning right to left)

Step 1: Start at index n-1 (rightmost)
Step 2: Skip spaces: "  " (2 spaces)
Step 3: Count non-spaces: "moon" = 4 characters
Step 4: Return 4
```

**Time Complexity:** O(n) - worst case we scan the entire string  
**Space Complexity:** O(1) - only using a counter variable

### Approach 2: Split and Get Last Element

**Strategy:**
1. Split the string by spaces
2. Filter out empty strings (from multiple consecutive spaces)
3. Get the last element
4. Return its length

**Why this works:**
- Simple and readable
- Uses built-in string operations
- Handles multiple spaces automatically

**Considerations:**
- Creates an array with all words
- Requires extra space proportional to the number of words
- Less efficient than two-pointer approach but very intuitive

**Time Complexity:** O(n) - need to scan the string to split  
**Space Complexity:** O(n) - storing all words in memory

### Approach 3: Two Pointers with Trim

**Strategy:**
1. Remove trailing spaces from the string
2. Find the position of the last space
3. Return the length from the last space to the end

**Considerations:**
- Requires trimming operation (extra pass or space)
- Still requires finding the last space
- More operations than direct right-to-left scan

**Time Complexity:** O(n)  
**Space Complexity:** O(n) - if you create a trimmed copy

### Approach 4: Reverse and Count

**Strategy:**
1. Reverse the string
2. Skip leading spaces (from the reversed perspective)
3. Count characters until hitting a space

**Considerations:**
- Requires string reversal
- Conceptually similar to right-to-left approach
- Takes extra space if reversal creates a new string

**Time Complexity:** O(n)  
**Space Complexity:** O(n) - for the reversed string

## Complexity Analysis Summary

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Two Pointers (Right) | O(n) | O(1) | ✅ Most Efficient |
| Split and Filter | O(n) | O(n) | Good readability |
| Trim + Last Space | O(n) | O(n) | Extra operations |
| Reverse and Count | O(n) | O(n) | Unnecessary reversal |

## Key Concepts

### 1. Word Definition
- A word consists of **consecutive non-space characters**
- Single character is also a valid word
- Empty strings between spaces don't count as words

### 2. Edge Cases with Spaces
- **Multiple consecutive spaces:** "hello  world" - should return 5 (length of "world")
- **Leading spaces:** "  hello" - should return 5
- **Trailing spaces:** "hello  " - should return 5
- **Single word:** "hello" - should return 5
- **Single character:** "a" - should return 1

### 3. String Indexing Patterns
- **Left-to-right:** Good for finding first word
- **Right-to-left:** Good for finding last word (most efficient here)

## Edge Cases and Common Pitfalls

### ❌ Common Mistakes

1. **Forgetting trailing spaces**
   - Input: `"hello  "`
   - ❌ Wrong: Count the spaces as part of length
   - ✅ Correct: Skip trailing spaces, return 5

2. **Multiple consecutive spaces between words**
   - Input: `"hello   world"`
   - ❌ Wrong: Only count spaces between words
   - ✅ Correct: Count characters in last word only (5)

3. **Not handling leading spaces**
   - Input: `"   hello world"`
   - ❌ Wrong: Start counting from beginning
   - ✅ Correct: Skip leading words, find last one

4. **Off-by-one errors in iteration**
   - Not properly detecting space boundaries
   - Not correctly initializing counter

### ✅ How to Avoid

- Test with strings that have multiple spaces
- Test with leading and trailing spaces
- Test with single word (no spaces)
- Test with single character
- Clearly define when to start/stop counting

## Optimization Notes

### For Interview/Production Code:

1. **Prefer the two-pointer from right approach**
   - O(1) space complexity
   - Clean and efficient
   - Easy to explain

2. **Consider language-specific optimizations**
   - Python: Built-in `split()` is well-optimized
   - Java: `strip()` and `lastIndexOf()` are efficient
   - C++: Using pointers directly is fastest

3. **Early termination strategy**
   - Skip trailing spaces first
   - Then count until you hit a space or reach the beginning
   - Minimizes unnecessary comparisons

### Practical Considerations:

- For very long strings with many words, right-to-left is better
- For short strings, either approach is fine
- Readability matters - don't over-optimize if it hurts clarity
- Use built-in functions when available and acceptable

## Pattern Recognition

This problem tests:
- **String manipulation** - comfortable with character iteration
- **Edge case handling** - managing whitespace
- **Space optimization** - choosing O(1) over O(n) space
- **Two-pointer technique** - a fundamental algorithmic pattern

Similar problems use these patterns:
- Finding first word (left-to-right scan)
- Reverse words (two-pointer swap)
- Remove duplicates (two-pointer technique)