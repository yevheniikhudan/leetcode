# 212. Word Search II - Tutorial

This problem combines backtracking with Trie (Prefix Tree) optimization for efficient multi-word search on a board.

## Key Concepts
- **Backtracking:** Explore all possible paths for each word starting from every cell.
- **Trie:** Store all words for fast prefix checking and pruning during DFS.
- **Pruning:** Stop searching a path early if it cannot lead to any word in the Trie.

## Approach Outline
1. Build a Trie from the list of words.
2. For each cell in the board, start a DFS if the cell's letter is a prefix in the Trie.
3. Mark visited cells to avoid revisiting in the same path.
4. Collect found words and avoid duplicates.

No code is provided here; see the solution files for language-specific skeletons.
