class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        indices = {}
        for index, ch in enumerate(keyboard):
            indices[ch] = index

        ans = indices[word[0]]
        for i in range(1, len(word)):
            ans += abs(indices[word[i - 1]] - indices[word[i]])
        return ans


# Test cases
def test_solution():
    solution = Solution()

    # Test case 1
    keyboard1 = "abcdefghijklmnopqrstuvwxyz"
    word1 = "cba"
    result1 = solution.calculateTime(keyboard1, word1)
    expected1 = 4
    print(f"{result1} | {expected1} | {'PASS' if result1 == expected1 else 'FAIL'}")

    # Test case 2
    keyboard2 = "pqrstuvwxyzabcdefghijklmno"
    word2 = "leetcode"
    result2 = solution.calculateTime(keyboard2, word2)
    expected2 = 73
    print(f"{result2} | {expected2} | {'PASS' if result2 == expected2 else 'FAIL'}")

    # Test case 3
    keyboard3 = "abcdefghijklmnopqrstuvwxyz"
    word3 = "abc"
    result3 = solution.calculateTime(keyboard3, word3)
    expected3 = 2
    print(f"{result3} | {expected3} | {'PASS' if result3 == expected3 else 'FAIL'}")

    # Test case 4
    keyboard4 = "abcdefghijklmnopqrstuvwxyz"
    word4 = "a"
    result4 = solution.calculateTime(keyboard4, word4)
    expected4 = 0
    print(f"{result4} | {expected4} | {'PASS' if result4 == expected4 else 'FAIL'}")

    # Test case 5
    keyboard5 = "zyxwvutsrqponmlkjihgfedcba"
    word5 = "z"
    result5 = solution.calculateTime(keyboard5, word5)
    expected5 = 0
    print(f"{result5} | {expected5} | {'PASS' if result5 == expected5 else 'FAIL'}")


if __name__ == "__main__":
    test_solution()
