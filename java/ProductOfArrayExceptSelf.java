import java.util.Arrays;

public class ProductOfArrayExceptSelf {
    /**
     * Product of Array Except Self
     *
     * @param nums List of integers
     * @return List of products except self
     */
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        ans[0] = 1;

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }

    public static void main(String[] args) {
        ProductOfArrayExceptSelf solution = new ProductOfArrayExceptSelf();

        // Test case 1
        int[] nums1 = { 1, 2, 3, 4 };
        int[] result1 = solution.productExceptSelf(nums1);
        System.out.println("Test 1: " + Arrays.toString(nums1) + " -> " + Arrays.toString(result1));
        assert Arrays.equals(result1, new int[] { 24, 12, 8, 6 })
                : "Expected [24,12,8,6], got " + Arrays.toString(result1);

        // Test case 2
        int[] nums2 = { -1, 1, 0, -3, 3 };
        int[] result2 = solution.productExceptSelf(nums2);
        System.out.println("Test 2: " + Arrays.toString(nums2) + " -> " + Arrays.toString(result2));
        assert Arrays.equals(result2, new int[] { 0, 0, 9, 0, 0 })
                : "Expected [0,0,9,0,0], got " + Arrays.toString(result2);

        // Test case 3: Zeros
        int[] nums3 = { 0, 0, 2, 3 };
        int[] result3 = solution.productExceptSelf(nums3);
        System.out.println("Test 3: " + Arrays.toString(nums3) + " -> " + Arrays.toString(result3));
        assert Arrays.equals(result3, new int[] { 0, 0, 0, 0 }) : "Expected [0,0,0,0], got " + Arrays.toString(result3);

        // Test case 4: Negative numbers
        int[] nums4 = { -2, -3, -4 };
        int[] result4 = solution.productExceptSelf(nums4);
        System.out.println("Test 4: " + Arrays.toString(nums4) + " -> " + Arrays.toString(result4));
        assert Arrays.equals(result4, new int[] { 12, 8, 6 }) : "Expected [12,8,6], got " + Arrays.toString(result4);

        System.out.println("All test cases passed!");
    }
}
