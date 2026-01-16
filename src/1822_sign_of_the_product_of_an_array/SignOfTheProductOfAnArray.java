public class SignOfTheProductOfAnArray {
    public int arraySign(int[] nums) {
        int sign = 1;
        for (int num : nums) {
            if (num == 0)
                return 0;
            if (num < 0)
                sign = -sign;
        }
        return sign;
    }

    // Test scaffolding
    public static void main(String[] args) {
        SignOfTheProductOfAnArray sol = new SignOfTheProductOfAnArray();
        System.out.println(sol.arraySign(new int[] { 1, -2, -3, 4 }) + " | 1");
        System.out.println(sol.arraySign(new int[] { 1, 5, 0, 2, -3 }) + " | 0");
        System.out.println(sol.arraySign(new int[] { -1, 1, -1, 1, -1 }) + " | -1");
        System.out.println(sol.arraySign(new int[] { 2, 3, 4, 5 }) + " | 1");
        System.out.println(sol.arraySign(new int[] { -2, -3, -4 }) + " | -1");
    }
}
