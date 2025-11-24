from typing import List


class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ""
        delimiter = "#"

        for s in strs:
            encoded = encoded + str(len(s)) + delimiter + s

        return encoded

    def decode(self, s: str) -> List[str]:
        decoded = []
        delimiter = "#"
        end = 0
        pointer = 0

        while pointer < len(s):
            while s[pointer] != delimiter:
                pointer += 1
            start = pointer + 1
            nextLength = int(s[end:pointer])
            end = start + nextLength
            decoded.append(s[start:end])
            pointer = end

        return decoded


def test_encode_decode_strings():
    solution = Solution()

    # Test case 1: Basic example
    strs1 = ["Hello", "World"]
    encoded1 = solution.encode(strs1)
    decoded1 = solution.decode(encoded1)
    print(f"Test 1: {strs1} -> {encoded1} -> {decoded1}")
    assert decoded1 == strs1, f"Expected {strs1}, got {decoded1}"

    # Test case 2: Empty string
    strs2 = [""]
    encoded2 = solution.encode(strs2)
    decoded2 = solution.decode(encoded2)
    print(f"Test 2: {strs2} -> {encoded2} -> {decoded2}")
    assert decoded2 == strs2, f"Expected {strs2}, got {decoded2}"

    # Test case 3: Empty list
    strs3 = []
    encoded3 = solution.encode(strs3)
    decoded3 = solution.decode(encoded3)
    print(f"Test 3: {strs3} -> {encoded3} -> {decoded3}")
    assert decoded3 == strs3, f"Expected {strs3}, got {decoded3}"

    # Test case 4: Strings with special characters
    strs4 = ["a#b", "c#d"]
    encoded4 = solution.encode(strs4)
    decoded4 = solution.decode(encoded4)
    print(f"Test 4: {strs4} -> {encoded4} -> {decoded4}")
    assert decoded4 == strs4, f"Expected {strs4}, got {decoded4}"

    # Test case 5: Multiple empty strings
    strs5 = ["", "", ""]
    encoded5 = solution.encode(strs5)
    decoded5 = solution.decode(encoded5)
    print(f"Test 5: {strs5} -> {encoded5} -> {decoded5}")
    assert decoded5 == strs5, f"Expected {strs5}, got {decoded5}"

    # Test case 6: Strings with numbers
    strs6 = ["123", "456", "789"]
    encoded6 = solution.encode(strs6)
    decoded6 = solution.decode(encoded6)
    print(f"Test 6: {strs6} -> {encoded6} -> {decoded6}")
    assert decoded6 == strs6, f"Expected {strs6}, got {decoded6}"

    # Test case 7: Mixed length strings
    strs7 = ["a", "ab", "abc", "abcd"]
    encoded7 = solution.encode(strs7)
    decoded7 = solution.decode(encoded7)
    print(f"Test 7: {strs7} -> {encoded7} -> {decoded7}")
    assert decoded7 == strs7, f"Expected {strs7}, got {decoded7}"

    print("All test cases passed!")


if __name__ == "__main__":
    test_encode_decode_strings()
