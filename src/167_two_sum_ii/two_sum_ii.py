class Solution:
    """
    Two Sum II - Input Array Is Sorted

    Find two numbers in a sorted array that add up to target. Return 1-indexed positions.
    """

    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        left, right = 0, len(numbers) - 1

        while left < right:
            cur = numbers[left] + numbers[right]

            if cur == target:
                return [left + 1, right + 1]
            elif cur < target:
                left += 1
            elif cur > target:
                right -= 1

        return [-1, -1]


def test_two_sum_ii():
    solution = Solution()

    # Test case 1
    numbers1 = [2, 7, 11, 15]
    target1 = 9
    result1 = solution.twoSum(numbers1, target1)
    print(f"Test 1: numbers={numbers1}, target={target1} -> {result1}")
    assert result1 == [1, 2], f"Expected [1,2], got {result1}"

    # Test case 2
    numbers2 = [2, 3, 4]
    target2 = 6
    result2 = solution.twoSum(numbers2, target2)
    print(f"Test 2: numbers={numbers2}, target={target2} -> {result2}")
    assert result2 == [1, 3], f"Expected [1,3], got {result2}"

    # Test case 3
    numbers3 = [-1, 0]
    target3 = -1
    result3 = solution.twoSum(numbers3, target3)
    print(f"Test 3: numbers={numbers3}, target={target3} -> {result3}")
    assert result3 == [1, 2], f"Expected [1,2], got {result3}"

    # Test case 4: Larger array
    numbers4 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    target4 = 17
    result4 = solution.twoSum(numbers4, target4)
    print(f"Test 4: numbers={numbers4}, target={target4} -> {result4}")
    assert result4 == [8, 9], f"Expected [8,9], got {result4}"

    # Test case 5: Negative numbers
    numbers5 = [-5, -3, -1, 0, 2, 4]
    target5 = -4
    result5 = solution.twoSum(numbers5, target5)
    print(f"Test 5: numbers={numbers5}, target={target5} -> {result5}")
    assert result5 == [2, 3], f"Expected [2,3], got {result5}"

    print("All test cases passed!")


if __name__ == "__main__":
    test_two_sum_ii()
