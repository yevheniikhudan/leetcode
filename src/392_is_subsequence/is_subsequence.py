class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = j = 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
            j += 1
        return i == len(s)


# Test Helper
def test_solution():
    solution = Solution()

    # Test Case 1: Basic subsequence
    s1 = "abc"
    t1 = "ahbgdc"
    result1 = solution.isSubsequence(s1, t1)
    expected1 = True
    print(f"{result1} | {expected1} | {'PASS' if result1 == expected1 else 'FAIL'}")

    # Test Case 2: Not a subsequence
    s2 = "axc"
    t2 = "ahbgdc"
    result2 = solution.isSubsequence(s2, t2)
    expected2 = False
    print(f"{result2} | {expected2} | {'PASS' if result2 == expected2 else 'FAIL'}")

    # Test Case 3: Empty s
    s3 = ""
    t3 = "ahbgdc"
    result3 = solution.isSubsequence(s3, t3)
    expected3 = True
    print(f"{result3} | {expected3} | {'PASS' if result3 == expected3 else 'FAIL'}")

    # Test Case 4: Empty t with non-empty s
    s4 = "a"
    t4 = ""
    result4 = solution.isSubsequence(s4, t4)
    expected4 = False
    print(f"{result4} | {expected4} | {'PASS' if result4 == expected4 else 'FAIL'}")

    # Test Case 5: Identical strings
    s5 = "abc"
    t5 = "abc"
    result5 = solution.isSubsequence(s5, t5)
    expected5 = True
    print(f"{result5} | {expected5} | {'PASS' if result5 == expected5 else 'FAIL'}")

    # Test Case 6: s longer than t
    s6 = "abcd"
    t6 = "abc"
    result6 = solution.isSubsequence(s6, t6)
    expected6 = False
    print(f"{result6} | {expected6} | {'PASS' if result6 == expected6 else 'FAIL'}")


if __name__ == "__main__":
    test_solution()
