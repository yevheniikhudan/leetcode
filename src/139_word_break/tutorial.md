# Tutorial: Word Break

## Understanding the Problem
The Word Break problem determines if a given string can be broken down into words from a provided dictionary. Words can be reused, and the segmentation must use the entire string without leftover characters. This is a classic string segmentation problem with dictionary constraints.

It's like checking if the string can be fully covered by dictionary words in sequence, allowing overlaps and reuse.

## Visual Examples
- **Example 1:** s = "leetcode", wordDict = ["leet","code"]
  - "leet" + "code" covers the entire string → true

- **Example 2:** s = "applepenapple", wordDict = ["apple","pen"]
  - "apple" + "pen" + "apple" → true

- **Example 3:** s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
  - Possible: "cat" + "sand" + "dog" but "sand" not in dict, or "cats" + "and" + "dog" but "and" not in dict → false

## Multiple Approaches

### 1. Dynamic Programming (Bottom-Up) - Most Efficient
Use a DP array where dp[i] is true if s[0..i-1] can be segmented.
- Initialize dp[0] = true
- For each position, check if any word matches the suffix ending at that position
- Time: O(n^2), Space: O(n) - optimal for n=300

### 2. Recursion with Memoization (Top-Down DP)
Recursive function that tries to match words from the start.
- Memoize results for each starting index
- Base: if index == len(s), return true
- For each word, if it matches prefix, recurse on remaining
- Time: O(n^2), Space: O(n) - similar to DP

### 3. Breadth-First Search (BFS)
Use a queue to explore possible starting positions.
- Start from index 0, add to queue
- For each position, try matching words and enqueue new positions
- Time: O(n^2), Space: O(n) - good for understanding

### 4. Trie-Based Approach
Build a trie from wordDict for efficient prefix matching.
- During DP or recursion, use trie to check valid words
- Time: O(n^2), Space: O(total characters in dict) - useful for large dicts

## Time/Space Complexity Analysis
- **DP/BFS/Memoization:** O(n^2) time, O(n) space - n=300, so 90k operations, fine
- **Trie:** Same time, but space depends on dict size
- DP is simplest and most efficient for interviews

## Key Concepts and Patterns
- **Substring Matching:** Check if prefixes/suffixes are in dict
- **Overlapping Subproblems:** DP avoids recomputing segments
- **Word Reuse:** Same word can be used multiple times
- **Complete Coverage:** Must use entire string, no leftovers

## Edge Cases and Common Pitfalls
- **Empty String:** Should return true (no words needed)
- **Single Character:** If "a" in dict, true; else false
- **No Matches:** Return false
- **Word Longer Than String:** Skip such words
- **All Words Match:** True
- **Prefix Matches But Not Full:** Ensure complete segmentation
- **Pitfall:** Forgetting word reuse or not handling overlapping words

## Optimization Notes
- Use set for wordDict for O(1) lookups
- DP is preferred for clarity
- For very large n, consider if optimizations needed, but constraints are small
- Trie helps if dict is large and words share prefixes
