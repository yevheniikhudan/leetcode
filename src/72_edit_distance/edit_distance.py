class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        memo = {}

        def dfs(i, j):
            if i == len(word1):
                return len(word2) - j
            if j == len(word2):
                return len(word1) - i
            if (i, j) in memo:
                return memo[(i, j)]

            if word1[i] == word2[j]:
                return dfs(i + 1, j + 1)

            res = min(1 + dfs(i + 1, j + 1), 1 + dfs(i + 1, j), 1 + dfs(i, j + 1))
            memo[(i, j)] = res
            return res

        return dfs(0, 0)


def test_minDistance():
    sol = Solution()
    # Test case 1: Example 1
    print(f"{sol.minDistance('horse', 'ros')} | 3")
    # Test case 2: Example 2
    print(f"{sol.minDistance('intention', 'execution')} | 5")
    # Test case 3: Empty word1
    print(f"{sol.minDistance('', 'a')} | 1")
    # Test case 4: Empty word2
    print(f"{sol.minDistance('a', '')} | 1")
    # Test case 5: Identical
    print(f"{sol.minDistance('abc', 'abc')} | 0")
    # Test case 6: Single replace
    print(f"{sol.minDistance('a', 'b')} | 1")


if __name__ == "__main__":
    test_minDistance()
