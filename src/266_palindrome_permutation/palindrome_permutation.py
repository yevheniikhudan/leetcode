class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        # TODO: Implement the solution.
        return False


def run_test(s: str, expected: bool) -> None:
    actual = Solution().canPermutePalindrome(s)
    status = "PASS" if actual == expected else "FAIL"
    print(f"{actual} | {expected} | {status}")


if __name__ == "__main__":
    run_test("code", False)
    run_test("aab", True)
    run_test("carerac", True)
    run_test("a", True)
    run_test("abc", False)
