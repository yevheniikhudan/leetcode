"""
875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the i-th pile has
piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses
some pile of bananas and eats k bananas from that pile. If the pile has less
than k bananas, she eats all of them instead and will not eat any more bananas
during this hour.

Return the minimum integer k such that she can eat all the bananas within h hours.
"""

from math import ceil
from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        """
        Find minimum eating speed to finish all bananas within h hours.

        Args:
            piles: List of banana pile sizes
            h: Hours available

        Returns:
            Minimum eating speed k

        Time Complexity: O(n log m) where n = len(piles), m = max(piles)
        Space Complexity: O(1) - only constant extra space
        """
        left = 1
        right = max(piles)

        def canFinish(speed):
            hours = 0
            for pile in piles:
                hours += ceil(pile / speed)
            return hours <= h

        while left < right:
            mid = left + (right - left) // 2

            if canFinish(mid):
                right = mid
            else:
                left = mid + 1

        return left


def test_min_eating_speed():
    solution = Solution()

    # Test case 1: Example 1
    result1 = solution.minEatingSpeed([3, 6, 7, 11], 8)
    print(f"Test 1: {result1} (expected: 4)")

    # Test case 2: Example 2 - must eat one pile per hour
    result2 = solution.minEatingSpeed([30, 11, 23, 4, 20], 5)
    print(f"Test 2: {result2} (expected: 30)")

    # Test case 3: Example 3
    result3 = solution.minEatingSpeed([30, 11, 23, 4, 20], 6)
    print(f"Test 3: {result3} (expected: 23)")

    # Test case 4: Single pile
    result4 = solution.minEatingSpeed([1000000000], 2)
    print(f"Test 4: {result4} (expected: 500000000)")

    # Test case 5: Many hours available
    result5 = solution.minEatingSpeed([3, 6, 7, 11], 100)
    print(f"Test 5: {result5} (expected: 1)")

    # Test case 6: Exact hours match piles
    result6 = solution.minEatingSpeed([5, 10, 15, 20], 4)
    print(f"Test 6: {result6} (expected: 20)")

    # Test case 7: All same size piles
    result7 = solution.minEatingSpeed([10, 10, 10, 10], 10)
    print(f"Test 7: {result7} (expected: 5)")

    # Test case 8: Small piles, exact hours match piles
    result8 = solution.minEatingSpeed([1, 1, 1, 1], 4)
    print(f"Test 8: {result8} (expected: 1)")


if __name__ == "__main__":
    test_min_eating_speed()
