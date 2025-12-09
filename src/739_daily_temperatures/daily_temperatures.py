"""
739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return
an array answer such that answer[i] is the number of days you have to wait after
the ith day to get a warmer temperature. If there is no future day for which this
is possible, keep answer[i] == 0 instead.
"""

from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0] * n
        stack = []

        for index, temperature in enumerate(temperatures):
            while stack and temperature > stack[-1][1]:
                stackIndex, _ = stack.pop()
                result[stackIndex] = index - stackIndex

            stack.append([index, temperature])

        return result

    def dailyTemperaturesDP(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0] * n

        for i in range(n - 2, -1, -1):
            j = i + 1
            while j < n and temperatures[j] <= temperatures[i]:
                if result[j] == 0:
                    j = n
                    break
                j += result[j]

            if j < n:
                result[i] = j - i

        return result

    def dailyTemperaturesBruteForce(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0] * n

        for i in range(n):
            for j in range(i + 1, n):
                if temperatures[j] > temperatures[i]:
                    result[i] = j - i
                    break

        return result


def test_daily_temperatures():
    solution = Solution()

    # Test case 1: Example 1
    temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
    result = solution.dailyTemperatures(temperatures)
    expected = [1, 1, 4, 2, 1, 1, 0, 0]
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2
    temperatures = [30, 40, 50, 60]
    result = solution.dailyTemperatures(temperatures)
    expected = [1, 1, 1, 0]
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: Example 3
    temperatures = [30, 60, 90]
    result = solution.dailyTemperatures(temperatures)
    expected = [1, 1, 0]
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: All decreasing
    temperatures = [100, 90, 80, 70]
    result = solution.dailyTemperatures(temperatures)
    expected = [0, 0, 0, 0]
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: All increasing
    temperatures = [30, 40, 50, 60, 70]
    result = solution.dailyTemperatures(temperatures)
    expected = [1, 1, 1, 1, 0]
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: Single day
    temperatures = [75]
    result = solution.dailyTemperatures(temperatures)
    expected = [0]
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: All same temperatures
    temperatures = [70, 70, 70, 70]
    result = solution.dailyTemperatures(temperatures)
    expected = [0, 0, 0, 0]
    print(f"Test 7: {result} (expected: {expected})")

    # Test case 8: Spike pattern
    temperatures = [30, 100, 30, 100, 30]
    result = solution.dailyTemperatures(temperatures)
    expected = [1, 0, 1, 0, 0]
    print(f"Test 8: {result} (expected: {expected})")

    # Test case 9: Valley pattern
    temperatures = [90, 30, 90, 30, 90]
    result = solution.dailyTemperatures(temperatures)
    expected = [0, 1, 0, 1, 0]
    print(f"Test 9: {result} (expected: {expected})")

    # Test case 10: Mixed pattern
    temperatures = [55, 38, 53, 81, 61, 93, 97, 32, 43, 78]
    result = solution.dailyTemperatures(temperatures)
    expected = [3, 1, 1, 2, 1, 1, 0, 1, 1, 0]
    print(f"Test 10: {result} (expected: {expected})")


if __name__ == "__main__":
    test_daily_temperatures()
