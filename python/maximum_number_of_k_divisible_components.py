"""
2872. Maximum Number of K-Divisible Components

There is an undirected tree with n nodes. Split the tree by removing edges
such that each resulting component has a sum of values divisible by k.
Return the maximum number of components possible.
"""

from typing import List
from collections import defaultdict


class Solution:
    def maxKDivisibleComponents(
        self, n: int, edges: List[List[int]], values: List[int], k: int
    ) -> int:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        res = 0

        def dfs(node, parent):
            nonlocal res
            subtree_sum = values[node] % k

            for child in adj[node]:
                if child != parent:
                    subtree_sum = (subtree_sum + dfs(child, node)) % k

            if subtree_sum == 0:
                res += 1

            return subtree_sum

        dfs(0, -1)

        return res


def test_maximum_k_divisible_components():
    solution = Solution()

    # Test case 1: Example 1
    n = 5
    edges = [[0, 2], [1, 2], [1, 3], [2, 4]]
    values = [1, 8, 1, 4, 4]
    k = 6
    result = solution.maxKDivisibleComponents(n, edges, values, k)
    expected = 2
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2
    n = 7
    edges = [[0, 1], [0, 2], [1, 3], [1, 4], [2, 5], [2, 6]]
    values = [3, 0, 6, 1, 5, 2, 1]
    k = 3
    result = solution.maxKDivisibleComponents(n, edges, values, k)
    expected = 3
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: Single node
    n = 1
    edges = []
    values = [10]
    k = 5
    result = solution.maxKDivisibleComponents(n, edges, values, k)
    expected = 1
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: All zeros
    n = 4
    edges = [[0, 1], [1, 2], [2, 3]]
    values = [0, 0, 0, 0]
    k = 3
    result = solution.maxKDivisibleComponents(n, edges, values, k)
    expected = 4
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: Linear tree
    n = 3
    edges = [[0, 1], [1, 2]]
    values = [3, 6, 3]
    k = 3
    result = solution.maxKDivisibleComponents(n, edges, values, k)
    expected = 3
    print(f"Test 5: {result} (expected: {expected})")


if __name__ == "__main__":
    test_maximum_k_divisible_components()
