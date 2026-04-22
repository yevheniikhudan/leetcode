from typing import List


class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []

        for query in queries:
            for word in dictionary:
                dis = 0
                for i in range(len(query)):
                    if query[i] != word[i]:
                        dis += 1
                if dis <= 2:
                    ans.append(query)
                    break

        return ans


# Test cases
def test_solution():
    solution = Solution()

    # Test case 1
    queries1 = ["word", "note", "ants", "wood"]
    dictionary = ["wood", "joke", "moat"]
    result1 = solution.twoEditWords(queries1, dictionary)
    expected1 = ["word", "note", "wood"]
    print(f"{result1} | {expected1} | {'PASS' if result1 == expected1 else 'FAIL'}")


if __name__ == "__main__":
    test_solution()
