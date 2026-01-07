from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def backtrack(s, left, right):
            if len(s) == 2 * n:
                res.append(s)
                return
            if left < n:
                backtrack(s + "(", left + 1, right)
            if right < left:
                backtrack(s + ")", left, right + 1)

        backtrack("", 0, 0)
        return res


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()
    print(
        sorted(sol.generateParenthesis(3)),
        "|",
        sorted(["((()))", "(()())", "(())()", "()(())", "()()()"]),
    )
    print(sorted(sol.generateParenthesis(1)), "|", sorted(["()"]))
    print(len(sol.generateParenthesis(4)), "|", 14)  # 4 pairs
