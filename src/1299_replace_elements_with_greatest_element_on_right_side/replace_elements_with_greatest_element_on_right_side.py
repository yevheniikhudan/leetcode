from typing import List


class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        max = arr[-1]
        arr[-1] = -1

        for i in range(len(arr) - 2, -1, -1):
            temp = arr[i]
            arr[i] = max
            if temp > max:
                max = temp

        return arr


def test_replace_elements():
    solution = Solution()

    # Test 1: Example from problem
    arr1 = [17, 18, 5, 4, 6, 1]
    result1 = solution.replaceElements(arr1)
    expected1 = [18, 6, 6, 6, 1, -1]
    print(f"{result1} | {expected1} | {'PASS' if result1 == expected1 else 'FAIL'}")

    # Test 2: Single element
    arr2 = [400]
    result2 = solution.replaceElements(arr2)
    expected2 = [-1]
    print(f"{result2} | {expected2} | {'PASS' if result2 == expected2 else 'FAIL'}")

    # Test 3: Strictly increasing
    arr3 = [1, 2, 3, 4, 5]
    result3 = solution.replaceElements(arr3)
    expected3 = [5, 5, 5, 5, -1]
    print(f"{result3} | {expected3} | {'PASS' if result3 == expected3 else 'FAIL'}")

    # Test 4: Strictly decreasing
    arr4 = [5, 4, 3, 2, 1]
    result4 = solution.replaceElements(arr4)
    expected4 = [4, 3, 2, 1, -1]
    print(f"{result4} | {expected4} | {'PASS' if result4 == expected4 else 'FAIL'}")

    # Test 5: All same elements
    arr5 = [3, 3, 3, 3]
    result5 = solution.replaceElements(arr5)
    expected5 = [3, 3, 3, -1]
    print(f"{result5} | {expected5} | {'PASS' if result5 == expected5 else 'FAIL'}")


if __name__ == "__main__":
    test_replace_elements()
