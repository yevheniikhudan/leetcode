from typing import List
from collections import defaultdict, deque


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList or beginWord == endWord:
            return 0
        adjList = defaultdict(list)

        for word in wordList:
            for i in range(len(word)):
                adjList[self._pattern(word, i)].append(word)

        q = deque([beginWord])
        visit = set([beginWord])
        result = 1

        while q:
            for _ in range(len(q)):
                word = q.popleft()

                if word == endWord:
                    return result

                for i in range(len(word)):
                    pattern = self._pattern(word, i)

                    for adj in adjList[pattern]:
                        if adj not in visit:
                            q.append(adj)
                            visit.add(adj)

            result += 1

        return 0

    def _pattern(self, word, i):
        return word[:i] + "*" + word[i + 1 :]


# Test scaffolding
def test():
    sol = Solution()
    print(
        sol.ladderLength("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]),
        "| 5",
    )
    print(sol.ladderLength("hit", "cog", ["hot", "dot", "dog", "lot", "log"]), "| 0")
    print(sol.ladderLength("a", "c", ["a", "b", "c"]), "| 2")
    print(
        sol.ladderLength(
            "red", "tax", ["ted", "tex", "red", "tax", "tad", "den", "rex", "pee"]
        ),
        "| 4",
    )


if __name__ == "__main__":
    test()
