from typing import List

class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        return ''.join(word1) == ''.join(word2)

def test():
    sol = Solution()
    print(sol.arrayStringsAreEqual(["ab", "c"], ["a", "bc"]), "| True")
    print(sol.arrayStringsAreEqual(["a", "cb"], ["ab", "c"]), "| False")
    print(sol.arrayStringsAreEqual(["abc", "d", "defg"], ["abcddefg"]), "| True")
    print(sol.arrayStringsAreEqual([""], [""]), "| True")
    print(sol.arrayStringsAreEqual(["a", "b", "c"], ["abc"]), "| True")

if __name__ == "__main__":
    test()
