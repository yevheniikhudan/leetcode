class Solution {
    public int clumsy(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 6;
        if (n == 4)
            return 7;
        if (n % 4 == 0)
            return n + 1;
        if (n % 4 == 1 || n % 4 == 2)
            return n + 2;
        return n - 1;
    }
}

public class ClumsyFactorial {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // Test case 1
        System.out.println(sol.clumsy(4) + " | " + 7);

        // Test case 2
        System.out.println(sol.clumsy(10) + " | " + 12);

        // Test case 3
        System.out.println(sol.clumsy(1) + " | " + 1);

        // Test case 4
        System.out.println(sol.clumsy(2) + " | " + 2);

        // Test case 5
        System.out.println(sol.clumsy(3) + " | " + 6);

        // Test case 6
        System.out.println(sol.clumsy(5) + " | " + 7);
    }
}
