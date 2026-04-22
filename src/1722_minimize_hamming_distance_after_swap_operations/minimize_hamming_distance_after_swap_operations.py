from collections import defaultdict
from typing import List


class DSU:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, n: int) -> int:
        if self.parent[n] != n:
            self.parent[n] = self.find(self.parent[n])
        return self.parent[n]

    def union(self, n1: int, n2: int) -> bool:
        x = self.find(n1)
        y = self.find(n2)

        if x == y:
            return False

        if self.rank[x] < self.rank[y]:
            x, y = y, x

        self.parent[y] = x
        if self.rank[x] == self.rank[y]:
            self.rank[x] += 1

        return True


class Solution:
    def minimumHammingDistance(
        self, source: List[int], target: List[int], allowedSwaps: List[List[int]]
    ) -> int:
        """
        Minimize the hamming distance after performing allowed swaps.

        Args:
            source: Source array
            target: Target array
            allowedSwaps: List of allowed swap pairs (indices)

        Returns:
            Minimum hamming distance achievable
        """
        n = len(source)
        dsu = DSU(n)
        for a, b in allowedSwaps:
            dsu.union(a, b)

        sets = defaultdict(int)
        for i in range(n):
            f = dsu.find(i)
            sets[(f, source[i])] += 1

        ans = 0
        for i in range(n):
            f = dsu.find(i)
            if sets[(f, target[i])] > 0:
                sets[(f, target[i])] -= 1
            else:
                ans += 1
        return ans


def test_minimize_hamming_distance():
    """Test cases for minimize hamming distance problem"""
    solution = Solution()

    # Test case 1: Basic example with allowed swaps
    source = [1, 2, 3, 4]
    target = [2, 1, 4, 5]
    allowedSwaps = [[0, 1], [2, 3]]
    expected = 1
    result = solution.minimumHammingDistance(source, target, allowedSwaps)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")

    # Test case 2: No swaps allowed
    source = [1, 2, 3]
    target = [4, 5, 6]
    allowedSwaps = []
    expected = 3
    result = solution.minimumHammingDistance(source, target, allowedSwaps)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")

    # Test case 3: All positions can be swapped with transitive connections
    source = [5, 1, 2, 4, 3]
    target = [1, 5, 4, 2, 3]
    allowedSwaps = [[0, 4], [4, 2], [1, 3], [1, 4], [3, 2]]
    expected = 0
    result = solution.minimumHammingDistance(source, target, allowedSwaps)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")

    # Test case 4: Identical source and target
    source = [1, 2, 3, 4]
    target = [1, 2, 3, 4]
    allowedSwaps = [[0, 1]]
    expected = 0
    result = solution.minimumHammingDistance(source, target, allowedSwaps)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")

    # Test case 5: Single element, different values
    source = [1]
    target = [2]
    allowedSwaps = []
    expected = 1
    result = solution.minimumHammingDistance(source, target, allowedSwaps)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")


if __name__ == "__main__":
    test_minimize_hamming_distance()
