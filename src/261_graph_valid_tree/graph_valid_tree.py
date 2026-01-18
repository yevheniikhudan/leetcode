from collections import deque
from typing import List


class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False

        adjList = [[] for _ in range(n)]

        for src, dest in edges:
            adjList[src].append(dest)
            adjList[dest].append(src)

        visited = set()

        q = deque()
        q.append((0, -1))
        visited.add(0)

        while q:
            node, parent = q.popleft()

            for adj in adjList[node]:
                if adj == parent:
                    continue

                if adj in visited:
                    return False

                visited.add(adj)
                q.append((adj, node))

        return len(visited) == n


# Test scaffolding
def test():
    sol = Solution()
    print(sol.validTree(5, [[0, 1], [0, 2], [0, 3], [1, 4]]), "| True")
    print(sol.validTree(5, [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]), "| False")
    print(sol.validTree(1, []), "| True")
    print(sol.validTree(2, [[0, 1]]), "| True")
    print(sol.validTree(2, []), "| False")


if __name__ == "__main__":
    test()
