from collections import defaultdict
from typing import List


class DetectSquares:
    def __init__(self):
        """
        Initialize the DetectSquares data structure.

        Skeleton: no implementation here. Replace `pass` with actual logic.
        """
        self.points = defaultdict(int)
        self.x_coords = defaultdict(set)

    def add(self, point: List[int]) -> None:
        """
        Add a point to the data structure.

        Args:
            point: A list [x, y] representing a coordinate.
        """
        x, y = point
        self.points[(x, y)] += 1
        self.x_coords[x].add(y)

    def count(self, point: List[int]) -> int:
        px, py = point
        result = 0

        for y in self.x_coords[px]:
            if py == y:
                continue

            side = abs(py - y)
            # Frequency of the vertical point (same x-coordinate)
            freq_vert = self.points[(px, y)]

            if (px + side, py) in self.points and (px + side, y) in self.points:
                result += (
                    freq_vert
                    * self.points[(px + side, py)]
                    * self.points[(px + side, y)]
                )

            if (px - side, py) in self.points and (px - side, y) in self.points:
                result += (
                    freq_vert
                    * self.points[(px - side, py)]
                    * self.points[(px - side, y)]
                )

        return result


def run_tests() -> None:
    # Test case 1: Basic square detection
    ds1 = DetectSquares()
    ds1.add([8, 7])
    ds1.add([9, 9])
    ds1.add([7, 8])
    ds1.add([9, 7])
    result1 = ds1.count([8, 9])
    expected1 = 1
    print(f"{result1} | {expected1} | {'PASS' if result1 == expected1 else 'FAIL'}")

    # Test case 2: No square formed
    ds2 = DetectSquares()
    ds2.add([1, 1])
    ds2.add([1, 2])
    result2 = ds2.count([2, 2])
    expected2 = 0
    print(f"{result2} | {expected2} | {'PASS' if result2 == expected2 else 'FAIL'}")

    # Test case 3: Unit square
    ds3 = DetectSquares()
    ds3.add([0, 0])
    ds3.add([1, 1])
    ds3.add([1, 0])
    ds3.add([0, 1])
    result3 = ds3.count([1, 1])
    expected3 = 1
    print(f"{result3} | {expected3} | {'PASS' if result3 == expected3 else 'FAIL'}")

    # Test case 4: Larger square
    ds4 = DetectSquares()
    ds4.add([0, 0])
    ds4.add([2, 2])
    ds4.add([2, 0])
    ds4.add([0, 2])
    result4 = ds4.count([2, 2])
    expected4 = 1
    print(f"{result4} | {expected4} | {'PASS' if result4 == expected4 else 'FAIL'}")

    # Test case 5: Multiple potential squares
    ds5 = DetectSquares()
    ds5.add([1, 1])
    ds5.add([1, 2])
    ds5.add([2, 1])
    ds5.add([2, 2])
    result5 = ds5.count([1, 1])
    expected5 = 1
    print(f"{result5} | {expected5} | {'PASS' if result5 == expected5 else 'FAIL'}")


if __name__ == "__main__":
    run_tests()
