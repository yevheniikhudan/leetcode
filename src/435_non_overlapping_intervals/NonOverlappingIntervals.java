import java.util.*;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int res = 0;
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));
        int last = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < last) {
                res++;
            } else {
                last = intervals[i][1];
            }
        }

        return res;
    }
}

class NonOverlappingIntervals {
    public static void main(String[] args) {
        runTests();
    }

    private static void runTests() {
        Solution sol = new Solution();
        List<int[][]> inputs = Arrays.asList(
                new int[][] { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 3 } },
                new int[][] { { 1, 2 }, { 1, 2 }, { 1, 2 } },
                new int[][] { { 1, 2 }, { 2, 3 } },
                new int[][] { { 1, 100 }, { 11, 22 }, { 1, 11 }, { 2, 12 } },
                new int[][] { { 1, 2 } });
        List<Integer> expecteds = Arrays.asList(1, 2, 0, 2, 0);

        for (int i = 0; i < inputs.size(); i++) {
            int actual = sol.eraseOverlapIntervals(inputs.get(i));
            System.out.println(actual + " | " + expecteds.get(i));
        }
    }
}
