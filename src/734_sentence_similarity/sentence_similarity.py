from typing import List


class Solution:
    def areSentencesSimilar(
        self, sentence1: List[str], sentence2: List[str], similarPairs: List[List[str]]
    ) -> bool:
        """
        Determine if two sentences are similar based on similar word pairs.

        Args:
            sentence1: First sentence as a list of words
            sentence2: Second sentence as a list of words
            similarPairs: List of similar word pairs

        Returns:
            True if sentences are similar, False otherwise
        """

        if len(sentence1) != len(sentence2):
            return False

        pairs = set()
        for w1, w2 in similarPairs:
            pairs.add((w1, w2))
            pairs.add((w2, w1))

        for i in range(len(sentence1)):
            if sentence1[i] == sentence2[i]:
                continue
            if (sentence1[i], sentence2[i]) not in pairs:
                return False

        return True


def test_sentence_similarity():
    """Test cases for sentence similarity problem"""
    solution = Solution()

    # Test case 1: Basic similar sentences
    sentence1 = ["great", "acting", "skills"]
    sentence2 = ["fine", "drama", "talent"]
    similarPairs = [
        ["great", "good"],
        ["fine", "good"],
        ["acting", "drama"],
        ["skills", "talent"],
    ]
    expected = True
    result = solution.areSentencesSimilar(sentence1, sentence2, similarPairs)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")

    # Test case 2: Sentences with exact match words
    sentence1 = ["great"]
    sentence2 = ["great"]
    similarPairs = []
    expected = True
    result = solution.areSentencesSimilar(sentence1, sentence2, similarPairs)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")

    # Test case 3: Different lengths (not similar)
    sentence1 = ["great", "acting"]
    sentence2 = ["fine", "drama", "talent"]
    similarPairs = [["great", "fine"], ["acting", "drama"]]
    expected = False
    result = solution.areSentencesSimilar(sentence1, sentence2, similarPairs)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")

    # Test case 4: Words not similar and not identical
    sentence1 = ["hello", "world"]
    sentence2 = ["hallo", "welt"]
    similarPairs = []
    expected = False
    result = solution.areSentencesSimilar(sentence1, sentence2, similarPairs)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")

    # Test case 5: Similar pairs with transitive-like relationship
    sentence1 = ["this", "is", "a", "test"]
    sentence2 = ["this", "is", "a", "test"]
    similarPairs = [["apple", "orange"], ["banana", "grape"]]
    expected = True
    result = solution.areSentencesSimilar(sentence1, sentence2, similarPairs)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")

    # Test case 6: Mixed exact and similar pairs
    sentence1 = ["similar", "example", "test"]
    sentence2 = ["alike", "sample", "test"]
    similarPairs = [["similar", "alike"], ["example", "sample"]]
    expected = True
    result = solution.areSentencesSimilar(sentence1, sentence2, similarPairs)
    print(f"{result} | {expected} | {'PASS' if result == expected else 'FAIL'}")


if __name__ == "__main__":
    test_sentence_similarity()
