class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def nextValidChar(st, index):
            backspace = 0
            while index >= 0:
                if backspace == 0 and st[index] != "#":
                    break
                elif st[index] == "#":
                    backspace += 1
                else:
                    backspace -= 1
                index -= 1
            return index

        index_s, index_t = len(s) - 1, len(t) - 1

        while index_s >= 0 or index_t >= 0:
            index_s = nextValidChar(s, index_s)
            index_t = nextValidChar(t, index_t)

            char_s = s[index_s] if index_s >= 0 else ""
            char_t = t[index_t] if index_t >= 0 else ""

            if char_s != char_t:
                return False

            index_s -= 1
            index_t -= 1

        return True


def test():
    sol = Solution()
    print(sol.backspaceCompare("ab#c", "ad#c"), "| True")
    print(sol.backspaceCompare("ab##", "c#d#"), "| True")
    print(sol.backspaceCompare("a#c", "b"), "| False")
    print(sol.backspaceCompare("a##b", "#a#b"), "| True")
    print(sol.backspaceCompare("", ""), "| True")


if __name__ == "__main__":
    test()
