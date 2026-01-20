from typing import List


class DSU:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, node: int) -> int:
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])

        return self.parent[node]

    def union(self, node1, node2):
        parent1 = self.find(node1)
        parent2 = self.find(node2)

        if parent1 == parent2:
            return False

        if self.rank[parent1] < self.rank[parent2]:
            self.parent[parent1] = parent2
        elif self.rank[parent2] < self.rank[parent1]:
            self.parent[parent2] = parent1
        else:
            self.parent[parent1] = parent2
            self.rank[parent1] += 1

        return True


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)

        dsu = DSU(n)

        for src, dst in edges:
            if not dsu.union(src - 1, dst - 1):
                return [src, dst]

        return []


# Test scaffolding
def test():
    sol = Solution()
    print(sol.findRedundantConnection([[1, 2], [1, 3], [2, 3]]), "| [2,3]")
    print(
        sol.findRedundantConnection([[1, 2], [2, 3], [3, 4], [1, 4], [1, 5]]), "| [1,4]"
    )
    print(sol.findRedundantConnection([[1, 2], [2, 3], [3, 1]]), "| [3,1]")
    print(
        sol.findRedundantConnection([[1, 2], [2, 3], [3, 4], [4, 1], [1, 5]]), "| [4,1]"
    )


if __name__ == "__main__":
    test()
