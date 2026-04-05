class Solution:
    def countBits(self, n: int) -> list[int]:
        res = []

        for i in range(n + 1):
            count = 0
            while i != 0:
                count += i & 1
                i >>= 1

            res.append(count)

        return res


def print_result(actual, expected):
    status = "PASS" if actual == expected else "FAIL"
    print(f"{actual} | {expected} | {status}")


if __name__ == "__main__":
    sol = Solution()

    # Test cases
    test_cases = [
        (2, [0, 1, 1]),
        (5, [0, 1, 1, 2, 1, 2]),
        (0, [0]),
        (1, [0, 1]),
        (10, [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2]),
    ]

    for n, expected in test_cases:
        actual = sol.countBits(n)
        print_result(actual, expected)
