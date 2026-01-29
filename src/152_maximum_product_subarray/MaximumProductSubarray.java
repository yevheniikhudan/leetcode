class Solution {
    public int maxProduct(int[] nums) {
        int maxSoFar = 1;
        int minSoFar = 1;
        int result = nums[0];

        for (int num : nums) {
            int nextMax = num * maxSoFar;
            int nextMin = num * minSoFar;
            maxSoFar = Math.max(num, Math.max(nextMax, nextMin));
            minSoFar = Math.min(num, Math.min(nextMax, nextMin));
            result = Math.max(result, maxSoFar);
        }

        return result;
    }
}

public class MaximumProductSubarray {
    public static void main(String[] args) {
        testMaxProduct();
    }

    public static void testMaxProduct() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int[] nums1 = { 2, 3, -2, 4 };
        int expected1 = 6;
        int actual1 = solution.maxProduct(nums1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int[] nums2 = { -2, 0, -1 };
        int expected2 = 0;
        int actual2 = solution.maxProduct(nums2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: All positive
        int[] nums3 = { 1, 2, 3, 4 };
        int expected3 = 24;
        int actual3 = solution.maxProduct(nums3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: All negative
        int[] nums4 = { -1, -2, -3 };
        int expected4 = -1;
        int actual4 = solution.maxProduct(nums4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Single element
        int[] nums5 = { 5 };
        int expected5 = 5;
        int actual5 = solution.maxProduct(nums5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: With zero
        int[] nums6 = { 2, 0, 3, -1 };
        int expected6 = 3;
        int actual6 = solution.maxProduct(nums6);
        System.out.println(actual6 + " | " + expected6);
    }
}
