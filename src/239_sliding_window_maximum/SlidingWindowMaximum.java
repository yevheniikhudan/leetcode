/*
239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k 
which is moving from the very left of the array to the very right. You can only 
see the k numbers in the window. Each time the sliding window moves right by one 
position.

Return the max sliding window.
*/

import java.util.*;

public class SlidingWindowMaximum {
    /**
     * Find the maximum value in each sliding window of size k.
     * 
     * @param nums Array of integers
     * @param k    Size of the sliding window
     * @return Array of maximum values for each window position
     * 
     *         Time Complexity: O(n) where n = nums.length
     *         Space Complexity: O(k) for the deque
     */
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] result = new int[n - k + 1];
        Deque<Integer> q = new LinkedList<>();

        for (int i = 0; i < nums.length; i++) {
            while (!q.isEmpty() && q.getFirst() <= i - k) {
                q.removeFirst();
            }

            while (!q.isEmpty() && nums[q.getLast()] < nums[i]) {
                q.removeLast();
            }

            q.addLast(i);

            if (i >= k - 1) {
                result[i - k + 1] = nums[q.getFirst()];
            }
        }

        return result;
    }

    public static void main(String[] args) {
        SlidingWindowMaximum solution = new SlidingWindowMaximum();

        // Test case 1: Example 1
        int[] result1 = solution.maxSlidingWindow(new int[] { 1, 3, -1, -3, 5, 3, 6, 7 }, 3);
        System.out.println("Test 1: " + Arrays.toString(result1) + " (expected: [3, 3, 5, 5, 6, 7])");

        // Test case 2: Example 2
        int[] result2 = solution.maxSlidingWindow(new int[] { 1 }, 1);
        System.out.println("Test 2: " + Arrays.toString(result2) + " (expected: [1])");

        // Test case 3: k equals array length
        int[] result3 = solution.maxSlidingWindow(new int[] { 1, 3, 1, 2, 0, 5 }, 6);
        System.out.println("Test 3: " + Arrays.toString(result3) + " (expected: [5])");

        // Test case 4: Descending array
        int[] result4 = solution.maxSlidingWindow(new int[] { 9, 8, 7, 6, 5, 4, 3, 2, 1 }, 3);
        System.out.println("Test 4: " + Arrays.toString(result4) + " (expected: [9, 8, 7, 6, 5, 4, 3])");

        // Test case 5: Ascending array
        int[] result5 = solution.maxSlidingWindow(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 3);
        System.out.println("Test 5: " + Arrays.toString(result5) + " (expected: [3, 4, 5, 6, 7, 8, 9])");

        // Test case 6: All elements equal
        int[] result6 = solution.maxSlidingWindow(new int[] { 5, 5, 5, 5, 5 }, 2);
        System.out.println("Test 6: " + Arrays.toString(result6) + " (expected: [5, 5, 5, 5])");

        // Test case 7: k = 1
        int[] result7 = solution.maxSlidingWindow(new int[] { 4, -2, 7, 1 }, 1);
        System.out.println("Test 7: " + Arrays.toString(result7) + " (expected: [4, -2, 7, 1])");

        // Test case 8: Negative numbers
        int[] result8 = solution.maxSlidingWindow(new int[] { -7, -8, 7, 5, 7, 1, 6, 0 }, 4);
        System.out.println("Test 8: " + Arrays.toString(result8) + " (expected: [7, 7, 7, 7, 7])");

        // Test case 9: Mixed positive and negative
        int[] result9 = solution.maxSlidingWindow(new int[] { 1, -1, 2, -2, 3, -3 }, 2);
        System.out.println("Test 9: " + Arrays.toString(result9) + " (expected: [1, 2, 2, 3, 3])");

        // Test case 10: Large window
        int[] result10 = solution.maxSlidingWindow(new int[] { 9, 11 }, 2);
        System.out.println("Test 10: " + Arrays.toString(result10) + " (expected: [11])");
    }
}
