/*
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the 
container contains the most water.

Return the maximum amount of water a container can store.
*/

public class ContainerWithMostWater {
    public int maxArea(int[] height) {
        int res = 0;
        int left = 0, right = height.length - 1;

        while (left < right) {
            int l = right - left;
            int h = Math.min(height[left], height[right]);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
            res = Math.max(res, l * h);
        }

        return res;
    }

    public static void main(String[] args) {
        ContainerWithMostWater solution = new ContainerWithMostWater();

        // Test case 1: Example 1
        int[] height1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        int result1 = solution.maxArea(height1);
        System.out.printf("Test 1: %d (expected: 49)%n", result1);

        // Test case 2: Example 2
        int[] height2 = { 1, 1 };
        int result2 = solution.maxArea(height2);
        System.out.printf("Test 2: %d (expected: 1)%n", result2);

        // Test case 3: Increasing heights
        int[] height3 = { 1, 2, 3, 4, 5 };
        int result3 = solution.maxArea(height3);
        System.out.printf("Test 3: %d (expected: 6)%n", result3);

        // Test case 4: Decreasing heights
        int[] height4 = { 5, 4, 3, 2, 1 };
        int result4 = solution.maxArea(height4);
        System.out.printf("Test 4: %d (expected: 6)%n", result4);

        // Test case 5: All same height
        int[] height5 = { 3, 3, 3, 3 };
        int result5 = solution.maxArea(height5);
        System.out.printf("Test 5: %d (expected: 9)%n", result5);

        // Test case 6: Two tall lines far apart
        int[] height6 = { 10, 1, 1, 1, 1, 1, 1, 1, 1, 10 };
        int result6 = solution.maxArea(height6);
        System.out.printf("Test 6: %d (expected: 90)%n", result6);

        // Test case 7: Peak in middle
        int[] height7 = { 1, 3, 5, 4, 2 };
        int result7 = solution.maxArea(height7);
        System.out.printf("Test 7: %d (expected: 6)%n", result7);
    }
}
