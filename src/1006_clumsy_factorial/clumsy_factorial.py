class Solution:
    def clumsy(self, n: int) -> int:
        if n == 0:
            return 1
        elif n == 1:
            return 1
        elif n == 2:
            return 2
        elif n == 3:
            return 6
        elif n == 4:
            return 7
        if n % 4 == 0:
            return n + 1
        elif n % 4 == 1 or n % 4 == 2:
            return n + 2
        else:  # n % 4 == 3
            return n - 1

    def clumsyStack(self, n: int) -> int:
        operations = ["*", "/", "+", "-"]
        stack = []
        opIdx = 0
        stack.append(n)
        n -= 1
        res = 0

        while n > 0:
            op = operations[opIdx % 4]
            if op == "*":
                stack.append(stack.pop() * n)
            elif op == "/":
                prev = stack.pop()
                if prev < 0:
                    stack.append(-(-prev // n))
                else:
                    stack.append(prev // n)
            elif op == "+":
                stack.append(n)
            else:
                stack.append(-n)

            opIdx += 1
            n -= 1

        while stack:
            res += stack.pop()

        return res


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()

    # Test case 1
    print(sol.clumsy(4), "|", 7)

    # Test case 2
    print(sol.clumsy(10), "|", 12)

    # Test case 3
    print(sol.clumsy(1), "|", 1)

    # Test case 4
    print(sol.clumsy(2), "|", 2)

    # Test case 5
    print(sol.clumsy(3), "|", 6)

    # Test case 6
    print(sol.clumsy(5), "|", 7)
