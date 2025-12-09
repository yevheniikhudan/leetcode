# Count Vowel Substrings of a String - Tutorial

## Key Insights
- A valid substring must contain only vowels and all five vowels at least once.
- For each starting index, expand the substring until a consonant is found, and check if all vowels are present.

## Steps
1. Iterate over all possible starting indices.
2. For each start, expand the substring as long as only vowels are present.
3. Use a set or counter to track which vowels have been seen.
4. If all five vowels are present, increment the result.

## Example
For word = "aeiouu":
- Substrings: "aeiou", "aeiouu" (both contain all vowels)

For word = "cuaieuouac":
- Multiple substrings starting at different indices contain all vowels.

## Implementation
- Time complexity: O(n^2) (acceptable for n ≤ 100)
- Space complexity: O(1)

## Edge Cases
- No vowels: return 0
- All vowels present but not contiguous: return 0
