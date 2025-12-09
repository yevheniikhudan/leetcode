#include <iostream>
#include <vector>
using namespace std;

class Bank {
   private:
    vector<long long> balance;
    int n;

    bool isValidAccount(int account) { return account >= 1 && account <= n; }
    bool hasSufficientBalance(int account, long long money) {
        return balance[account - 1] >= money;
    }

   public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
        this->n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (!isValidAccount(account1)) return false;
        if (!isValidAccount(account2)) return false;
        if (!hasSufficientBalance(account1, money)) return false;

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;

        return true;
    }

    bool deposit(int account, long long money) {
        if (!isValidAccount(account)) return false;

        balance[account - 1] += money;

        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValidAccount(account)) return false;
        if (!hasSufficientBalance(account, money)) return false;

        balance[account - 1] -= money;

        return true;
    }
};

int main() {
    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank* bank = new Bank(balance);

    cout << bank->withdraw(3, 10) << " Expected: 1" << endl;
    cout << bank->transfer(5, 1, 20) << " Expected: 1" << endl;
    cout << bank->deposit(5, 20) << " Expected: 1" << endl;
    cout << bank->transfer(3, 4, 15) << " Expected: 0" << endl;
    cout << bank->withdraw(10, 50) << " Expected: 0" << endl;

    delete bank;
    return 0;
}
