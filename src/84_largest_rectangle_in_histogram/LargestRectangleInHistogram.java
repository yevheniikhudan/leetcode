/*
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height 
where the width of each bar is 1, return the area of the largest rectangle 
in the histogram.
*/

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

class Solution {
    /**
     * Find the largest rectangle area in a histogram.
     * 
     * @param heights Array of bar heights
     * @return Maximum rectangle area
     * 
     *         Time Complexity: O(n) where n = heights.length
     *         Space Complexity: O(n) for the stack
     */
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int result = 0;
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < n + 1; i++) {
            while (!stack.isEmpty() && (i == n || heights[stack.peekLast()] > heights[i])) {
                int height = heights[stack.pollLast()];
                int width = stack.isEmpty() ? i : i - stack.peekLast() - 1;
                result = Math.max(result, height * width);
            }
            stack.addLast(i);
        }

        return result;
    }
}

public class LargestRectangleInHistogram {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int result1 = solution.largestRectangleArea(new int[] { 2, 1, 5, 6, 2, 3 });
        System.out.println("Test 1: " + result1 + " (expected: 10)");

        // Test case 2: Example 2
        int result2 = solution.largestRectangleArea(new int[] { 2, 4 });
        System.out.println("Test 2: " + result2 + " (expected: 4)");

        // Test case 3: Single bar
        int result3 = solution.largestRectangleArea(new int[] { 5 });
        System.out.println("Test 3: " + result3 + " (expected: 5)");

        // Test case 4: Increasing heights
        int result4 = solution.largestRectangleArea(new int[] { 1, 2, 3, 4, 5 });
        System.out.println("Test 4: " + result4 + " (expected: 9)");

        // Test case 5: Decreasing heights
        int result5 = solution.largestRectangleArea(new int[] { 5, 4, 3, 2, 1 });
        System.out.println("Test 5: " + result5 + " (expected: 9)");

        // Test case 6: All same height
        int result6 = solution.largestRectangleArea(new int[] { 3, 3, 3, 3 });
        System.out.println("Test 6: " + result6 + " (expected: 12)");

        // Test case 7: With zeros
        int result7 = solution.largestRectangleArea(new int[] { 2, 0, 2 });
        System.out.println("Test 7: " + result7 + " (expected: 2)");

        // Test case 8: Large rectangle in middle
        int result8 = solution.largestRectangleArea(new int[] { 1, 2, 3, 4, 5, 3, 3, 2 });
        System.out.println("Test 8: " + result8 + " (expected: 15)");
    }
}
