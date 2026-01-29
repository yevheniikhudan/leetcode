import java.util.*;

class Solution {
    public int lengthOfLIS(int[] nums) {
        List<Integer> dp = new ArrayList<>();
        dp.add(nums[0]);

        int LIS = 1;
        for (int i = 1; i < nums.length; i++) {
            if (dp.get(dp.size() - 1) < nums[i]) {
                dp.add(nums[i]);
                LIS++;
                continue;
            }

            int idx = Collections.binarySearch(dp, nums[i]);
            if (idx < 0) {
                idx = -(idx + 1);
            }
            dp.set(idx, nums[i]);
        }

        return LIS;
    }
}

public class LongestIncreasingSubsequence {
    public static void main(String[] args) {
        testLengthOfLIS();
    }

    public static void testLengthOfLIS() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int[] nums1 = { 10, 9, 2, 5, 3, 7, 101, 18 };
        int expected1 = 4;
        int actual1 = solution.lengthOfLIS(nums1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int[] nums2 = { 0, 1, 0, 3, 2, 3 };
        int expected2 = 4;
        int actual2 = solution.lengthOfLIS(nums2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Example 3
        int[] nums3 = { 7, 7, 7, 7, 7, 7, 7 };
        int expected3 = 1;
        int actual3 = solution.lengthOfLIS(nums3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: Strictly increasing
        int[] nums4 = { 1, 2, 3, 4, 5 };
        int expected4 = 5;
        int actual4 = solution.lengthOfLIS(nums4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Strictly decreasing
        int[] nums5 = { 5, 4, 3, 2, 1 };
        int expected5 = 1;
        int actual5 = solution.lengthOfLIS(nums5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: Mixed with duplicates
        int[] nums6 = { 1, 3, 2, 3, 1, 4 };
        int expected6 = 4; // e.g., [1,2,3,4]
        int actual6 = solution.lengthOfLIS(nums6);
        System.out.println(actual6 + " | " + expected6);
    }
}
