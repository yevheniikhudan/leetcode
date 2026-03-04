import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        boolean res = true;
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }

        return res;
    }
}

public class MeetingRooms {
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
                { { 1, 2 }, { 2, 3 }, { 3, 4 } },
                { { 1, 5 }, { 2, 3 }, { 5, 6 } },
                { { 1, 2 } },
                { { 5, 8 }, { 9, 15 }, { 15, 20 }, { 21, 22 } }
        };
        boolean[] expecteds = { false, true, true, false, true, true };

        for (int i = 0; i < inputs.length; i++) {
            boolean actual = sol.canAttendMeetings(copy2D(inputs[i]));
            System.out.println(actual + " | " + expecteds[i]);
        }
    }

    public static void main(String[] args) {
        runTests();
    }
}
