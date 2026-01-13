# 211. Design Add and Search Words Data Structure - Tutorial

This problem is a variant of the classic Trie (Prefix Tree) data structure, with the added complexity of supporting wildcard searches using the `.` character. The main challenge is efficiently supporting both word addition and search with wildcards.

## Key Concepts
- **Trie Data Structure:** Used for efficient word storage and prefix-based search.
- **DFS/Backtracking:** Required for handling the `.` wildcard during search.

## Approach Outline
1. **Trie Node Structure:** Each node contains a map/array of children and a boolean indicating if a word ends at this node.
2. **addWord:** Insert each character of the word into the Trie.
3. **search:** Use DFS/backtracking to handle `.` wildcards, exploring all possible children when a `.` is encountered.

No code is provided here; see the solution files for language-specific skeletons.
