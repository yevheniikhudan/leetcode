# Confusing Number - Tutorial

## Understanding the Problem

A confusing number is one that, when rotated 180 degrees:
1. All its digits must be rotatable (0, 1, 6, 8, 9 are valid)
2. The result must be a different number than the original

When rotated 180 degrees:
- The digit at position 0 becomes position n-1 (reversal)
- Each digit transforms: 0→0, 1→1, 6→9, 8→8, 9→6
- Invalid digits (2,3,4,5,7) make the number non-confusing

---

## Visual Examples

### Example 1: 6 is confusing
```
Original: 6
Rotated 180°: 9
6 ≠ 9, so it's confusing ✓
```

### Example 2: 89 is confusing
```
Original: 89
Step 1: Reverse digits → 98
Step 2: Rotate each digit: 9→6, 8→8 → 68
89 ≠ 68, so it's confusing ✓
```

### Example 3: 11 is NOT confusing
```
Original: 11
Step 1: Reverse digits → 11
Step 2: Rotate each digit: 1→1, 1→1 → 11
11 = 11, so it's NOT confusing ✗
```

### Example 4: 25 is NOT confusing
```
Original: 25
The digit 2 cannot be rotated to a valid digit ✗
```

### Example 5: 69 is confusing
```
Original: 69
Step 1: Reverse digits → 96
Step 2: Rotate each digit: 9→6, 6→9 → 69
69 = 69, so it's NOT confusing ✗
```

---

## Multiple Approaches

### Approach 1: String Conversion with Mapping (Most Straightforward)
**Concept:**
- Convert number to string
- Check if all digits are valid (0, 1, 6, 8, 9)
- Reverse the string
- Apply rotation mapping to each character
- Compare original with rotated number

**Strategy:**
1. Create a mapping: {'0': '0', '1': '1', '6': '9', '8': '8', '9': '6'}
2. Convert n to string
3. Check if all digits exist in mapping
4. Build rotated number by iterating string from right to left and applying mapping
5. Return whether rotated number is different from original

**Pros:**
- Straightforward logic
- Easy to implement and understand
- Handles all edge cases naturally

**Cons:**
- String conversion and manipulation overhead

### Approach 2: Mathematical Digit Extraction
**Concept:**
- Extract digits using modulo and division
- Build the rotated number mathematically
- Compare values

**Strategy:**
1. Extract each digit from right to left using mod 10
2. Check validity and apply transformation
3. Build rotated number by multiplying by 10 and adding rotated digit
4. Compare original with rotated

**Pros:**
- No string conversion needed
- Pure mathematical approach

**Cons:**
- More complex logic
- Harder to visualize

---

## Time and Space Complexity

### Approach 1 (String Mapping):
- **Time Complexity:** O(d) where d is the number of digits (at most 10 for 10^9)
- **Space Complexity:** O(d) for the string representation

### Approach 2 (Mathematical):
- **Time Complexity:** O(d) where d is the number of digits
- **Space Complexity:** O(1) if we don't count output

---

## Key Concepts and Patterns

1. **Valid Rotation Digits:** Only 0, 1, 6, 8, 9 can be rotated; all others disqualify
2. **Bidirectional Mapping:** 6↔9 and everything else maps to itself
3. **Reversal + Transformation:** Must both reverse (180°) and apply digit mapping

---

## Edge Cases and Common Pitfalls

1. **Single Digit Numbers:**
   - 0: Rotates to 0 (not confusing)
   - 1: Rotates to 1 (not confusing)
   - 6: Rotates to 9 (confusing) ✓
   - 8: Rotates to 8 (not confusing)
   - 9: Rotates to 6 (confusing) ✓

2. **Invalid Digits:**
   - Any number containing 2, 3, 4, 5, or 7 is NOT confusing
   - Example: 12, 96002 (has 2), etc.

3. **Palindromic Rotations:**
   - 11, 69, 88, 96 all map to themselves after rotation
   - These are NOT confusing despite having valid digits

4. **Leading Zeros After Rotation:**
   - Not an issue for n <= 10^9
   - Rotation won't produce leading zeros naturally

---

## Optimization Notes

- **Early Exit:** Return false immediately if any invalid digit is found
- **Caching:** If checking multiple numbers, pre-build the mapping dictionary
- **Mathematical Approach:** Avoids string overhead but adds complexity
