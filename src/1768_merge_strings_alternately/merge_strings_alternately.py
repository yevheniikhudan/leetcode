class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        n1, n2 = len(word1), len(word2)
        res = []

        for i in range(max(n1, n2)):
            if i < n1:
                res.append(word1[i])
            if i < n2:
                res.append(word2[i])

        return "".join(res)


# Test scaffolding
if __name__ == "__main__":
    print(Solution().mergeAlternately("abc", "pqr"))  # "apbqcr"
    print(Solution().mergeAlternately("ab", "pqrs"))  # "apbqrs"
    print(Solution().mergeAlternately("abcd", "pq"))  # "apbqcd"
    print(Solution().mergeAlternately("a", "z"))  # "az"
    print(Solution().mergeAlternately("abcde", ""))  # "abcde"
