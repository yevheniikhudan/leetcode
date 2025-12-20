/**
 * 287. Find the Duplicate Number
 * 
 * Given an array of integers nums containing n + 1 integers where each integer
 * is in the range [1, n] inclusive.
 * 
 * There is only one repeated number in nums, return this repeated number.
 * You must solve the problem without modifying the array nums and using only
 * constant extra space.
 * 
 * Difficulty: Medium
 */

public class FindDuplicate {

    /**
     * Find the duplicate number in the array.
     * 
     * @param nums Array of integers with n+1 elements in range [1, n]
     * @return The duplicate number
     * 
     *         Time Complexity: O(n)
     *         Space Complexity: O(1)
     */
    public int findDuplicate(int[] nums) {
        int slow = nums[0], fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
                break;
        } while (slow != fast);

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];

            if (slow == fast)
                return nums[slow];
        }

        return slow;
    }

    public static void main(String[] args) {
        FindDuplicate solution = new FindDuplicate();

        // Test case 1: Example 1 - basic case
        int[] nums1 = { 1, 3, 4, 2, 2 };
        int result1 = solution.findDuplicate(nums1);
        System.out.println("Test 1: " + result1 + " (expected: 2)");

        // Test case 2: Example 2 - duplicate at different position
        int[] nums2 = { 3, 1, 3, 4, 2 };
        int result2 = solution.findDuplicate(nums2);
        System.out.println("Test 2: " + result2 + " (expected: 3)");

        // Test case 3: Example 3 - all same number
        int[] nums3 = { 3, 3, 3, 3, 3 };
        int result3 = solution.findDuplicate(nums3);
        System.out.println("Test 3: " + result3 + " (expected: 3)");

        // Test case 4: Duplicate at start
        int[] nums4 = { 1, 1 };
        int result4 = solution.findDuplicate(nums4);
        System.out.println("Test 4: " + result4 + " (expected: 1)");

        // Test case 5: Duplicate at end
        int[] nums5 = { 1, 2, 3, 4, 4 };
        int result5 = solution.findDuplicate(nums5);
        System.out.println("Test 5: " + result5 + " (expected: 4)");

        // Test case 6: Larger array
        int[] nums6 = { 2, 5, 9, 6, 9, 3, 8, 9, 7, 1, 4 };
        int result6 = solution.findDuplicate(nums6);
        System.out.println("Test 6: " + result6 + " (expected: 9)");

        // Test case 7: Sequential with duplicate in middle
        int[] nums7 = { 1, 2, 3, 3, 4, 5, 6 };
        int result7 = solution.findDuplicate(nums7);
        System.out.println("Test 7: " + result7 + " (expected: 3)");
    }
}
