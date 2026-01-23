from typing import List
from collections import Counter


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        counts = Counter(chars)
        result = 0

        for word in words:
            wordCounts = Counter(word)

            if any([counts[key] < wordCounts[key] for key in wordCounts.keys()]):
                continue

            result += len(word)

        return result


# Test helper
def test_count_characters():
    solution = Solution()

    # Test case 1: Example 1
    words1 = ["cat", "bt", "hat", "tree"]
    chars1 = "atach"
    expected1 = 6
    actual1 = solution.countCharacters(words1, chars1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    words2 = ["hello", "world", "leetcode"]
    chars2 = "welldonehoneyr"
    expected2 = 10
    actual2 = solution.countCharacters(words2, chars2)
    print(f"{actual2} | {expected2}")

    # Test case 3: No good words
    words3 = ["abc", "def"]
    chars3 = "xyz"
    expected3 = 0
    actual3 = solution.countCharacters(words3, chars3)
    print(f"{actual3} | {expected3}")

    # Test case 4: All words good
    words4 = ["a", "b"]
    chars4 = "ab"
    expected4 = 2
    actual4 = solution.countCharacters(words4, chars4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Words with duplicates
    words5 = ["aa", "bb"]
    chars5 = "aab"
    expected5 = 2  # "aa" uses a,a; "bb" uses b,b but only one b
    actual5 = solution.countCharacters(words5, chars5)
    print(f"{actual5} | {expected5}")

    # Test case 6: Single word
    words6 = ["test"]
    chars6 = "tset"
    expected6 = 4
    actual6 = solution.countCharacters(words6, chars6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_count_characters()
