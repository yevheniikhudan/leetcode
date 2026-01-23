# Tutorial: Find Words That Can Be Formed by Characters

## Understanding the Problem
We need to determine which words from a list can be formed using the characters from a given string `chars`, where each character in `chars` can be used at most once per word. We then sum the lengths of all such "good" words.

This is a frequency-based problem: for each word, check if the count of each character in the word does not exceed the count in `chars`.

## Key Concepts
- **Frequency Counting:** Use arrays or maps to count character occurrences.
- **String Formation:** Each character in `chars` is unique per word, so we compare frequencies.
- **Efficiency:** With small constraints (words[i].length <= 100), we can afford O(len(word)) per word.

## Approaches

### 1. Frequency Count with Arrays (Optimal)
- Count frequencies of `chars` using an array of size 26.
- For each word, count its frequencies and compare against `chars`' frequencies.
- If all word frequencies <= `chars` frequencies, add word length to sum.

**Time Complexity:** O(N + M), where N is total characters in words, M is length of chars.  
**Space Complexity:** O(1) for frequency arrays (fixed size 26).

### 2. Frequency Count with Maps
- Use HashMap for frequencies.
- Similar logic, but slightly slower due to map operations.

**Time Complexity:** O(N + M) with good hash, but higher constants.  
**Space Complexity:** O(1) average case.

## Visual Example
For words = ["cat", "bt", "hat"], chars = "atach":

- chars frequencies: a:2, t:2, c:1, h:1
- "cat": c:1, a:1, t:1 → all <=, good (length 3)
- "bt": b:1, t:1 → b not in chars, bad
- "hat": h:1, a:1, t:1 → all <=, good (length 3)
- Sum: 6

## Edge Cases
- Empty words or chars: Handled by constraints (min length 1).
- Words with duplicate chars: Check frequencies.
- No good words: Return 0.
- All words good: Sum all lengths.

## Common Pitfalls
- Forgetting that chars can be used only once per word.
- Not resetting word frequency counts between words.
- Case sensitivity: All lowercase, no issue.

## Optimization Notes
- Use arrays for speed (O(1) access).
- Early exit if word has chars not in chars.
- Since N<=1000*100=100k, any approach is fine.
