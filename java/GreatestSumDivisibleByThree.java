public class GreatestSumDivisibleByThree {
    public int maxSumDivThree(int[] nums) {
        int[] dp = new int[] { 0, 0, 0 };

        for (int num : nums) {
            int[] temp = dp.clone();

            for (int i : dp) {
                temp[(i + num) % 3] = Math.max(temp[(i + num) % 3], i + num);
            }

            dp = temp;
        }

        return dp[0];
    }

    public static void main(String[] args) {
        GreatestSumDivisibleByThree s = new GreatestSumDivisibleByThree();
        int[] nums1 = { 3, 6, 5, 1, 8 };
        System.out.println(s.maxSumDivThree(nums1) + " 18");
        int[] nums2 = { 4 };
        System.out.println(s.maxSumDivThree(nums2) + " 0");
        int[] nums3 = { 1, 2, 3, 4, 4 };
        System.out.println(s.maxSumDivThree(nums3) + " 12");
    }
}
