from collections import defaultdict
from typing import List


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adjList = defaultdict(list)
        for src, dst in sorted(tickets)[::-1]:
            adjList[src].append(dst)

        res = []

        def dfs(src):
            while adjList[src]:
                dst = adjList[src].pop()
                dfs(dst)

            res.append(src)

        dfs("JFK")
        return res[::-1]


# Test helper
def test_find_itinerary():
    solution = Solution()

    # Test case 1: Example 1
    tickets1 = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    expected1 = ["JFK", "MUC", "LHR", "SFO", "SJC"]
    actual1 = solution.findItinerary(tickets1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    tickets2 = [
        ["JFK", "SFO"],
        ["JFK", "ATL"],
        ["SFO", "ATL"],
        ["ATL", "JFK"],
        ["ATL", "SFO"],
    ]
    expected2 = ["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"]
    actual2 = solution.findItinerary(tickets2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Single ticket
    tickets3 = [["JFK", "ABC"]]
    expected3 = ["JFK", "ABC"]
    actual3 = solution.findItinerary(tickets3)
    print(f"{actual3} | {expected3}")

    # Test case 4: Two tickets
    tickets4 = [["JFK", "A"], ["A", "JFK"]]
    expected4 = ["JFK", "A", "JFK"]
    actual4 = solution.findItinerary(tickets4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Multiple from JFK
    tickets5 = [["JFK", "A"], ["JFK", "B"], ["A", "JFK"]]
    expected5 = ["JFK", "A", "JFK", "B"]
    actual5 = solution.findItinerary(tickets5)
    print(f"{actual5} | {expected5}")


if __name__ == "__main__":
    test_find_itinerary()
