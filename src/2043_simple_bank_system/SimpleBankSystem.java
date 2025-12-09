class SimpleBankSystem {
    private int N;
    private long[] balance;

    public SimpleBankSystem(long[] balance) {
        this.N = balance.length;
        this.balance = balance.clone();
    }

    public boolean transfer(int account1, int account2, long money) {
        if (!isValidAccount(account1))
            return false;

        if (!isValidAccount(account2))
            return false;

        if (!hasSufficientBalance(account1, money))
            return false;

        this.balance[account1 - 1] -= money;
        this.balance[account2 - 1] += money;

        return true;
    }

    public boolean deposit(int account, long money) {
        if (!isValidAccount(account))
            return false;

        this.balance[account - 1] += money;

        return true;
    }

    public boolean withdraw(int account, long money) {
        if (!isValidAccount(account))
            return false;

        if (!hasSufficientBalance(account, money))
            return false;

        this.balance[account - 1] -= money;

        return true;
    }

    private boolean isValidAccount(int account) {
        return account >= 1 && account <= this.N;
    }

    private boolean hasSufficientBalance(int account, long money) {
        return this.balance[account - 1] >= money;
    }

    public static void main(String[] args) {
        SimpleBankSystem bank = new SimpleBankSystem(new long[] { 10, 100, 20, 50, 30 });

        System.out.println(bank.withdraw(3, 10) + " Expected: true");
        System.out.println(bank.transfer(5, 1, 20) + " Expected: true");
        System.out.println(bank.deposit(5, 20) + " Expected: true");
        System.out.println(bank.transfer(3, 4, 15) + " Expected: false");
        System.out.println(bank.withdraw(10, 50) + " Expected: false");
    }
}
