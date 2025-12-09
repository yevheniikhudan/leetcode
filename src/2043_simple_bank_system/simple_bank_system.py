from typing import List


class Bank:
    def __init__(self, balance: List[int]):
        self.n = len(balance)
        self.balance = balance

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if not self.isValidAccount(account1):
            return False

        if not self.isValidAccount(account2):
            return False

        if not self.hasSufficientBalance(account1, money):
            return False

        self.balance[account1 - 1] -= money
        self.balance[account2 - 1] += money

        return True

    def deposit(self, account: int, money: int) -> bool:
        if not self.isValidAccount(account):
            return False

        self.balance[account - 1] += money

        return True

    def withdraw(self, account: int, money: int) -> bool:
        if not self.isValidAccount(account):
            return False

        if not self.hasSufficientBalance(account, money):
            return False

        self.balance[account - 1] -= money

        return True

    def isValidAccount(self, account: int) -> bool:
        return 1 <= account <= self.n

    def hasSufficientBalance(self, account: int, money: int) -> bool:
        return self.balance[account - 1] >= money


# Test case
bank = Bank([10, 100, 20, 50, 30])
print(bank.withdraw(3, 10), True)
print(bank.transfer(5, 1, 20), True)
print(bank.deposit(5, 20), True)
print(bank.transfer(3, 4, 15), False)
print(bank.withdraw(10, 50), False)
