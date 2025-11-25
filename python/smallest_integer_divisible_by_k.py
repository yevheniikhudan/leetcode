class Solution:
    """
    Smallest Integer Divisible by K

    Given a positive integer k, find the length of the smallest positive
    integer n such that n is divisible by k, and n only contains the digit 1.
    """

    def smallestRepunitDivByK(self, k: int) -> int:
        if k == 1:
            return 1

        if k % 2 == 0 or k % 5 == 0:
            return -1

        remainder = 0
        for i in range(1, k + 1):
            remainder = (remainder * 10 + 1) % k
            if remainder == 0:
                return i

        return -1


def test_smallest_integer_divisible_by_k():
    solution = Solution()

    # Test case 1: k = 1
    k1 = 1
    result1 = solution.smallestRepunitDivByK(k1)
    print(f"Test 1: k = {k1}, Output = {result1}")
    assert result1 == 1, f"Expected 1, got {result1}"

    # Test case 2: k = 2 (no solution - even number)
    k2 = 2
    result2 = solution.smallestRepunitDivByK(k2)
    print(f"Test 2: k = {k2}, Output = {result2}")
    assert result2 == -1, f"Expected -1, got {result2}"

    # Test case 3: k = 3
    k3 = 3
    result3 = solution.smallestRepunitDivByK(k3)
    print(f"Test 3: k = {k3}, Output = {result3}")
    assert result3 == 3, f"Expected 3, got {result3}"

    # Test case 4: k = 7
    k4 = 7
    result4 = solution.smallestRepunitDivByK(k4)
    print(f"Test 4: k = {k4}, Output = {result4}")
    assert result4 == 6, f"Expected 6, got {result4}"

    # Test case 5: k = 5 (no solution - divisible by 5)
    k5 = 5
    result5 = solution.smallestRepunitDivByK(k5)
    print(f"Test 5: k = {k5}, Output = {result5}")
    assert result5 == -1, f"Expected -1, got {result5}"

    # Test case 6: k = 9
    k6 = 9
    result6 = solution.smallestRepunitDivByK(k6)
    print(f"Test 6: k = {k6}, Output = {result6}")
    assert result6 == 9, f"Expected 9, got {result6}"

    # Test case 7: k = 17
    k7 = 17
    result7 = solution.smallestRepunitDivByK(k7)
    print(f"Test 7: k = {k7}, Output = {result7}")
    assert result7 == 16, f"Expected 16, got {result7}"

    print("All test cases passed!")


if __name__ == "__main__":
    test_smallest_integer_divisible_by_k()
