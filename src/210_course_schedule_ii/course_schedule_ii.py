from collections import deque
from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adjList = [[] for _ in range(numCourses)]
        inEdges = [0] * numCourses
        q = deque()
        path = []

        for dest, src in prerequisites:
            inEdges[dest] += 1
            adjList[src].append(dest)

        for i in range(numCourses):
            if inEdges[i] == 0:
                q.append(i)

        while q:
            course = q.popleft()
            path.append(course)

            for adj in adjList[course]:
                if inEdges[adj] > 0:
                    inEdges[adj] -= 1

                if inEdges[adj] == 0:
                    q.append(adj)

        return path if len(path) == numCourses else []


# Test scaffolding
def test():
    sol = Solution()
    print(sol.findOrder(2, [[1, 0]]), "| [0, 1]")
    print(sol.findOrder(2, [[1, 0], [0, 1]]), "| []")
    print(sol.findOrder(1, []), "| [0]")
    print(
        sol.findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]]), "| [0,2,1,3] or [0,1,2,3]"
    )
    print(sol.findOrder(3, [[1, 0], [0, 2], [2, 1]]), "| []")


if __name__ == "__main__":
    test()
