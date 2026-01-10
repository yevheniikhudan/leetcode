from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res, part = [], []

        def dfs(start):
            if start == len(s):
                res.append(part[:])
                return

            for end in range(start, len(s)):
                if self.isPalindrome(s, start, end):
                    part.append(s[start : end + 1])
                    dfs(end + 1)
                    part.pop()

        dfs(0)

        return res

    def isPalindrome(self, s, left, right):
        while left < right:
            if s[left] != s[right]:
                return False

            left += 1
            right -= 1

        return True


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()
    tests = [
        ("aab", [["a", "a", "b"], ["aa", "b"]]),
        ("a", [["a"]]),
        (
            "racecar",
            [
                ["r", "a", "c", "e", "c", "a", "r"],
                ["r", "a", "cec", "a", "r"],
                ["r", "aceca", "r"],
                ["racecar"],
            ],
        ),
        ("abba", [["a", "b", "b", "a"], ["a", "bb", "a"], ["abba"]]),
        ("abc", [["a", "b", "c"]]),
    ]
    for i, (s, expected) in enumerate(tests, 1):
        result = sol.partition(s)
        print(f"Test {i}: {result} | {expected}")
