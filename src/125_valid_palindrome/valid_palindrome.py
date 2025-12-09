class Solution:
    """
    Valid Palindrome

    Check if a string is a palindrome after converting to lowercase and removing non-alphanumeric characters.
    """

    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1

        while left < right:
            while left < right and not self.isAlphaNum(s[left]):
                left += 1
            while left < right and not self.isAlphaNum(s[right]):
                right -= 1
            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True

    def isAlphaNum(self, c: str) -> bool:
        return (
            ord("A") <= ord(c) <= ord("Z")
            or ord("a") <= ord(c) <= ord("z")
            or ord("0") <= ord(c) <= ord("9")
        )


def test_valid_palindrome():
    solution = Solution()

    # Test case 1
    s1 = "A man, a plan, a canal: Panama"
    result1 = solution.isPalindrome(s1)
    print(f"Test 1: '{s1}' -> {result1}")
    assert result1 == True, f"Expected True, got {result1}"

    # Test case 2
    s2 = "race a car"
    result2 = solution.isPalindrome(s2)
    print(f"Test 2: '{s2}' -> {result2}")
    assert result2 == False, f"Expected False, got {result2}"

    # Test case 3
    s3 = " "
    result3 = solution.isPalindrome(s3)
    print(f"Test 3: '{s3}' -> {result3}")
    assert result3 == True, f"Expected True, got {result3}"

    # Test case 4: Single character
    s4 = "a"
    result4 = solution.isPalindrome(s4)
    print(f"Test 4: '{s4}' -> {result4}")
    assert result4 == True, f"Expected True, got {result4}"

    # Test case 5: With numbers
    s5 = "0P"
    result5 = solution.isPalindrome(s5)
    print(f"Test 5: '{s5}' -> {result5}")
    assert result5 == False, f"Expected False, got {result5}"

    # Test case 6: Empty after filtering
    s6 = ".,;"
    result6 = solution.isPalindrome(s6)
    print(f"Test 6: '{s6}' -> {result6}")
    assert result6 == True, f"Expected True, got {result6}"

    print("All test cases passed!")


if __name__ == "__main__":
    test_valid_palindrome()
