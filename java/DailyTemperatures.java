/*
739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return 
an array answer such that answer[i] is the number of days you have to wait after 
the ith day to get a warmer temperature. If there is no future day for which this 
is possible, keep answer[i] == 0 instead.
*/

import java.util.*;

public class DailyTemperatures {
    /**
     * Find number of days until a warmer temperature for each day.
     * 
     * @param temperatures Array of daily temperatures
     * @return Array of days to wait for warmer temperature (0 if none)
     * 
     *         Time Complexity: O(n) where n = temperatures.length
     *         Space Complexity: O(n) for the stack
     */
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]) {
                int prevIndex = stack.pop();
                result[prevIndex] = i - prevIndex;
            }
            stack.push(i);
        }

        return result;
    }

    public static void main(String[] args) {
        DailyTemperatures solution = new DailyTemperatures();

        // Test case 1: Example 1
        int[] result1 = solution.dailyTemperatures(new int[] { 73, 74, 75, 71, 69, 72, 76, 73 });
        System.out.println("Test 1: " + Arrays.toString(result1) + " (expected: [1, 1, 4, 2, 1, 1, 0, 0])");

        // Test case 2: Example 2
        int[] result2 = solution.dailyTemperatures(new int[] { 30, 40, 50, 60 });
        System.out.println("Test 2: " + Arrays.toString(result2) + " (expected: [1, 1, 1, 0])");

        // Test case 3: Example 3
        int[] result3 = solution.dailyTemperatures(new int[] { 30, 60, 90 });
        System.out.println("Test 3: " + Arrays.toString(result3) + " (expected: [1, 1, 0])");

        // Test case 4: All decreasing
        int[] result4 = solution.dailyTemperatures(new int[] { 100, 90, 80, 70 });
        System.out.println("Test 4: " + Arrays.toString(result4) + " (expected: [0, 0, 0, 0])");

        // Test case 5: All increasing
        int[] result5 = solution.dailyTemperatures(new int[] { 30, 40, 50, 60, 70 });
        System.out.println("Test 5: " + Arrays.toString(result5) + " (expected: [1, 1, 1, 1, 0])");

        // Test case 6: Single day
        int[] result6 = solution.dailyTemperatures(new int[] { 75 });
        System.out.println("Test 6: " + Arrays.toString(result6) + " (expected: [0])");

        // Test case 7: All same temperatures
        int[] result7 = solution.dailyTemperatures(new int[] { 70, 70, 70, 70 });
        System.out.println("Test 7: " + Arrays.toString(result7) + " (expected: [0, 0, 0, 0])");

        // Test case 8: Spike pattern
        int[] result8 = solution.dailyTemperatures(new int[] { 30, 100, 30, 100, 30 });
        System.out.println("Test 8: " + Arrays.toString(result8) + " (expected: [1, 0, 1, 0, 0])");

        // Test case 9: Valley pattern
        int[] result9 = solution.dailyTemperatures(new int[] { 90, 30, 90, 30, 90 });
        System.out.println("Test 9: " + Arrays.toString(result9) + " (expected: [0, 1, 0, 1, 0])");

        // Test case 10: Mixed pattern
        int[] result10 = solution.dailyTemperatures(new int[] { 55, 38, 53, 81, 61, 93, 97, 32, 43, 78 });
        System.out.println("Test 10: " + Arrays.toString(result10) + " (expected: [3, 1, 1, 2, 1, 1, 0, 1, 1, 0])");
    }
}
