import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int minMeetingRooms(int[][] intervals) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        return pq.size();
    }
}

public class MeetingRoomsIi {
    private static int[][] copy2D(int[][] source) {
        int[][] copy = new int[source.length][];
        for (int i = 0; i < source.length; i++) {
            copy[i] = Arrays.copyOf(source[i], source[i].length);
        }
        return copy;
    }

    private static void runTests() {
        Solution sol = new Solution();
        int[][][] inputs = {
                { { 0, 30 }, { 5, 10 }, { 15, 20 } },
                { { 7, 10 }, { 2, 4 } },
                { { 1, 5 }, { 2, 3 }, { 3, 6 } },
                { { 1, 2 }, { 2, 3 }, { 3, 4 } },
                { { 1, 10 }, { 2, 9 }, { 3, 8 }, { 4, 7 } },
                { { 5, 8 } }
        };
        int[] expecteds = { 2, 1, 2, 1, 4, 1 };

        for (int i = 0; i < inputs.length; i++) {
            int actual = sol.minMeetingRooms(copy2D(inputs[i]));
            System.out.println(actual + " | " + expecteds[i]);
        }
    }

    public static void main(String[] args) {
        runTests();
    }
}
