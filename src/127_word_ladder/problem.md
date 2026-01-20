# 127. Word Ladder

[LeetCode link](https://leetcode.com/problems/word-ladder/description/)

Given two words, `beginWord` and `endWord`, and a dictionary's word list, find the length of the shortest transformation sequence from `beginWord` to `endWord`, such that:
- Only one letter can be changed at a time.
- Each transformed word must exist in the word list.

Return the length of the sequence, or 0 if no such sequence exists.

**Example 1:**

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: "hit" -> "hot" -> "dot" -> "dog" -> "cog"

**Example 2:**

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]

Output: 0

**Constraints:**
- 1 <= beginWord.length <= 10
- endWord.length == beginWord.length
- 1 <= wordList.length <= 5000
- wordList[i].length == beginWord.length
- All words are lowercase English letters.
- beginWord, endWord, and wordList[i] consist of lowercase English letters.
- beginWord != endWord
- All words in wordList are unique.
