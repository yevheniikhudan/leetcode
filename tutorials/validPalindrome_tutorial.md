# Valid Palindrome - Tutorial

## Problem Understanding

Check if a string is a palindrome after:
1. Converting to lowercase
2. Removing all non-alphanumeric characters (keep only letters and numbers)

## Key Insights

1. **Two-Pointer Technique**: Use left and right pointers moving towards center
2. **Skip Non-Alphanumeric**: Move pointers past invalid characters
3. **Case-Insensitive Comparison**: Convert to lowercase when comparing
4. **O(1) Space**: Can solve without creating a new filtered string

## Approach 1: Two Pointers (Optimal)

### Algorithm:
1. Initialize left pointer at start, right pointer at end
2. While left < right:
   - Skip non-alphanumeric characters from left
   - Skip non-alphanumeric characters from right
   - Compare characters (case-insensitive)
   - If they don't match, return false
   - Move both pointers inward
3. Return true if all characters match

### Example Walkthrough

```
s = "A man, a plan, a canal: Panama"

After filtering: "amanaplanacanalpanama"

left = 0, right = 20
Compare 'a' and 'a' ✓
left = 1, right = 19
Compare 'm' and 'm' ✓
...
All characters match → return true
```

### Time Complexity
- O(n) where n is the length of the string
- Each character is visited at most once

### Space Complexity
- O(1) - only using two pointers

## Approach 2: Filter and Compare

### Algorithm:
1. Filter string to keep only alphanumeric characters
2. Convert to lowercase
3. Compare filtered string with its reverse

### Time Complexity
- O(n) for filtering and reversing

### Space Complexity
- O(n) for the filtered string

## Edge Cases

1. **Empty string after filtering**: Return true
2. **Single character**: Return true
3. **All non-alphanumeric**: Return true (empty after filtering)
4. **Mixed case**: Must compare case-insensitively
5. **Numbers and letters**: Both are valid alphanumeric

## Common Mistakes

1. **Not handling case**: Must convert to lowercase
2. **Not skipping non-alphanumeric**: Must filter out spaces, punctuation
3. **Off-by-one errors**: Make sure left < right condition is correct
4. **Not handling numbers**: Numbers are alphanumeric too

## Character Classification

**Alphanumeric characters:**
- Letters: a-z, A-Z
- Numbers: 0-9

**Non-alphanumeric (skip these):**
- Spaces, punctuation, special characters

## Optimization Tips

1. **In-place comparison**: Don't create filtered string (saves space)
2. **Early exit**: Return false as soon as mismatch found
3. **Use built-in functions**: isalnum(), tolower() in C++, isalnum() in Python

## Language-Specific Helpers

### Python:
```python
char.isalnum()  # Check if alphanumeric
char.lower()    # Convert to lowercase
```

### C++:
```cpp
isalnum(char)  # Check if alphanumeric
tolower(char)  # Convert to lowercase
```

### Java:
```java
Character.isLetterOrDigit(char)  # Check if alphanumeric
Character.toLowerCase(char)      # Convert to lowercase
```
