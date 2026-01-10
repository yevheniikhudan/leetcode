from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        numbersToLetters = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def dfs(index, s):
            if len(s) == len(digits):
                res.append(s)
                return

            for c in numbersToLetters[digits[index]]:
                dfs(index + 1, s + c)

        if digits:
            dfs(0, "")

        return res


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()
    tests = [
        ("23", ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]),
        ("", []),
        ("2", ["a", "b", "c"]),
        ("7", ["p", "q", "r", "s"]),
        ("9", ["w", "x", "y", "z"]),
    ]
    for i, (digits, expected) in enumerate(tests, 1):
        result = sol.letterCombinations(digits)
        print(f"Test {i}: {sorted(result)} | {sorted(expected)}")
