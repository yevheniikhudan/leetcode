from typing import List
import heapq


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adjList = [[] for _ in range(n)]
        for u, v, w in times:
            adjList[u - 1].append([v, w])

        time = 0
        h = []
        heapq.heappush(h, [0, k])
        visit = set()

        while h:
            w, u = heapq.heappop(h)

            if u in visit:
                continue
            time = w
            visit.add(u)

            for v, w1 in adjList[u - 1]:
                if v in visit:
                    continue

                heapq.heappush(h, [w + w1, v])

        return time if len(visit) == n else -1


# Test helper
def test_network_delay_time():
    solution = Solution()

    # Test case 1: Example 1
    times1 = [[2, 1, 1], [2, 3, 1], [3, 4, 1]]
    n1 = 4
    k1 = 2
    expected1 = 2
    actual1 = solution.networkDelayTime(times1, n1, k1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    times2 = [[1, 2, 1]]
    n2 = 2
    k2 = 1
    expected2 = 1
    actual2 = solution.networkDelayTime(times2, n2, k2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Example 3
    times3 = [[1, 2, 1]]
    n3 = 2
    k3 = 2
    expected3 = -1
    actual3 = solution.networkDelayTime(times3, n3, k3)
    print(f"{actual3} | {expected3}")

    # Test case 4: Single node
    times4 = []
    n4 = 1
    k4 = 1
    expected4 = 0
    actual4 = solution.networkDelayTime(times4, n4, k4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Disconnected nodes
    times5 = [[1, 2, 1], [3, 4, 1]]
    n5 = 4
    k5 = 1
    expected5 = -1
    actual5 = solution.networkDelayTime(times5, n5, k5)
    print(f"{actual5} | {expected5}")

    # Test case 6: All connected
    times6 = [[1, 2, 1], [1, 3, 2], [2, 3, 1], [3, 4, 1]]
    n6 = 4
    k6 = 1
    expected6 = 3
    actual6 = solution.networkDelayTime(times6, n6, k6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_network_delay_time()
