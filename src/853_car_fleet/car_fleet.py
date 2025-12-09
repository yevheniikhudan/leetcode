"""
853. Car Fleet

There are n cars going to the same destination along a one-lane road. The destination
is target miles away.

You are given two integer arrays position and speed, both of length n, where
position[i] is the position of the ith car and speed[i] is the speed of the ith car
(in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive
bumper to bumper at the same speed. The faster car will slow down to match the
slower car's speed. The distance between these two cars is ignored.

A car fleet is some non-empty set of cars driving at the same position and same speed.
Note that a single car is also a car fleet.

Return the number of car fleets that will arrive at the destination.
"""


class Solution:
    def carFleet(self, target: int, position: list[int], speed: list[int]) -> int:
        """
        Calculate the number of car fleets that arrive at the destination.

        Args:
            target: Distance to the destination in miles
            position: List of starting positions for each car
            speed: List of speeds for each car (miles per hour)

        Returns:
            Number of car fleets that arrive at the destination

        Time Complexity: O(n log n) where n = len(position)
        Space Complexity: O(n) for sorting and storing pairs
        """
        cars = sorted(zip(position, speed), reverse=True)

        stack = []

        for pos, spd in cars:
            time = (target - pos) / spd

            if not stack or time > stack[-1]:
                stack.append(time)

        return len(stack)


def test_car_fleet():
    solution = Solution()

    # Test case 1: Example 1
    result1 = solution.carFleet(12, [10, 8, 0, 5, 3], [2, 4, 1, 1, 3])
    print(f"Test 1: {result1} (expected: 3)")

    # Test case 2: Example 2 - Single car
    result2 = solution.carFleet(10, [3], [3])
    print(f"Test 2: {result2} (expected: 1)")

    # Test case 3: Example 3 - All cars merge into one fleet
    result3 = solution.carFleet(100, [0, 2, 4], [4, 2, 1])
    print(f"Test 3: {result3} (expected: 1)")

    # Test case 4: All separate fleets (times increase from closest to farthest)
    result4 = solution.carFleet(10, [8, 5, 0], [1, 2, 3])
    print(f"Test 4: {result4} (expected: 3)")

    # Test case 5: All same speed
    result5 = solution.carFleet(10, [6, 8], [3, 3])
    print(f"Test 5: {result5} (expected: 2)")

    # Test case 6: Two cars, faster behind
    result6 = solution.carFleet(10, [0, 5], [3, 2])
    print(f"Test 6: {result6} (expected: 2)")

    # Test case 7: Two cars, same arrival time
    result7 = solution.carFleet(10, [0, 4], [2, 1])
    print(f"Test 7: {result7} (expected: 1)")

    # Test case 8: Multiple fleets
    result8 = solution.carFleet(20, [6, 2, 17], [3, 9, 2])
    print(f"Test 8: {result8} (expected: 2)")


if __name__ == "__main__":
    test_car_fleet()
