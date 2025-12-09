public class FindMinimumOperationsDivisibleByThree {
    public int minimumOperations(int[] nums) {
        int ans = 0;

        for (int num : nums) {
            if (num % 3 != 0) {
                ans += 1;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        FindMinimumOperationsDivisibleByThree s = new FindMinimumOperationsDivisibleByThree();
        int[] nums1 = { 1, 2, 3, 4 };
        System.out.println(s.minimumOperations(nums1) + " 3");
        int[] nums2 = { 3, 6, 9 };
        System.out.println(s.minimumOperations(nums2) + " 0");
    }
}
