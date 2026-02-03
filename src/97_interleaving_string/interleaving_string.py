class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False

        dp = {}

        def dfs(i, j, k):
            if k == len(s3):
                return i == len(s1) and j == len(s2)
            if (i, j) in dp:
                return dp[(i, j)]

            res = False
            if i < len(s1) and s1[i] == s3[k]:
                res = dfs(i + 1, j, k + 1)
            if not res and j < len(s2) and s2[j] == s3[k]:
                res = dfs(i, j + 1, k + 1)

            dp[(i, j)] = res
            return res

        return dfs(0, 0, 0)


def test_isInterleave():
    sol = Solution()
    # Test case 1: Example 1
    print(f"{sol.isInterleave('aabcc', 'dbbca', 'aadbbcbcac')} | True")
    # Test case 2: Example 2
    print(f"{sol.isInterleave('aabcc', 'dbbca', 'aadbbbaccc')} | False")
    # Test case 3: Example 3
    print(f"{sol.isInterleave('', '', '')} | True")
    # Test case 4: One empty
    print(f"{sol.isInterleave('a', '', 'a')} | True")
    # Test case 5: No match
    print(f"{sol.isInterleave('a', 'b', 'ab')} | True")
    # Test case 6: Length mismatch
    print(f"{sol.isInterleave('a', 'b', 'abc')} | False")


if __name__ == "__main__":
    test_isInterleave()
