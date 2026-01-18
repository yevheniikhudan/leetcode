# 261. Graph Valid Tree

[LeetCode link](https://leetcode.com/problems/graph-valid-tree/)

Given `n` nodes labeled from 0 to n - 1 and a list of undirected edges, write a function to check whether these edges make up a valid tree.

- **Input:**
    - `n` (int): Number of nodes.
    - `edges` (List[List[int]]): List of undirected edges.
- **Output:**
    - `True` if the edges form a valid tree, otherwise `False`.

**Example 1:**

Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]

Output: true

**Example 2:**

Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]

Output: false

**Constraints:**
- 1 <= n <= 2000
- 0 <= edges.length <= 5000
- 0 <= ai, bi < n
- All the pairs are unique.
