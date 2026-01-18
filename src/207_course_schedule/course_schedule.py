from collections import deque
from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjList = [[] for _ in range(numCourses)]
        inEdges = [0] * numCourses
        q = deque()
        coursesFinished = 0

        for dest, src in prerequisites:
            inEdges[dest] += 1
            adjList[src].append(dest)

        for i in range(numCourses):
            if inEdges[i] == 0:
                q.append(i)

        while q:
            coursesFinished += 1
            course = q.popleft()

            for adj in adjList[course]:
                if inEdges[adj] > 0:
                    inEdges[adj] -= 1

                if inEdges[adj] == 0:
                    q.append(adj)

        return coursesFinished == numCourses


# Test scaffolding
def test():
    sol = Solution()
    print(sol.canFinish(2, [[1, 0]]), "| True")
    print(sol.canFinish(2, [[1, 0], [0, 1]]), "| False")
    print(sol.canFinish(1, []), "| True")
    print(sol.canFinish(3, [[1, 0], [2, 1]]), "| True")
    print(sol.canFinish(3, [[1, 0], [0, 2], [2, 1]]), "| False")


if __name__ == "__main__":
    test()
