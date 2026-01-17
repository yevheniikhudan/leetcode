from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1


def test():
    arr = list("hello")
    Solution().reverseString(arr)
    print(arr, "| ['o','l','l','e','h']")
    arr = list("a")
    Solution().reverseString(arr)
    print(arr, "| ['a']")
    arr = list("")
    Solution().reverseString(arr)
    print(arr, "| []")
    arr = list("ab")
    Solution().reverseString(arr)
    print(arr, "| ['b','a']")
    arr = list("racecar")
    Solution().reverseString(arr)
    print(arr, "| ['r','a','c','e','c','a','r']")


if __name__ == "__main__":
    test()
