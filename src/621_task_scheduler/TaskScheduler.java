import java.util.*;

public class TaskScheduler {
    public int leastInterval(char[] tasks, int n) {
        Map<Character, Integer> counter = new HashMap<>();
        for (char t : tasks)
            counter.put(t, counter.getOrDefault(t, 0) + 1);
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int cnt : counter.values())
            maxHeap.offer(cnt);
        Queue<int[]> q = new LinkedList<>(); // [count, nextAvailableTime]
        int time = 0;
        while (!maxHeap.isEmpty() || !q.isEmpty()) {
            time++;
            if (maxHeap.isEmpty()) {
                time = q.peek()[1];
            } else {
                int cnt = maxHeap.poll() - 1;
                if (cnt > 0)
                    q.offer(new int[] { cnt, time + n });
            }
            if (!q.isEmpty() && q.peek()[1] <= time) {
                maxHeap.offer(q.poll()[0]);
            }
        }
        return time;
    }

    // Test scaffolding
    public static void main(String[] args) {
        char[][] testTasks = {
                { 'A', 'A', 'A', 'B', 'B', 'B' },
                { 'A', 'A', 'A', 'B', 'B', 'B' },
                { 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G' },
                { 'A' },
                { 'A', 'B', 'C', 'D' }
        };
        int[] ns = { 2, 0, 2, 100, 2 };
        int[] expected = { 8, 6, 16, 1, 4 };
        TaskScheduler sol = new TaskScheduler();
        for (int i = 0; i < testTasks.length; i++) {
            int actual = sol.leastInterval(testTasks[i], ns[i]);
            System.out.println(actual + " | " + expected[i]);
        }
    }
}
