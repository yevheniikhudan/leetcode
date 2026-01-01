import java.util.*;

public class LastStoneWeight {
    /**
     * Returns the weight of the last remaining stone (or 0 if none remain).
     */
    public static int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pQueue = new PriorityQueue<>(Collections.reverseOrder());
        for (int stone : stones) {
            pQueue.offer(stone);
        }

        while (pQueue.size() > 1) {
            int s1 = pQueue.poll();
            int s2 = pQueue.poll();

            if (s1 != s2) {
                pQueue.offer(s1 - s2);
            }
        }

        return pQueue.isEmpty() ? 0 : pQueue.peek();
    }

    // Helper for testing
    public static void main(String[] args) {
        System.out.println(lastStoneWeight(new int[] { 2, 7, 4, 1, 8, 1 })); // 1
        System.out.println(lastStoneWeight(new int[] { 1 })); // 1
        System.out.println(lastStoneWeight(new int[] { 3, 3, 3, 3 })); // 0
        System.out.println(lastStoneWeight(new int[] { 10, 4, 2, 10 })); // 2
        System.out.println(lastStoneWeight(new int[] { 5, 5, 5, 1 })); // 2
    }
}
