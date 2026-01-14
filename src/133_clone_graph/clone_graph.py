from typing import List, Optional


class Node:
    def __init__(self, val: int = 0, neighbors: Optional[List["Node"]] = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


def are_graphs_equal(node1: "Node", node2: "Node") -> bool:
    # Helper to check if two graphs are structurally equal (ignoring object identity)
    visited1, visited2 = {}, {}

    def dfs(n1, n2):
        if not n1 and not n2:
            return True
        if not n1 or not n2 or n1.val != n2.val:
            return False
        if n1 in visited1 and n2 in visited2:
            return True
        visited1[n1] = True
        visited2[n2] = True
        if len(n1.neighbors) != len(n2.neighbors):
            return False
        for neigh1, neigh2 in zip(n1.neighbors, n2.neighbors):
            if not dfs(neigh1, neigh2):
                return False
        return True

    return dfs(node1, node2)


class Solution:
    def cloneGraph(self, node: "Node") -> "Node":
        seen = {}

        def dfs(node):
            if not node:
                return None

            if node in seen:
                return seen[node]

            clone = Node(node.val)
            seen[node] = clone

            for n in node.neighbors:
                clone.neighbors.append(dfs(n))

            return clone

        return dfs(node)


# Test scaffolding
if __name__ == "__main__":

    def build_graph(adj):
        if not adj:
            return None
        nodes = [Node(i + 1) for i in range(len(adj))]
        for i, neighbors in enumerate(adj):
            nodes[i].neighbors = [nodes[j - 1] for j in neighbors]
        return nodes[0]

    def print_graph(node):
        # Print adjacency list for debug
        if not node:
            print([])
            return
        visited = set()
        res = []

        def dfs(n):
            if n.val in visited:
                return
            visited.add(n.val)
            res.append((n.val, sorted([neigh.val for neigh in n.neighbors])))
            for neigh in n.neighbors:
                dfs(neigh)

        dfs(node)
        print(sorted(res))

    # Test case 4: Four nodes, square
    node = build_graph([[2, 4], [1, 3], [2, 4], [1, 3]])
    cloned = Solution().cloneGraph(node)
    print_graph(cloned)  # [(1, [2, 4]), (2, [1, 3]), (3, [2, 4]), (4, [1, 3])]

    # Test case 1: Empty graph
    node = build_graph([])
    cloned = Solution().cloneGraph(node)
    print(cloned is None)  # True

    # Test case 2: Single node, no neighbors
    node = build_graph([[]])
    cloned = Solution().cloneGraph(node)
    print_graph(cloned)  # [(1, [])]

    # Test case 3: Two nodes, one edge
    node = build_graph([[2], [1]])
    cloned = Solution().cloneGraph(node)
    print_graph(cloned)  # [(1, [2]), (2, [1])]

    # Test case 5: Three nodes, chain
    node = build_graph([[2], [1, 3], [2]])
    cloned = Solution().cloneGraph(node)
    print_graph(cloned)  # [(1, [2]), (2, [1, 3]), (3, [2])]
