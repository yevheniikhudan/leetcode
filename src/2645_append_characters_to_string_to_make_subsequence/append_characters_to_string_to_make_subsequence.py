class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        """
        Find the minimum number of characters to append to s
        to make t a subsequence of s.

        Args:
            s: The original string
            t: The target string that should be a subsequence

        Returns:
            The number of characters to append
        """

        sPointer, tPointer = 0, 0

        while sPointer < len(s) and tPointer < len(t):
            # increment tPointer only if s[sPointer] == t[tPointer]
            if s[sPointer] == t[tPointer]:
                tPointer += 1

            # always increment sPointer
            sPointer += 1

        # return difference between tPointer and len(t)
        return len(t) - tPointer


# Test cases
def run_tests():
    solution = Solution()

    # Test case 1: Basic example
    s1 = "coaching"
    t1 = "coding"
    result1 = solution.appendCharacters(s1, t1)
    expected1 = 4
    print(f"{result1} | {expected1} | {'PASS' if result1 == expected1 else 'FAIL'}")

    # Test case 2: t is already subsequence
    s2 = "abcde"
    t2 = "a"
    result2 = solution.appendCharacters(s2, t2)
    expected2 = 0
    print(f"{result2} | {expected2} | {'PASS' if result2 == expected2 else 'FAIL'}")

    # Test case 3: s and t don't match
    s3 = "z"
    t3 = "abcde"
    result3 = solution.appendCharacters(s3, t3)
    expected3 = 5
    print(f"{result3} | {expected3} | {'PASS' if result3 == expected3 else 'FAIL'}")

    # Test case 4: t is already complete subsequence
    s4 = "aabbcc"
    t4 = "abc"
    result4 = solution.appendCharacters(s4, t4)
    expected4 = 0
    print(f"{result4} | {expected4} | {'PASS' if result4 == expected4 else 'FAIL'}")

    # Test case 5: Partial match
    s5 = "abc"
    t5 = "abcd"
    result5 = solution.appendCharacters(s5, t5)
    expected5 = 1
    print(f"{result5} | {expected5} | {'PASS' if result5 == expected5 else 'FAIL'}")

    # Test case 6: Single character match
    s6 = "a"
    t6 = "aa"
    result6 = solution.appendCharacters(s6, t6)
    expected6 = 1
    print(f"{result6} | {expected6} | {'PASS' if result6 == expected6 else 'FAIL'}")


if __name__ == "__main__":
    run_tests()
