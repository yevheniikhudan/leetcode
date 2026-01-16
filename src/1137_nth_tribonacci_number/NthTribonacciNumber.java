public class NthTribonacciNumber {
    public int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; ++i) {
            int next = a + b + c;
            a = b;
            b = c;
            c = next;
        }
        return c;
    }

    // Test scaffolding
    public static void main(String[] args) {
        NthTribonacciNumber sol = new NthTribonacciNumber();
        System.out.println(sol.tribonacci(0)); // 0
        System.out.println(sol.tribonacci(1)); // 1
        System.out.println(sol.tribonacci(2)); // 1
        System.out.println(sol.tribonacci(3)); // 2
        System.out.println(sol.tribonacci(4)); // 4
        System.out.println(sol.tribonacci(25)); // 1389537
    }
}
