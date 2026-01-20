# 684. Redundant Connection

[LeetCode link](https://leetcode.com/problems/redundant-connection/)

In this problem, a tree is a connected undirected graph with no cycles. You are given a graph that started as a tree with n nodes (labeled 1 to n), with one additional edge added. The task is to find the edge that can be removed to restore the tree property. If there are multiple answers, return the edge that occurs last in the input.

- **Input:**
    - `edges` (List[List[int]]): List of undirected edges.
- **Output:**
    - The edge to remove (as a list of two integers).

**Example 1:**

Input: edges = [[1,2],[1,3],[2,3]]

Output: [2,3]

**Example 2:**

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]

Output: [1,4]

**Constraints:**
- 3 <= n <= 1000
- 1 <= edges.length <= 1000
- edges[i].length == 2
- 1 <= ai < bi <= n
- All edges are unique.
