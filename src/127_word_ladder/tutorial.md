# Tutorial: Word Ladder (BFS)

This problem is a classic application of Breadth-First Search (BFS) in a graph where each word is a node and edges exist between words that differ by one letter.

**Approach:**
- Use BFS starting from `beginWord`.
- At each step, generate all possible words by changing one letter at a time.
- If the new word is in the word list and not visited, add it to the queue.
- Track the number of transformations (levels in BFS).
- Stop when `endWord` is reached.

*No code is provided in this tutorial, only the algorithmic idea.*
