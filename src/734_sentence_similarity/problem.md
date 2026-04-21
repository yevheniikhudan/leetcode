# Sentence Similarity

**Problem Number:** 734  
**Difficulty:** Easy  

## Topics/Tags
- Union-Find (Disjoint Set Union)
- Graph
- Hash Set
- Word Comparison

## Problem Description

We can represent a sentence as an array of words. For example, the sentence `"I am happy with leetcode"` can be represented as `["I","am","happy","with","leetcode"]`.

Given two sentences `sentence1` and `sentence2` composed of words, and a list of similar word pairs `similarPairs`, determine if the two sentences are similar.

Two sentences are similar if and only if they have the same length and each word at the same position is similar.

A word is similar to another word if:
- The words are the same, OR
- The two words can be made the same after a series of similar pairs

For example, if the similar pairs are:
- `["great","good"]`
- `["fine","good"]`
- `["fine","excellent"]`
- `["supper","good"]`

Then the words `"great"`, `"fine"`, `"good"`, `"supper"` are all similar to each other, and they should all be treated as the same word.

## Examples

**Example 1:**
```
Input: sentence1 = ["great","acting","skills"], 
       sentence2 = ["fine","drama","talent"], 
       similarPairs = [["great","fine"],["acting","drama"],["skills","talent"]]
Output: true
Explanation: The words at the same positions are similar.
```

**Example 2:**
```
Input: sentence1 = ["great"], 
       sentence2 = ["great"], 
       similarPairs = []
Output: true
Explanation: The words are identical.
```

**Example 3:**
```
Input: sentence1 = ["great"], 
       sentence2 = ["doubleplus"], 
       similarPairs = [["great","doubleplus"]]
Output: true
Explanation: "great" and "doubleplus" are similar, so they should be treated as the same.
```

## Constraints

- `1 <= sentence1.length, sentence2.length <= 1000`
- `1 <= sentence1[i].length, sentence2[i].length <= 20`
- `sentence1[i]` and `sentence2[i]` consist of lowercase and uppercase English letters
- `0 <= similarPairs.length <= 2000`
- `similarPairs[i].length == 2`
- `0 <= similarPairs.length <= 2000`
- `similarPairs[i]` and `similarPairs[j]` are different
- `similarPairs[i]` and `similarPairs[j]` both consist of lowercase and uppercase English letters

## Related Problems

- 839. Similar String Groups
- 947. Most Stones Removed with Same Row or Column
- 990. Satisfiability of Equality Equations