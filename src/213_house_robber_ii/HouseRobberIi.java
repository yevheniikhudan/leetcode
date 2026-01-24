
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }

        return Math.max(rob(nums, 0, n - 1), rob(nums, 1, n));
    }

    private int rob(int[] nums, int left, int right) { // rob left inclusive, right exclusive
        int a = 0, b = 0;
        for (int i = left; i < right; i++) {
            int temp = b;
            b = Math.max(nums[i] + a, b);
            a = temp;
        }
        return b;
    }
}

public class HouseRobberIi {
    public static void main(String[] args) {
        testRob();
    }

    // Test helper
    public static void testRob() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int[] nums1 = { 2, 3, 2 };
        int expected1 = 3;
        int actual1 = solution.rob(nums1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int[] nums2 = { 1, 2, 3, 1 };
        int expected2 = 4;
        int actual2 = solution.rob(nums2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Example 3
        int[] nums3 = { 1, 2, 3 };
        int expected3 = 3;
        int actual3 = solution.rob(nums3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: Single house
        int[] nums4 = { 5 };
        int expected4 = 5;
        int actual4 = solution.rob(nums4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Two houses
        int[] nums5 = { 1, 2 };
        int expected5 = 2;
        int actual5 = solution.rob(nums5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: All zeros
        int[] nums6 = { 0, 0, 0, 0 };
        int expected6 = 0;
        int actual6 = solution.rob(nums6);
        System.out.println(actual6 + " | " + expected6);
    }
}
