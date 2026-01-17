class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(word[::-1] for word in s.split(" "))


def test():
    sol = Solution()
    print(
        sol.reverseWords("Let's take LeetCode contest"), "| s'teL ekat edoCteeL tsetnoc"
    )
    print(sol.reverseWords("God Ding"), "| doG gniD")
    print(sol.reverseWords("a b c"), "| a b c")
    print(sol.reverseWords("  hello world  "), "|   olleh dlrow  ")
    print(sol.reverseWords(""), "| ")


if __name__ == "__main__":
    test()
