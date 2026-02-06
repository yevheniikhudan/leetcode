class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)

        if m > n:
            return 0

        memo = {}

        def dfs(i, j):
            if j == m:
                return 1
            if i == n:
                return 0
            if (i, j) in memo:
                return memo[(i, j)]

            # skip
            res = dfs(i + 1, j)
            if s[i] == t[j]:
                res += dfs(i + 1, j + 1)

            memo[(i, j)] = res
            return res

        return dfs(0, 0)


def test_numDistinct():
    sol = Solution()
    # Test case 1: Example 1
    print(f"{sol.numDistinct('rabbbit', 'rabbit')} | 3")
    # Test case 2: Example 2
    print(f"{sol.numDistinct('babgbag', 'bag')} | 5")
    # Test case 3: t empty
    print(f"{sol.numDistinct('a', '')} | 1")
    # Test case 4: s empty
    print(f"{sol.numDistinct('', 'a')} | 0")
    # Test case 5: Exact match
    print(f"{sol.numDistinct('abc', 'abc')} | 1")
    # Test case 6: Multiple ways
    print(f"{sol.numDistinct('aaa', 'aa')} | 3")


if __name__ == "__main__":
    test_numDistinct()
