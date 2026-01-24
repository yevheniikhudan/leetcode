import java.util.*;

class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        int a = nums[0], b = Math.max(nums[0], nums[1]);

        for (int i = 2; i < nums.length; i++) {
            int next = Math.max(nums[i] + a, b);
            a = b;
            b = next;
        }

        return b;
    }
}

public class HouseRobber {
    public static void main(String[] args) {
        testRob();
    }

    // Test helper
    public static void testRob() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int[] nums1 = { 1, 2, 3, 1 };
        int expected1 = 4;
        int actual1 = solution.rob(nums1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int[] nums2 = { 2, 7, 9, 3, 1 };
        int expected2 = 12;
        int actual2 = solution.rob(nums2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: n=1
        int[] nums3 = { 5 };
        int expected3 = 5;
        int actual3 = solution.rob(nums3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: n=2
        int[] nums4 = { 1, 2 };
        int expected4 = 2;
        int actual4 = solution.rob(nums4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: All zeros
        int[] nums5 = { 0, 0, 0 };
        int expected5 = 0;
        int actual5 = solution.rob(nums5);
        System.out.println(actual5 + " | " + expected5);
    }
}
