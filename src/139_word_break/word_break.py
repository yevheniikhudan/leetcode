from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True

        for i in range(len(s)):
            if not dp[i]:
                continue
            for word in wordDict:
                if s[i : i + len(word)] != word:
                    continue

                dp[i + len(word)] = True

        return dp[n]

    def wordBreakTopDown(self, s: str, wordDict: List[str]) -> bool:
        memo = {}

        def dfs(i):
            if i in memo:
                return memo[i]

            if i == len(s):
                return True

            for word in wordDict:
                if s[i : i + len(word)] != word:
                    continue

                memo[i] = dfs(i + len(word))

                if memo[i]:
                    return True

            memo[i] = False
            return memo[i]

        return dfs(0)


# Test helper
def test_word_break():
    solution = Solution()

    # Test case 1: Example 1
    s1 = "leetcode"
    wordDict1 = ["leet", "code"]
    expected1 = True
    actual1 = solution.wordBreak(s1, wordDict1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    s2 = "applepenapple"
    wordDict2 = ["apple", "pen"]
    expected2 = True
    actual2 = solution.wordBreak(s2, wordDict2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Example 3
    s3 = "catsandog"
    wordDict3 = ["cats", "dog", "sand", "and", "cat"]
    expected3 = False
    actual3 = solution.wordBreak(s3, wordDict3)
    print(f"{actual3} | {expected3}")

    # Test case 4: Single word
    s4 = "a"
    wordDict4 = ["a"]
    expected4 = True
    actual4 = solution.wordBreak(s4, wordDict4)
    print(f"{actual4} | {expected4}")

    # Test case 5: No match
    s5 = "abc"
    wordDict5 = ["d", "e"]
    expected5 = False
    actual5 = solution.wordBreak(s5, wordDict5)
    print(f"{actual5} | {expected5}")

    # Test case 6: Reuse words
    s6 = "aaaa"
    wordDict6 = ["a", "aa"]
    expected6 = True
    actual6 = solution.wordBreak(s6, wordDict6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_word_break()
