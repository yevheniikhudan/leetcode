# Valid Anagram - Tutorial

## Key Insights
- Two strings are anagrams if they contain the same characters with the same frequencies
- Different lengths → automatically not anagrams
- Multiple approaches possible: sorting, hash map, or frequency array

## Approaches

### Approach 1: Sorting (Simple)
1. Check if lengths are equal (if not, return false)
2. Sort both strings
3. Compare if sorted strings are equal

**Time:** O(n log n)  
**Space:** O(1) or O(n) depending on sort implementation

### Approach 2: Hash Map / Counter (Optimal)
1. Check if lengths are equal (if not, return false)
2. Count character frequencies in both strings
3. Compare the frequency maps

**Time:** O(n)  
**Space:** O(1) - at most 26 lowercase letters

### Approach 3: Frequency Array (For lowercase letters only)
1. Check if lengths are equal (if not, return false)
2. Use an array of size 26 to count frequencies
3. Increment for s, decrement for t
4. Check if all counts are zero

**Time:** O(n)  
**Space:** O(1) - fixed size 26

## Example
For s = "anagram", t = "nagaram":
- Both have length 7
- Character frequencies:
  - s: {a:3, n:1, g:1, r:1, m:1}
  - t: {n:1, a:3, g:1, r:1, m:1}
- Frequencies match → true

For s = "rat", t = "car":
- Both have length 3
- Character frequencies:
  - s: {r:1, a:1, t:1}
  - t: {c:1, a:1, r:1}
- Different characters → false

## Implementation
Hash map approach is optimal and works for Unicode characters.

## Edge Cases
- Different lengths: return false immediately
- Empty strings: both empty → true
- Single character: check if equal
