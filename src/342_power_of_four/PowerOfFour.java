public class PowerOfFour {
    public boolean isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }

    public static void main(String[] args) {
        PowerOfFour sol = new PowerOfFour();
        System.out.println(sol.isPowerOfFour(16) + " | True");
        System.out.println(sol.isPowerOfFour(5) + " | False");
        System.out.println(sol.isPowerOfFour(1) + " | True");
        System.out.println(sol.isPowerOfFour(64) + " | True");
        System.out.println(sol.isPowerOfFour(0) + " | False");
        System.out.println(sol.isPowerOfFour(-4) + " | False");
    }
}
