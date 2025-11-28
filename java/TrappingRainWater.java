/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width 
of each bar is 1, compute how much water it can trap after raining.
*/

public class TrappingRainWater {
    /**
     * Calculate trapped rainwater using two pointers.
     * 
     * @param height Array representing elevation map
     * @return Total units of trapped water
     * 
     *         Time Complexity: O(n)
     *         Space Complexity: O(1)
     */
    public int trap(int[] height) {
        int left = 0, right = height.length - 1, res = 0, maxLeft = 0, maxRight = 0;

        while (left < right) {
            int hLeft = height[left], hRight = height[right];

            if (hLeft < hRight) {
                maxLeft = Math.max(maxLeft, hLeft);
                res += maxLeft - hLeft;
                left += 1;
            } else {
                maxRight = Math.max(maxRight, hRight);
                res += maxRight - hRight;
                right -= 1;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        TrappingRainWater solution = new TrappingRainWater();

        // Test case 1: Example 1
        int[] height1 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        int result1 = solution.trap(height1);
        System.out.printf("Test 1: %d (expected: 6)%n", result1);

        // Test case 2: Example 2
        int[] height2 = { 4, 2, 0, 3, 2, 5 };
        int result2 = solution.trap(height2);
        System.out.printf("Test 2: %d (expected: 9)%n", result2);

        // Test case 3: No water trapped (flat)
        int[] height3 = { 3, 3, 3, 3 };
        int result3 = solution.trap(height3);
        System.out.printf("Test 3: %d (expected: 0)%n", result3);

        // Test case 4: No water trapped (increasing)
        int[] height4 = { 1, 2, 3, 4, 5 };
        int result4 = solution.trap(height4);
        System.out.printf("Test 4: %d (expected: 0)%n", result4);

        // Test case 5: No water trapped (decreasing)
        int[] height5 = { 5, 4, 3, 2, 1 };
        int result5 = solution.trap(height5);
        System.out.printf("Test 5: %d (expected: 0)%n", result5);

        // Test case 6: Simple valley
        int[] height6 = { 3, 0, 2 };
        int result6 = solution.trap(height6);
        System.out.printf("Test 6: %d (expected: 2)%n", result6);

        // Test case 7: Multiple valleys
        int[] height7 = { 3, 0, 2, 0, 4 };
        int result7 = solution.trap(height7);
        System.out.printf("Test 7: %d (expected: 7)%n", result7);

        // Test case 8: Two elements
        int[] height8 = { 2, 1 };
        int result8 = solution.trap(height8);
        System.out.printf("Test 8: %d (expected: 0)%n", result8);
    }
}
