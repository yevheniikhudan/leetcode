import java.util.*;

public class KthLargestElementInAnArray {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int num : nums) {
            pq.add(num);

            if (pq.size() > k) {
                pq.poll();
            }
        }

        return pq.poll();
    }

    // Test scaffolding
    public static void main(String[] args) {
        int[][] testNums = {
                { 3, 2, 1, 5, 6, 4 },
                { 3, 2, 3, 1, 2, 4, 5, 5, 6 },
                { 1 },
                { 2, 1 },
                { 7, 6, 5, 4, 3, 2, 1 }
        };
        int[] ks = { 2, 4, 1, 2, 5 };
        int[] expected = { 5, 4, 1, 1, 3 };
        KthLargestElementInAnArray sol = new KthLargestElementInAnArray();
        for (int i = 0; i < testNums.length; i++) {
            int actual = sol.findKthLargest(testNums[i], ks[i]);
            System.out.println(actual + " | " + expected[i]);
        }
    }
}
